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

//const GUI_POINT aPoints[] =
//{
//    { 40, 20},
//    { 0, 20},
//    { 20, 0}
//};
///* ���ڴ洢�Ŵ�������� */
//GUI_POINT aEnlargedPoints[GUI_COUNTOF(aPoints)];
//void Sample(void)
//{
//    int i;
//    /* ���� */
//    GUI_Clear();
//    /* ���û�ͼģʽ */
//	GUI_SetPenSize(1);
//    GUI_SetDrawMode(GUI_DM_XOR);
//    /* ���ƶ���� */
//    GUI_FillPolygon(aPoints, /* ָ��Ҫ��ʾ�����Ķ���� */
//                    GUI_COUNTOF(aPoints), /* ���б���ָ���ĵ����� */
//                    140, /* ԭ��� X λ�� */
//                    110); /* ԭ��� Y λ�� */
//    for (i = 1; i < 10; i++)
//    {
//        GUI_EnlargePolygon(aEnlargedPoints, /* ָ��Ŀ������ */
//                           aPoints, /* ָ��Դ����� */
//                           GUI_COUNTOF(aPoints), /* ���б���ָ���ĵ����� */
//                           i * 5); /* ��չ����εĳ��� �����أ� */
//        /* ���ƷŴ��Ķ���� */
//        GUI_FillPolygon(aEnlargedPoints, GUI_COUNTOF(aPoints), 140, 110);

//    }
//}


//��ǰҳ����
WM_HWIN hWin_now;
/**************************************************************************

*ע�⣺������GPоƬʹ�õ�stm32��flash�����㷨�����������ʹ�û�GD��flash�㷨
*������DB13��DB15Ҫ��ת

***************************************************************************/
u32 a_bkcolor[3]={GUI_RED,GUI_GREEN,GUI_BLUE};

void GPIO_TEST(void)
{
	GUI_PID_STATE TouchState;
  int           xPhys;
  int           yPhys;

  GUI_Init();
  GUI_CURSOR_Show();
  GUI_CURSOR_Select(&GUI_CursorCrossL);
  GUI_SetBkColor(GUI_WHITE);
  GUI_SetColor(GUI_BLACK);
  GUI_Clear();
  GUI_DispString("Measurement of\nA/D converter values");
  while (1) {
    GUI_TOUCH_GetState(&TouchState);  // Get the touch position in pixel
    xPhys = GUI_TOUCH_GetxPhys();     // Get the A/D mesurement result in x
    yPhys = GUI_TOUCH_GetyPhys();     // Get the A/D mesurement result in y
    //
    // Display the measurement result
    //
    GUI_SetColor(GUI_BLUE);
    GUI_DispStringAt("Analog input:\n", 0, 20);
    GUI_GotoY(GUI_GetDispPosY() + 2);
    GUI_DispString("x:");
    GUI_DispDec(xPhys, 4);
    GUI_DispString(", y:");
    GUI_DispDec(yPhys, 4);
    //
    // Display the according position
    //
    GUI_SetColor(GUI_RED);
    GUI_GotoY(GUI_GetDispPosY() + 4);
    GUI_DispString("\nPosition:\n");
    GUI_GotoY(GUI_GetDispPosY() + 2);
    GUI_DispString("x:");
    GUI_DispDec(TouchState.x,4);
    GUI_DispString(", y:");
    GUI_DispDec(TouchState.y,4);
    //
    // Wait a while
    //
    GUI_Delay(100);
  };

}

int main(void)
{
    u8 key_value = 0;
    u8 key_value1 = 0;
    u8 key_value2 = 0;
    u8 key_value3 = 0;
    u16 count = 0;
    GUI_COLOR color;


    delay_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    LED_GPIO_Init();        //����LED��ʼ��,ȫ��
    KEY_GPIO_Init();        //������ʼ��
    Encoder_GPIO_Init();    //��������ʼ��
    Lcd_Initialize();       //LCD��ʼ��
    TIM3_Int_Init(999, 71); //1KHZ ��ʱ��1ms
    my_mem_init(SRAMIN);    //��������ʹ���ⲿRAM



    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC,ENABLE); //ʹ��CRCʱ�ӣ�����STemWin����ʹ��
	TP_Init();
//	GPIO_TEST();  //����

	MainTask(); //������

    while(1)
    {
        if(WM_IsWindow(hWin_now)) //�ж�hWin_now�Ƿ���Ч,Framewin���ڿͻ������
        {

            //��ť���
            //�����⣬������whileѭ��,��Ҫע��������ѭ��
            key_value1 = Encoder_Check_One();   //��ť1���
            key_value2 = Encoder_Check_Two();   //��ť2���
            key_value3 = Encoder_Check_Three(); //��ť3���
            //�˳���һ��ֻ���һ����ť����
            if((key_value1 != Encoder_static) || (key_value2 != Encoder_static)
               || (key_value3 != Encoder_static)) //�ж���
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
                }

            }


            //�������
            key_value = KEY_Scan(0);
            if(key_value)
            {
                switch(key_value)
                {
                    //���밴ť
                    case KEY_INPUT:
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_INPUT);
                        //�Ȱѵ�ȫ��
                        LED_All_Off;
                        Input_led_On; //����
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
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_OUTPUT);
                        break;

                    //ϵͳ��ť
                    case KEY_SYSTEM:
                        LED_All_Off;
                        Sys_led_On; //����
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_SYSTEM);
                        break;

                    //��ť1
                    case KEY_EN_1:
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_INPUT);
                        break;

                    //��ť2
                    case KEY_EN_2:
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_OUTPUT);
                        break;

                    //��ť3
                    case KEY_EN_3:
//                  GUI_SendKeyMsg(GUI_KEY_ENTER, 1);  //����ȷ����������Ϣ
                        WM_SendMessageNoPara(hWin_now, MSG_KEY_CONTROL);
                        break;
                    default:
                        break;
                }

            }
        }
        else   //��Ч��ˢRED��
        {
            GUI_SetBkColor(GUI_RED);
            GUI_Clear();

            GUI_SetColor(GUI_BLACK);
            GUI_GotoXY(0, 0);
            GUI_DispDecMin(GUI_ALLOC_GetNumFreeBytes());
        }

        if(count == 1000)
        {
            count = 0;
            LED = ~LED;  //LED��ת���������ϵͳ�Ƿ���������
        }
        GUI_Delay(1);
        count++;

    }

}
