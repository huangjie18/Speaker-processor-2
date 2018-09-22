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
***********ע������********************
STM32��Ϊ����оƬ
1.��DeviceΪGDF303ʱ���øĶ�������ֱ����,��ΪGDF303
û��FPU��Ԫ;
2.��DeviceΪATF403ʱ,ATF403ӵ��FPU��Ԫ������ʱ�õ�
EMWIN-CM3��û��֧��FPU��Ԫ,�������FPU������Ӳ������,
�ر�FPU��Ԫ������ʹ�á�
�رղ��裺Target -> Floating Poirt Hardware -> Not Used
3.������Ƶ����Ҫ��FSMC���ٶȣ�����emwin������������

4.����ֱ�Ӱ�Device ΪATF403�ĳ���ֱ�����ص�STM32�ϣ��������У�Ҫ��Device
////////////////
4.���ʹ��SRAM-224k��Ҫ����EOPB0 Ϊ 0xfe��ZW���128k�ָ�SRAM,NZW������128k��
��ʱ��ZW�̶�Ϊ128k


5.*ע�⣺�����GPоƬʹ�õ�stm32��flash�����㷨�����������ʹ�û�GD��flash�㷨
*������DB13��DB15Ҫ��ת

6.STM32�ĳ����ø�Device��ֱ�����ص�AT��GD��������������

7.��Ϊ�õ��˲�ͬ�����С������ռ��RO-data�Ƚϴ�
***************************************/

//��ǰҳ����
WM_HWIN hWin_now;

//��ǰҳ������ָ��
void *Inface_data;

//�����鿴�Ƿ��ͷ��ڴ�

u8 FLASH_EXTER = 0; //�����RAM

extern void default_download_IC_1(void);
void adu114(void);
u32 key_press = 0;

void gain_select(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9);						 //PB.5 �����	 

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_12|GPIO_Pin_13;			
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_SetBits(GPIOC,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_12|GPIO_Pin_13);						 //PB.5 �����	 	
				
}

void Check_scan(void)
{
	u8 key_value = 0;
    u8 key_value1 = 0;
    u8 key_value2 = 0;
    u8 key_value3 = 0;
	u8 mem_use = 0;  //�ڴ�ʹ����
    u16 count = 0;
	u32 key_count = 0;
	
	if(WM_IsWindow(hWin_now)) //�ж�hWin_now�Ƿ���Ч,Framewin���ڿͻ������
        {

            /***********************************��ť���************************************/
            //�����⣬������whileѭ��,��Ҫע��������ѭ��
            key_value1 = Encoder_Check_One();   //��ť1���
            key_value2 = Encoder_Check_Two();   //��ť2���
            key_value3 = Encoder_Check_Three(); //��ť3���
            //�˳���һ��ֻ���һ����ť����
            if(((key_value1 != Encoder_static) || (key_value2 != Encoder_static)
               || (key_value3 != Encoder_static))&&(key_lock_flag==0)) //�ж���
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
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_INPUT_LEFT); //������ť���͵���Ϣ
                        //��ֱ��ִ�б��۽����ڵĻص�����
                        //���ù��̣�GUI_SendKeyMsg->WM_SendMessage->�ص�����->����WM_NOTIFY_PARENT
                        //��������

                        break;

                    case Encoder1_right:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_INPUT_RIGHT);
                        break;

                    case Encoder2_left:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_OUT_LEFT); //�����ť
                        break;

                    case Encoder2_right:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_OUT_RIGHT);
                        break;

                    case Encoder3_left:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_CONTROL_LEFT); //control��ť
                        break;
                    case Encoder3_right:
                        WM_SendMessageNoPara(hWin_now, MSG_KNOB_CONTROL_RIGHT);
                        break;

                    default:
                        break;
                }//end of switch(key_value)
				key_count = 0;
            }//end of if
			else  //û����ť����
			{
				key_count++;  
				if(key_count >= 700) //����ԼXXXms��û�ж���
				{
					key_count = 0;
					WM_SendMessageNoPara(hWin_now, MSG_KNOB_NULL);  
				}
			}


            /*********************************�������*********************************/
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
                    //���밴ť
                    case KEY_INPUT:
                        
                        //�Ȱѵ�ȫ��
                        LED_All_Off;
                        Input_led_On; //����
						GUI_EndDialog(hWin_now, 0); //����������
						hWin_now = Input_First(); //��ʾINPUT��һ������
//						WM_SendMessageNoPara(hWin_now, MSG_KEY_INPUT);
                        break;

                    //�˳���ť
                    case KEY_ESC:
                        //�Ȱѵ�ȫ��
                        LED_All_Off;
                        Esc_led_On; //����
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_ESC);
                        break;

                    //�����ť
                    case KEY_OUTPUT:
                        //�Ȱѵ�ȫ��
                        LED_All_Off;
                        Out_led_On; //����
//                        WM_SendMessageNoPara(hWin_now, MSG_KEY_OUTPUT);
						GUI_EndDialog(hWin_now, 0); //����������
						hWin_now = Output_First(); //��ʾOUTPUT�ڶ�������
                        break;

                    //ϵͳ��ť
                    case KEY_SYSTEM:
                        LED_All_Off;
                        Sys_led_On; //����
//                      WM_SendMessageNoPara(hWin_now, MSG_KEY_SYSTEM);
						GUI_EndDialog(hWin_now, 0); //����������
						hWin_now = System_First();
						break;

                    //��ť1
                    case KEY_EN_1:
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_VOL_INPUT);
                        break;

                    //��ť2
                    case KEY_EN_2:
						check_key_lock(1);
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_VOL_OUTPUT);
                        break;

                    //��ť3
                    case KEY_EN_3:
//                  GUI_SendKeyMsg(GUI_KEY_ENTER, 1);  //����ȷ����������Ϣ
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_CONTROL);
                        break;
					
					//�ɿ�
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
				if(key_press >= 2000) //����ԼXXXms��û�ж���
				{
					key_press = 0;
					check_key_lock(0);
					WM_SendMessageNoPara(hWin_now, MSG_KEY_NULL);  
				}
			}
        }
        else //��Ч��ˢRED��
        {
            GUI_SetBkColor(GUI_RED);
            GUI_Clear();

            GUI_SetColor(GUI_BLACK);
            GUI_GotoXY(0, 0);
            GUI_DispDecMin(GUI_ALLOC_GetNumFreeBytes());
			
			//��ʾ�ڴ�ʹ����
//			p = mymalloc(0,20480); //����20k
			mem_use = my_mem_perused(SRAMIN);
			GUI_GotoXY(0, 10);
			GUI_DispDecMin(mem_use);
//			myfree(0,p);          //�ͷ��ڴ�
        }

        if(count == 1000)
        {
            count = 0;
            LED = ~LED;  //LED��ת���������ϵͳ�Ƿ���������
        }
        GUI_Delay(1);
        count++;
}
/*
*********************************************************************************************************
*	�� �� ��: _cbTimer
*	����˵��: ��ʱ���ص�����,Ϊ�˱�֤ʵʱ��	
*	��    ��: pTM ��Ϣָ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void _cbTimer(GUI_TIMER_MESSAGE * pTM)
{
	switch (pTM->Context) 
	{
		case 0x01:
			/* ���败���� */
			if(key_lock_flag == 0)
			{
				#if (USE_TOUCH_MODE == 1)
				GUI_TOUCH_Exec();  //����STemwin�Դ���������
				#else
				ReadTouch();   //�Զ��崥������
				#endif
			}
			/* �˺���һ��Ҫ���ã���������������Ҫ����ִ��һ�� */
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
* �� �� ��: GPIO_TEST
* ����˵��: ��������GUI��������
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/
void GPIO_TEST(void)
{
	u8 data;
    GUI_Init();
    /* ���ò��Ժ��� */
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
* �� �� ��: All_Init
* ����˵��: ��������
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/
void All_Init(void)
{
	u8 flat;
	delay_init();
//	delay_ms(3000); //�ȴ���Ƭ�������ȶ�
	
	/*************************AT32F403***********************************/
	//��֤��β�����ԴҪ�ȶ����������оƬ,���������ٶȽ���(������)��
	//��SRAM��չΪ224k,ֻ������AT32ϵ��оƬ,Ҫ�������β�����������
	//�������أ�MEM1_MAX_SIZEһ��Ҫ<(96*1024),�Ա�֤������ȷ,����ȷ����SRAMΪ224k
	//�ڶ������أ�MEM1_MAX_SIZE��������>96k,Ȼ��ע�������
//	FLASH_Unlock();  //����FLASH
//	FLASH_EraseOptionBytes();
//	FLASH_ProgramOptionByteData(0x1FFFF810,0xFF);// 224 KB SRAM 96+128
//	FLASH_Lock();//����
	

	/*****************************END*************************************/
	
	
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    LED_GPIO_Init();        //����LED��ʼ��,ȫ��
    KEY_GPIO_Init();        //������ʼ��
    Encoder_GPIO_Init();    //��������ʼ��
    TIM3_Int_Init(999, (SystemCoreClock/1000000-1)); //1KHZ ��ʱ��1ms
	TP_Init();             //���������ų�ʼ��
	my_mem_init(SRAMIN);    //��������ʹ���ⲿRAM,�õ��ⲿSRAM��ʹ�ã���SRAMʱҪ��FSMC����
	IIC_Init();             //��������24c16
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE); //ʹ��CRCʱ�ӣ�����STemWin����ʹ��,�˴���emwin���Բ���
	flat = g_interface_data();  //���붯̬�ڴ�
	if(flat == 0)
	{
		while(1);
	}
	RTC_Init();
	
//	MainTask(); //������
	
	//��ʼ��ͨ��
	sigma_init();
	default_download_IC_1();	 //Main Program Download 
	delay_ms(1000);
	ak4612_init();
	gain_select();
	
	Lcd_Initialize();       //LCD��ʼ��
	
	
}

/*
*******************************************************************************************
* �� �� ��: main
* ����˵��: ������
* �� ��: ��
* �� �� ֵ: int
*******************************************************************************************
*/



int main(void)
{
	GUI_TIMER_HANDLE hTimer;
    
	
	All_Init();  //���������ʼ��
//	GPIO_TEST();  //����
	MainTask(); //������
	/* ������ʱ�������ô�����⺯��*/
	hTimer = GUI_TIMER_Create(_cbTimer, /* �ص����� */
							  10,       /* ����ʱ�䣬����ϵͳ�ϵ��10ms��Ϊ���ʱ�� */
							  0x01,     /* ������Ϊ�˲��������ֲ�ͬ��ʱ����ID����������ʱʹ��ͬһ���ص����� */ 
							  0);       /* ��������ʱδ�õ� */
					 
	/* ���ö�ʱ������Ϊ10ms */
	GUI_TIMER_SetPeriod(hTimer, 10);
	
//	hTimer = GUI_TIMER_Create(_cbTimer, /* �ص����� */
//							  20,       /* ����ʱ�䣬����ϵͳ�ϵ��10ms��Ϊ���ʱ�� */
//							  0x02,     /* ������Ϊ�˲��������ֲ�ͬ��ʱ����ID����������ʱʹ��ͬһ���ص����� */ 
//							  0);       /* ��������ʱδ�õ� */
//	
//	GUI_TIMER_SetPeriod(hTimer, 20);
    while(1)
    {
        //ɨ����
		Check_scan();
		
    }

}




