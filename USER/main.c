#include "stm32f10x.h"
#include "delay.h"
#include "ILI93xx.h"
#include "malloc.h"
#include "GUI.h"
#include "timer.h"
#include "GUIDemo.h"
#include "test.h"
#include "led.h"
#include "key.h"
#include "Interface.h"
#include "example.h"
#include "touch.h"
#include "iic.h"
#include "24c16.h"
#include "data.h"
#include "sigmastudiofw.h"
#include "algorithm.h"
#include "rtc.h"
/**************************************
***********注意事项********************
STM32改为其他芯片
1.改Device为GDF303时不用改东西可以直接用,因为GDF303
没有FPU单元;
2.改Device为ATF403时,ATF403拥有FPU单元，但此时用的
EMWIN-CM3库没有支持FPU单元,如果开启FPU则会进入硬件错误,
关闭FPU单元则正常使用。
关闭步骤：Target -> Floating Poirt Hardware -> Not Used
3.改了主频后需要改FSMC的速度，否则emwin读数据有问题

4.不能直接把Device 为ATF403的程序直接下载到STM32上，不能运行，要改Device
////////////////
4.如果使用SRAM-224k需要配置EOPB0 为 0xfe，ZW会把128k分给SRAM,NZW会增大128k，
此时的ZW固定为128k


5.*注意：该软件GP芯片使用的stm32的flash下载算法，如果不行请使用回GD的flash算法
*该屏的DB13和DB15要掉转

6.STM32的程序不用改Device可直接下载到AT和GD，但反过来不行

7.因为用到了不同字体大小，所以占的RO-data比较大
***************************************/

//当前页面句柄
WM_HWIN hWin_now;

//当前页面数据指针
void *Inface_data;

//用来查看是否释放内存

u8 FLASH_EXTER = 0; //额外的RAM

extern void default_download_IC_1(void);
void adu114(void);
u32 key_press = 0;

void gain_select(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);						 //PB.5 输出高	 

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_12|GPIO_Pin_13;			
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_12|GPIO_Pin_13);						 //PB.5 输出高	 	
				
}

void Check_scan(void)
{
	u8 key_value = 0;
    u8 key_value1 = 0;
    u8 key_value2 = 0;
    u8 key_value3 = 0;
	u8 mem_use = 0;  //内存使用率
    u16 count = 0;
	u32 key_count = 0;
	
	if(WM_IsWindow(hWin_now)) //判断hWin_now是否有效,Framewin窗口客户区句柄
        {

            /***********************************旋钮检测************************************/
            //有问题，里面有while循环,需要注意陷入死循环
            key_value1 = Encoder_Check_One();   //旋钮1检测
            key_value2 = Encoder_Check_Two();   //旋钮2检测
            key_value3 = Encoder_Check_Three(); //旋钮3检测
            //此程序一次只检测一个旋钮动作
            if(((key_value1 != Encoder_static) || (key_value2 != Encoder_static)
               || (key_value3 != Encoder_static))&&(key_lock_flag==0)) //有动作
            {
                if(key_value1)
                {
                    key_value = key_value1;
                }
                else if(key_value2)
                {
                    key_value = key_value2;
                }
                else if(key_value3)
                {
                    key_value = key_value3;
                }
				
                switch(key_value)
                {
                    case Encoder1_left:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_INPUT_LEFT); //输入旋钮发送的信息
                        //会直接执行被聚焦窗口的回调函数
                        //调用过程：GUI_SendKeyMsg->WM_SendMessage->回调函数->发送WM_NOTIFY_PARENT
                        //给父窗口

                        break;

                    case Encoder1_right:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_INPUT_RIGHT);
                        break;

                    case Encoder2_left:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_OUT_LEFT); //输出旋钮
                        break;

                    case Encoder2_right:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_OUT_RIGHT);
                        break;

                    case Encoder3_left:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_CONTROL_LEFT); //control旋钮
                        break;
                    case Encoder3_right:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_CONTROL_RIGHT);
                        break;

                    default:
                        break;
                }//end of switch(key_value)
				key_count = 0;
            }//end of if
			else  //没有旋钮动作
			{
				key_count++;  
				if(key_count >= 700) //当大约XXXms内没有动作
				{
					key_count = 0;
					WM_SendMessageNoPara(hWin_now, MSG_KNOB_NULL);  
				}
			}


            /*********************************按键检测*********************************/
            key_value = KEY_Scan(0);
            if(key_value)
            {
				key_press = 0;
				if((key_lock_flag == 1)&&(key_value != KEY_EN_2))
				{
					key_value = 55;
				}
                switch(key_value)
                {
                    //输入按钮
                    case KEY_INPUT:
                        
                        //先把灯全灭
                        LED_All_Off;
                        Input_led_On; //灯亮
						GUI_EndDialog(hWin_now, 0); //结束本界面
						hWin_now = Input_First(); //显示INPUT第一个界面
//						WM_SendMessageNoPara(hWin_now, MSG_KEY_INPUT);
                        break;

                    //退出按钮
                    case KEY_ESC:
                        //先把灯全灭
                        LED_All_Off;
                        Esc_led_On; //灯亮
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_ESC);
                        break;

                    //输出按钮
                    case KEY_OUTPUT:
                        //先把灯全灭
                        LED_All_Off;
                        Out_led_On; //灯亮
//                        WM_SendMessageNoPara(hWin_now, MSG_KEY_OUTPUT);
						GUI_EndDialog(hWin_now, 0); //结束本界面
						hWin_now = Output_First(); //显示OUTPUT第二个界面
                        break;

                    //系统按钮
                    case KEY_SYSTEM:
                        LED_All_Off;
                        Sys_led_On; //灯亮
//                      WM_SendMessageNoPara(hWin_now, MSG_KEY_SYSTEM);
						GUI_EndDialog(hWin_now, 0); //结束本界面
						hWin_now = System_First();
						break;

                    //旋钮1
                    case KEY_EN_1:
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_VOL_INPUT);
                        break;

                    //旋钮2
                    case KEY_EN_2:
						check_key_lock(1);
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_VOL_OUTPUT);
                        break;

                    //旋钮3
                    case KEY_EN_3:
//                  GUI_SendKeyMsg(GUI_KEY_ENTER, 1);  //发送确定按键的信息
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_CONTROL);
                        break;
					
					//松开
					case 0xff:
						WM_SendMessageNoPara(hWin_now, MSG_KEY_RELEASE);
						break;
					
                    default:
                        break;
                }//end of switch(key_value)
				
            }//end of key_value
			else
			{
				key_press++;  //
				if(key_press >= 2000) //当大约XXXms内没有动作
				{
					key_press = 0;
					check_key_lock(0);
					WM_SendMessageNoPara(hWin_now, MSG_KEY_NULL);  
				}
			}
        }
        else //无效则刷RED屏
        {
            GUI_SetBkColor(GUI_RED);
            GUI_Clear();

            GUI_SetColor(GUI_BLACK);
            GUI_GotoXY(0, 0);
            GUI_DispDecMin(GUI_ALLOC_GetNumFreeBytes());
			
			//显示内存使用率
//			p = mymalloc(0,20480); //申请20k
			mem_use = my_mem_perused(SRAMIN);
			GUI_GotoXY(0, 10);
			GUI_DispDecMin(mem_use);
//			myfree(0,p);          //释放内存
        }

        if(count == 1000)
        {
            count = 0;
            LED = ~LED;  //LED反转，用来检测系统是否正常运行
        }
        GUI_Delay(1);
        count++;
}
/*
*********************************************************************************************************
*	函 数 名: _cbTimer
*	功能说明: 定时器回调函数,为了保证实时性	
*	形    参: pTM 消息指针
*	返 回 值: 无
*********************************************************************************************************
*/
void _cbTimer(GUI_TIMER_MESSAGE * pTM)
{
	switch (pTM->Context) 
	{
		case 0x01:
			/* 电阻触摸屏 */
			if(key_lock_flag == 0)
			{
				#if (USE_TOUCH_MODE == 1)
				GUI_TOUCH_Exec();  //调用STemwin自带触摸函数
				#else
				ReadTouch();   //自定义触摸函数
				#endif
			}
			/* 此函数一定要调用，设置重新启动，要不仅执行一次 */
			GUI_TIMER_Restart(pTM->hTimer);
			break;
		
		case 0x02:
	
//			Check_scan();
//			GUI_TIMER_Restart(pTM->hTimer);
			break;		
		
		default:
			break;
	}
}
/*
*******************************************************************************************
* 函 数 名: GPIO_TEST
* 功能说明: 用来测试GUI单个例子
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
void GPIO_TEST(void)
{
	u8 data;
    GUI_Init();
    /* 调用测试函数 */
	GUI_SetBkColor(GUI_WHITE);
	GUI_SetColor(GUI_BLACK);
    GUI_Clear();
//	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
//	GUI_FillCircle(120, 64, 40);
//	GUI_SetDrawMode(GUI_DRAWMODE_XOR);
//	GUI_FillCircle(140, 84, 40);
	AT24CXX_WriteOneByte(1500,0xd0);
	data = AT24CXX_ReadOneByte(1500);
	
	GUI_GotoXY(20,20);
	GUI_DispHex(data,2);
    while (1)
    {
        GUI_Delay(10);
    }

}

/*
*******************************************************************************************
* 函 数 名: All_Init
* 功能说明: 配置外设
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
void All_Init(void)
{
	u8 flat;
	delay_init();
//	delay_ms(3000); //等待单片机供电稳定
	
	/*************************AT32F403***********************************/
	//保证这段操作电源要稳定否则会锁死芯片,如果锁了请百度解锁(￣▽￣)／
	//把SRAM扩展为224k,只适用于AT32系列芯片,要下载两次才能正常运行
	//初次下载：MEM1_MAX_SIZE一定要<(96*1024),以保证程序正确,能正确设置SRAM为224k
	//第二次下载：MEM1_MAX_SIZE可以设置>96k,然后注销掉这段
//	FLASH_Unlock();  //解锁FLASH
//	FLASH_EraseOptionBytes();
//	FLASH_ProgramOptionByteData(0x1FFFF810,0xFF);// 224 KB SRAM 96+128
//	FLASH_Lock();//上锁
	

	/*****************************END*************************************/
	
	
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    LED_GPIO_Init();        //按键LED初始化,全亮
    KEY_GPIO_Init();        //按键初始化
    Encoder_GPIO_Init();    //编码器初始化
    TIM3_Int_Init(999, (SystemCoreClock/1000000-1)); //1KHZ 定时器1ms
	TP_Init();             //触摸屏引脚初始化
	my_mem_init(SRAMIN);    //可以用来使用外部RAM,用到外部SRAM再使用，用SRAM时要对FSMC配置
	IIC_Init();             //用来驱动24c16
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE); //使能CRC时钟，否则STemWin不能使用,此处用emwin所以不用
	flat = g_interface_data();  //申请动态内存
	if(flat == 0)
	{
		while(1);
	}
	RTC_Init();
	
//	MainTask(); //主程序
	
	//初始化通信
	sigma_init();
	default_download_IC_1();	 //Main Program Download 
	delay_ms(1000);
	ak4612_init();
	gain_select();
	
	Lcd_Initialize();       //LCD初始化
	
	
}

/*
*******************************************************************************************
* 函 数 名: main
* 功能说明: 主函数
* 形 参: 无
* 返 回 值: int
*******************************************************************************************
*/



int main(void)
{
	GUI_TIMER_HANDLE hTimer;
    
	
	All_Init();  //所有外设初始化
//	GPIO_TEST();  //测试
	MainTask(); //主程序
	/* 创建定时器，调用触摸检测函数*/
	hTimer = GUI_TIMER_Create(_cbTimer, /* 回调函数 */
							  10,       /* 绝对时间，设置系统上电后10ms作为溢出时间 */
							  0x01,     /* 可以认为此参数是区分不同定时器的ID，方便多个定时使用同一个回调函数 */ 
							  0);       /* 保留，暂时未用到 */
					 
	/* 设置定时器周期为10ms */
	GUI_TIMER_SetPeriod(hTimer, 10);
	
//	hTimer = GUI_TIMER_Create(_cbTimer, /* 回调函数 */
//							  20,       /* 绝对时间，设置系统上电后10ms作为溢出时间 */
//							  0x02,     /* 可以认为此参数是区分不同定时器的ID，方便多个定时使用同一个回调函数 */ 
//							  0);       /* 保留，暂时未用到 */
//	
//	GUI_TIMER_SetPeriod(hTimer, 20);
    while(1)
    {
        //扫描检测
		Check_scan();
		
    }

}




