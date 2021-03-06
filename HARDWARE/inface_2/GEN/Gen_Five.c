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
#include "algorithm.h"
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
#define ID_CHECKBOX_0 (GUI_ID_USER + 0x04)
#define ID_CHECKBOX_1 (GUI_ID_USER + 0x05)
#define ID_CHECKBOX_2 (GUI_ID_USER + 0x06)
#define ID_CHECKBOX_3 (GUI_ID_USER + 0x07)
#define ID_CHECKBOX_4 (GUI_ID_USER + 0x08)
#define ID_CHECKBOX_5 (GUI_ID_USER + 0x09)
#define ID_CHECKBOX_6 (GUI_ID_USER + 0x0A)
#define ID_CHECKBOX_7 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_3 (GUI_ID_USER + 0x0C)
#define ID_BUTTON_4 (GUI_ID_USER + 0x0D)
#define ID_BUTTON_5 (GUI_ID_USER + 0x0E)
#define ID_BUTTON_6 (GUI_ID_USER + 0x0F)
#define ID_BUTTON_7 (GUI_ID_USER + 0x10)
#define ID_BUTTON_8 (GUI_ID_USER + 0x11)
#define ID_TEXT_0	(GUI_ID_USER + 0x12)
#define ID_TEXT_1	(GUI_ID_USER + 0x13)
#define ID_TEXT_2	(GUI_ID_USER + 0x14)



// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
#define AUX_START_ITEM	Four_Item

static Gen_Five_Data * Current_Data;

static const GUI_POINT pPoint_left[] = {
	{ 0, 10 },
	{ 10, 0 },
	{ 10, 20 },
};

static const GUI_POINT pPoint_right[] = {
	{ 10+20, 0 },
	{ 20+20, 10 },
	{ 10+20, 20 },
};  

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

static void _cbButton_right(WM_MESSAGE * pMsg) //--------------（3）
{
	WM_HWIN hWin;

//	const GUI_PID_STATE* pState = (const GUI_PID_STATE*)pMsg->Data.p;
	hWin = pMsg->hWin;

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

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
#define dec_size 40

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 0, 68, 98, 32, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 202, 68, 98, 32, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 0, 102, 198, 32, 0, 0x0, 0 },
	
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_0, 5, 174, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_1, 107, 174, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_2, 207, 174, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_3, 307, 174, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_4, 5, 208, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_5, 107, 208, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_6, 207, 208, 90, 23, 0, 0x0, 0 },
	{ CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_7, 307, 208, 90, 23, 0, 0x0, 0 },
	
	//增减按钮

	//left
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 104, 73, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 104 + 202, 73, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 208, 107, dec_size, 25, 0, 0x0, 0 },
	//right
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_6, 175 - 20, 73, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_7, 375-20, 73, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_8, 375-20, 107, dec_size, 25, 0, 0x0, 0 },
	
	//TEXT
	//第一标题
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 59, 3, 294, 28, 0, 0, 0 },
	//LIMITER
	{ TEXT_CreateIndirect, "Text", ID_TEXT_1, 59, 36, 294, 28, 0, 0, 0 },
	//AUX_MIXER_GAIN_SW
	{ TEXT_CreateIndirect, "Text", ID_TEXT_2, 59, 136, 294, 28, 0, 0, 0 },
	
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
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
	if(Current_Data->overflow != 0)
	{
		Current_Data->overflow = 0;
		param = -1;
	}
	
	switch(param)
	{
		case First_Item:
			pulse_frequency(PULSE_FREQUENCY_ADDR,Current_Data->data.FREQ_DATA);
			break;
		
		case Second_Item:
			pulse_th(PULSE_DUTY_CYCLE_ADDR,Current_Data->data.DUTY_DATA);
			break;
		
		case Third_Item:
			pulse_gain(PULSE_GAIN_ADDR,(Current_Data->data.GAIN_DATA * 0.04));
			break;
		
		//AUX
		case Four_Item:
			if(Current_Data->data.AUX1_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux1MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux1MixerGainSw_ADDR,0);
			}
			break;
		
		case Five_Item:
			if(Current_Data->data.AUX2_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux2MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux2MixerGainSw_ADDR,0);
			}
			break;
		
		case Six_Item:
			if(Current_Data->data.AUX3_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux3MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux3MixerGainSw_ADDR,0);
			}
			break;
		
		case Seven_Item:
			if(Current_Data->data.AUX4_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux4MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux4MixerGainSw_ADDR,0);
			}
			break;
		
		case Eight_Item:
			if(Current_Data->data.AUX5_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux5MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux5MixerGainSw_ADDR,0);
			}
			break;
		
		case Nine_Item:
			if(Current_Data->data.AUX6_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux6MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux6MixerGainSw_ADDR,0);
			}
			break;
		
		case Ten_Item:
			if(Current_Data->data.AUX7_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux7MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux7MixerGainSw_ADDR,0);
			}
			break;
		
		case Eleven_Item:
			if(Current_Data->data.AUX8_STA == 1)
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux8MixerGainSw_ADDR,1);
			}
			else
			{
				pulse_aux_mixer_gain_sw(PULSE_Aux8MixerGainSw_ADDR,0);
			}
			break;
	}
	
	Current_Data->change_item = -1; //重新判断
}


/*
*******************************************************************************************
* 函 数 名: Show_Value
* 功能说明: 显示数值
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
#define FREQ_DATA_MAX	20000
#define FREQ_DATA_MIN	20
#define GAIN_DATA_MAX	0
#define GAIN_DATA_MIN	-2000
#define DUTY_DATA_MAX	100
#define DUTY_DATA_MIN	0

//定义无效区域
static const GUI_RECT Rect[] = {
	{ 100, 		70, 	200, 	90 },   //FREQ
	{ 300, 		70, 	400, 	90 },   //DUTY
	{ 250, 		104, 	350, 	124 },  //GAIN
};
static void Show_Value(void)
{
	char str[10];
	char over;
	float temp;
	
	GUI_SetColor(GUI_BLACK);
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetFont(&GUI_Font20_1);
	
	//FREQ
	over = Max_Min(&Current_Data->data.FREQ_DATA,FREQ_DATA_MAX,FREQ_DATA_MIN);
	Current_Data->overflow |= (over<<First_Item);
	snprintf(str,sizeof(str) - 1,"%d",Current_Data->data.FREQ_DATA);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,150,75);          //以当前坐标为中心显示字符串

	//DUTY
	over = Max_Min(&Current_Data->data.DUTY_DATA,DUTY_DATA_MAX,DUTY_DATA_MIN);
	Current_Data->overflow |= (over<<Second_Item);
	snprintf(str,sizeof(str) - 1,"%d",Current_Data->data.DUTY_DATA);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,350,75);          //以当前坐标为中心显示字符串
	
	//GAIN
	over = Max_Min(&Current_Data->data.GAIN_DATA,GAIN_DATA_MAX,GAIN_DATA_MIN);
	Current_Data->overflow |= (over<<Third_Item);
	temp = (Current_Data->data.GAIN_DATA * 0.04);
	snprintf(str,sizeof(str) - 1,"%.2f",temp);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,300,109);          //以当前坐标为中心显示字符串
	
	//根据更改项传输数据
	tranrfer_data(Current_Data->change_item);
	
}
// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
#define aux_font  GUI_FONT_13B_1

static void _cbDialog(WM_MESSAGE * pMsg) {
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	u8		*check_sta;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		
		//TEXT设置
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem, "PULSE  SETTINGS");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//LIMITER
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "FREQ_AND_GAIN");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//AUX_MIXER_GAIN_SW
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
		TEXT_SetText(hItem, "AUX_MIXER_GAIN_SW");
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));
		
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		BUTTON_SetText(hItem, "FREQ(Hz)");
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		BUTTON_SetText(hItem, "GAIN(dB)");
		//
		// Initialization of 'Button'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);
		BUTTON_SetText(hItem, "DUTY(%)");
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
		CHECKBOX_SetText(hItem, "AUX_SW_1");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX1_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
		CHECKBOX_SetText(hItem, "AUX_SW_2");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX2_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_2);
		CHECKBOX_SetText(hItem, "AUX_SW_3");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX3_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_3);
		CHECKBOX_SetText(hItem, "AUX_SW_4");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX4_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_4);
		CHECKBOX_SetText(hItem, "AUX_SW_5");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX5_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_5);
		CHECKBOX_SetText(hItem, "AUX_SW_6");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX6_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_6);
		CHECKBOX_SetText(hItem, "AUX_SW_7");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX7_STA);
		//
		// Initialization of 'Checkbox'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_7);
		CHECKBOX_SetText(hItem, "AUX_SW_8");
		CHECKBOX_SetFont(hItem, aux_font);
		CHECKBOX_SetTextColor(hItem, GUI_WHITE);
		CHECKBOX_SetFocusColor(hItem, GUI_WHITE);
		CHECKBOX_SetState(hItem,Current_Data->data.AUX8_STA);
		
		/*重新设计按钮的外观*/
		//NOISEGATE
		//left
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		WM_SetCallback(hItem, _cbButton_left);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
		WM_SetCallback(hItem, _cbButton_right);
		BUTTON_SetFocussable(hItem, 0); //不接受输入焦点
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
		WM_SetCallback(hItem, _cbButton_right);
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
						hWin_now = Gen_First();  //显示Input_First页面
						break;
			}
			break;
			
		case ID_BUTTON_0: // Notifications sent by 'Button'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = First_Item;  //子选项改变
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
				Current_Data->Item = Third_Item;  //子选项改变
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
				Current_Data->Item = Second_Item;  //子选项改变
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_0: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
					
					check_sta = &(Current_Data->data.AUX1_STA);
					if(Current_Data->checkbox_sta & (0x01<<0))
					{
						Current_Data->change_item = AUX_START_ITEM;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<0);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_1: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 1;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX2_STA);
					if(Current_Data->checkbox_sta & (0x01<<1))
					{
						Current_Data->change_item = AUX_START_ITEM + 1;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<1);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_2: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 2;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX3_STA);
					if(Current_Data->checkbox_sta & (0x01<<2))
					{
						Current_Data->change_item = AUX_START_ITEM + 2;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<2);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_3: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 3;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX4_STA);
					if(Current_Data->checkbox_sta & (0x01<<3))
					{
						Current_Data->change_item = AUX_START_ITEM + 3;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<3);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_4: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 4;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX5_STA);
					if(Current_Data->checkbox_sta & (0x01<<4))
					{
						Current_Data->change_item = AUX_START_ITEM + 4;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<4);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_5: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 5;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX6_STA);
					if(Current_Data->checkbox_sta & (0x01<<5))
					{
						Current_Data->change_item = AUX_START_ITEM + 5;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<5);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_6: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 6;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX7_STA);
					if(Current_Data->checkbox_sta & (0x01<<6))
					{
						Current_Data->change_item = AUX_START_ITEM + 6;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<6);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_CHECKBOX_7: // Notifications sent by 'Checkbox'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				WM_SetFocus(WM_GetDialogItem(pMsg->hWin, Id)); //改变聚焦
				Current_Data->Item = AUX_START_ITEM + 7;
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				
					check_sta = &(Current_Data->data.AUX8_STA);
					if(Current_Data->checkbox_sta & (0x01<<7))
					{
						Current_Data->change_item = AUX_START_ITEM + 7;
						*check_sta = (*check_sta == 0) ? 1 : 0; 
					}
					else 
					{
						Current_Data->checkbox_sta |= (0x01<<7);
					}
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			
		//增减按钮
		//left
		case ID_BUTTON_3:
			switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						Current_Data->change_item = First_Item;  //子选项改变
						Time_add_dec(&Current_Data->data.FREQ_DATA,&Rect[First_Item],&Current_Data->hItime,First_Time_left,pMsg);
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Current_Data->Time_count,Current_Data->hItime);
					break;
				}
			break;
				
		case ID_BUTTON_4:
			switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						Current_Data->change_item = Second_Item;  //子选项改变
						Time_add_dec(&Current_Data->data.DUTY_DATA,&Rect[Second_Item],&Current_Data->hItime,Second_Time_left,pMsg);
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Current_Data->Time_count,Current_Data->hItime);
					break;
				}
			break;
				
		case ID_BUTTON_5:
			switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						Current_Data->change_item = Third_Item;  //子选项改变
						Time_add_dec(&Current_Data->data.GAIN_DATA,&Rect[Third_Item],&Current_Data->hItime,Third_Time_left,pMsg);
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Current_Data->Time_count,Current_Data->hItime);
					break;
				}
			break;
				
		//right
				
		case ID_BUTTON_6:
			switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						Current_Data->change_item = First_Item;  //子选项改变
						Time_add_dec(&Current_Data->data.FREQ_DATA,&Rect[First_Item],&Current_Data->hItime,First_Time_right,pMsg);
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
						Time_add_dec(&Current_Data->data.DUTY_DATA,&Rect[Second_Item],&Current_Data->hItime,Second_Time_right,pMsg);
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
						Time_add_dec(&Current_Data->data.GAIN_DATA,&Rect[Third_Item],&Current_Data->hItime,Third_Time_right,pMsg);
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Current_Data->Time_count,Current_Data->hItime);
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
			case First_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_3)))
				{
					Current_Data->change_item = First_Item;
					Time_long_press(pMsg,&Current_Data->data.FREQ_DATA,&Current_Data->Time_count,&Rect[First_Item],Id);
				}
				break;
				
			case Second_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_4)))
				{
					Current_Data->change_item = Second_Item;
					Time_long_press(pMsg,&Current_Data->data.DUTY_DATA,&Current_Data->Time_count,&Rect[Second_Item],Id);
				}
				break;
				
			case Third_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_5)))
				{
					Current_Data->change_item = Third_Item;
					Time_long_press(pMsg,&Current_Data->data.GAIN_DATA,&Current_Data->Time_count,&Rect[Third_Item],Id);
				}
				break;
				
			case First_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_6)))
				{
					Current_Data->change_item = First_Item;
					Time_long_press(pMsg,&Current_Data->data.FREQ_DATA,&Current_Data->Time_count,&Rect[First_Item],Id);
				}
				break;
				
			case Second_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_7)))
				{
					Current_Data->change_item = Second_Item;
					Time_long_press(pMsg,&Current_Data->data.DUTY_DATA,&Current_Data->Time_count,&Rect[Second_Item],Id);
				}
				break;
				
			case Third_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_8)))
				{
					Current_Data->change_item = Third_Item;
					Time_long_press(pMsg,&Current_Data->data.GAIN_DATA,&Current_Data->Time_count,&Rect[Third_Item],Id);
				}
				break;
		}
		break;
	//绘制背景
	case WM_PAINT:
		GUI_SetBkColor(GUI_BLACK);
		GUI_Clear();

		//标题项
		GUI_SetColor(GUI_RED);
		GUI_FillRoundedRect(0, 0, 400, 30, 4);

		//LIMITER
		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 34, 400, 64, 4);

		//AUX_SW
		GUI_FillRoundedRect(0, 136, 400, 166, 4);

		//白色条
		GUI_SetColor(GUI_WHITE);
		GUI_FillRoundedRect(102, 68, 198, 98, 4);
		GUI_FillRoundedRect(304, 68, 396, 98, 4);
		GUI_FillRoundedRect(202, 102, 396, 132, 4);

		//第四项
		GUI_SetColor(GUI_BLUE);
		GUI_FillRoundedRect(0, 170, 98, 200, 4);
		GUI_FillRoundedRect(102, 170, 198, 200, 4);
		GUI_FillRoundedRect(0, 204, 98, 234, 4);
		GUI_FillRoundedRect(102, 204, 198, 234, 4);
		GUI_FillRoundedRect(202, 170, 298, 200, 4);
		GUI_FillRoundedRect(302, 170, 398, 200, 4);
		GUI_FillRoundedRect(202, 204, 298, 234, 4);
		GUI_FillRoundedRect(302, 204, 398, 234, 4);
		
		//显示数据
		Show_Value();
		break;
		
	/*********************************************自定义信息处理**************************************************/
	//旋钮左转
	case MSG_KNOB_CONTROL_LEFT:
		Item_change(&(Current_Data->Item),First_Item,Eleven_Item,Next_dir);
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //下一个聚焦点
		break;
	
	//旋钮右转
	case MSG_KNOB_CONTROL_RIGHT:
		Item_change(&(Current_Data->Item),First_Item,Eleven_Item,Last_dir);
		GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //上一个聚焦
		break;
	
	//CONTROL按下
	case MSG_KEY_CONTROL:
		if(Current_Data->Item > Third_Item) //IN_MUTE_Item和IN_INVERT_Item项
		{
			GUI_SendKeyMsg(GUI_KEY_SPACE,1);
		}
		else
		{
			GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //确定
		}
		break;
	
	//ESC
	case MSG_KEY_ESC:
		GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
		hWin_now = Gen_First();  //显示Input_First页面
		break;
	
	//没有旋钮动作
	case MSG_KNOB_NULL:
		Current_Data->Key_count = 0;
		Current_Data->dir		 = 0;
		break;
	
	//INPUT左转
	case MSG_KNOB_INPUT_LEFT:
		if(Current_Data->dir == 2)
		{
			Current_Data->Key_count = 0;
		}
		Current_Data->dir = 1;
		switch(Current_Data->Item)
		{
			//FREQ
			case First_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(&Current_Data->data.FREQ_DATA,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//DUTY
			case Second_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(&Current_Data->data.DUTY_DATA,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//GAIN
			case Third_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_add(&Current_Data->data.GAIN_DATA,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
		}
		break;
		
	//INPUT右转
	case MSG_KNOB_INPUT_RIGHT:
		if(Current_Data->dir == 1)
		{
			Current_Data->Key_count = 0;
		}
		Current_Data->dir = 2;
		switch(Current_Data->Item)
		{
			//FREQ
			case First_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(&Current_Data->data.FREQ_DATA,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//FREQ
			case Second_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(&Current_Data->data.DUTY_DATA,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
				break;
			
			//GAIN
			case Third_Item:
				Current_Data->change_item = Current_Data->Item;
				Value_Change_dec(&Current_Data->data.GAIN_DATA,&Current_Data->Key_count);
				WM_InvalidateRect(pMsg->hWin,&Rect[Current_Data->Item]); //无效化该区域重新刷新
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
static void Init_data(Gen_Five_Data * L)
{
	L->checkbox_sta		=	0;
	L->Item				=	First_Item;
	L->change_item		=	-1;
	L->Key_count		=	0;
	L->Time_count		=	0;
	
	//复选框状态初始化,初次读取24CXX芯片的数据是0xFF，所以要初始化
	Checkbox_Init(&L->data.AUX1_STA);
	Checkbox_Init(&L->data.AUX2_STA);
	Checkbox_Init(&L->data.AUX3_STA);
	Checkbox_Init(&L->data.AUX4_STA);
	Checkbox_Init(&L->data.AUX5_STA);
	Checkbox_Init(&L->data.AUX6_STA);
	Checkbox_Init(&L->data.AUX7_STA);
	Checkbox_Init(&L->data.AUX8_STA);
}


WM_HWIN Gen_Five(void) {
	WM_HWIN hWin;
	
	Init_data(Gen_five);  //初始化数据
	
	Current_Data = Gen_five;
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
