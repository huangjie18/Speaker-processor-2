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
#include "data.h"
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

#define    dec_size 	40
static WM_HWIN hButton;
// USER START (Optionally insert additional defines)
// USER END
static Current USE_Data;
/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
//static Output_Four_data *Out_Four[OUTPUT_CHANNEL];
static Output_Four_data * Current_Out_four;  //指示当前界面数据结构
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

//页面显示的字符串数据
static char face_string[][20] = 
{
//	"NULL",
	"OUTPUT1 PAGE 3/3",
	"OUTPUT2 PAGE 3/3",
	"OUTPUT3 PAGE 3/3",
	"OUTPUT4 PAGE 3/3",
	"OUTPUT5 PAGE 3/3",
	"OUTPUT6 PAGE 3/3",
	"OUTPUT7 PAGE 3/3",
	"OUTPUT8 PAGE 3/3",

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
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_6, 208, 73, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_7, 208, 107, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_8, 208, 141, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_9, 208, 174, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_10, 208, 208, dec_size, 25, 0, 0x0, 0 },

	//right
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_11, 170 + 180, 73, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_12, 170 + 180, 107, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_13, 170 + 180, 141, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_14, 170 + 180, 174, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_15, 170 + 180, 208, dec_size, 25, 0, 0x0, 0 },

	/*页面切换*/
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_16, 5, 5, dec_size, 25, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Button", ID_BUTTON_17, 375-20, 5, dec_size, 25, 0, 0x0, 0 },
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
/*
*******************************************************************************************
* 函 数 名: Use_data_choose
* 功能说明: 改变段的数据
* 形 参: 段值
* 返 回 值: 无
*******************************************************************************************
*/
static void Use_data_choose(s16 band)
{
	band = band;
	switch(band)
	{
		case 1:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_1;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_1;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_1;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_1;
			break;
		
		case 2:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_2;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_2;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_2;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_2;
			break;
		
		case 3:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_3;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_3;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_3;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_3;
			break;
		
		case 4:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_4;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_4;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_4;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_4;
			break;
		
		case 5:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_5;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_5;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_5;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_5;
			break;
		
		case 6:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_6;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_6;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_6;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_6;
			break;
		
		case 7:
			USE_Data.First_data  = &Current_Out_four->data.FREQ_DATA_7;
			USE_Data.Second_data = &Current_Out_four->data.TYPE_DATA_7;
			USE_Data.Third_data  = &Current_Out_four->data.GAIN_DATA_7;
			USE_Data.Four_data   = &Current_Out_four->data.Q_DATA_7;
			break;
	}
}
//按钮状态转换
static void Band_Sta(WM_HWIN hItem,s16 band,u8 sta)
{
	u8 i;
	if(band < 1)
	{
		band = 1;
	}
	else if(band > 7)
	{
		band = 7;
	}
	//ON_OFF转换
	if(sta == 1)
	{
		if(Out_Four[OUTPUT_CHANNEL]->data.ON_OFF&(1<<band))
		{
			//清零
			Current_Out_four->data.ON_OFF &= ~(1<<band);
		}
		else
		{
			//置1
			Current_Out_four->data.ON_OFF |= (1<<band);
		}
	}
	
	//按钮的字符串显示
	if ((Out_Four[OUTPUT_CHANNEL]->data.ON_OFF&(1<<band)) == 0)
	{
		BUTTON_SetText(hItem, "ON");          //设置显示的字符串
	}
	else
	{
		BUTTON_SetText(hItem, "OFF");          //设置显示的字符串
	}
	WM_InvalidateWindow(hItem);//无效化该窗口
}
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
	float gain_temp; //gain中间变量
	float q_temp;    //q中间变量
	u8 sta;
	sta = Current_Out_four->data.ON_OFF & (1<<Current_Out_four->data.BAND_DATA);
	
	if(Current_Out_four->overflow != 0)
	{
		Current_Out_four->overflow = 0;
		param = -1;
	}
	
	gain_temp = *USE_Data.Third_data * 0.1;
	q_temp = *USE_Data.Four_data * 0.01;
	
	//根据更改项发送数据
	switch(param)
	{
		case ON_OFF_Four:
		case BAND_Four:
		case FREQ_Four:
		case TYPE_Four:
		case GAIN_Four:
		case Q_Four:
			if(*USE_Data.Second_data == 0)
			{
				Data_input_eq_param(OUTPUT_CHANNEL,Current_Out_four->data.BAND_DATA,
				gain_temp,*USE_Data.First_data,q_temp,0,output_flag,sta);
			}
			else if(*USE_Data.Second_data == 1)
			{
				Data_input_eq_param(OUTPUT_CHANNEL,Current_Out_four->data.BAND_DATA,
				gain_temp,*USE_Data.First_data,q_temp,1,output_flag,sta);
			}
			else if(*USE_Data.Second_data == 2)
			{
				Data_input_eq_param(OUTPUT_CHANNEL,Current_Out_four->data.BAND_DATA,
				gain_temp,*USE_Data.First_data,q_temp,2,output_flag,sta);
			}
		
			break;
	}
	
	
	Current_Out_four->change_item = -1;
	
}
/*
*******************************************************************************************
* 函 数 名: Show_Value
* 功能说明: 显示数值
* 形 参: 无
* 返 回 值: 无
*******************************************************************************************
*/
#include "stdio.h"
#include "string.h"
#define		BAND_X		300
#define 	BAND_Y   	75
#define 	FREQ_Y   	BAND_Y+34
#define  	TYPE_Y		FREQ_Y+34
#define 	GAIN_Y		TYPE_Y+34
#define		Q_Y			GAIN_Y+34


//最大和最小值
#define		BAND_MAX    7
#define		BAND_MIN	1
#define		FREQ_MAX	20000
#define		FREQ_MIN	20
#define		GAIN_MAX	300
#define		GAIN_MIN	-600
#define		Q_MAX		2000
#define		Q_MIN		5
#define		TYPE_MAX	2
#define		TYPE_MIN	0

//定义无效区域
static const GUI_RECT InvaliRect_Value[][4] = {
	{0},
	{ BAND_X-50, BAND_Y, BAND_X+50, Q_Y+20},
	{ BAND_X-50, FREQ_Y, BAND_X+50, FREQ_Y+20},
	{ BAND_X-50, TYPE_Y, BAND_X+50, TYPE_Y+20},
	{ BAND_X-50, GAIN_Y, BAND_X+50, GAIN_Y+20},
	{ BAND_X-50, Q_Y, 	 BAND_X+50, Q_Y+20},
};


static void Show_Value(void)
{
	char str[10];
	char over;  //数据溢出的临时变量
	float temp; //数据的中间变量
	GUI_SetColor(GUI_BLACK); 		//设置颜色
	GUI_SetTextMode(GUI_TM_TRANS);  //设置透明模式
	GUI_SetFont(&GUI_Font20_1); 	//设置字体
	
	//BAND
	over = Max_Min(&Current_Out_four->data.BAND_DATA,BAND_MAX,BAND_MIN);
	Current_Out_four->overflow |= (over<<BAND_Four);
	snprintf(str,sizeof(str) - 1,"%d",Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,BAND_X,BAND_Y);          //以当前坐标为中心显示字符串
	
	
	//FREQ
	over = Max_Min(USE_Data.First_data,FREQ_MAX,FREQ_MIN);
	Current_Out_four->overflow |= (over<<FREQ_Four);
	snprintf(str,sizeof(str) - 1,"%d",*USE_Data.First_data);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,BAND_X,FREQ_Y);
	
	
	
	//GAIN
	over = Max_Min(USE_Data.Third_data,GAIN_MAX,GAIN_MIN);
	Current_Out_four->overflow |= (over<<GAIN_Four);
	temp = *USE_Data.Third_data * 0.1;
	snprintf(str,sizeof(str) - 1,"%.1f",temp);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,BAND_X,GAIN_Y);
	
	//Q
	over = Max_Min(USE_Data.Four_data,Q_MAX,Q_MIN);
	Current_Out_four->overflow |= (over<<Q_Four);
	temp = *USE_Data.Four_data * 0.01;
	snprintf(str,sizeof(str) - 1,"%.2f",temp);  //把数值转为字符串
	GUI_DispStringHCenterAt(str,BAND_X,Q_Y);
	
	
	//TYPE
	over = Max_Min(USE_Data.Second_data,TYPE_MAX,TYPE_MIN);
	Current_Out_four->overflow |= (over<<TYPE_Four);
//	snprintf(str,sizeof(str) - 1,"%d",Out_Four[OUTPUT_CHANNEL]->data.TYPE_DATA);  //把数值转为字符串
	if(*USE_Data.Second_data == 0)
	{
		strcpy(str,"PEQ");
	}
	else if(*USE_Data.Second_data == 1)
	{
		strcpy(str,"HS");
	}
	else if(*USE_Data.Second_data == 2)
	{
		strcpy(str,"LS");
	}
	GUI_DispStringHCenterAt(str,BAND_X,TYPE_Y);
	//AT24C16_PageWrite((u8 *)(&(Out_Four[OUTPUT_CHANNEL]->data)),IIC_Addr[Out_Four[OUTPUT_CHANNEL]->face_switch+38],sizeof(Out_Four[OUTPUT_CHANNEL]->data));
	//判断更改项，然后进行数据传输
	tranrfer_data(Current_Out_four->change_item);
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
		TEXT_SetText(hItem, Out_Four[OUTPUT_CHANNEL]->String);
		TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		TEXT_SetFont(hItem, GUI_FONT_24B_1);
		TEXT_SetTextColor(hItem, GUI_MAKE_COLOR(0x00FFFFFF));

		//INPUT_EQ
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "OUTPUT_EQ  SETTINGS");
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
		
		//ON_OFF
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		hButton = hItem;
		BUTTON_SetFont(hItem, GUI_FONT_16B_1);  //设置字体
//		if ((Out_Four[OUTPUT_CHANNEL]->data.ON_OFF&0x01) == 0)
//		{
//			BUTTON_SetText(hItem, "ON");          //设置显示的字符串
//		}
//		else
//		{
//			BUTTON_SetText(hItem, "OFF");          //设置显示的字符串
//		}
		Band_Sta(hItem,Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,0);
		break;

	//信息处理
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);  //获得是哪个子窗口发生变化
		NCode = pMsg->Data.v;          //子窗口发生什么变化
		switch(Id)
		{
			//点击主标题  退出
			case ID_TEXT_0:
				switch(NCode)
				{
					case WM_NOTIFICATION_RELEASED:
							GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
							hWin_now = Output_First();  //页面
							break;
				}
				break;
				
			//ON_OFF
			case ID_BUTTON_5:
				switch (NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5));
						Out_Four[OUTPUT_CHANNEL]->Item = ON_OFF_Four;
						break;

					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Current_Out_four->change_item = ON_OFF_Four;
//						Out_Four[OUTPUT_CHANNEL]->data.ON_OFF = ~Out_Four[OUTPUT_CHANNEL]->data.ON_OFF;  //切换显示的字符串
//						if ((Out_Four[OUTPUT_CHANNEL]->data.ON_OFF&0x01) == 0)
//						{
//							BUTTON_SetText(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5), "ON");          //设置显示的字符串
//						}
//						else
//						{
//							BUTTON_SetText(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5), "OFF");
//						}
						Band_Sta(hButton,Current_Out_four->data.BAND_DATA,1);
						
						break;
				}
				break;
				
			//子选项
			case ID_BUTTON_0:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0)); //改变聚焦
						Out_Four[OUTPUT_CHANNEL]->Item = BAND_Four;  //子选项改变
						break;
				}
				break; 
				
			case ID_BUTTON_1:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1)); //改变聚焦
						Out_Four[OUTPUT_CHANNEL]->Item = FREQ_Four;  //子选项改变
						break;
				}
				break;
				
			case ID_BUTTON_2:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2)); //改变聚焦
						Out_Four[OUTPUT_CHANNEL]->Item = TYPE_Four;  //子选项改变
						break;
				}
				break;
				
			case ID_BUTTON_3:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3)); //改变聚焦
						Out_Four[OUTPUT_CHANNEL]->Item = GAIN_Four;  //子选项改变
						break;
				}
				break;
				
			case ID_BUTTON_4:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4)); //改变聚焦
						Out_Four[OUTPUT_CHANNEL]->Item = Q_Four;  //子选项改变
						break;
				}
				break;
				
			//增减
			case ID_BUTTON_6:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = BAND_Four;
						Time_add_dec(&Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,InvaliRect_Value[BAND_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,First_Time_left,pMsg);
						Band_Sta(hButton,Current_Out_four->data.BAND_DATA,0);
						Use_data_choose(Current_Out_four->data.BAND_DATA);
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break; 
				
			case ID_BUTTON_7:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = FREQ_Four;
						Time_add_dec(USE_Data.First_data,InvaliRect_Value[FREQ_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Second_Time_left,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_8:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = TYPE_Four;
						Time_add_dec(USE_Data.Second_data,InvaliRect_Value[TYPE_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Third_Time_left,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_9:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = GAIN_Four;
						Time_add_dec(USE_Data.Third_data,InvaliRect_Value[GAIN_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Four_Time_left,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_10:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = Q_Four;
						Time_add_dec(USE_Data.Four_data,InvaliRect_Value[Q_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Five_Time_left,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_11:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = BAND_Four;
						Time_add_dec(&Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,InvaliRect_Value[BAND_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,First_Time_right,pMsg);
						Band_Sta(hButton,Current_Out_four->data.BAND_DATA,0);
						Use_data_choose(Current_Out_four->data.BAND_DATA);
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break; 
				
			case ID_BUTTON_12:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = FREQ_Four;
						Time_add_dec(USE_Data.First_data,InvaliRect_Value[FREQ_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Second_Time_right,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_13:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = TYPE_Four;
						Time_add_dec(USE_Data.Second_data,InvaliRect_Value[TYPE_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Third_Time_right,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_14:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = GAIN_Four;
						Time_add_dec(USE_Data.Third_data,InvaliRect_Value[GAIN_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Four_Time_right,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			case ID_BUTTON_15:
				switch(NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:
						// USER START (Optionally insert code for reacting on notification message)
						Current_Out_four->change_item = Q_Four;
						Time_add_dec(USE_Data.Four_data,InvaliRect_Value[Q_Four],&Out_Four[OUTPUT_CHANNEL]->hItime,Five_Time_right,pMsg);
	
					break;
					
					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						Time_end(&Out_Four[OUTPUT_CHANNEL]->Time_count,Out_Four[OUTPUT_CHANNEL]->hItime);
					break;
				}
				break;
				
			//页面切换
			case ID_BUTTON_16:
				switch (NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:

						break;

					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
						hWin_now = Output_Third();      //切换下一个界面
						break;
				}	
				break;
				
			case ID_BUTTON_17:
				switch (NCode)
				{
					//已点击按钮
					case WM_NOTIFICATION_CLICKED:

						break;

					//已释放按钮
					case WM_NOTIFICATION_RELEASED:
						GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
						hWin_now = Output_Second();      //切换下一个界面
						break;
				}	
				break;
		}
	
		break;
	/*****************************************定时器****************************************/
	case WM_TIMER:
		switch(WM_GetTimerId(pMsg->Data.v))  //根据不同定时器的ID号来处理不同的信息
		{
			case First_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_6)))
				{
					Current_Out_four->change_item = BAND_Four;
					Time_long_press(pMsg,&Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[BAND_Four],First_Time_left);
					Band_Sta(hButton,Current_Out_four->data.BAND_DATA,0);
					Use_data_choose(Current_Out_four->data.BAND_DATA);
				}
				break;
				
			case Second_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_7)))
				{
					Current_Out_four->change_item = FREQ_Four;
					Time_long_press(pMsg,USE_Data.First_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[FREQ_Four],Second_Time_left);
				}
				break;
				
			case Third_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_8)))
				{
					Current_Out_four->change_item = TYPE_Four;
					Time_long_press(pMsg,USE_Data.Second_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[TYPE_Four],Third_Time_left);
				}
				break;
				
			case Four_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_9)))
				{
					Current_Out_four->change_item = GAIN_Four;
					Time_long_press(pMsg,USE_Data.Third_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[GAIN_Four],Four_Time_left);
				}
				break;
				
			case Five_Time_left:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_10)))
				{
					Current_Out_four->change_item = Q_Four;
					Time_long_press(pMsg,USE_Data.Four_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[Q_Four],Five_Time_left);
				}
				break;
				
			case First_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_11)))
				{
					Current_Out_four->change_item = BAND_Four;
					Time_long_press(pMsg,&Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[BAND_Four],First_Time_right);
					Band_Sta(hButton,Current_Out_four->data.BAND_DATA,0);
					Use_data_choose(Current_Out_four->data.BAND_DATA);
				}
				break;
				
			case Second_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_12)))
				{
					Current_Out_four->change_item = FREQ_Four;
					Time_long_press(pMsg,USE_Data.First_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[FREQ_Four],Second_Time_right);
				}
				break;
				
			case Third_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_13)))
				{
					Current_Out_four->change_item = TYPE_Four;
					Time_long_press(pMsg,USE_Data.Second_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[TYPE_Four],Third_Time_right);
				}
				break;
				
			case Four_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_14)))
				{
					Current_Out_four->change_item = GAIN_Four;
					Time_long_press(pMsg,USE_Data.Third_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[GAIN_Four],Four_Time_right);
				}
				break;
				
			case Five_Time_right:
				if(BUTTON_IsPressed(WM_GetDialogItem(pMsg->hWin,ID_BUTTON_15)))
				{
					Current_Out_four->change_item = Q_Four;
					Time_long_press(pMsg,USE_Data.Four_data,&Out_Four[OUTPUT_CHANNEL]->Time_count,InvaliRect_Value[Q_Four],Five_Time_right);
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
	
		//显示数值
		Show_Value();
		break;
	/*********************************************自定义信息处理**************************************************/
	//页面切换
	case MSG_KNOB_OUT_LEFT:	
		GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
		hWin_now = Output_Second();      //切换下一个界面
		break;
	
	case MSG_KNOB_OUT_RIGHT:
		GUI_EndDialog(pMsg->hWin, 0);   //结束当前界面
		hWin_now = Output_Third();      //切换下一个界面
		break;
	
	//ESC
	case MSG_KEY_ESC:
		GUI_EndDialog(pMsg->hWin, 0); //关闭当前窗口
        hWin_now = Output_First();  //显示Output_First页面
//		OUTPUT_CHANNEL = 1;
		break;
	
	
	//CONTROL 左转
	case MSG_KNOB_CONTROL_LEFT:
		//子选项指示
		Item_change(&(Out_Four[OUTPUT_CHANNEL]->Item),ON_OFF_Four,Q_Four,Next_dir);
		GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //下一个聚焦点
		break;
	
	//CONTROL 右转
	case MSG_KNOB_CONTROL_RIGHT:
		//子选项指示
		Item_change(&(Out_Four[OUTPUT_CHANNEL]->Item),ON_OFF_Four,Q_Four,Last_dir);
		GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //上一个聚焦
		break;
	
	//CONTROL按下
	case MSG_KEY_CONTROL:
		GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //确定
		break;
	
	//INPUT右转
	case MSG_KNOB_INPUT_RIGHT:
		if(Current_Out_four->dir == 2)
		{
			Current_Out_four->Key_count = 0;
		}
		Current_Out_four->dir = 1;
		switch(Out_Four[OUTPUT_CHANNEL]->Item)
		{
			//值减少
			case BAND_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_dec(&Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				Band_Sta(hButton,Current_Out_four->data.BAND_DATA,0);
				
				Use_data_choose(Current_Out_four->data.BAND_DATA);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[BAND_Four]); //无效化该区域重新刷新
				break;
			
			case FREQ_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_dec(USE_Data.First_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[FREQ_Four]); //无效化该区域重新刷新
				break;
			
			case TYPE_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_dec(USE_Data.Second_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[TYPE_Four]); //无效化该区域重新刷新
				break;
			
			case GAIN_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_dec(USE_Data.Third_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[GAIN_Four]); //无效化该区域重新刷新
				break;
			
			case Q_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_dec(USE_Data.Four_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[Q_Four]); //无效化该区域重新刷新
				break;
		}
		break;
	
	//INPUT左转
	case MSG_KNOB_INPUT_LEFT:
		if(Current_Out_four->dir == 1)
		{
			Current_Out_four->Key_count = 0;
		}
		Current_Out_four->dir = 2;
		switch(Out_Four[OUTPUT_CHANNEL]->Item)
		{
			//值增加
			case BAND_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_add(&Out_Four[OUTPUT_CHANNEL]->data.BAND_DATA,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				Band_Sta(hButton,Current_Out_four->data.BAND_DATA,0);
				
				Use_data_choose(Current_Out_four->data.BAND_DATA);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[BAND_Four]); //无效化该区域重新刷新
				break;
			
			case FREQ_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_add(USE_Data.First_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[FREQ_Four]); //无效化该区域重新刷新
				break;
			
			case TYPE_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_add(USE_Data.Second_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[TYPE_Four]); //无效化该区域重新刷新
				break;
			
			case GAIN_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_add(USE_Data.Third_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[GAIN_Four]); //无效化该区域重新刷新
				break;
			
			case Q_Four:
				Current_Out_four->change_item = Current_Out_four->Item;
				Value_Change_add(USE_Data.Four_data,&Out_Four[OUTPUT_CHANNEL]->Key_count);
				WM_InvalidateRect(pMsg->hWin, InvaliRect_Value[Q_Four]); //无效化该区域重新刷新
				break;
		}
		break;
	//没有旋钮动作
	case MSG_KNOB_NULL:
		Out_Four[OUTPUT_CHANNEL]->Key_count = 0;
		Current_Out_four->dir 				= 0;
		break;
	
	
	case WM_DELETE:
//		myfree(0,Out_Four[OUTPUT_CHANNEL]);
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

//初始化数据
static void Init_data(Output_Four_data *L)
{
	L->face_switch		=		OUTPUT_CHANNEL;
	L->Item				=		ON_OFF_Four;
	L->String			=		face_string[OUTPUT_CHANNEL];
	L->Time_count		=		0;
	L->hItime			=		0;
	L->Key_count		=		0;
	L->change_item		=		-1;
	L->overflow			=		0;
	
	//数据初始化
//	L->data.RMSTC_DATA  =		0;
//	L->data.DECAY_DATA	=		0;
//	L->data.THRSH_DATA	=		0;
//	L->data.OUT_INVERT_STA 	=	0;
//	L->data.OUT_MUTE_STA	=	0;
//	L->data.DELAY_DATA	=		0;
//	AT24C16_PageRead((u8 *)(&(L->data)),IIC_Addr[L->face_switch+38],sizeof(L->data));

	if(L->data.BAND_DATA == 0)
	{
		L->data.BAND_DATA = 1;
	}
	
	//选择使用的数据
	Use_data_choose(L->data.BAND_DATA);
}

WM_HWIN Output_Four(void) {
	WM_HWIN hWin;
	
	//申请内存
//	Out_Four[OUTPUT_CHANNEL] = (Output_Four_data *)mymalloc(0,sizeof(Output_Four_data));
//	
//	if(Out_Four[OUTPUT_CHANNEL] == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		Init_data(Out_Four[OUTPUT_CHANNEL]);
//	}
//	
	Init_data(Out_Four[OUTPUT_CHANNEL]);
	Current_Out_four = Out_Four[OUTPUT_CHANNEL];
	
	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
