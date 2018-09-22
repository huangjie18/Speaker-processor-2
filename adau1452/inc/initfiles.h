/******************** (C) COPYRIGHT 2010 Analog Devices Inc ***********************
* File Name          : InitFiles.h
* Author             : Wilfrido Sierra
* Date First Issued  : 08/19/2010
* Description        : functions for initialization of EVAL-ADAU1442DZ
********************************************************************************
* History:
*******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INITFILES_H
#define __INITFILES_H

//#include "stm32f10x_lib.h"
#include "stm32f10x.h"
#include "stm32f10x_i2c.h"
/* Private define ------------------------------------------------------------*/
#define I2C1_SLAVE_ADDRESS7    0x70
#define ClockSpeed            100000
//#define GPIO_PINA_ALL_USED    ((u16)0x1FFF) 	// pins 0-12 without test pins
/* function declaration ------------------------------------------------------*/
void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void I2C1_Config(void);
/* ---------------------------------------------------------------------------*/

#endif
