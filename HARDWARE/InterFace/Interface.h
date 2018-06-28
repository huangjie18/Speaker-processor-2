#ifndef __INTERFACE_H
#define __INTERFACE_H
#include "GUI.h"
#include "DIALOG.h"
#include "example.h"
//��ӱ���������ת��
#ifdef Gen_GLOBALS //��.c�ļ��ж��������,�����ⷽ�����ܸ���ֵ
#define EXTERN1
#else 
#define EXTERN1  extern
#endif

//���尴ť����ϢID
#define MSG_KEY_ESC      (GUI_ID_USER + 0xF0)
#define MSG_KEY_SYSTEM   (GUI_ID_USER + 0xF1)
#define MSG_KEY_INPUT     (GUI_ID_USER + 0xF2)
#define MSG_KEY_OUTPUT   (GUI_ID_USER + 0xF3)
#define MSG_KEY_VOL_INPUT  (GUI_ID_USER + 0xF4)
#define MSG_KEY_VOL_OUTPUT (GUI_ID_USER + 0xF5)
#define MSG_KEY_CONTROL    (GUI_ID_USER + 0xF6)

//������ť����ϢID
#define MSG_KNOB_INPUT_LEFT    (GUI_ID_USER + 0xF7)
#define MSG_KNOB_INPUT_RIGHT   (GUI_ID_USER + 0xF8)
#define MSG_KNOB_OUT_LEFT      (GUI_ID_USER + 0xF9)
#define MSG_KNOB_OUT_RIGHT     (GUI_ID_USER + 0xFA)
#define MSG_KNOB_CONTROL_LEFT  (GUI_ID_USER + 0xFB)
#define MSG_KNOB_CONTROL_RIGHT (GUI_ID_USER + 0xFC)


//����һ����������ŵ�ǰ��ҳ��ľ��
extern WM_HWIN hWin_now;


//Ƥ�����ú���
void Button_flex(void); //��ťƤ������
void Framewin_flex(void); //���Ƥ������
int _DrawSkin_SLIDER1(const WIDGET_ITEM_DRAW_INFO * pDrawItemInfo);//����Ƥ������
void Listbox_flex(void);
//���溯��
WM_HWIN CreateMainface(void); //�����洰��

//�ڶ������
WM_HWIN CreateINPUT_CHANNEL(void); //����ͨ�����洰��
WM_HWIN CreateOut_face(void); //���������


//���������

/*******************************������**********************************/
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

//�ұ��Ӵ��ڴ�����ݽṹ��
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


//�ⲿ����
extern Input_data Input1_data1[8]; //������ݵı���
extern char INPUT_channel;         //����ͨ����־
 


/*************************END****************************************/

/***********************************���溯��*****************************************/
/************************************INPUT******************************************/
WM_HWIN Createthird_layer(void); //Input1���洰��

//�ұߵ�һ���Ӵ���
WM_HWIN CreateWindow_Child(void); //�ұߵ�һ���Ӵ��ڽ���
WM_HWIN Get_child_hWin(I32 ID);  //Input1�ұ��Ӵ��ڻ�ÿؼ����

//�ұߵڶ����Ӵ���
WM_HWIN CreateSecond_Child(void);

//�ұߵ������Ӵ���
WM_HWIN CreateThird_Child(void);

//�ұߵ��ĸ��Ӵ���
WM_HWIN CreateFour_Child(void);

//�ұߵ�����Ӵ���
WM_HWIN CreateFive_Child(void);

/************************************Output******************************************/
//������
extern char OUTPUT_channel;        //���ͨ����־ 


WM_HWIN CreateOutput1_third_face(void); //�����������


//�ұߵ�һ���Ӵ���
WM_HWIN Out_fristchild(void);


//�ұߵڶ����Ӵ���
WM_HWIN CreateOut_twoface(void);

//�ұߵ������Ӵ���
WM_HWIN CreateOut_threeface(void);


/************************************COAX_IN******************************************/
WM_HWIN Create_COAX_face(void);  //�����溯��

//�Ӵ��ڽ���
WM_HWIN CreateCOAX_face_3(void); //�ڶ���


/************************************Gen_Out******************************************/
//������
typedef struct Gen_out  //��Ÿô���Ҫ�õ�������
{
	char Window_Switch ; //����һ���������б�ǰ������۽����ĸ����ڣ�0�������б��
    WM_HWIN hChild; //�Ӵ��ھ��
    int Sel;            //������
	
} Gen;



EXTERN1 Gen Gen_data; //����������Gen_OutDLG.C��
EXTERN1 char Gen_channel;

WM_HWIN CreateGen_Out(void);   //������

//WNoise����
WM_HWIN CreateGen_WNoise(void); //Gen_Out->WNoise���� 

//SIN����
WM_HWIN CreateGen_Sin(void);
WM_HWIN CreateSIN_Child1(void); //SET_1����

//SweepFreq����
WM_HWIN CreateGen_Sweep(void);   //������
WM_HWIN CreateSweep_Two(void); 
WM_HWIN CreateSweep_child_1(void); //SET_1����

//Pulse����
WM_HWIN CreatePulse(void);     //������
WM_HWIN CreatePulse_Child(void);   //SET_1����

//WNoise2����
WM_HWIN CreateWNoise2(void);   //������
WM_HWIN CreateWNoise_Child1(void);  //SET_1
WM_HWIN CreateWNoise_Child2(void);  //SET_2
/***********************************SYS*************************************************/
//Sys����
WM_HWIN CreateSystem(void);

/***********************************Mode*************************************************/
//Mode����
WM_HWIN CreateMode(void);
/*************************************************END*************************************/


#endif
