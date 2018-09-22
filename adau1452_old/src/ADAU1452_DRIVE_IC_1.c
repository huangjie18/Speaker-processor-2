#include"ADAU1452_DRIVE_IC_1.h"


void default_download_IC_1() {
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOFT_RESET_IC_1_ADDR, REG_SOFT_RESET_IC_1_BYTE, R0_SOFT_RESET_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOFT_RESET_IC_1_ADDR, REG_SOFT_RESET_IC_1_BYTE, R1_SOFT_RESET_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R2_RESET_DELAY_IC_1_SIZE, R2_RESET_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_HIBERNATE_IC_1_ADDR, REG_HIBERNATE_IC_1_BYTE, R3_HIBERNATE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_HIBERNATE_IC_1_ADDR, REG_HIBERNATE_IC_1_BYTE, R4_HIBERNATE_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R5_HIBERNATE_DELAY_IC_1_SIZE, R5_HIBERNATE_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_KILL_CORE_IC_1_ADDR, REG_KILL_CORE_IC_1_BYTE, R6_KILL_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_KILL_CORE_IC_1_ADDR, REG_KILL_CORE_IC_1_BYTE, R7_KILL_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_ENABLE_IC_1_ADDR, REG_PLL_ENABLE_IC_1_BYTE, R8_PLL_ENABLE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL0_IC_1_ADDR, REG_PLL_CTRL0_IC_1_BYTE, R9_PLL_CTRL0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CTRL1_IC_1_ADDR, REG_PLL_CTRL1_IC_1_BYTE, R10_PLL_CTRL1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_CLK_SRC_IC_1_ADDR, REG_PLL_CLK_SRC_IC_1_BYTE, R11_PLL_CLK_SRC_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MCLK_OUT_IC_1_ADDR, REG_MCLK_OUT_IC_1_BYTE, R12_MCLK_OUT_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_PLL_ENABLE_IC_1_ADDR, REG_PLL_ENABLE_IC_1_BYTE, R13_PLL_ENABLE_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R14_PLL_LOCK_DELAY_IC_1_SIZE, R14_PLL_LOCK_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_POWER_ENABLE0_IC_1_ADDR, REG_POWER_ENABLE0_IC_1_BYTE, R15_POWER_ENABLE0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_POWER_ENABLE1_IC_1_ADDR, REG_POWER_ENABLE1_IC_1_BYTE, R16_POWER_ENABLE1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP5_MODE_IC_1_ADDR, REG_MP5_MODE_IC_1_BYTE, R17_MP5_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP6_MODE_IC_1_ADDR, REG_MP6_MODE_IC_1_BYTE, R18_MP6_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_MP7_MODE_IC_1_ADDR, REG_MP7_MODE_IC_1_BYTE, R19_MP7_MODE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ASRC_INPUT0_IC_1_ADDR, REG_ASRC_INPUT0_IC_1_BYTE, R20_ASRC_INPUT0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_ASRC_OUT_RATE0_IC_1_ADDR, REG_ASRC_OUT_RATE0_IC_1_BYTE, R21_ASRC_OUT_RATE0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE0_IC_1_ADDR, REG_SOUT_SOURCE0_IC_1_BYTE, R22_SOUT_SOURCE0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE1_IC_1_ADDR, REG_SOUT_SOURCE1_IC_1_BYTE, R23_SOUT_SOURCE1_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE2_IC_1_ADDR, REG_SOUT_SOURCE2_IC_1_BYTE, R24_SOUT_SOURCE2_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE3_IC_1_ADDR, REG_SOUT_SOURCE3_IC_1_BYTE, R25_SOUT_SOURCE3_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE4_IC_1_ADDR, REG_SOUT_SOURCE4_IC_1_BYTE, R26_SOUT_SOURCE4_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE5_IC_1_ADDR, REG_SOUT_SOURCE5_IC_1_BYTE, R27_SOUT_SOURCE5_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE6_IC_1_ADDR, REG_SOUT_SOURCE6_IC_1_BYTE, R28_SOUT_SOURCE6_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE7_IC_1_ADDR, REG_SOUT_SOURCE7_IC_1_BYTE, R29_SOUT_SOURCE7_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE8_IC_1_ADDR, REG_SOUT_SOURCE8_IC_1_BYTE, R30_SOUT_SOURCE8_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE9_IC_1_ADDR, REG_SOUT_SOURCE9_IC_1_BYTE, R31_SOUT_SOURCE9_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE10_IC_1_ADDR, REG_SOUT_SOURCE10_IC_1_BYTE, R32_SOUT_SOURCE10_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE11_IC_1_ADDR, REG_SOUT_SOURCE11_IC_1_BYTE, R33_SOUT_SOURCE11_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE12_IC_1_ADDR, REG_SOUT_SOURCE12_IC_1_BYTE, R34_SOUT_SOURCE12_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE13_IC_1_ADDR, REG_SOUT_SOURCE13_IC_1_BYTE, R35_SOUT_SOURCE13_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE14_IC_1_ADDR, REG_SOUT_SOURCE14_IC_1_BYTE, R36_SOUT_SOURCE14_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE15_IC_1_ADDR, REG_SOUT_SOURCE15_IC_1_BYTE, R37_SOUT_SOURCE15_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE16_IC_1_ADDR, REG_SOUT_SOURCE16_IC_1_BYTE, R38_SOUT_SOURCE16_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE17_IC_1_ADDR, REG_SOUT_SOURCE17_IC_1_BYTE, R39_SOUT_SOURCE17_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE18_IC_1_ADDR, REG_SOUT_SOURCE18_IC_1_BYTE, R40_SOUT_SOURCE18_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE19_IC_1_ADDR, REG_SOUT_SOURCE19_IC_1_BYTE, R41_SOUT_SOURCE19_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE20_IC_1_ADDR, REG_SOUT_SOURCE20_IC_1_BYTE, R42_SOUT_SOURCE20_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE21_IC_1_ADDR, REG_SOUT_SOURCE21_IC_1_BYTE, R43_SOUT_SOURCE21_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE22_IC_1_ADDR, REG_SOUT_SOURCE22_IC_1_BYTE, R44_SOUT_SOURCE22_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SOUT_SOURCE23_IC_1_ADDR, REG_SOUT_SOURCE23_IC_1_BYTE, R45_SOUT_SOURCE23_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_0_0_IC_1_ADDR, REG_SERIAL_BYTE_0_0_IC_1_BYTE, R46_SERIAL_BYTE_0_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_1_0_IC_1_ADDR, REG_SERIAL_BYTE_1_0_IC_1_BYTE, R47_SERIAL_BYTE_1_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_2_0_IC_1_ADDR, REG_SERIAL_BYTE_2_0_IC_1_BYTE, R48_SERIAL_BYTE_2_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_3_0_IC_1_ADDR, REG_SERIAL_BYTE_3_0_IC_1_BYTE, R49_SERIAL_BYTE_3_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_4_0_IC_1_ADDR, REG_SERIAL_BYTE_4_0_IC_1_BYTE, R50_SERIAL_BYTE_4_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_5_0_IC_1_ADDR, REG_SERIAL_BYTE_5_0_IC_1_BYTE, R51_SERIAL_BYTE_5_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_6_0_IC_1_ADDR, REG_SERIAL_BYTE_6_0_IC_1_BYTE, R52_SERIAL_BYTE_6_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_SERIAL_BYTE_7_0_IC_1_ADDR, REG_SERIAL_BYTE_7_0_IC_1_BYTE, R53_SERIAL_BYTE_7_0_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK_CONST( DEVICE_ADDR_IC_1, PROGRAM_ADDR_IC_1, PROGRAM_SIZE_IC_1, Program_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK_CONST( DEVICE_ADDR_IC_1, PARAM_ADDR_IC_1, PARAM_SIZE_IC_1, Param_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK_CONST( DEVICE_ADDR_IC_1, DM1_DATA_ADDR_IC_1, DM1_DATA_SIZE_IC_1, DM1_DATA_Data_IC_1 );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_KILL_CORE_IC_1_ADDR, REG_KILL_CORE_IC_1_BYTE, R57_KILL_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_ADDRESS_IC_1_ADDR, REG_START_ADDRESS_IC_1_BYTE, R58_START_ADDRESS_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_PULSE_IC_1_ADDR, REG_START_PULSE_IC_1_BYTE, R59_START_PULSE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_CORE_IC_1_ADDR, REG_START_CORE_IC_1_BYTE, R60_START_CORE_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_START_CORE_IC_1_ADDR, REG_START_CORE_IC_1_BYTE, R61_START_CORE_IC_1_Default );
	SIGMA_WRITE_DELAY( DEVICE_ADDR_IC_1, R62_START_DELAY_IC_1_SIZE, R62_START_DELAY_IC_1_Default );
	SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, REG_HIBERNATE_IC_1_ADDR, REG_HIBERNATE_IC_1_BYTE, R63_HIBERNATE_IC_1_Default );
}