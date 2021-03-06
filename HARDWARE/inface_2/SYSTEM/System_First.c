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
#define ID_BUTTON_0 (GUI_ID_USER + 0x07)
#define ID_BUTTON_1 (GUI_ID_USER + 0x08)
#define ID_BUTTON_2 (GUI_ID_USER + 0x09)
#define ID_BUTTON_3 (GUI_ID_USER + 0x0A)
#define ID_BUTTON_4 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_5 (GUI_ID_USER + 0x0C)

#define ID_TEXT_0	(GUI_ID_USER + 0x0D)
#define ID_TEXT_1	(GUI_ID_USER + 0x0E)
#define ID_TEXT_2	(GUI_ID_USER + 0x0F)
#define ID_TEXT_3	(GUI_ID_USER + 0x10)

#define ID_BUTTON_6 (GUI_ID_USER + 0x11)
#define ID_BUTTON_7 (GUI_ID_USER + 0x12)
#define ID_BUTTON_8 (GUI_ID_USER + 0x13)
#define ID_BUTTON_9  (GUI_ID_USER + 0x14)
#define ID_BUTTON_10 (GUI_ID_USER + 0x15)
#define ID_BUTTON_11 (GUI_ID_USER + 0x16)
#define ID_BUTTON_12  (GUI_ID_USER + 0x17)
#define ID_BUTTON_13 (GUI_ID_USER + 0x18)
#define ID_BUTTON_14 (GUI_ID_USER + 0x19)
#define ID_BUTTON_15  (GUI_ID_USER + 0x1A)
#define ID_BUTTON_16 (GUI_ID_USER + 0x1B)
#define ID_BUTTON_17 (GUI_ID_USER + 0x1C)
#define ID_BUTTON_18 (GUI_ID_USER + 0x1D)
#define ID_BUTTON_19 (GUI_ID_USER + 0x1E)
// USER START (Optionally insert additional defines)
// USER END
#define dec_size	40
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


static Current USE_Data;  //需要的使用数据
// USER START (Optionally insert additional static data)
// USER END
static System_First_Data * Current_Data;
/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 0, 104, 98, 42, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 0, 150, 98, 42, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 0, 196, 98, 42, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 202, 104, 98, 42, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 202, 150, 98, 42, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 202, 196, 98, 42, 0, 0x0, 0 },
	
	//INPUT 2/3
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 109, 3, 194, 28, 0, 0, 0 },
	//INPUT_EQ SETTINGD
	{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 59, 36, 294, 28, 0, 0, 0 },
	//LOW PASS
	{ TEXT_CreateIndirect, "Text", ID_TEXT_2, 0, 70, 194, 28, 0, 0, 0 },
	//HIGH PASS
	{ TEXT_CreateIndirect, "Text", ID_TEXT_3, 204, 70, 194, 28, 0, 0, 0 },
	
	//增减按钮
	/*START VOL*/
	//left
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_6, 104, 114, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_7, 104, 160, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_8, 104, 206, dec_size, 25, 0, 0x0, 0 },
	
	//right
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_9,  175-20, 114, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_10, 175-20, 160, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_11, 175-20, 206, dec_size, 25, 0, 0x0, 0 },
	
	/*MAX VOL*/
	//left
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_12, 104+203, 114, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_13, 104+203, 160, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_14, 104+203, 206, dec_size, 25, 0, 0x0, 0 },
	
	//right
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_15,  175+180, 114, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_16,  175+180, 160, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_17,  175+180, 206, dec_size, 25, 0, 0x0, 0 },
	
	/*页面切换*/
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_18, 5, 5, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_19, 375-20, 5, dec_size, 25, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
const GUI_POINT g_pPoint_left[] = {
	{ 0, 10 },
	{ 10, 0 },
	{ 10, 20 },
};

const GUI_POINT g_pPoint_right[] = {
	{ 10+20, 0 },
	{ 20+20, 10 },
	{ 10+20, 20 },
};

//定义无效区域
static const GUI_RECT Rect[] = {
	{ 100, 		114, 	200, 	144 }, 
	{ 100, 		160, 	200, 	190 },
	{ 100, 		206, 	200, 	236 },
	{ 300, 		114, 	400, 	144 }, 
	{ 300, 		160, 	400, 	190 },
	{ 300, 		206, 	400, 	236 },
};
//左边三角形
void g_cbButton_left(WM_MESSAGE * pMsg) //--------------（3）
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
			GUI_FillPolygon(g_pPoint_left, 3, 0, 0);
		}
		else
		{
			//画黑色三角形
			GUI_SetColor(GUI_BLACK);
			GUI_FillPolygon(g_pPoint_left, 3, 0, 0);
		}

		break;

		//处理默认信息
	default:
		BUTTON_Callback(pMsg);
	}
}

#include "BUTTON_Private.h"
//右边三角形
#define BUTTON_H2P(h) (BUTTON_Obj*) GUI_ALLOC_h2p(h)

void g_cbButton_right(WM_MESSAGE * pMsg) //--------------（3）
{
	WM_HWIN hWin;
	BUTTON_Obj * pObj; //用来提取出按钮的指针结构体，包含了各种信息

	//	const GUI_PID_STATE* pState = (const GUI_PID_STATE*)pMsg->Data.p;
	hWin = pMsg->hWin;
	pObj = BUTTON_H2P(hWin);

	switch (pMsg->MsgId)
	{
	case WM_PAINT:
		if (BUTTON_IsPressed(hWin))
		{
			//画红色三角形
			GUI_SetColor(GUI_RED);
			GUI_FillPolygon(g_pPoint_right, 3, 0, 0);
		}
		else
		{
			//画黑色三角形
			GUI_SetColor(GUI_BLACK);
			GUI_FillPolygon(g_pPoint_right, 3, 0, 0);
		}

		//绘制聚焦,如果不接受聚焦则此项不起作用
		if (pObj->Widget.State & WIDGET_STATE_FOCUS)
		{
			GUI_SetColor(GUI_RED);
			GUI_FillPolygon(g_pPoint_right, 3, 0, 0);
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
/*
*******************************************************************************************
* 函 数 名: Show_Value
* 功能说明: 显示数值
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
#define STR_MAX	 	100
#define STR_MIN		0
#define END_MAX		100
#define END_MIN		0
#include "string.h"

static void Show_Value(void)
{
	char str[10];
	char over;
	
	GUI_SetColor(GUI_BLACK);
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetFont(&GUI_Font20_1);
	
	//MIC_STR
	over = Max_Min(USE_Data.First_data,STR_MAX,STR_MIN);
	Current_Data->overflow |= (over<<First_Item);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.First_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,150,117);
	
	//MUS_STR
	over = Max_Min(USE_Data.Second_data,STR_MAX,STR_MIN);
	Current_Data->overflow |= (over<<Second_Item);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.Second_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,150,163);
	//EFF_STR
	over = Max_Min(USE_Data.Third_data,STR_MAX,STR_MIN);
	Current_Data->overflow |= (over<<Third_Item);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.Third_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,150,209);
	
	//MIC_END
	over = Max_Min(USE_Data.Four_data,STR_MAX,STR_MIN);
	Current_Data->overflow |= (over<<Four_Item);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.Four_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,350,117);
	
	//MUS_END
	over = Max_Min(USE_Data.Five_data,STR_MAX,STR_MIN);
	Current_Data->overflow |= (over<<Five_Item);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.Five_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,350,163);
	
	//EFF_END
	over = Max_Min(USE_Data.Six_data,STR_MAX,STR_MIN);
	Current_Data->overflow |= (over<<Six_Item);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.Six_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,350,209);
	
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetText(hItem, "MIC");
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetText(hItem, "MUS");
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		BUTTON_SetText(hItem, "EFF");
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetText(hItem, "MIC");
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		BUTTON_SetText(hItem, "MUS");
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		BUTTON_SetText(hItem, "EFF");
		BUTTON_SetFont(hItem, GUI_FONT_20B_1);
		
		
		//TEXT设置
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem, "SYS PAGE 1/2");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//INPUT_EQ
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "VOLUME  CONTROL");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//LOW PASS
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
		TEXT_SetText(hItem, "START VOL");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//HIGH PASS
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
		TEXT_SetText(hItem, "MAX VOL");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
		
		/*增减按钮*/
		//left
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		//right
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		//left
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_12);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_13);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_14);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		//right
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_15);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_16);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点

		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_17);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		/*页面切换*/
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_18);
		WM_SetCallback(hItem, g_cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_19);
		WM_SetCallback(hItem, g_cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
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
						hWin_now = CreateMainface();  //页面
						break;
			}
			break;
			
		case ID_BUTTON_0: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = First_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
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
				Current_Data->Item = Second_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
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
				Current_Data->Item = Third_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
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
				Current_Data->Item = Four_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_4: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = Five_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_5: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = Six_Item;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			
		//left
		case ID_BUTTON_6:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = First_Item;  //子选项改变
					Time_add_dec(USE_Data.First_data,&Rect[First_Item],&Current_Data->hItime,First_Time_left,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_7:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Second_Item;  //子选项改变
					Time_add_dec(USE_Data.Second_data,&Rect[Second_Item],&Current_Data->hItime,Second_Time_left,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_8:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Third_Item;  //子选项改变
					Time_add_dec(USE_Data.Third_data,&Rect[Third_Item],&Current_Data->hItime,Third_Time_left,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		//right
		case ID_BUTTON_9:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = First_Item;  //子选项改变
					Time_add_dec(USE_Data.First_data,&Rect[First_Item],&Current_Data->hItime,First_Time_right,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_10:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Second_Item;  //子选项改变
					Time_add_dec(USE_Data.Second_data,&Rect[Second_Item],&Current_Data->hItime,Second_Time_right,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_11:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Third_Item;  //子选项改变
					Time_add_dec(USE_Data.Third_data ,&Rect[Third_Item],&Current_Data->hItime,Third_Time_right,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
		
		//MAX VOL
		case ID_BUTTON_12:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Four_Item;  //子选项改变
					Time_add_dec(USE_Data.Four_data ,&Rect[Four_Item],&Current_Data->hItime,Four_Time_left,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_13:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Five_Item;  //子选项改变
					Time_add_dec(USE_Data.Five_data ,&Rect[Five_Item],&Current_Data->hItime,Five_Time_left,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_14:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Six_Item;  //子选项改变
					Time_add_dec(USE_Data.Six_data ,&Rect[Six_Item],&Current_Data->hItime,Six_Time_left,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_15:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Four_Item;  //子选项改变
					Time_add_dec(USE_Data.Four_data ,&Rect[Four_Item],&Current_Data->hItime,Four_Time_right,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_16:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Five_Item;  //子选项改变
					Time_add_dec(USE_Data.Five_data ,&Rect[Five_Item],&Current_Data->hItime,Five_Time_right,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
			}
			break;
			
		case ID_BUTTON_17:
			switch(NCode)
			{
				//已点击按钮
				case WM_NOTIFICATION_CLICKED:
					Current_Data->change_item = Six_Item;  //子选项改变
					Time_add_dec(USE_Data.Six_data ,&Rect[Six_Item],&Current_Data->hItime,Six_Time_right,pMsg);
				break;
				
				//已释放按钮
				case WM_NOTIFICATION_RELEASED:
					Time_end(&Current_Data->Time_count,Current_Data->hItime);
				break;
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
					hWin_now = System_Second();      //切换下一个界面
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
					hWin_now = System_Second();      //切换下一个界面
					break;
			}
			break;
			// USER START (Optionally insert additional code for further Ids)
			// USER END
		}
		break;
		// USER START (Optionally insert additional message handling)
		// USER END
	/********************************定时器**********************************/
	case WM_TIMER:
		Id = WM_GetTimerId(pMsg->Data.v);
		switch(Id)  //根据不同定时器的ID号来处理不同的信息
		{
			//STR VOL
			case First_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_6)))
				{
					Current_Data->change_item = First_Item;
					Time_long_press(pMsg,USE_Data.First_data,&Current_Data->Time_count,&Rect[First_Item],Id);
				}
				break;
				
			case Second_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_7)))
				{
					Current_Data->change_item = Second_Item;
					Time_long_press(pMsg,USE_Data.Second_data,&Current_Data->Time_count,&Rect[Second_Item],Id);
				}
				break;
				
			case Third_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_8)))
				{
					Current_Data->change_item = Third_Item;
					Time_long_press(pMsg,USE_Data.Third_data,&Current_Data->Time_count,&Rect[Third_Item],Id);
				}
				break;
				
			case First_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_9)))
				{
					Current_Data->change_item = First_Item;
					Time_long_press(pMsg,USE_Data.First_data,&Current_Data->Time_count,&Rect[First_Item],Id);
				}
				break;
				
			case Second_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_10)))
				{
					Current_Data->change_item = Second_Item;
					Time_long_press(pMsg,USE_Data.Second_data,&Current_Data->Time_count,&Rect[Second_Item],Id);
				}
				break;
				
			case Third_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_11)))
				{
					Current_Data->change_item = Third_Item;
					Time_long_press(pMsg,USE_Data.Third_data,&Current_Data->Time_count,&Rect[Third_Item],Id);
				}
				break;
			
			//END VOL
			case Four_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_12)))
				{
					Current_Data->change_item = Four_Item;
					Time_long_press(pMsg,USE_Data.Four_data,&Current_Data->Time_count,&Rect[Four_Item],Id);
				}
				break; 
				
			case Five_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_13)))
				{
					Current_Data->change_item = Five_Item;
					Time_long_press(pMsg,USE_Data.Five_data,&Current_Data->Time_count,&Rect[Five_Item],Id);
				}
				break; 
				
			case Six_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_14)))
				{
					Current_Data->change_item = Six_Item;
					Time_long_press(pMsg,USE_Data.Six_data,&Current_Data->Time_count,&Rect[Six_Item],Id);
				}
				break; 
				
			case Four_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_15)))
				{
					Current_Data->change_item = Four_Item;
					Time_long_press(pMsg,USE_Data.Four_data,&Current_Data->Time_count,&Rect[Four_Item],Id);
				}
				break; 
				
			case Five_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_16)))
				{
					Current_Data->change_item = Five_Item;
					Time_long_press(pMsg,USE_Data.Five_data,&Current_Data->Time_count,&Rect[Five_Item],Id);
				}
				break; 
				
			case Six_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_17)))
				{
					Current_Data->change_item = Six_Item;
					Time_long_press(pMsg,USE_Data.Six_data,&Current_Data->Time_count,&Rect[Six_Item],Id);
				}
				break; 
		}
		break;
	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();

		//标题项
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30, 4);

		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 400, 64, 4);
		//LOW PASS
		GUI_FillRoundedRect(0, 68, 198, 100, 4);
		//HIGHT PASS
		GUI_FillRoundedRect(202, 68, 398, 100, 4);

		//白色条
		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(102, 104, 198, 144, 4);
		GUI_FillRoundedRect(102, 150, 198, 190, 4);
		GUI_FillRoundedRect(102, 196, 198, 236, 4);

		GUI_FillRoundedRect(304, 104, 396, 144, 4);
		GUI_FillRoundedRect(304, 150, 396, 190, 4);
		GUI_FillRoundedRect(304, 196, 396, 236, 4);
		
		//显示数据
		Show_Value();
		break;
	/*********************************************自定义信息处理**************************************************/
	//旋钮左转
	case MSG_KNOB_CONTROL_LEFT:
		Item_change(&(Current_Data->Item),First_Item,Six_Item,Next_dir);
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //下一个聚焦点
		break;
	
	//旋钮右转
	case MSG_KNOB_CONTROL_RIGHT:
		Item_change(&(Current_Data->Item),First_Item,Six_Item,Last_dir);
		GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //上一个聚焦
		break;
	
	//ESC
	case MSG_KEY_ESC:
		GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
        hWin_now = CreateMainface();  //显示Input_First页面
		break;
	
	//没有旋钮动作
	case MSG_KNOB_NULL:
		Current_Data->Key_count = 0;
		Current_Data->dir		 = 0;
		break;
	
	//INPUT右转
	case MSG_KNOB_INPUT_RIGHT:
		if(Current_Data->dir	== 1)
		{
			Current_Data->Key_count = 0;
		}
		Current_Data->dir = 2;
		switch(Current_Data->Item)
		{
			//LOAD MODE
			case First_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(USE_Data.First_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//SAVE MODE
			case Second_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(USE_Data.Second_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//INIT MODE
			case Third_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(USE_Data.Third_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//LOAD MODE
			case Four_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(USE_Data.Four_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//LOAD MODE
			case Five_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(USE_Data.Five_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//LOAD MODE
			case Six_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(USE_Data.Six_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
		}
		break;
	
	//INPUT左转
	case MSG_KNOB_INPUT_LEFT:
		if(Current_Data->dir	== 2)
		{
			Current_Data->Key_count = 0;
		}
		Current_Data->dir = 1;
		switch(Current_Data->Item)
		{
			//LOAD MODE
			case First_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(USE_Data.First_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//SAVE MODE
			case Second_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(USE_Data.Second_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//INIT MODE
			case Third_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(USE_Data.Third_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//LOAD MODE
			case Four_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(USE_Data.Four_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//LOAD MODE
			case Five_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(USE_Data.Five_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//LOAD MODE
			case Six_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(USE_Data.Six_data,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
		}
		break;
		
	//页面切换
	case MSG_KNOB_OUT_LEFT:	
		GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
		hWin_now = System_Second();      //切换下一个界面
		break;
	
	case MSG_KNOB_OUT_RIGHT:
		GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
		hWin_now = System_Second();      //切换上一个界面
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
static void Init_data(System_First_Data *L)
{
	L->Item				=	First_Item;
	L->change_item 		=	-1;
	L->overflow			=	0;
	
	//初始化变量
	USE_Data.First_data 	= 	&System_first->data.MIC_DATA_STR;
	USE_Data.Second_data 	= 	&System_first->data.MUS_DATA_STR;
	USE_Data.Third_data		=	&System_first->data.EFF_DATA_STR;
	USE_Data.Four_data 		= 	&System_first->data.MIC_DATA_END;
	USE_Data.Five_data 		= 	&System_first->data.MUS_DATA_END;
	USE_Data.Six_data 		= 	&System_first->data.EFF_DATA_END;
}


WM_HWIN System_First(void) {
	WM_HWIN hWin;
	
	Button_flex_2();
	
	Init_data(System_first); //初始化变量
	
	Current_Data = System_first;
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
