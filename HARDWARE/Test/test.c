/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2014  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.26 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : CURSOR_Sample.c
Purpose     : demonstrates the use of cursors
Requirements: WindowManager - ( )
              MemoryDevices - ( )
              AntiAliasing  - ( )
              VNC-Server    - ( )
              PNG-Library   - ( )
              TrueTypeFonts - ( )
----------------------------------------------------------------------
*/
#include "test.h"
#include "example.h"
#include "GUI.h"
#include "DIALOG.h"
#include "WM.h"
#include "BUTTON.h"
#include "CHECKBOX.h"
#include "DROPDOWN.h"
#include "EDIT.h"
#include "FRAMEWIN.h"
#include "LISTBOX.h"
#include "MULTIEDIT.h"
#include "RADIO.h"
#include "SLIDER.h"
#include "TEXT.h"
#include "PROGBAR.h"
#include "SCROLLBAR.h"
#include "LISTVIEW.h"
#include "GRAPH.h"
#include "MENU.h"
#include "MULTIPAGE.h"
#include "ICONVIEW.h"
#include "TREEVIEW.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "Interface.h"
#include "key.h"
#include "malloc.h"
#include "touch.h"


WM_HWIN test_2(void);
/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.26                          *
*        Compiled Aug  8 2014, 14:49:54                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

//默认皮肤设置
static void FLEX_SET(void)
{
	//设置皮肤
//	Button_flex();   //按钮皮肤设置
//	Framewin_flex(); //用了自定义
	SLIDER_SetDefaultSkin(_DrawSkin_SLIDER1);//滑块皮肤设置
	Listbox_flex(); //列表框皮肤设置
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
BUTTON_SKINFLEX_PROPS Props_Default; //按钮初始颜色

u8 te[5] = {1,2,3,4,5};
u8 te_r[5] = {0};

void MainTask(void)
{
	u8 key_value;
    WM_SetCreateFlags(WM_CF_MEMDEV);  //开启存储设备，要消耗内存RAM 
	GUI_Init();                    //emwin初始化
	WM_SetDesktopColor(GUI_BLACK); //背景色
	GUI_Delay(1); //为什么要加这个呢，先让背景无效化一次刷新，然后就可以在背景上绘制图画
	FLEX_SET(); //皮肤设置
	
#if (USE_TOUCH_MODE	== 0)
	Init_touch_adj();  //触摸校准
#else
#endif
	BUTTON_GetSkinFlexProps(&Props_Default, BUTTON_SKINFLEX_PI_ENABLED); //按钮初始状态颜色
	hWin_now = CreateMainface(); //创建主界面
//  Pratice();  //练习用
//  example();  //例子用
//	touch_main();
//	while(1)
//	{
//		GUI_Delay(10);
//	}
//	key_value = AT24C16_PageRead(te_r,0,sizeof(te_r));
//	if(key_value)
//	{
//		GUI_SetBkColor(GUI_RED);
//        GUI_Clear();
//	}
//	else
//	{
//		GUI_SetBkColor(GUI_GREEN);
//        GUI_Clear();
//	}
//	
//	GUI_SetColor(GUI_BLACK);
//    GUI_GotoXY(0, 0);
//    GUI_DispDecMin(te_r[4]);
//	while(1);

}

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
#include "GUI.h"
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
#define ID_TEXT_4 (GUI_ID_USER + 0x08)
#define ID_TEXT_5 (GUI_ID_USER + 0x09)
#define ID_BUTTON_3 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_4 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_5 (GUI_ID_USER + 0x0C)
#define ID_EDIT_0 (GUI_ID_USER + 0x0D)
#define ID_SPINBOX_0 (GUI_ID_USER + 0x0E)
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
const GUI_POINT pPoint[] = {
	{0,10},
	{10,0},
	{10,20},
};

const GUI_POINT pPoint_1[] = {
	{ 10, 0 },
	{ 20, 10 },
	{ 10, 20 },
};
static const GUI_RECT RMSTC[] = {
	{ 125, 70, 205, 90 },
};
static int RMSTC_Value=0;

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 109, 0, 194, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 0, 36, 194, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 172, 194, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_3, 0, 70, 98, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_4, 0, 104, 98, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_5, 0, 138, 98, 28, 0, 0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 104, 73, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 104, 107, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 104, 141, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 175, 73, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 175, 107, 20, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 175, 141, 20, 25, 0, 0x0, 0 },
	/*{ EDIT_CreateIndirect, "Edit", ID_EDIT_0, 79, 125, 80, 20, 0, 0x64, 0 },*/
	//{ SPINBOX_CreateIndirect, "Spinbox", ID_SPINBOX_0, 104, 70, 92, 28, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
//左边三角形
static void _cbButton(WM_MESSAGE * pMsg) //--------------（3）
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
			GUI_FillPolygon(pPoint, 3, 0, 0);
		}
		else
		{ 
			//画黑色三角形
			GUI_SetColor(GUI_BLACK);
			GUI_FillPolygon(pPoint, 3, 0, 0);
		}
		
		break;

	//处理默认信息
	default:
		BUTTON_Callback(pMsg);
	}
}

//右边三角形
#define BUTTON_H2P(h) (BUTTON_Obj*) GUI_ALLOC_h2p(h)

static void _cbButton_1(WM_MESSAGE * pMsg) //--------------（3）
{
	WM_HWIN hWin;
	const GUI_PID_STATE* pState = (const GUI_PID_STATE*)pMsg->Data.p;

	hWin = pMsg->hWin;
	switch (pMsg->MsgId)
	{
	case WM_PAINT:
		if (BUTTON_IsPressed(hWin))
		{
			//画红色三角形
			GUI_SetColor(GUI_RED);
			GUI_FillPolygon(pPoint_1, 3, 0, 0);
		}
		else
		{
			//画黑色三角形
			GUI_SetColor(GUI_BLACK);
			GUI_FillPolygon(pPoint_1, 3, 0, 0);
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
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	static WM_HTIMER hItime;  //定时器句柄
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Text'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem, "INPUT PAGE 1/3");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "NOISEGATE");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
		TEXT_SetText(hItem, "COMPRESSOR");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
		TEXT_SetText(hItem, "RMSTC");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_20B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
		TEXT_SetText(hItem, "HOLD");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_20B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
		TEXT_SetText(hItem, "DECAY");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_20B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//按钮回调函数
		//左
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		WM_SetCallback(hItem, _cbButton);
		//BUTTON_SetFocussable(hItem,0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		WM_SetCallback(hItem, _cbButton);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		WM_SetCallback(hItem, _cbButton);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		//右
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		WM_SetCallback(hItem, _cbButton_1);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		WM_SetCallback(hItem, _cbButton_1);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		WM_SetCallback(hItem, _cbButton_1);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		

		//选值框
		hItem = WM_GetDialogItem(pMsg->hWin, ID_SPINBOX_0);
		SPINBOX_SetEdge(hItem, SPINBOX_EDGE_CENTER);
		SPINBOX_SetRange(hItem,1,10000);
		SPINBOX_SetFont(hItem, GUI_FONT_16_1);


		break;
		

	/*定时器消息*/
	case WM_TIMER:
		if (BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3))) //判断按钮是否还在按下
		{
			RMSTC_Value = RMSTC_Value + 100;
			WM_InvalidateRect(pMsg->hWin, RMSTC); //无效化该区域重新刷新
			WM_RestartTimer(pMsg->Data.v, 200); // 重启定时器
			
		}
		else
		{
			WM_DeleteTimer(pMsg->Data.v);    //删除该定时器
		}
		
		
		break;

	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_BUTTON_3:
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				RMSTC_Value++;
				WM_InvalidateRect(pMsg->hWin, RMSTC);
				hItime = WM_CreateTimer(pMsg->hWin, 0, 200, 0); //创建一个定时器
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				
				// USER END
				break;
			}
			break;
		}

		break;

	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();

		//左边第一项
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30,4);

		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 198, 64, 4);
		GUI_FillRoundedRect(0, 68, 98, 98, 4);
		GUI_FillRoundedRect(0, 102, 98, 132, 4);
		GUI_FillRoundedRect(0, 136, 98, 166, 4);

		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(102, 68, 198, 98, 4);
		GUI_FillRoundedRect(102, 102, 198, 132, 4);
		GUI_FillRoundedRect(102, 136, 198, 166, 4);

		//右边第二项
		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(202, 34, 298, 64, 4);
		GUI_FillRoundedRect(202, 68, 298, 98, 4);
		GUI_FillRoundedRect(202, 102, 298, 132, 4);
		GUI_FillRoundedRect(202, 136, 298, 166, 4);
		GUI_FillRoundedRect(202, 170, 298, 200, 4);

		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(302, 34, 398, 64, 4);
		GUI_FillRoundedRect(302, 68, 398, 98, 4);
		GUI_FillRoundedRect(302, 102, 398, 132, 4);
		GUI_FillRoundedRect(302, 136, 398, 166, 4);
		GUI_FillRoundedRect(302, 170, 398, 200, 4);
	    
		//第三项
		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 170, 198, 200, 4);
		GUI_FillRoundedRect(0, 204, 98, 234, 4);

		GUI_SetColor(GUI_WHITE);

		GUI_FillRoundedRect(102, 204, 198, 234, 4);

		//画线
		//GUI_SetColor(GUI_WHITE);
		//GUI_DrawVLine(200, 30, 240);
		//GUI_DrawVLine(100, 63, 240);
		//GUI_DrawVLine(300, 63, 240);


		//显示值
		GUI_SetColor(GUI_BLACK); //设置颜色
		GUI_SetTextMode(GUI_TM_TRANS); //设置透明模式
		GUI_SetFont(&GUI_Font20_1); //设置字体
		GUI_GotoXY(125, 75);  //设置1位置
		GUI_DispDecMin(RMSTC_Value); //显示值

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
WM_HWIN test_2(void);
WM_HWIN test_2(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/







