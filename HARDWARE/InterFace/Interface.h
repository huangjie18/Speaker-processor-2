#ifndef __INTERFACE_H
#define __INTERFACE_H
#include "GUI.h"
#include "DIALOG.h"
#include "example.h"
//添加变量的声明转换
#ifdef Gen_GLOBALS //在.c文件中定义该类型,采用这方法不能赋初值
#define EXTERN1
#else 
#define EXTERN1  extern
#endif

//定义按钮的信息ID
#define MSG_KEY_ESC      (GUI_ID_USER + 0xF0)
#define MSG_KEY_SYSTEM   (GUI_ID_USER + 0xF1)
#define MSG_KEY_INPUT     (GUI_ID_USER + 0xF2)
#define MSG_KEY_OUTPUT   (GUI_ID_USER + 0xF3)
#define MSG_KEY_VOL_INPUT  (GUI_ID_USER + 0xF4)
#define MSG_KEY_VOL_OUTPUT (GUI_ID_USER + 0xF5)
#define MSG_KEY_CONTROL    (GUI_ID_USER + 0xF6)

//定义旋钮的信息ID
#define MSG_KNOB_INPUT_LEFT    (GUI_ID_USER + 0xF7)
#define MSG_KNOB_INPUT_RIGHT   (GUI_ID_USER + 0xF8)
#define MSG_KNOB_OUT_LEFT      (GUI_ID_USER + 0xF9)
#define MSG_KNOB_OUT_RIGHT     (GUI_ID_USER + 0xFA)
#define MSG_KNOB_CONTROL_LEFT  (GUI_ID_USER + 0xFB)
#define MSG_KNOB_CONTROL_RIGHT (GUI_ID_USER + 0xFC)


//定义一个变量来存放当前的页面的句柄
extern WM_HWIN hWin_now;


//皮肤设置函数
void Button_flex(void); //按钮皮肤设置
void Framewin_flex(void); //框架皮肤设置
int _DrawSkin_SLIDER1(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);//滑块皮肤设置
void Listbox_flex(void);
//界面函数
WM_HWIN CreateMainface(void); //主界面窗口

//第二层界面
WM_HWIN CreateINPUT_CHANNEL(void); //输入通道界面窗口
WM_HWIN CreateOut_face(void); //输出主界面


//第三层界面

/*******************************变量区**********************************/
enum 
{
	list_0 = 0,
	list_1,
	list_2,
	list_3,
	list_4,
	list_5,
	list_6,
	list_7,
};
/****************Input1************************/

//右边子窗口存放数据结构体
typedef struct
{
	char Invert;
	unsigned char RMSTC;  
	unsigned char Hold;
	unsigned char Decay;
	signed char Gain;
	signed char Aux1MixerGain;
	signed char Aux2MixerGain;
	signed char Aux3MixerGain;
	signed char Aux4MixerGain;
	signed char Aux5MixerGain;
	signed char Aux6MixerGain;
	signed char Aux7MixerGain;
	signed char Aux8MixerGain;
	
}Input_data;


//外部变量
extern Input_data Input1_data1[8]; //存放数据的变量
extern char INPUT_channel;         //输入通道标志
 


/*************************END****************************************/

/***********************************界面函数*****************************************/
/************************************INPUT******************************************/
WM_HWIN Createthird_layer(void); //Input1界面窗口

//右边第一个子窗口
WM_HWIN CreateWindow_Child(void); //右边第一个子窗口界面
WM_HWIN Get_child_hWin(I32 ID);  //Input1右边子窗口获得控件句柄

//右边第二个子窗口
WM_HWIN CreateSecond_Child(void);

//右边第三个子窗口
WM_HWIN CreateThird_Child(void);

//右边第四个子窗口
WM_HWIN CreateFour_Child(void);

//右边第五个子窗口
WM_HWIN CreateFive_Child(void);

/************************************Output******************************************/
//变量区
extern char OUTPUT_channel;        //输出通道标志 


WM_HWIN CreateOutput1_third_face(void); //第三输出界面


//右边第一个子窗口
WM_HWIN Out_fristchild(void);


//右边第二个子窗口
WM_HWIN CreateOut_twoface(void);

//右边第三个子窗口
WM_HWIN CreateOut_threeface(void);


/************************************COAX_IN******************************************/
WM_HWIN Create_COAX_face(void);  //主界面函数

//子窗口界面
WM_HWIN CreateCOAX_face_3(void); //第二个


/************************************Gen_Out******************************************/
//变量区
typedef struct Gen_out  //存放该窗口要用到的数据
{
	char Window_Switch ; //设置一个变量来判别当前的输入聚焦在哪个窗口，0代表在列表框
    WM_HWIN hChild; //子窗口句柄
    int Sel;            //索引号
	
} Gen;



EXTERN1 Gen Gen_data; //变量定义在Gen_OutDLG.C中
EXTERN1 char Gen_channel;

WM_HWIN CreateGen_Out(void);   //主界面

//WNoise界面
WM_HWIN CreateGen_WNoise(void); //Gen_Out->WNoise界面 

//SIN界面
WM_HWIN CreateGen_Sin(void);
WM_HWIN CreateSIN_Child1(void); //SET_1界面

//SweepFreq界面
WM_HWIN CreateGen_Sweep(void);   //主界面
WM_HWIN CreateSweep_Two(void); 
WM_HWIN CreateSweep_child_1(void); //SET_1界面

//Pulse界面
WM_HWIN CreatePulse(void);     //主界面
WM_HWIN CreatePulse_Child(void);   //SET_1界面

//WNoise2界面
WM_HWIN CreateWNoise2(void);   //主界面
WM_HWIN CreateWNoise_Child1(void);  //SET_1
WM_HWIN CreateWNoise_Child2(void);  //SET_2
/***********************************SYS*************************************************/
//Sys界面
WM_HWIN CreateSystem(void);

/***********************************Mode*************************************************/
//Mode界面
WM_HWIN CreateMode(void);
/*************************************************END*************************************/


#endif
