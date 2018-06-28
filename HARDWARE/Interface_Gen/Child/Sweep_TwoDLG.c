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
#define ID_WINDOW_0 (GUI_ID_USER + 0x0D)
#define ID_SLIDER_0 (GUI_ID_USER + 0x16)
#define ID_CHECKBOX_0 (GUI_ID_USER + 0x17)
#define ID_CHECKBOX_1 (GUI_ID_USER + 0x1F)
#define ID_CHECKBOX_2 (GUI_ID_USER + 0x20)
#define ID_CHECKBOX_3 (GUI_ID_USER + 0x21)
#define ID_CHECKBOX_4 (GUI_ID_USER + 0x22)
#define ID_CHECKBOX_5 (GUI_ID_USER + 0x23)
#define ID_CHECKBOX_6 (GUI_ID_USER + 0x24)
#define ID_CHECKBOX_7 (GUI_ID_USER + 0x25)
#define ID_TEXT_0 (GUI_ID_USER + 0x26)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
//���ﶨ�廬����ʾ���ַ�������ʾ��ֵ����
char SLIDER_String[][16]=
{
	"WNoise_Gain:",
	"SweepFreq_Gain:",
	"Pulse:"
};
// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Sweep_Two", ID_WINDOW_0, 0, 0, 285, 240, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "Slider", ID_SLIDER_0, 20, 36, 253, 39, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux1", ID_CHECKBOX_0, 20, 95, 117, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux2", ID_CHECKBOX_1, 160, 95, 117, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux3", ID_CHECKBOX_2, 20, 130, 121, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux4", ID_CHECKBOX_3, 160, 130, 118, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux5", ID_CHECKBOX_4, 20, 165, 122, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux6", ID_CHECKBOX_5, 160, 165, 118, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux7", ID_CHECKBOX_6, 20, 200, 120, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Aux8", ID_CHECKBOX_7, 160, 200, 120, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Sweepfreq_gain", ID_TEXT_0, 20, 10, 125, 20, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

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
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Aux1'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "Aux1MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux2'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
    CHECKBOX_SetText(hItem, "Aux2MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux3'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_2);
    CHECKBOX_SetText(hItem, "Aux3MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux4'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_3);
    CHECKBOX_SetText(hItem, "Aux4MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux5'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_4);
    CHECKBOX_SetText(hItem, "Aux5MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux6'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_5);
    CHECKBOX_SetText(hItem, "Aux6MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux7'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_6);
    CHECKBOX_SetText(hItem, "Aux7MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Aux8'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_7);
    CHECKBOX_SetText(hItem, "Aux8MixerSw");
    CHECKBOX_SetFont(hItem, GUI_FONT_16B_1);
    //
    // Initialization of 'Sweepfreq_gain'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
	if(Gen_channel == 0)
	{
		TEXT_SetText(hItem, SLIDER_String[0]);
	}
	else if(Gen_channel == 3)
	{
		TEXT_SetText(hItem, SLIDER_String[1]);
	}
	else
	{
		TEXT_SetText(hItem, SLIDER_String[2]);
	}
    TEXT_SetFont(hItem, GUI_FONT_16B_1);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_SLIDER_0: // Notifications sent by 'Slider'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_0: // Notifications sent by 'Aux1'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_1: // Notifications sent by 'Aux2'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_2: // Notifications sent by 'Aux3'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_3: // Notifications sent by 'Aux4'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_4: // Notifications sent by 'Aux5'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_5: // Notifications sent by 'Aux6'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_6: // Notifications sent by 'Aux7'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_7: // Notifications sent by 'Aux8'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
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
*       CreateSweep_Two
*/

WM_HWIN CreateSweep_Two(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/