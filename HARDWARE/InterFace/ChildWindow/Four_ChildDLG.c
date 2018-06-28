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

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0 (GUI_ID_USER + 0x00)
#define ID_SLIDER_0 (GUI_ID_USER + 0x01)
#define ID_SLIDER_1 (GUI_ID_USER + 0x02)
#define ID_SLIDER_2 (GUI_ID_USER + 0x03)
#define ID_TEXT_0 (GUI_ID_USER + 0x04)
#define ID_TEXT_1 (GUI_ID_USER + 0x05)
#define ID_TEXT_2 (GUI_ID_USER + 0x06)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { WINDOW_CreateIndirect, "Four_Child", ID_WINDOW_0, 0, 0, 285, 240, 0, 0x0, 0 },
    { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 27, 28, 224, 34, 0, 0x0, 0 },
    { SLIDER_CreateIndirect, "Slider", ID_SLIDER_1, 27, 107, 224, 34, 0, 0x0, 0 },
    { SLIDER_CreateIndirect, "Slider", ID_SLIDER_2, 27, 181, 224, 34, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_0, 27, 7, 109, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_1, 27, 79, 109, 20, 0, 0x64, 0 },
    { TEXT_CreateIndirect, "Text", ID_TEXT_2, 27, 155, 109, 20, 0, 0x64, 0 },
    // USER START (Optionally insert additional widgets)
    // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
//��Ч��������
static GUI_RECT Rect_3[]=
{
    {136,7,156,27},
    {136,79,156,99},
    {136,155,156,175},
};

//����ṹ��
//typedef struct
//{
//    int Value;  //�����ֵ
//    int x;      //xλ��
//    int y;      //yλ��
//}SLIDER_Show;

//static signed char SLIDER_Value[3] = {-80,-80,-80}; //������������ֵ

//��ʾ����ֵ
static void _ShowSlidervalue(void)
{
    GUI_SetColor(GUI_RED);           //������ʾ��ɫ
    GUI_SetTextMode(GUI_TM_TRANS);   //������ʾģʽΪ͸��ģʽ���ǲ��Ḳ�Ǳ���
    GUI_SetFont(&GUI_Font20_1);      //��ʾ�����С
    GUI_GotoXY(136,7);               //���õ�һ������λ��
    GUI_DispDecMin(Input1_data1[INPUT_channel].Aux4MixerGain); //��ʾ��һ������ֵ
    GUI_GotoXY(136,79);              //���õڶ�������λ��
    GUI_DispDecMin(Input1_data1[INPUT_channel].Aux5MixerGain); //��ʾ�ڶ�������ֵ
    GUI_GotoXY(136,155);             //���õ���������λ��
    GUI_DispDecMin(Input1_data1[INPUT_channel].Aux6MixerGain); //��ʾ����������ֵ
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    // USER START (Optionally insert additional variables)
    // USER END

    switch (pMsg->MsgId)
    {
    case WM_INIT_DIALOG:

        //����4�ķ�Χ����
        hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0); //��þ��
        SLIDER_SetRange(hItem,-80,0); //���û��鷶Χ
        SLIDER_SetValue(hItem,Input1_data1[INPUT_channel].Aux4MixerGain); //���û����ֵ

        //����5�ķ�Χ����
        hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_1); //��þ��
        SLIDER_SetRange(hItem,-80,0); //���û��鷶Χ
        SLIDER_SetValue(hItem,Input1_data1[INPUT_channel].Aux5MixerGain); //���û����ֵ

        //����6�ķ�Χ����
        hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_2); //��þ��
        SLIDER_SetRange(hItem,-80,0); //���û��鷶Χ
        SLIDER_SetValue(hItem,Input1_data1[INPUT_channel].Aux6MixerGain); //���û����ֵ
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
        TEXT_SetText(hItem, "Aux4MixerGain:");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
        TEXT_SetText(hItem, "Aux5MixerGain:");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        //
        // Initialization of 'Text'
        //
        hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
        TEXT_SetText(hItem, "Aux6MixerGain:");
        TEXT_SetFont(hItem, GUI_FONT_16B_1);
        // USER START (Optionally insert additional code for further widget initialization)
        // USER END
        break;
    case WM_NOTIFY_PARENT:
        Id    = WM_GetId(pMsg->hWinSrc);
        NCode = pMsg->Data.v;
        switch(Id)
        {
        case ID_SLIDER_0: // Notifications sent by 'Slider'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_VALUE_CHANGED: //����λ�÷����仯��ִ���������
                hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0); //��û�����
                Input1_data1[INPUT_channel].Aux4MixerGain = SLIDER_GetValue(hItem); //���滬��ֵ
                WM_InvalidateRect(pMsg->hWin,&Rect_3[0]); //��Ч����ֵ����ˢ����ʾֵ
                break;
                // USER START (Optionally insert additional code for further notification handling)
                // USER END
            }
            break;
        case ID_SLIDER_1: // Notifications sent by 'Slider'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_VALUE_CHANGED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_1); //��û�����
                Input1_data1[INPUT_channel].Aux5MixerGain = SLIDER_GetValue(hItem); //���滬��ֵ
                WM_InvalidateRect(pMsg->hWin,&Rect_3[1]); //��Ч����ֵ����ˢ����ʾֵ
                break;
                // USER START (Optionally insert additional code for further notification handling)
                // USER END
            }
            break;
        case ID_SLIDER_2: // Notifications sent by 'Slider'
            switch(NCode)
            {
            case WM_NOTIFICATION_CLICKED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
            case WM_NOTIFICATION_VALUE_CHANGED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_2); //��û�����
                Input1_data1[INPUT_channel].Aux6MixerGain = SLIDER_GetValue(hItem); //���滬��ֵ
                WM_InvalidateRect(pMsg->hWin,&Rect_3[2]); //��Ч����ֵ����ˢ����ʾֵ
                break;
                // USER START (Optionally insert additional code for further notification handling)
                // USER END
            }
            break;
            // USER START (Optionally insert additional code for further Ids)
            // USER END
        }
        break;

    case WM_PAINT:  //����
        _ShowSlidervalue(); //��ʾ����ֵ
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
*       CreateFour_Child
*/

WM_HWIN CreateFour_Child(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/