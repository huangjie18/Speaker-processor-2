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
#include "BUTTON_Private.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0 (GUI_ID_USER + 0x01)
#define ID_TEXT_1 (GUI_ID_USER + 0x02)
#define ID_TEXT_2 (GUI_ID_USER + 0x03)
#define ID_TEXT_3 (GUI_ID_USER + 0x04)
#define ID_BUTTON_0 (GUI_ID_USER + 0x05)
#define ID_BUTTON_1 (GUI_ID_USER + 0x06)
#define ID_BUTTON_2 (GUI_ID_USER + 0x07)
#define ID_BUTTON_3 (GUI_ID_USER + 0x08)
#define ID_BUTTON_4 (GUI_ID_USER + 0x09)
#define ID_BUTTON_5 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_6 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_7 (GUI_ID_USER + 0x0C)
#define ID_BUTTON_8 (GUI_ID_USER + 0x0D)
#define ID_BUTTON_9 (GUI_ID_USER + 0x0E)
#define ID_BUTTON_10 (GUI_ID_USER + 0x0F)
#define ID_BUTTON_11 (GUI_ID_USER + 0x10)
#define ID_BUTTON_12 (GUI_ID_USER + 0x11)
#define ID_BUTTON_13 (GUI_ID_USER + 0x12)
#define ID_BUTTON_14 (GUI_ID_USER + 0x13)
#define ID_BUTTON_15 (GUI_ID_USER + 0x14)
#define ID_BUTTON_16 (GUI_ID_USER + 0x15)
#define ID_BUTTON_17 (GUI_ID_USER + 0x16)

#define First_y		34
#define Secend_y	68
#define Thirt_y		102
#define Four_y		136
#define Five_y		170
#define Six_y		204

#define First_x     0
#define Secend_x    104
#define Thirt_x     202
#define Four_x      304
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const GUI_POINT pPoint_left[] = {
	{ 0, 10 },
	{ 10, 0 },
	{ 10, 20 },
};

static const GUI_POINT pPoint_right[] = {
	{ 10, 0 },
	{ 20, 10 },
	{ 10, 20 },
};
// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
	/*创建字符串*/
	//INPUT 2/3
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 109, 3, 194, 28, 0, 0, 0 },
	//INPUT_EQ SETTINGD
	{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 59, 36, 294, 28, 0, 0, 0 },

	/*创建按钮*/
	//ON
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 355, 36, 40, 25, 0, 0x0, 0 },
	//
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 0, Secend_y, 198, 32, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 0, Thirt_y, 198, 32, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 0, Four_y, 198, 32, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 0, Five_y, 198, 32, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 0, Six_y, 198, 32, 0, 0x0, 0 },

	/*增减按钮*/
	//left 
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_6,  208, 73, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_7,  208, 107, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_8,  208, 141, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_9,  208, 174, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_10, 208, 208, 20, 25, 0, 0x0, 0 },

	//right
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_11, 170 + 200, 73, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_12, 170 + 200, 107, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_13, 170 + 200, 141, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_14, 170 + 200, 174, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_15, 170 + 200, 208, 20, 25, 0, 0x0, 0 },

	/*页面切换*/
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_16, 5, 3, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_17, 375, 3, 20, 25, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
//左边三角形
static void _cbButton_left(WM_MESSAGE * pMsg) //--------------（3）
{
	WM_HWIN hWin;
	hWin = pMsg->hWin;
	switch (pMsg->MsgId)
	{
	case WM_PAINT:
		if (BUTTON_IsPressed(hWin))
		{
			//画红色三角形
			GUI_SetColor(GUI_RED);
			GUI_FillPolygon(pPoint_left, 3, 0, 0);
		}
		else
		{
			//画黑色三角形
			GUI_SetColor(GUI_BLACK);
			GUI_FillPolygon(pPoint_left, 3, 0, 0);
		}

		break;

		//处理默认信息
	default:
		BUTTON_Callback(pMsg);
	}
}

//右边三角形
#define BUTTON_H2P(h) (BUTTON_Obj*) GUI_ALLOC_h2p(h)

static void _cbButton_right(WM_MESSAGE * pMsg) //--------------（3）
{
	WM_HWIN hWin;
	BUTTON_Obj * pObj; //用来提取出按钮的指针结构体，包含了各种信息

	const GUI_PID_STATE* pState = (const GUI_PID_STATE*)pMsg->Data.p;
	hWin = pMsg->hWin;
	pObj = BUTTON_H2P(hWin);

	switch (pMsg->MsgId)
	{
	case WM_PAINT:
		if (BUTTON_IsPressed(hWin))
		{
			//画红色三角形
			GUI_SetColor(GUI_RED);
			GUI_FillPolygon(pPoint_right, 3, 0, 0);
		}
		else
		{
			//画黑色三角形
			GUI_SetColor(GUI_BLACK);
			GUI_FillPolygon(pPoint_right, 3, 0, 0);
		}

		//绘制聚焦,如果不接受聚焦则此项不起作用
		if (pObj->Widget.State & WIDGET_STATE_FOCUS)
		{
			GUI_SetColor(GUI_RED);
			GUI_FillPolygon(pPoint_right, 3, 0, 0);
		}
		break;


		//case WM_TOUCH:
		//	if (pMsg->Data.p) {  /* Something happened in our area (pressed or released) */
		//		if (pState->Pressed) {
		//			RMSTC_Value++;
		//			WIDGET_OrState(hWin, BUTTON_STATE_PRESSED);
		//			WM_NotifyParent(hWin, WM_NOTIFICATION_CLICKED);
		//		}
		//		else {
		//			/* React only if button was pressed before ... avoid problems with moving / hiding windows above (such as dropdown) */
		//			
		//		}
		//	}
		//	else {
		//		
		//	}
		//	break;
		//处理默认信息
	default:
		BUTTON_Callback(pMsg);
	}
}
// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	// USER START (Optionally insert additional variables)
	// USER END
	WM_HWIN hItem;
	int		NCode;
	int		Id;

	switch (pMsg->MsgId) {
		// USER START (Optionally insert additional message handling)
		// USER END
	case WM_INIT_DIALOG:
		//TEXT设置
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem, "INPUT PAGE 2/3");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//INPUT_EQ
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "INPUT_EQ  SETTINGS");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//按钮设置
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);  //设置字体
		BUTTON_SetText(hItem, "BAND");          //设置显示的字符串

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);  //设置字体
		BUTTON_SetText(hItem, "FREQ(Hz)");          //设置显示的字符串

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);  //设置字体
		BUTTON_SetText(hItem, "TYPE");          //设置显示的字符串

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);  //设置字体
		BUTTON_SetText(hItem, "GAIN(dB)");          //设置显示的字符串

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);  //设置字体
		BUTTON_SetText(hItem, "Q");          //设置显示的字符串

		/*增减按钮*/
		//left
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		//right
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_12);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_13);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_14);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_15);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		/*页面切换*/
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_16);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_17);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		break;
		

	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();

		//标题项
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30, 4);

		/*EQ项*/
		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 400, 64, 4);

		//白色条
		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(Thirt_x, Secend_y, 396, Secend_y + 30, 4);
		GUI_FillRoundedRect(Thirt_x, Thirt_y, 396, Thirt_y + 30, 4);
		GUI_FillRoundedRect(Thirt_x, Four_y, 396, Four_y + 30, 4);
		GUI_FillRoundedRect(Thirt_x, Five_y, 396, Five_y + 30, 4);
		GUI_FillRoundedRect(Thirt_x, Six_y, 396, Six_y + 30, 4);
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

WM_HWIN Input_Four(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
