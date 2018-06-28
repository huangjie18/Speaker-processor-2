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
#define ID_LISTBOX_0 (GUI_ID_USER + 0x01)
#define Esc 2

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
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Pulse", ID_WINDOW_0, 0, 0, 400, 240, 0, 0x0, 0 },
  { LISTBOX_CreateIndirect, "Listbox", ID_LISTBOX_0, 0, 0, 114, 240, 0, 0x0, 0 },
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
    // Initialization of 'Listbox'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0);
    LISTBOX_AddString(hItem, "SET_1");
    LISTBOX_AddString(hItem, "SET_2");
    LISTBOX_AddString(hItem, "Pulse_Esc");
    LISTBOX_SetFont(hItem, GUI_FONT_20_1);
  
    Gen_data.hChild = CreatePulse_Child();
    WM_AttachWindowAt(Gen_data.hChild, pMsg->hWin, 115, 0); //�Ѵ��ڼӵ��ø�������
    WM_SetFocus(hItem); //���þ۽�Ϊ�б���
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_LISTBOX_0: // Notifications sent by 'Listbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
	    Gen_data.Sel = LISTBOX_GetSel(pMsg->hWinSrc); //���ѡ���
		if(Gen_data.Sel == 0)
		{
			if (WM_IsWindow(Gen_data.hChild)) //������Ƿ���Ч
			{
				GUI_EndDialog(Gen_data.hChild, 1); //ɾ����һ������
			}
			Gen_data.hChild = CreatePulse_Child(); //�������ڣ���һ������
			WM_AttachWindowAt(Gen_data.hChild, pMsg->hWin, 115, 0); //�Ѵ��ڼӵ��ø�������
			WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //�۽����б���
		}
		else if(Gen_data.Sel == 1)
		{
			if (WM_IsWindow(Gen_data.hChild)) //������Ƿ���Ч
			{
				GUI_EndDialog(Gen_data.hChild, 1); //ɾ����һ������
			}
			Gen_data.hChild = CreateSweep_Two(); //�������ڣ���һ������
			WM_AttachWindowAt(Gen_data.hChild, pMsg->hWin, 115, 0); //�Ѵ��ڼӵ��ø�������
			WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //�۽����б���
		}
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
  
   /*********************************�Զ�����Ϣ*********************************************/
    //�˳���
    case MSG_KEY_ESC:
        GUI_SendKeyMsg(GUI_KEY_ESCAPE, 1);  //ESC
        break;

    //CONTROL��ת
    case MSG_KNOB_CONTROL_LEFT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                        ID_LISTBOX_0))) //�жϾ۽��Ƿ����б���
        {
            GUI_SendKeyMsg(GUI_KEY_DOWN, 1); //listѡ�������ƶ�
        }
        else
        {
            GUI_SendKeyMsg(GUI_KEY_TAB, 1);     //��һ���۽���
        }
        break;

    //CONTROL��ת
    case MSG_KNOB_CONTROL_RIGHT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                        ID_LISTBOX_0))) //�жϾ۽��Ƿ����б���
        {
            GUI_SendKeyMsg(GUI_KEY_UP, 1);  //listѡ�������ƶ�
        }
        else
        {
            GUI_SendKeyMsg(GUI_KEY_BACKTAB, 1); //��һ���۽�
        }
        break;

    //CONTROL����
    case MSG_KEY_CONTROL:
        if(!WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //�����б���
        {
            GUI_SendKeyMsg(GUI_KEY_SPACE, 1);   //�л� CHECKBOX �ؼ���ѡ��״̬��
        }
        else
        {
            GUI_SendKeyMsg(GUI_KEY_ENTER, 1);   //ȷ����Ϣ
        }
        break;

    //��ת
    case MSG_KNOB_OUT_LEFT:
		if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //���۽��Ƿ���ѡ���
		{
			//����۽����б���������Ը���Ϣ
		}
		else if(Gen_data.Sel == list_1)
		{
			GUI_SendKeyMsg(GUI_KEY_RIGHT,1); //��������
		}
        break;


    //��ת
    case MSG_KNOB_OUT_RIGHT:
        if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0))) //���۽��Ƿ���ѡ���
		{
			//����۽����б���������Ը���Ϣ
		}
		else if(Gen_data.Sel == list_1) //��ѡ���б�1ʱ
		{
			GUI_SendKeyMsg(GUI_KEY_LEFT,1); //��������
		}
		
        break;

    //INPUT
    case MSG_KEY_INPUT:
        INPUT_channel = 0;  //����ͨ���۽�λ�ñ�־
        GUI_EndDialog(pMsg->hWin, 0); //����������
        hWin_now = CreateINPUT_CHANNEL(); //��ʾINPUT�ӽ���
        break;

    //OUT
    case MSG_KEY_OUTPUT:
        OUTPUT_channel = 0;
        GUI_EndDialog(pMsg->hWin, 0);    //������ǰҳ��
        hWin_now = CreateOut_face();     //���OUT�ӽ���
        break;
	
	//SYS
	case MSG_KEY_SYSTEM:
		GUI_EndDialog(pMsg->hWin,0);
		hWin_now = CreateSystem();
		break;
/************************************END******************************************/

    //��Ϣ����
    case WM_KEY:
        switch (((WM_KEY_INFO*)(pMsg->Data.p))->Key) //��ù��ڰ�����Ϣ��ֵ
        {
        case GUI_KEY_ESCAPE:
            if(WM_HasFocus(WM_GetDialogItem(pMsg->hWin,
                                            ID_LISTBOX_0)))//������ڵľ۽��Ƿ���listbox��
            {
                GUI_EndDialog(pMsg->hWin, 0); //�رյ�ǰ����
                hWin_now = CreateGen_Out();  //Gen_Out����
            }
            else
            {
                WM_SetFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)); //�۽����б���
                LISTBOX_SetSel(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0),
                               Gen_data.Sel); //�����б�����ѡ��Ŀ
            }
            break;

        case GUI_KEY_ENTER:
            if(Gen_data.Sel != Esc && WM_HasFocus(WM_GetDialogItem(pMsg->hWin, ID_LISTBOX_0)))
            {
                WM_SetFocus(WM_GetFirstChild(Gen_data.hChild)); //�����ӽ���ĵ�һ���ؼ���
            }
            else if (Gen_data.Sel == Esc) //�˳�
            {
                Gen_data.Sel = 0;
                GUI_EndDialog(pMsg->hWin, 0);
                hWin_now = CreateGen_Out();  //��һ�����
            }
            break;
        }
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
*       CreatePulse
*/

WM_HWIN CreatePulse(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/