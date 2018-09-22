/*
 * File:           VOL_ModesIC_1.h
 *
 * Created:        Saturday, December 23, 2017 5:21:15 PM
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




ADI_REG_TYPE VOL_0[8] = {0x00, 0x0ff, 0xe4, 0xb3,0x00,0x00,0x1b,0x4d};

void VOL_download(){
SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, 0x001E, 8, VOL_0);			/* SWGainOptADAU145XAlg2target */
}
