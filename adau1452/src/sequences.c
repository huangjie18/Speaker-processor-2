/******************** (C) COPYRIGHT 2010 Analog Devices Inc ********************
* File Name          : switch_modes.c
* Author             : Wilfrido Sierra
* Date First Issued  : 08/23/2010
* Description        : ADAT Modes
****************************F****************************************************
* History:
* 08/23/2010: V0.1
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, ANALOG DEVICES, INC. SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
#include "1761Demo_seq.h"//manual
//#include "Tones_Modes.h" 
//#include "External Input_Modes.h"
//#include "White Noise_Modes.h"
//#include "sequences.h"

 /* Private variables ---------------------------------------------------------*/
u8 flag = 0x00;

// /* Private functions ---------------------------------------------------------*/
//void tone_download (void);
//void ext_in_download (void);
//void white_noise_download (void);

/*******************************************************************************
* Function Name		: SWITCH5
* Description		: Sets the triggered ports for Switch 5
* Input				: None
* Output			: None
* Return			: None
*******************************************************************************/
void Modes(void)
{
	//Switch 1 MODE 0 (Tones)
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0x00))
	{
		tone_download ();
		//flag  = 0x01;
	}

	//Switch 2 MODE 1 (External Input Mode)
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0x00))
	{
		ext_in_download ();
		//flag  = 0x01;
	}

	//Switch 3 MODE 2 (White Noise Mode)
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0x00))
	{
		white_noise_download ();
		//flag  = 0x01;
	}
}
