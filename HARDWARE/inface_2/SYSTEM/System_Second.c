/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "data.h"
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_BUTTON_0 (GUI_ID_USER + 0x01)
#define ID_BUTTON_1 (GUI_ID_USER + 0x02)
#define ID_BUTTON_2 (GUI_ID_USER + 0x03)
#define ID_BUTTON_3 (GUI_ID_USER + 0x04)

#define ID_TEXT_0	(GUI_ID_USER + 0x05)
#define ID_TEXT_1	(GUI_ID_USER + 0x06)
#define ID_BUTTON_18 (GUI_ID_USER + 0x07)
#define ID_BUTTON_19 (GUI_ID_USER + 0x08)

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static u8 key_restore = 0; //
//static WM_HWIN    hWinInfo;  //������¼��һ�����ھ��
//static WM_HWIN    _hLastFrame;


/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 0, 68, 198, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 0, 110, 198, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 0, 153, 198, 40, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 0, 196, 198, 40, 0, 0x0, 0 },

	//TEXT
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 109, 3, 194, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 59, 36, 294, 28, 0, 0, 0 },
	
	/*ҳ���л�*/
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_18, 5, 5, 40, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_19, 375-20, 5, 40, 25, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
#include "stdio.h"
#define CONF_X   300
#define CONF_Y   80
/*
*******************************************************************************************
* �� �� ��: Show_Value
* ����˵��: ��ʾ��ֵ
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/

static void Show_Value(void)
{
	char str[10];
	GUI_SetColor(GUI_BLACK); 		//������ɫ
	GUI_SetTextMode(GUI_TM_TRANS);  //����͸��ģʽ
	GUI_SetFont(&GUI_Font24B_1); 	//��������
	
	GUI_DispStringHCenterAt("****",CONF_X,CONF_Y);          //�Ե�ǰ����Ϊ������ʾ�ַ���
	GUI_DispStringHCenterAt("****",CONF_X,CONF_Y+40);          //�Ե�ǰ����Ϊ������ʾ�ַ���
	
	if(Sys_Second->data.LOCK_KEY_STA == CLOSE)
	{
		GUI_DispStringHCenterAt("USER",CONF_X,CONF_Y+80);          //�Ե�ǰ����Ϊ������ʾ�ַ���
	}
	else
	{
		GUI_DispStringHCenterAt("ADMIN",CONF_X,CONF_Y+80);          //�Ե�ǰ����Ϊ������ʾ�ַ���
	}
	
	if(Sys_Second->data.CURRENT == CLOSE)
	{
		GUI_DispStringHCenterAt("OFF",CONF_X,CONF_Y+125);          //�Ե�ǰ����Ϊ������ʾ�ַ���
	}
	else
	{
		GUI_SetFont(&GUI_Font20B_1); 	//��������
		GUI_DispStringHCenterAt("LONG PRESS",CONF_X,CONF_Y+125);          //�Ե�ǰ����Ϊ������ʾ�ַ���
	}
//	snprintf(str,sizeof(str) - 1,"%d",Sys_Second->data.CURRENT);  //����ֵתΪ�ַ���
//	GUI_DispStringHCenterAt(str,CONF_X,CONF_Y+125);
	
//	AT24C16_PageWrite((u8 *)(&(Sys_Second->data)),IIC_Addr[48],sizeof(Sys_Second->data)); //д��EEPROM
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	GUI_RECT r;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		BUTTON_SetText(hItem, "CONF IRM PSW");
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		BUTTON_SetText(hItem, "NEWPSW");
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		BUTTON_SetText(hItem, "USER  MODE");
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		BUTTON_SetText(hItem, "RESTORE");

		//TEXT����
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem, "SYS PAGE 2/2");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//INPUT_EQ
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "SYSTEM  PASSWORD");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
		
		/*ҳ���л�*/
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_18);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //���������뽹��
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_19);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //���������뽹��
		// USER START (Optionally insert additional code for further widget initialization)
		// USER END
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
			
		//���������  �˳�
		case ID_TEXT_0:
			switch(NCode)
			{
				case WM_NOTIFICATION_RELEASED:
						GUI_EndDialog(pMsg->hWin, 0); //�رյ�ǰ����
						hWin_now = CreateMainface();  //��ʾInput_Firstҳ��
						break;
			}
			break;
			
		case ID_BUTTON_0: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //�ı�۽�
				Sys_Second->Item = 0;
				break;
			case WM_NOTIFICATION_RELEASED:
				Sys_Second->Item = 0;
				if(Sys_Second->_Lock_sta == Success)
				{
					
				}
				else
				{
					if(!WM_IsWindow(Sys_Second->hWinInfo))
					{
						Get_Sys_Second(Sys_Second);  //������������
						Sys_Second->hWinInfo = CreatePIN();
						WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //�Ѵ��ڼӵ��ø�������
					}
				}
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //�ı�۽�
				Sys_Second->Item = 1;
				break;
			case WM_NOTIFICATION_RELEASED:
				Sys_Second->Item = 1;
				if(!WM_IsWindow(Sys_Second->hWinInfo))
				{
					Get_Sys_Second(Sys_Second);  //������������
					Sys_Second->hWinInfo = CreatePIN();
					WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //�Ѵ��ڼӵ��ø�������
				}
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_2: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //�ı�۽�
				Sys_Second->Item = 2;
				break;
			case WM_NOTIFICATION_RELEASED:
				Sys_Second->Item = 2;
				if(Sys_Second->_Lock_sta == Success)
				{
					if(Sys_Second->data.LOCK_KEY_STA == CLOSE)
					{
						Sys_Second->data.LOCK_KEY_STA = OPEN;
					}
					else
					{
						Sys_Second->data.LOCK_KEY_STA = CLOSE;
					}
					WM_GetWindowRectEx(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2),&r);
					r.x0 += 200;
					r.x1 += 200;
					WM_InvalidateArea(&r);
				}
				else
				{
					if(!WM_IsWindow(Sys_Second->hWinInfo))
					{
						Get_Sys_Second(Sys_Second);  //������������
						Sys_Second->hWinInfo = CreatePIN();
						WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //�Ѵ��ڼӵ��ø�������
					}
				}
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_3: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //�ı�۽�
				Sys_Second->Item = 3;
				break;
			case WM_NOTIFICATION_RELEASED:
				Sys_Second->Item = 3;
				if(Sys_Second->_Lock_sta == Success)
				{
					if(Sys_Second->data.CURRENT == CLOSE)
					{
						Sys_Second->data.CURRENT = OPEN;
					}
					else
					{
						Sys_Second->data.CURRENT = CLOSE;
					}
					WM_GetWindowRectEx(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3),&r);
					r.x0 += 200;
					r.x1 += 200;
					WM_InvalidateArea(&r);
				}
				else
				{
					if(!WM_IsWindow(Sys_Second->hWinInfo))
					{
						Get_Sys_Second(Sys_Second);  //������������
						Sys_Second->hWinInfo = CreatePIN();
						WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //�Ѵ��ڼӵ��ø�������
						
					}
				}
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			
		//ҳ���л�
		case ID_BUTTON_18:
			switch (NCode)
			{
				//�ѵ����ť
				case WM_NOTIFICATION_CLICKED:

					break;

				//���ͷŰ�ť
				case WM_NOTIFICATION_RELEASED:
					GUI_EndDialog(pMsg->hWin, 0);   //������ǰ����
					hWin_now = System_First();      //�л���һ������
					break;
			}
			break;
		
		case ID_BUTTON_19:
			switch (NCode)
			{
				//�ѵ����ť
				case WM_NOTIFICATION_CLICKED:

					break;

				//���ͷŰ�ť
				case WM_NOTIFICATION_RELEASED:
					GUI_EndDialog(pMsg->hWin, 0);   //������ǰ����
					hWin_now = System_First();      //�л���һ������
					break;
			}
			break;
			// USER START (Optionally insert additional code for further Ids)
			// USER END
		}
		break;
		// USER START (Optionally insert additional message handling)
		// USER END

	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();

		//������
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30, 4);

		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 400, 64, 4);

		//��ɫ��
		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(202, 68, 396, 106, 4);
		GUI_FillRoundedRect(202, 110, 396, 148, 4);
		GUI_FillRoundedRect(202, 153, 396, 191, 4);
		GUI_FillRoundedRect(202, 196, 396, 234, 4);
		
		Show_Value();
		break;
	/*********************************************�Զ�����Ϣ����**************************************************/
	//��ť��ת
	case MSG_KNOB_CONTROL_LEFT:
		if(WM_IsWindow(Sys_Second->hWinInfo))
		{

		}
		else
		{
			Item_change(&(Sys_Second->Item),0,3,Next_dir);
		}
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //��һ���۽���
		break;
	
	//��ť��ת
	case MSG_KNOB_CONTROL_RIGHT:
		if(WM_IsWindow(Sys_Second->hWinInfo))
		{

		}
		else
		{
			Item_change(&(Sys_Second->Item),0,3,Last_dir);
		}
		GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //��һ���۽�
		break;
	
	//CONTROL����
	case MSG_KEY_CONTROL:
		if(Sys_Second->Item != 3)
		{
			GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //ȷ��
		}
		else
		{
			key_restore = 1;
			GUI_SendKeyMsg(GUI_KEY_SPACE,1);   //����
		}
		break;
	
		
	//�ɿ�
	case MSG_KEY_RELEASE:
		if(Sys_Second->Item != 3 ||(key_restore == 0))
		{

		}
		else
		{
			key_restore = 0;
			GUI_SendKeyMsg(GUI_KEY_SPACE,0);   //����
		}
		break;
		
	//ESC
	case MSG_KEY_ESC:
//		GUI_EndDialog(pMsg->hWin, 0); //�رյ�ǰ����
//        hWin_now = CreateMainface();  //��ʾInput_Firstҳ��
//		GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //�˳�
		if(WM_IsWindow(Sys_Second->hWinInfo))
		{
			GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //�˳�	
//			GUI_EndDialog(Sys_Second->hWinInfo, 0); //�رմ���
		}
		else
		{
			GUI_EndDialog(pMsg->hWin, 0); //�رյ�ǰ����
			hWin_now = CreateMainface();  //��ʾ������
		}
		break;
	
	//ҳ���л�
	case MSG_KNOB_OUT_LEFT:	
		GUI_EndDialog(pMsg->hWin, 0);   //������ǰ����
		hWin_now = System_First();      //�л���һ������
		break;
	
	case MSG_KNOB_OUT_RIGHT:
		GUI_EndDialog(pMsg->hWin, 0);   //������ǰ����
		hWin_now = System_First();      //�л���һ������
		break;
	
	case MSG_PIN_UNLOCK:
		Sys_Second->_Lock_sta = Success;
		break;
	
	case MSG_PIN_NEW:
		Sys_Second->data._Old_PIN = Return_PIN();
		Sys_Second->_Lock_sta = Fail; //��ʾ����Ҫ������������
		WM_InvalidateWindow(pMsg->hWin);
		break;
	
	//�ͷ��ڴ�
	case WM_DELETE:
//		myfree(0,Sys_Second);
		break;
	
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
static void Init_data(System_Second_Data *L)
{
	L->_PIN_Digits = 0;
	L->_PIN_Value  = 0;
	L->hWinInfo    = 0;
	L->_Lock_sta   = 0; 
	L->Item 	   = 0;

//	AT24C16_PageRead((u8 *)(&(L->data)),IIC_Addr[48],sizeof(L->data));
	
	if(L->data._Old_PIN > 0x270f) //���������9999������Ҫ��ʼ������
	{
		L->data._Old_PIN = 0;  //���������ʼ������
//		AT24C16_PageWrite((u8 *)(&(L->data)),IIC_Addr[48],sizeof(L->data)); //д��EEPROM
	}
	
	//��ʼ��LOCK_KEY״̬
	if((L->data.LOCK_KEY_STA != CLOSE)&&(L->data.LOCK_KEY_STA != OPEN))
	{
		L->data.LOCK_KEY_STA = CLOSE;
	}
	
	if((L->data.CURRENT != CLOSE)&&(L->data.CURRENT != OPEN))
	{
		L->data.CURRENT = CLOSE;
	}

}

WM_HWIN System_Second(void) {
	WM_HWIN hWin;
	

	Button_flex_2();
	
	//���붯̬�ڴ�
	//���ж��Ƿ��ͷŶ�̬�ڴ�

	Init_data(Sys_Second); //��ʼ������
	
	
	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/

