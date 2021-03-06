#ifndef __INTERFACE_H
#define __INTERFACE_H
#include "GUI.h"
#include "DIALOG.h"
#include "example.h"
#include "sys.h"
#include "24c16.h"
#include "iic.h"
#include "ak4612.h"	

//添加变量的声明转换
#ifdef Gen_GLOBALS //在.c文件中定义该类型,采用这方法不能赋初值
#define EXTERN1
#else 
#define EXTERN1  extern
#endif


//GUI_ID_USER 换成 WM_USER
//定义按钮的信息ID
#define MSG_KEY_ESC        (WM_USER + 0xF0)
#define MSG_KEY_SYSTEM     (WM_USER + 0xF1)
#define MSG_KEY_INPUT      (WM_USER + 0xF2)
#define MSG_KEY_OUTPUT     (WM_USER + 0xF3)
#define MSG_KEY_VOL_INPUT  (WM_USER + 0xF4)
#define MSG_KEY_VOL_OUTPUT (WM_USER + 0xF5)
#define MSG_KEY_CONTROL    (WM_USER + 0xF6)


//定义旋钮的信息ID
#define MSG_KNOB_INPUT_LEFT    (WM_USER + 0xF7)
#define MSG_KNOB_INPUT_RIGHT   (WM_USER + 0xF8)
#define MSG_KNOB_OUT_LEFT      (WM_USER + 0xF9)
#define MSG_KNOB_OUT_RIGHT     (WM_USER + 0xFA)
#define MSG_KNOB_CONTROL_LEFT  (WM_USER + 0xFB)
#define MSG_KNOB_CONTROL_RIGHT (WM_USER + 0xFC)
#define MSG_KNOB_NULL		   (WM_USER + 0xFD)  //没有旋钮动作
#define MSG_KEY_RELEASE    	   (WM_USER + 0xFE)  //按钮释放
#define MSG_KEY_NULL		   (WM_USER + 0xFF)  //无按键按下
//滑动
#define MSG_SLIDER_L		   	 (WM_USER + 0xEE)
#define MSG_SLIDER_R			 (WM_USER + 0xEF)
//定义关于密码的信息ID
#define MSG_PIN_CHANGED			(WM_USER + 0xE0)
#define MSG_PIN_OK				(WM_USER + 0xE1)
#define MSG_PIN_ERROR			(WM_USER + 0xE2)
#define MSG_PIN_UNLOCK          (WM_USER + 0xE3)  //解锁成功
#define MSG_PIN_NEW        		(WM_USER + 0xE4)  //改密码成功
#define MSG_TIME_UPDATE			(WM_USER + 0xE5)  //时间更新
//定义一个变量来存放当前的页面的句柄
extern WM_HWIN hWin_now;


//皮肤设置函数
void Button_flex(void); //按钮皮肤设置
void Button_flex_2(void); //按钮皮肤设置
void Framewin_flex(void); //框架皮肤设置
int _DrawSkin_SLIDER1(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);//滑块皮肤设置
void Listbox_flex(void);
//界面函数
WM_HWIN CreateMainface(void); //主界面窗口

//IIC地址设置
#define Addr_num  100


/*********************************************第二次界面**********************************/
/******************************
***
***变量
***
*******************************/
extern BUTTON_SKINFLEX_PROPS Props_Default; 
extern char INPUT_CHANNEL;  //用来指示选中哪个输入通道
extern void *Inface_data;   //当前页面数据指针
extern u16 IIC_Addr[Addr_num];  //IC24C16存放地址
//Out_First数据结构
extern char OUTPUT_CHANNEL;  //指示输出通道
extern char GEN_CHANNEL;     //指示发生器

extern const GUI_POINT g_pPoint_left[];
extern const GUI_POINT g_pPoint_right[];

/******************************************Input_First  数据*********************************************/
//Input_First数据结构
typedef struct
{
	u16  IN_DATA_1;
	u16  IN_DATA_2;
	u16  IN_DATA_3;
	u16  IN_DATA_4;
	u16  IN_DATA_5;
	u16  IN_DATA_6;
	u16  IN_DATA_7;
	u16  IN_DATA_8;
}Input_Data1;


typedef struct
{
	Input_Data1 data;
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	
}Input_First_data;

//项目定义
enum
{
	slider_0,
	slider_1,
	slider_2,
	slider_3,
	slider_4,
	slider_5,
	slider_6,
	slider_7,
	button_0,
	button_1,
	button_2,
	button_3,
	button_4,
	button_5,
	button_6,
	button_7,
};
/******************************************Input_First  End*********************************************/

/******************************************Input_Second  数据****************************************/
//要保存的数据
typedef struct 
{
	//NOISEGATE的数据
	s16  RMSTC_DATA;       //存放RMSTC的数值,有符号
	s16  HOLD_DATA;		   //存放HOLD的数值
	s16  DECAY_DATA;	   //存放DECAY的数值
	
	//MUTE_AND_INVERT
	u8 IN_MUTE_STA;      //指示IN_MUTE当前状态
	u8 IN_INVERT_STA;    //指示IN_INVERT当前状态 
	
	//COMPRESSOR的数据
	char ON_OFF;           //存放开或关的数据
	s16  THRSH_DATA;       //存放THRSH的数据
	s16  RATIO_DATA;       //存放RATIO的数据
	s16  ATK_TIME_DATA;    //存放ATK_TIME的数据
	s16  RELEASE_DATA;     //存放RELEASE的数据
	s16  COM_HOLD_DATA;    //存放HOLD的数据
}Input_Data2;

//Input_Second数据
typedef  struct 
{
	Input_Data2 data;      //要保存的数据

	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Input_Second_data;

//子项目
enum
{
	RMSTC_Item,
	HOLD_Item,
	DECAY_Item,
	IN_MUTE_Item,
	IN_INVERT_Item,
	ON_OFF_Item,
	THRSH_Item,
	RATIO_Item,
	ATK_TIME_Item,
	RELEASE_Item,
	COM_HOLD_Item,
};

//定时器
enum
{
	RMSTC_Time_left,
	RMSTC_Time_right,
	HOLD_Time_left,
	HOLD_Time_right,
	DECAY_Time_left,
	DECAY_Time_right,
	THRSH_Time_left,
	THRSH_Time_right,
	RATIO_Time_left,
	RATIO_Time_right,
	ATK_Time_left,
	ATK_Time_right,
	RELEASE_Time_left,
	RELEASE_Time_right,
	COM_HOLD_Time_left,
	COM_HOLD_Time_right,
};

enum
{
	First_Time_left,
	First_Time_right,
	Second_Time_left,
	Second_Time_right,
	Third_Time_left,
	Third_Time_right,
	Four_Time_left,
	Four_Time_right,
	Five_Time_left,
	Five_Time_right,
	Six_Time_left,
	Six_Time_right,
	Seven_Time_left,
	Seven_Time_right,
	Eight_Time_left,
	Eight_Time_right,
};

/*******************************************Input_Second  End*******************************************/

/*******************************************Input_Third 数据**********************************/
typedef struct 
{
	u16 Aux1_SLIDER_DATA;
	u16 Aux2_SLIDER_DATA;
	u16 Aux3_SLIDER_DATA;
	u16 Aux4_SLIDER_DATA;
	u16 Aux5_SLIDER_DATA;
	u16 Aux6_SLIDER_DATA;
	u16 Aux7_SLIDER_DATA;
	u16 Aux8_SLIDER_DATA;
	u8 Aux1_CHECKBOX_STA;
	u8 Aux2_CHECKBOX_STA;
	u8 Aux3_CHECKBOX_STA;
	u8 Aux4_CHECKBOX_STA;
	u8 Aux5_CHECKBOX_STA;
	u8 Aux6_CHECKBOX_STA;
	u8 Aux7_CHECKBOX_STA;
	u8 Aux8_CHECKBOX_STA;
}Input_Data3;


typedef struct 
{
	Input_Data3  data;
	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
	//用来判断按钮是否释放
	u16 Released;         //0代表已经释放，1代表没释放
	
	//专门用来对应复选框
	char checkbox_sta;
	
	//定义一个函数指针来区别滑块的增减
	void (*slider_change)();
	
	//用来判断按钮是否释放
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Input_Third_data;

enum
{
	aux1_slider,
	aux2_slider,
	aux3_slider,
	aux4_slider,
	aux5_slider,
	aux6_slider,
	aux7_slider,
	aux8_slider,
	aux1_checkbox,
	aux2_checkbox,
	aux3_checkbox,
	aux4_checkbox,
	aux5_checkbox,
	aux6_checkbox,
	aux7_checkbox,
	aux8_checkbox,
	
};


/***********************************************Input_Four 数据**************************************************/
typedef struct 
{
	char 	ON_OFF;
	s16		BAND_DATA;
	s16		FREQ_DATA;
	s16		TYPE_DATA;
	s16		GAIN_DATA;
	s16		Q_DATA;
	s16		BAND_DATA_1;
	s16		FREQ_DATA_1;
	s16		TYPE_DATA_1;
	s16		GAIN_DATA_1;
	s16		Q_DATA_1;
	s16		BAND_DATA_2;
	s16		FREQ_DATA_2;
	s16		TYPE_DATA_2;
	s16		GAIN_DATA_2;
	s16		Q_DATA_2;
	s16		BAND_DATA_3;
	s16		FREQ_DATA_3;
	s16		TYPE_DATA_3;
	s16		GAIN_DATA_3;
	s16		Q_DATA_3;
	s16		BAND_DATA_4;
	s16		FREQ_DATA_4;
	s16		TYPE_DATA_4;
	s16		GAIN_DATA_4;
	s16		Q_DATA_4;
	s16		BAND_DATA_5;
	s16		FREQ_DATA_5;
	s16		TYPE_DATA_5;
	s16		GAIN_DATA_5;
	s16		Q_DATA_5;
	s16		BAND_DATA_6;
	s16		FREQ_DATA_6;
	s16		TYPE_DATA_6;
	s16		GAIN_DATA_6;
	s16		Q_DATA_6;
	s16		BAND_DATA_7;
	s16		FREQ_DATA_7;
	s16		TYPE_DATA_7;
	s16		GAIN_DATA_7;
	s16		Q_DATA_7;
	
}Input_Data4;

typedef struct
{
	Input_Data4 data;
	
	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Input_Four_data;

//子项目标号
enum
{
	ON_OFF_Four,
	BAND_Four,
	FREQ_Four,
	TYPE_Four,
	GAIN_Four,
	Q_Four,
};

enum
{
	Next_dir,
	Last_dir,
};

/***********************************************Input_Five 数据************************************************/
typedef struct 
{
	s16  	TYPE_DATA_LOW;
	s16		FREQ_DATA_LOW;
	s16		GAIN_DATA_LOW;
	s16		TYPE_DATA_HIGH;
	s16		FREQ_DATA_HIGH;
	s16 	GAIN_DATA_HIGH;
	
	u8		LOW_HIGH_STA;
	u8		INVERT_LOW_STA;
	u8		MID_HIGH_STA;
	u8		INVERT_HIGH_STA;
	
	
}Input_Data5;


typedef struct
{
	Input_Data5  data;
	
	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
	//专门用来对应复选框
	char checkbox_sta;
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Input_Five_data;


/***********************************************OUT_First 数据************************************************/


typedef struct
{
	u16  OUT_DATA_1;
	u16  OUT_DATA_2;
	u16  OUT_DATA_3;
	u16  OUT_DATA_4;
	u16  OUT_DATA_5;
	u16  OUT_DATA_6;
	u16  OUT_DATA_7;
	u16  OUT_DATA_8;
}Output_Data;


typedef struct 
{
	Output_Data data;
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	//用来判断按钮是否释放
	signed char change_item;         //记录更改项,传输数据
	
}Output_First_data;
/***********************************************OUT_Second 数据************************************************/
typedef struct 
{
	s16 RMSTC_DATA;   //RMSTC数值
	s16 DECAY_DATA;   //DECAT数值
	s16 THRSH_DATA;   //THRESHOLD数值
	s16 DELAY_DATA;   //DELAY数值
	
	u8  OUT_MUTE_STA; //OUT_MUTE状态
	u8  OUT_INVERT_STA; //OUT_INVERT状态
	
}Output_Data1;


typedef struct
{
	Output_Data1  data;
	
	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
	//专门用来对应复选框
	char checkbox_sta;
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Output_Second_Data;

enum
{
	RMSTC_Item_Out,
	DECAY_Item_Out,
	THRES_Item_Out,
	MUTE_Item_Out,
	INVERT_Item_Out,
	DELAY_Item_Out,
};


/***********************************************OUT_Third 数据************************************************/
typedef struct 
{
	s16  	TYPE_DATA_LOW;
	s16		FREQ_DATA_LOW;
	s16		GAIN_DATA_LOW;
	s16		TYPE_DATA_HIGH;
	s16		FREQ_DATA_HIGH;
	s16 	GAIN_DATA_HIGH;
	
	u8		LOW_HIGH_STA;
	u8		INVERT_LOW_STA;
	u8		MID_HIGH_STA;
	u8		INVERT_HIGH_STA;
	
	
}Output_Data2;


typedef struct
{
	Output_Data2  data;
	
	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
	//专门用来对应复选框
	char checkbox_sta;
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Output_Third_Data;

//对应子项目选项
enum
{
	TYPE_LOW_Item_Out,
	FREQ_LOW_Item_Out,
	GAIN_LOW_Item_Out,
//	LOW_HIGH_Item_Out,
	INVERT_LOW_Item_Out,
	TYPE_HIGH_Item_Out,
	FREQ_HIGH_Item_Out,
	GAIN_HIGH_Item_Out,
//	MID_HIGH_Item_Out,
	INVERT_HIGH_Item_Out,
};

enum
{
	BESSEL_12_TYPE,
	BUTTER_12_TYPE,
	BESSEL_24_TYPE,
	BUTTER_24_TYPE,
};
/***********************************************OUT_Four 数据************************************************/

typedef struct 
{
	char 	ON_OFF;
	s16		BAND_DATA;
	s16		FREQ_DATA;
	s16		TYPE_DATA;
	s16		GAIN_DATA;
	s16		Q_DATA;
	s16		BAND_DATA_1;
	s16		FREQ_DATA_1;
	s16		TYPE_DATA_1;
	s16		GAIN_DATA_1;
	s16		Q_DATA_1;
	s16		BAND_DATA_2;
	s16		FREQ_DATA_2;
	s16		TYPE_DATA_2;
	s16		GAIN_DATA_2;
	s16		Q_DATA_2;
	s16		BAND_DATA_3;
	s16		FREQ_DATA_3;
	s16		TYPE_DATA_3;
	s16		GAIN_DATA_3;
	s16		Q_DATA_3;
	s16		BAND_DATA_4;
	s16		FREQ_DATA_4;
	s16		TYPE_DATA_4;
	s16		GAIN_DATA_4;
	s16		Q_DATA_4;
	s16		BAND_DATA_5;
	s16		FREQ_DATA_5;
	s16		TYPE_DATA_5;
	s16		GAIN_DATA_5;
	s16		Q_DATA_5;
	s16		BAND_DATA_6;
	s16		FREQ_DATA_6;
	s16		TYPE_DATA_6;
	s16		GAIN_DATA_6;
	s16		Q_DATA_6;
	s16		BAND_DATA_7;
	s16		FREQ_DATA_7;
	s16		TYPE_DATA_7;
	s16		GAIN_DATA_7;
	s16		Q_DATA_7;
	
}Output_Data4;

typedef struct
{
	Output_Data4 data;

	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串

	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢

	//定时器的句柄
	WM_HTIMER  hItime;
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	

} Output_Four_data;


/***********************************************MODE 数据************************************************/
typedef struct 
{
	s16 LOAD_DATA;
	s16 SAVE_DATA;
	s16 INIT_DATA;
	
}Mode_Data1;

typedef struct 
{
	Mode_Data1  data;
	
	//指示不同通道的数据
	char face_switch;      //指示第几个通道页面
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串

	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢

	//定时器的句柄
	WM_HTIMER  hItime;
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
	
}Mode_First_Data;

enum
{
	MODE_0,
	MODE_1,
	MODE_2,
	MODE_3,
	MODE_4,
	MODE_5,
	MODE_6,
	MODE_7,
	MODE_8,
	MODE_9,
};

/**********************************System_First 数据************************************************/
typedef struct
{
	s16 *First_data;
	s16 *Second_data;
	s16 *Third_data;
	s16 *Four_data;
	s16 *Five_data;
	s16 *Six_data;
	s16 *Seven_data;
	s16 *Eight_data;
	s16 *Nint_data;
}Current;

typedef struct
{
	s16  MIC_DATA_STR;
	s16  MUS_DATA_STR;
	s16  EFF_DATA_STR;
	s16  MIC_DATA_END;
	s16  MUS_DATA_END;
	s16  EFF_DATA_END;
}System_Data1;

typedef struct
{
	System_Data1  data;
	
	char Item;             //指示选中第几个子项目
	char *String;          //用来存放字符串

	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	u16  Key_count;        //判断旋转按钮快慢

	//定时器的句柄
	WM_HTIMER  hItime;
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	u8	dir;               //正反转方向
}System_First_Data;

/**********************************System_Second 数据************************************************/
typedef struct 
{
	u16 	_Old_PIN;   //要存入EEPROM的密码
	unsigned char	LOCK_KEY_STA;  //用来记录LOCK_KEY的状态
	u8		CURRENT;     //用来记录开机次数
}System_Data2;


typedef struct
{
	System_Data2 data;
	u16		 _PIN_Value;  //输入的密码
	u8 		 _PIN_Digits; //输入密码个数
	u8     _Lock_sta;   //判断是否可以改数据标志位,0表示未开锁状态
	WM_HWIN  hWinInfo;
	char Item;             //指示选中第几个子项目
}System_Second_Data;

enum
{
	CONF_Item,
	NEW_Item,
	LOCK_Item,
	CURR_Item,
};

enum
{
	CLOSE,
	OPEN,
	input_flag,
	output_flag,
};

enum
{
	g_mute,
	g_umute,
};

enum
{
	g_invert,
	g_uinvert,
};

/**********************************Gen_First 数据******************************/
typedef struct
{
	u8  WHITE_NOISE_STA; //白噪声的开关状态
	u8  SIN_STA;		 //SIN开关
	u8  SQUARE_STA;
	u8  SWEEPFREQ_STA;
	u8  PULSE_STA;
	u8  PINK_NOISE_STA;
}Gen_Data1;


typedef struct
{
	Gen_Data1 data;
	
	char Item;             //指示选中第几个子项目
	
	signed char change_item;         //记录更改项
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
}Gen_First_Data;

enum
{
	First_Item,
	Second_Item,
	Third_Item,
	Four_Item,
	Five_Item,
	Six_Item,
	Seven_Item,
	Eight_Item,
	Nine_Item,
	Ten_Item,
	Eleven_Item,
	Twelve_Item,
	Thirteen_Item,
	Fourteen_Item,
	Fifteen_Item,
	Sixteen_Item,
	Seventeen_Item,
	Eighteen_Item,
	Nineteen_Item,
	Twenty_Item,
	
};

/**********************************Gen_Second 数据******************************/
typedef struct 
{
	//WHITE_NOISE
	s16 WHITE_NOISE_GAIN;
	//AUX
	u8	WHITE_AUX1_STA;
	u8	WHITE_AUX2_STA;
	u8	WHITE_AUX3_STA;
	u8	WHITE_AUX4_STA;
	u8	WHITE_AUX5_STA;
	u8	WHITE_AUX6_STA;
	u8	WHITE_AUX7_STA;
	u8	WHITE_AUX8_STA;
	
	//PINK
	s16 PINK_NOISE_GAIN;
	//AUX
	u8	PINK_AUX1_STA;
	u8	PINK_AUX2_STA;
	u8	PINK_AUX3_STA;
	u8	PINK_AUX4_STA;
	u8	PINK_AUX5_STA;
	u8	PINK_AUX6_STA;
	u8	PINK_AUX7_STA;
	u8	PINK_AUX8_STA;
}Gen_Data2;


typedef struct
{
	Gen_Data2 data;
	
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	//用来判断按钮是否释放
	signed char change_item;         //记录更改项,传输数据
	
	//专门用来对应复选框
	u32 checkbox_sta;
	
}Gen_Second_Data;

/*************************************Gen_Third 数据***************************/
typedef struct
{
	s16 START_DATA;
	s16 STOP_DATA;
	s16 STEP_DATA;
	s32 CYCSLES_DATA;
	
	//GAIN
	s16 GAIN_DATA;
	//AUX
	u8	AUX1_STA;
	u8	AUX2_STA;
	u8	AUX3_STA;
	u8	AUX4_STA;
	u8	AUX5_STA;
	u8	AUX6_STA;
	u8	AUX7_STA;
	u8	AUX8_STA;
}Gen_Data3;

typedef struct
{
	Gen_Data3 data;
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	
	signed char change_item;         //记录更改项,传输数据
	
	//专门用来对应复选框
	u32 checkbox_sta;
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	
	//定时器的句柄
	WM_HTIMER  hItime;
	
}Gen_Third_Data;

/************************************Gen_Four 数据*******************************/
typedef struct
{
	//FREQ
	s16 FREQ_DATA;
	
	//GAIN
	s16 GAIN_DATA;
	
	//AUX
	u8	AUX1_STA;
	u8	AUX2_STA;
	u8	AUX3_STA;
	u8	AUX4_STA;
	u8	AUX5_STA;
	u8	AUX6_STA;
	u8	AUX7_STA;
	u8	AUX8_STA;
}Gen_Data4;

typedef struct
{
	Gen_Data4 data;
	char *String;          //用来存放字符串
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	
	signed char change_item;         //记录更改项,传输数据
	
	//专门用来对应复选框
	u32 checkbox_sta;
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	
	//定时器的句柄
	WM_HTIMER  hItime;
}Gen_Four_Data;

/************************************GEN_OUT 界面5数据*******************************************/
typedef struct
{
	//FREQ
	s16 FREQ_DATA;
	
	//GAIN
	s16 GAIN_DATA;
	
	//DUTY
	s16 DUTY_DATA;
	
	//AUX
	u8	AUX1_STA;
	u8	AUX2_STA;
	u8	AUX3_STA;
	u8	AUX4_STA;
	u8	AUX5_STA;
	u8	AUX6_STA;
	u8	AUX7_STA;
	u8	AUX8_STA;
}Gen_Data5;

typedef struct
{
	Gen_Data5 data;
	char *String;          //用来存放字符串
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	
	signed char change_item;         //记录更改项,传输数据
	
	//专门用来对应复选框
	u32 checkbox_sta;
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	
	//定时器的句柄
	WM_HTIMER  hItime;
}Gen_Five_Data;

/************************************TIME First数据********************************/
typedef struct
{
	s16 YEAR_DATA;
	s16 MONTH_DATA;
	s16 DATE_DATA;
	s16 HOUR_DATA;
	s16 MINUTE_DATA;
	
}Time_Data1;

typedef struct
{
	Time_Data1 data;
	
	char Item;             //指示选中第几个子项目
	u16  Key_count;        //判断旋转按钮快慢
	u8	dir;               //正反转方向
	
	//用来判断是否溢出
	s16 overflow;         	//0表示没溢出，1表示溢出
	
	//用来计算长短按的
	u16  Time_count;       //判断定时器长短按
	
	signed char change_item;         //记录更改项,传输数据
	
	//定时器的句柄
	WM_HTIMER  hItime;
}Time_First_Data;

/*******************************Meter 数据*********************************/
typedef struct
{
	//输入电平
	s16 INPUT_1_METER;
	s16 INPUT_2_METER;
	s16 INPUT_3_METER;
	s16 INPUT_4_METER;
	s16 INPUT_5_METER;
	s16 INPUT_6_METER;
	s16 COAX_L_METER;
	s16 COAX_R_METER;
	
	//输出电平
	s16 OUTPUT1_METER;
	s16 OUTPUT2_METER;
	s16 OUTPUT3_METER;
	s16 OUTPUT4_METER;
	s16 OUTPUT5_METER;
	s16 OUTPUT6_METER;
	s16 OUTPUT7_METER;
	s16 OUTPUT8_METER;
	
}Meter_Data;

typedef struct
{
	Meter_Data data;
	
	//用来滑动识别
	char touch_hua;
	int touch_x_last;
	int touch_y_last;
	int touch_x_current;
	int touch_y_current;
	
	//存放时间句柄
	WM_HTIMER hItime;
	
	//存放电平句柄，加快速度
	WM_HWIN  hItem_IN1; 
	WM_HWIN  hItem_IN2; 
	WM_HWIN  hItem_IN3; 
	WM_HWIN  hItem_IN4; 
	WM_HWIN  hItem_IN5; 
	WM_HWIN  hItem_IN6; 
	WM_HWIN  hItem_COAL; 
	WM_HWIN  hItem_COAR;

	WM_HWIN  hItem_OUT1;
	WM_HWIN  hItem_OUT2;
	WM_HWIN  hItem_OUT3;
	WM_HWIN  hItem_OUT4;
	WM_HWIN  hItem_OUT5;
	WM_HWIN  hItem_OUT6;
	WM_HWIN  hItem_OUT7;
	WM_HWIN  hItem_OUT8;
	
	
}Meter_First_Data;


/**********************************RTA 数据****************************/
typedef struct
{
	s16 RTA1_DATA;
	s16 RTA2_DATA;
	s16 RTA3_DATA;
	s16 RTA4_DATA;
	s16 RTA5_DATA;
	s16 RTA6_DATA;
	s16 RTA7_DATA;
	s16 RTA8_DATA;
	s16 RTA9_DATA;
	s16 RTA10_DATA;
	s16 RTA11_DATA;
	s16 RTA12_DATA;
	s16 RTA13_DATA;
	s16 RTA14_DATA;
	s16 RTA15_DATA;
	s16 RTA16_DATA;
	s16 RTA17_DATA;
	s16 RTA18_DATA;
	s16 RTA19_DATA;
	s16 RTA20_DATA;
	s16 RTA21_DATA;
	s16 RTA22_DATA;
	s16 RTA23_DATA;
	s16 RTA24_DATA;
	s16 RTA25_DATA;
	s16 RTA26_DATA;
	s16 RTA27_DATA;
	s16 RTA28_DATA;
	s16 RTA29_DATA;
	s16 RTA30_DATA;
	s16 RTA31_DATA;
	
}RTA_Data;

typedef struct
{
	RTA_Data data;
	
	//用来辨别第几通道
	char RTA_Channel;
	//用来滑动识别
	char touch_hua;
	int touch_x_last;
	int touch_y_last;
	int touch_x_current;
	int touch_y_current;
	
	//定时器句柄
	WM_HTIMER hItime1;
	
	
	
}RTA_First_Data;

enum
{
	RTA_IN1,
	RTA_IN2,
	RTA_IN3,
	RTA_IN4,
	RTA_IN5,
	RTA_IN6,
	RTA_COAL,
	RTA_COAR,
	RTA_OUT1,
	RTA_OUT2,
	RTA_OUT3,
	RTA_OUT4,
	RTA_OUT5,
	RTA_OUT6,
	RTA_OUT7,
	RTA_OUT8,
	
	
};
/*
*******************************************************************************************
* *********************************函 数 名***********************************************
* 
*
* 
*******************************************************************************************
*/
extern u8 key_lock_flag; //键盘锁标记
void check_key_lock(u8 clr);  //键盘锁需要的函数
/*************************INPUT********************************/
WM_HWIN Input_First(void);
WM_HWIN Input_Second(void);
WM_HWIN Input_Third(void);
WM_HWIN Input_Four(void);
WM_HWIN Input_Five(void);

int Max_Min(void *p,s32 Max,s32 Min);  //最大和最小值
void Value_Change_add(void *p,u16 *time); //值增加
void Value_Change_dec(void *p,u16 *time); //值减少
void Checkbox_Init(u8 *p);				  //复选框初始化
void Item_change(char *Item,u8 First_Item,u8 Last_Item,u8 dir); //改变子选项
void Time_add_dec(s16 *Value,const GUI_RECT * pRect, WM_HTIMER *time,u8 fight,WM_MESSAGE * pMsg);
void Time_end(u16 *count,WM_HTIMER htime);
void Time_long_press(WM_MESSAGE * pMsg,s16 *q,u16 *time,const GUI_RECT * pRect,u8 fight);
void g_cbButton_left(WM_MESSAGE * pMsg);
void g_cbButton_right(WM_MESSAGE * pMsg);
/**************************OUTPUT********************************/
WM_HWIN Output_First(void);
WM_HWIN Output_Second(void);
WM_HWIN Output_Third(void);
WM_HWIN Output_Four(void);
//void Band_Sta(WM_HWIN hItem,s16 band,u8 sta); //按钮状态转换
/**************************GEN_OUT******************************/
WM_HWIN Gen_First(void);
WM_HWIN Gen_Second(void);
WM_HWIN Gen_Third(void);
WM_HWIN Gen_Four(void);
WM_HWIN Gen_Five(void);


/**************************MODE********************************/
WM_HWIN Mode_First(void);

/**************************SYSTEM*****************************/
WM_HWIN System_First(void);
WM_HWIN System_Second(void);

//子窗口
WM_HWIN CreatePIN(void);
WM_HWIN CreateMessge(void);
void Get_Sys_Second (System_Second_Data* L);
u16 Return_PIN(void); //返回新密码

/**************************TIME*****************************/
WM_HWIN Time_First(void);

/**************************Meter***************************/
WM_HWIN Meter_Show(void);


/**************************RTA*****************************/
WM_HWIN RTA_Show(void);

#endif
