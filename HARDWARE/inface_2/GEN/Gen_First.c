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
#include "bmp.h"
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
#define ID_BUTTON_4 (GUI_ID_USER + 0x05)
#define ID_BUTTON_5 (GUI_ID_USER + 0x06)
#define ID_BUTTON_6 (GUI_ID_USER + 0x07)
#define ID_TEXT_0 	(GUI_ID_USER + 0x08)
#define ID_TEXT_1 	(GUI_ID_USER + 0x09)
#define ID_BUTTON_7 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_8 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_9 (GUI_ID_USER + 0x0C)
#define ID_BUTTON_10 (GUI_ID_USER + 0x0D)
#define ID_BUTTON_11 (GUI_ID_USER + 0x0E)
#define ID_BUTTON_12 (GUI_ID_USER + 0x0f)
#define ID_BUTTON_13 (GUI_ID_USER + 0x10)
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
char GEN_CHANNEL = 0;
GUI_BITMAP buttonbmp_tab[2];  //关于开关的图
// USER START (Optionally insert additional static data)
// USER END

//Button控件的自定义绘制函数
static int SKIN_button(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo)
{
	WM_HWIN hWin;
	switch (pDrawItemInfo->Cmd)
	{

	//将设置与皮肤相关的属性，如透明度或文本对齐方式
	case WIDGET_ITEM_CREATE:
		break;

	//绘制可选的按钮位图
	case WIDGET_ITEM_DRAW_BITMAP:
		
		break;

	//emWin默认控件绘制函数
	default: return BUTTON_DrawSkinFlex(pDrawItemInfo);

	//将绘制控件的背景
	case WIDGET_ITEM_DRAW_BACKGROUND:
		if (pDrawItemInfo->ItemIndex == BUTTON_SKINFLEX_PI_ENABLED)
		{
			GUI_DrawBitmap(&buttonbmp_tab[0], 0, 0);
		}
		else if (pDrawItemInfo->ItemIndex == BUTTON_SKINFLEX_PI_PRESSED)
		{
			GUI_DrawBitmap(&buttonbmp_tab[1], 0, 0);
		}
		else
		{
			BUTTON_DrawSkinFlex(pDrawItemInfo);
		}
		break;
	case WIDGET_ITEM_DRAW_TEXT:
		return BUTTON_DrawSkinFlex(pDrawItemInfo);
	}

	return 0;
}

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
	
	//创建字符串
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 59, 3, 294, 28, 0, 0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 59, 36, 294, 28, 0, 0, 0 },
	
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 0, 73,  100, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 0, 129, 100, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 0, 185, 100, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 202, 73,  96, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 202, 129, 96, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 202, 185, 96, 50, 0, 0x0, 0 },

	//开关
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_6, 102, 73, 98, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_7, 102, 129, 98, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_8, 102, 185, 98, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_9,  300, 73, 98, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_10, 300, 129, 98, 50, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_11, 300, 185, 98, 50, 0, 0x0, 0 },
	
	//页面切换
	/*页面切换*/
//	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_12, 5, 5, 40, 25, 0, 0x0, 0 },
//	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_13, 375-20, 5, 40, 25, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
//static const GUI_POINT pPoint_left[] = {
//	{ 0, 10 },
//	{ 10, 0 },
//	{ 10, 20 },
//};

//static const GUI_POINT pPoint_right[] = {
//	{ 10+20, 0 },
//	{ 20+20, 10 },
//	{ 10+20, 20 },
//};
// USER START (Optionally insert additional static code)
// USER END
//左边三角形
//#include "BUTTON_Private.h"

//static void _cbButton_left(WM_MESSAGE * pMsg) //--------------（3）
//{
//	WM_HWIN hWin;
//	hWin = pMsg->hWin;
//	switch (pMsg->MsgId)
//	{
//	case WM_PAINT:
//		if (BUTTON_IsPressed(hWin))
//		{
//			//画红色三角形
//			GUI_SetColor(GUI_RED);
//			GUI_FillPolygon(pPoint_left, 3, 0, 0);
//		}
//		else
//		{
//			//画黑色三角形
//			GUI_SetColor(GUI_BLACK);
//			GUI_FillPolygon(pPoint_left, 3, 0, 0);
//		}

//		break;

//		//处理默认信息
//	default:
//		BUTTON_Callback(pMsg);
//	}
//}

////右边三角形
//#define BUTTON_H2P(h) (BUTTON_Obj*) GUI_ALLOC_h2p(h)

//static void _cbButton_right(WM_MESSAGE * pMsg) //--------------（3）
//{
//	WM_HWIN hWin;
//	BUTTON_Obj * pObj; //用来提取出按钮的指针结构体，包含了各种信息

////	const GUI_PID_STATE* pState = (const GUI_PID_STATE*)pMsg->Data.p;
//	hWin = pMsg->hWin;
//	pObj = BUTTON_H2P(hWin);

//	switch (pMsg->MsgId)
//	{
//	case WM_PAINT:
//		if (BUTTON_IsPressed(hWin))
//		{
//			//画红色三角形
//			GUI_SetColor(GUI_RED);
//			GUI_FillPolygon(pPoint_right, 3, 0, 0);
//		}
//		else
//		{
//			//画黑色三角形
//			GUI_SetColor(GUI_BLACK);
//			GUI_FillPolygon(pPoint_right, 3, 0, 0);
//		}

//		//绘制聚焦,如果不接受聚焦则此项不起作用
//		if (pObj->Widget.State & WIDGET_STATE_FOCUS)
//		{
//			GUI_SetColor(GUI_RED);
//			GUI_FillPolygon(pPoint_right, 3, 0, 0);
//		}
//		break;


//		//case WM_TOUCH:
//		//	if (pMsg->Data.p) {  /* Something happened in our area (pressed or released) */
//		//		if (pState->Pressed) {
//		//			RMSTC_Value++;
//		//			WIDGET_OrState(hWin, BUTTON_STATE_PRESSED);
//		//			WM_NotifyParent(hWin, WM_NOTIFICATION_CLICKED);
//		//		}
//		//		else {
//		//			/* React only if button was pressed before ... avoid problems with moving / hiding windows above (such as dropdown) */
//		//
//		//		}
//		//	}
//		//	else {
//		//
//		//	}
//		//	break;
//		//处理默认信息
//	default:
//		BUTTON_Callback(pMsg);
//	}
//}

/*
*******************************************************************************************
* 函 数 名: 进行数据传输
* 功能说明: 对此界面中的一些数据传输给DSP
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
static void tranrfer_data(signed char param)
{
	switch(param)
	{
		case First_Item:
			Data_gen_enable(param,Gen_first->data.WHITE_NOISE_STA);
			break;
		
		case Second_Item:
			Data_gen_enable(param,Gen_first->data.SIN_STA);
			break;
		
		case Third_Item:
			Data_gen_enable(param,Gen_first->data.SQUARE_STA);
			break;
		
		case Four_Item:
			Data_gen_enable(param,Gen_first->data.SWEEPFREQ_STA);
			break;
		
		case Five_Item:
			Data_gen_enable(param,Gen_first->data.PULSE_STA);
			break;
		
		case Six_Item:
			Data_gen_enable(param,Gen_first->data.PINK_NOISE_STA);
			break;

	}
	
	Gen_first->change_item = -1; //重新判断
}

/*
*******************************************************************************************
* 函 数 名: Show_Value
* 功能说明: 传输数值
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
static void Show_Value(void)
{
	//判断更改项，然后进行数据传输
	tranrfer_data(Gen_first->change_item);
}
/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	u8		*buttonS;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//TEXT设置
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem,"GEN_OUT PAGE"); //显示字符串数据
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
	
		//NOISEGATE
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "GEN_OUT_ENABLE");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetText(hItem, "WHITE_NOISE");
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetText(hItem, "SIN");
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetText(hItem, "SQUARE");
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetText(hItem, "SWEEPFREQ");
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		BUTTON_SetText(hItem, "PULSE");
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		BUTTON_SetText(hItem, "PINK_NOISE");
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);

		//开关
		//WHITE_NOISE
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
		BUTTON_SetText(hItem, "");
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		BUTTON_SetSkin(hItem, SKIN_button);
		BUTTON_SetPressed(hItem, Gen_first->data.WHITE_NOISE_STA);
		
		//SIN
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
		BUTTON_SetText(hItem, "");
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		BUTTON_SetSkin(hItem, SKIN_button);
		BUTTON_SetPressed(hItem, Gen_first->data.SIN_STA);
		
		//SQUARE
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
		BUTTON_SetText(hItem, "");
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		BUTTON_SetSkin(hItem, SKIN_button);
		BUTTON_SetPressed(hItem, Gen_first->data.SQUARE_STA);
		
		//SWEEPFREQ
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
		BUTTON_SetText(hItem, "");
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		BUTTON_SetSkin(hItem, SKIN_button);
		BUTTON_SetPressed(hItem, Gen_first->data.SWEEPFREQ_STA);
		
		//PULSE
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
		BUTTON_SetText(hItem, "");
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		BUTTON_SetSkin(hItem, SKIN_button);
		BUTTON_SetPressed(hItem, Gen_first->data.PULSE_STA);
		
		//PINK_NOISE
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
		BUTTON_SetText(hItem, "");
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		BUTTON_SetSkin(hItem, SKIN_button);
		BUTTON_SetPressed(hItem, Gen_first->data.PINK_NOISE_STA);
		
		/*页面切换*/
//		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_12);
//		WM_SetCallback(hItem, _cbButton_left);
//		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

//		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_13);
//		WM_SetCallback(hItem, _cbButton_right);
//		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
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
						hWin_now = CreateMainface();  //显示主界面页面
						break;
			}
			break;
			
		case ID_BUTTON_0: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id));
				Gen_first->Item = First_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
				hWin_now = Gen_Second();  //页面
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_1: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id));
				Gen_first->Item = Second_Item;
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				GEN_CHANNEL = 0;
				GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
				hWin_now = Gen_Four();  //页面
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_2: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id));
				Gen_first->Item = Third_Item;
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				GEN_CHANNEL = 1;
				GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
				hWin_now = Gen_Four();  //页面
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_3: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id));
				Gen_first->Item = Four_Item;
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
				hWin_now = Gen_Third();  //页面
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_4: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id));
				Gen_first->Item = Five_Item;
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
				hWin_now = Gen_Five();  //页面
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_5: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id));
				Gen_first->Item = Six_Item;
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
				hWin_now = Gen_Second();  //页面
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			
		//WHITE_NOISE
		case ID_BUTTON_6: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
			case WM_NOTIFICATION_MOVED_OUT:
				Gen_first->change_item = First_Item;
				Gen_first->data.WHITE_NOISE_STA = (Gen_first->data.WHITE_NOISE_STA==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, Id), Gen_first->data.WHITE_NOISE_STA);
				break;

				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		
		//SIN
		case ID_BUTTON_7: // Notifications sent by 'Button'
			buttonS = &(Gen_first->data.SIN_STA);
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
			case WM_NOTIFICATION_MOVED_OUT:
				Gen_first->change_item = Second_Item;
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, Id), *buttonS);
				break;

				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		
		//SQUARE
		case ID_BUTTON_8: // Notifications sent by 'Button'
			buttonS = &(Gen_first->data.SQUARE_STA);
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
			case WM_NOTIFICATION_MOVED_OUT:
				Gen_first->change_item = Third_Item;
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, Id), *buttonS);
				break;

				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			
		//SWEEPFREQ
		case ID_BUTTON_9: // Notifications sent by 'Button'
			buttonS = &(Gen_first->data.SWEEPFREQ_STA);
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
			case WM_NOTIFICATION_MOVED_OUT:
				Gen_first->change_item = Four_Item;
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, Id), *buttonS);
				break;

				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		
		//PULSE
		case ID_BUTTON_10: // Notifications sent by 'Button'
			buttonS = &(Gen_first->data.PULSE_STA);
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
			case WM_NOTIFICATION_MOVED_OUT:
				Gen_first->change_item = Five_Item;
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, Id), *buttonS);
				break;

				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		
		//PINK_NOISE
		case ID_BUTTON_11: // Notifications sent by 'Button'
			buttonS = &(Gen_first->data.PINK_NOISE_STA);
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
			case WM_NOTIFICATION_MOVED_OUT:
				Gen_first->change_item = Six_Item;
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, Id), *buttonS);
				break;

				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			// USER START (Optionally insert additional code for further Ids)
			// USER END
		}
		break;
		// USER START (Optionally insert additional message handling)
		// USER END
	//绘制背景
	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();

		//第一项
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30, 4);

		//第二项
		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 400, 68, 4);

		//白色条
		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(102,73,198,121,4);
		GUI_FillRoundedRect(102, 129, 198, 177, 4);
		GUI_FillRoundedRect(102, 185, 198, 233, 4);
		GUI_FillRoundedRect(100+200, 73,  398, 121, 4);
		GUI_FillRoundedRect(100+200, 129, 398, 177, 4);
		GUI_FillRoundedRect(100+200, 185, 398, 233, 4);
	
		//传输各个子选项数值
		Show_Value();
		
		break;
	/*****************************************自定义信息********************************/
	//左转
	case MSG_KNOB_CONTROL_LEFT:
		Item_change(&(Gen_first->Item),First_Item,Six_Item,Next_dir);
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //下一个聚焦点
		break;
	
	//CONTROL 右转
	case MSG_KNOB_CONTROL_RIGHT:
		Item_change(&(Gen_first->Item),First_Item,Six_Item,Last_dir);
		GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1);     //上一个聚焦点
		break;
	
	//CONTROL按下
	case MSG_KEY_CONTROL:
		GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //确定
		break;
	
	//ESC
	case MSG_KEY_ESC:
		GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
		hWin_now = CreateMainface();  //显示Input_First页面
//		input_channel_four = 1;
		break;
	
	//INPUT右转
//	case MSG_KNOB_INPUT_RIGHT:
//	case MSG_KNOB_INPUT_LEFT:
	case MSG_KEY_VOL_INPUT:
		switch(Gen_first->Item)
		{
			case First_Item:
				Gen_first->change_item = Gen_first->Item;
				buttonS = &(Gen_first->data.WHITE_NOISE_STA);
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6), *buttonS);
				break;
			
			case Second_Item:
				Gen_first->change_item = Gen_first->Item;
				buttonS = &(Gen_first->data.SIN_STA);
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7), *buttonS);
				break;
			
			case Third_Item:
				Gen_first->change_item = Gen_first->Item;
				buttonS = &(Gen_first->data.SQUARE_STA);
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8), *buttonS);
				break;
			
			case Four_Item:
				Gen_first->change_item = Gen_first->Item;
				buttonS = &(Gen_first->data.SWEEPFREQ_STA);
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9), *buttonS);
				break;
			
			case Five_Item:
				Gen_first->change_item = Gen_first->Item;
				buttonS = &(Gen_first->data.PULSE_STA);
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10), *buttonS);
				break;
			
			case Six_Item:
				Gen_first->change_item = Gen_first->Item;
				buttonS = &(Gen_first->data.PINK_NOISE_STA);
				*buttonS = (*buttonS==0) ? 1 : 0;
				BUTTON_SetPressed(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11), *buttonS);
				break;
		}
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
//初始化变量
static void Init_data(Gen_First_Data *L)
{
	L->Item				=	First_Item;
	L->change_item		=	-1;  //表示没有更改项
	L->overflow			=	0;
	
}

WM_HWIN Gen_First(void) {
	WM_HWIN hWin;
	buttonbmp_tab[0] = button_off;
	buttonbmp_tab[1] = button_on;
	Button_flex_2();
	
	Init_data(Gen_first);  //初始化变量
	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
