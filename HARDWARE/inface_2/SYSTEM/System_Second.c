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
//static WM_HWIN    hWinInfo;  //用来记录上一个窗口句柄
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
	
	/*页面切换*/
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
* 函 数 名: Show_Value
* 功能说明: 显示数值
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/

static void Show_Value(void)
{
	char str[10];
	GUI_SetColor(GUI_BLACK); 		//设置颜色
	GUI_SetTextMode(GUI_TM_TRANS);  //设置透明模式
	GUI_SetFont(&GUI_Font24B_1); 	//设置字体
	
	GUI_DispStringHCenterAt("****",CONF_X,CONF_Y);          //以当前坐标为中心显示字符串
	GUI_DispStringHCenterAt("****",CONF_X,CONF_Y+40);          //以当前坐标为中心显示字符串
	
	if(Sys_Second->data.LOCK_KEY_STA == CLOSE)
	{
		GUI_DispStringHCenterAt("USER",CONF_X,CONF_Y+80);          //以当前坐标为中心显示字符串
	}
	else
	{
		GUI_DispStringHCenterAt("ADMIN",CONF_X,CONF_Y+80);          //以当前坐标为中心显示字符串
	}
	
	if(Sys_Second->data.CURRENT == CLOSE)
	{
		GUI_DispStringHCenterAt("OFF",CONF_X,CONF_Y+125);          //以当前坐标为中心显示字符串
	}
	else
	{
		GUI_SetFont(&GUI_Font20B_1); 	//设置字体
		GUI_DispStringHCenterAt("LONG PRESS",CONF_X,CONF_Y+125);          //以当前坐标为中心显示字符串
	}
//	snprintf(str,sizeof(str) - 1,"%d",Sys_Second->data.CURRENT);  //把数值转为字符串
//	GUI_DispStringHCenterAt(str,CONF_X,CONF_Y+125);
	
//	AT24C16_PageWrite((u8 *)(&(Sys_Second->data)),IIC_Addr[48],sizeof(Sys_Second->data)); //写入EEPROM
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

		//TEXT设置
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
		
		/*页面切换*/
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_18);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_19);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		// USER START (Optionally insert additional code for further widget initialization)
		// USER END
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
			
		//点击主标题  退出
		case ID_TEXT_0:
			switch(NCode)
			{
				case WM_NOTIFICATION_RELEASED:
						GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
						hWin_now = CreateMainface();  //显示Input_First页面
						break;
			}
			break;
			
		case ID_BUTTON_0: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
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
						Get_Sys_Second(Sys_Second);  //用来传递数据
						Sys_Second->hWinInfo = CreatePIN();
						WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //把窗口加到该父窗口中
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
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Sys_Second->Item = 1;
				break;
			case WM_NOTIFICATION_RELEASED:
				Sys_Second->Item = 1;
				if(!WM_IsWindow(Sys_Second->hWinInfo))
				{
					Get_Sys_Second(Sys_Second);  //用来传递数据
					Sys_Second->hWinInfo = CreatePIN();
					WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //把窗口加到该父窗口中
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
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
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
						Get_Sys_Second(Sys_Second);  //用来传递数据
						Sys_Second->hWinInfo = CreatePIN();
						WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //把窗口加到该父窗口中
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
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
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
						Get_Sys_Second(Sys_Second);  //用来传递数据
						Sys_Second->hWinInfo = CreatePIN();
						WM_AttachWindowAt(Sys_Second->hWinInfo, pMsg->hWin, 0, 0); //把窗口加到该父窗口中
						
					}
				}
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			
		//页面切换
		case ID_BUTTON_18:
			switch (NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:

					break;

				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
					hWin_now = System_First();      //切换下一个界面
					break;
			}
			break;
		
		case ID_BUTTON_19:
			switch (NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:

					break;

				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
					hWin_now = System_First();      //切换下一个界面
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

		//标题项
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30, 4);

		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 400, 64, 4);

		//白色条
		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(202, 68, 396, 106, 4);
		GUI_FillRoundedRect(202, 110, 396, 148, 4);
		GUI_FillRoundedRect(202, 153, 396, 191, 4);
		GUI_FillRoundedRect(202, 196, 396, 234, 4);
		
		Show_Value();
		break;
	/*********************************************自定义信息处理**************************************************/
	//旋钮左转
	case MSG_KNOB_CONTROL_LEFT:
		if(WM_IsWindow(Sys_Second->hWinInfo))
		{

		}
		else
		{
			Item_change(&(Sys_Second->Item),0,3,Next_dir);
		}
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //下一个聚焦点
		break;
	
	//旋钮右转
	case MSG_KNOB_CONTROL_RIGHT:
		if(WM_IsWindow(Sys_Second->hWinInfo))
		{

		}
		else
		{
			Item_change(&(Sys_Second->Item),0,3,Last_dir);
		}
		GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //上一个聚焦
		break;
	
	//CONTROL按下
	case MSG_KEY_CONTROL:
		if(Sys_Second->Item != 3)
		{
			GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //确定
		}
		else
		{
			key_restore = 1;
			GUI_SendKeyMsg(GUI_KEY_SPACE,1);   //按下
		}
		break;
	
		
	//松开
	case MSG_KEY_RELEASE:
		if(Sys_Second->Item != 3 ||(key_restore == 0))
		{

		}
		else
		{
			key_restore = 0;
			GUI_SendKeyMsg(GUI_KEY_SPACE,0);   //按下
		}
		break;
		
	//ESC
	case MSG_KEY_ESC:
//		GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
//        hWin_now = CreateMainface();  //显示Input_First页面
//		GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //退出
		if(WM_IsWindow(Sys_Second->hWinInfo))
		{
			GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //退出	
//			GUI_EndDialog(Sys_Second->hWinInfo, 0); //关闭窗口
		}
		else
		{
			GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
			hWin_now = CreateMainface();  //显示主界面
		}
		break;
	
	//页面切换
	case MSG_KNOB_OUT_LEFT:	
		GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
		hWin_now = System_First();      //切换下一个界面
		break;
	
	case MSG_KNOB_OUT_RIGHT:
		GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
		hWin_now = System_First();      //切换上一个界面
		break;
	
	case MSG_PIN_UNLOCK:
		Sys_Second->_Lock_sta = Success;
		break;
	
	case MSG_PIN_NEW:
		Sys_Second->data._Old_PIN = Return_PIN();
		Sys_Second->_Lock_sta = Fail; //表示操作要重新输入密码
		WM_InvalidateWindow(pMsg->hWin);
		break;
	
	//释放内存
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
	
	if(L->data._Old_PIN > 0x270f) //当密码大于9999，代表要初始化密码
	{
		L->data._Old_PIN = 0;  //这里代表初始化密码
//		AT24C16_PageWrite((u8 *)(&(L->data)),IIC_Addr[48],sizeof(L->data)); //写入EEPROM
	}
	
	//初始化LOCK_KEY状态
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
	
	//申请动态内存
	//先判断是否释放动态内存

	Init_data(Sys_Second); //初始化数据
	
	
	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/


