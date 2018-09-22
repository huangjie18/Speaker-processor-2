#ifndef __DATA_H
#define __DATA_H

#include  "interface.h"


//输入
extern Input_First_data *In_first;     //输入界面1变量
extern Input_Second_data *Data_p[8];   //输入界面2变量
extern Input_Third_data * In_Third[8]; //输入界面3变量
extern Input_Four_data* In_Four[8];    //输入界面4变量
extern Input_Five_data* In_Five[8];	 //输入界面5数据

//输出
extern Output_First_data *Out_first;   	   //输出界面1变量
extern Output_Second_Data *Out_Second[8];  //输出界面2变量
extern Output_Third_Data *Out_Third[8];    //输出界面3变量
extern Output_Four_data *Out_Four[8];      //输出界面4变量

//GEN_OUT
extern Gen_First_Data *Gen_first;      //GEN_OUT界面1数据
extern Gen_Second_Data *Gen_second;    //GEN_OUT界面2数据
extern Gen_Third_Data	*Gen_third;	   //GEN_OUT界面3数据
extern Gen_Four_Data	*Gen_four[2];  //GEN_OUT界面4数据
extern Gen_Five_Data	*Gen_five;	   //GEN_OUT界面5数据

//MODE
extern Mode_First_Data	*Mode_first;	//MODE界面1数据

//SYS
extern System_First_Data *System_first; //SYS界面1数据
extern System_Second_Data* Sys_Second;  //SYS界面2数据

//TIME
extern Time_First_Data *Time_first;  			//TIME界面1数据

//METER
extern Meter_First_Data *Meter_first;   //METER界面数据

//RTA
extern RTA_First_Data	*RTA_first;      //RTA界面数据

int g_interface_data(void);        //申请动态内存

//数据传输
void Data_input_gate_RMS(u8 channel,unsigned int millisecond);
void Data_input_gate_decay(u8 channel,unsigned int millisecond);
void Data_input_gate_thres(u8 channel,unsigned int millisecond);
void Data_mute_transfer(u8 flag,u8 channel,u8 sw);
void Data_input_gain(char Item,u16 param);
void Data_invert_transfer(u8 flag,u8 channel,u8 sw);
void Data_input_compressor_ATK(u8 channel,unsigned int millisecond);
void Data_input_compressor_RELEASE (u8 channel,unsigned int millisecond,s16 atk_value);
void Data_input_compressor_HOLD (u8 channel,unsigned int millisecond);
void Data_input_compressor_threshold_ratio(u8 channel,s16 threshold,double ratio);
void Data_input_eq_param(u8 channel,s16 band,double boost,unsigned int frequency,double Q,u8 type,u8 flag,u8 pass);
void Data_input_mixer_gain(u8 channel,u8 item,double gain);
void Data_input_mixer_sw(u8 channel, u8 item,unsigned char sw);

//输出
void Data_output_delay(u8 channel,unsigned int delay_data);
void Data_output_limiter_rmstc(u8 channel,unsigned int millisecond);
void Data_output_limiter_thres(u8 channel,unsigned int millisecond);
void Data_output_limiter_decay (u8 channel,unsigned int millisecond,s16 atk_value);
void Data_output_pass(u8 channel,unsigned int frequency,double gain,u8 type,u8 high_low,u8 pass,u8 in_or_out);

//发生器
void Data_gen_enable(u8 Item,u8 sta);

#endif

