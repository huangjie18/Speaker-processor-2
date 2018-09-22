/*
 * File:           SWGainOpt_ModesIC_1.h
 *
 * Created:        Saturday, December 23, 2017 11:23:10 AM
 * Description:    ADAU1452 DRIVE Sequence data definitions.
 *
 * This software is distributed in the hope that it will be useful,
 * but is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This software may only be used to program products purchased from
 * Analog Devices for incorporation by you into audio products that
 * are intended for resale to audio product end users. This software
 * may not be distributed whole or in any part to third parties.
 *
 * Copyright (c) 2017 Analog Devices, Inc. All rights reserved.
 */

#include "algorithm.h"

//ADI_REG_TYPE SWGAINOPT_0[4] = {0x00, 0x80, 0x00, 0x00};//1±¶£¬me 250mvp
ADI_REG_TYPE SWGAINOPT_0[4] = {0x01, 0x00, 0x00, 0x00};//1±¶£¬adi  500mvp

//ADI_REG_TYPE SWGAINOPT_0[4] = {0x00, 0x0c, 0xcc, 0xcc};//0.1±¶£¬me 25mvp
//ADI_REG_TYPE SWGAINOPT_0[4] = {0x00, 0x19, 0x99, 0x9a};//0.1±¶£¬adi  50mvp

void SWGAINOPT_download(){
SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, 0x001E, 4, param_hex);			/* SWGainOptADAU145XAlg2alpha */
	
//SIGMA_READ_REGISTER_BLOCK( DEVICE_ADDR_IC_1, 0x001F, 10, debug_value);			/* SWGainOptADAU145XAlg2alpha */	
}
