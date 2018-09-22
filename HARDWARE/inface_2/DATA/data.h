#ifndef __DATA_H
#define __DATA_H

#include  "interface.h"


//����
extern Input_First_data *In_first;     //�������1����
extern Input_Second_data *Data_p[8];   //�������2����
extern Input_Third_data * In_Third[8]; //�������3����
extern Input_Four_data* In_Four[8];    //�������4����
extern Input_Five_data* In_Five[8];	 //�������5����

//���
extern Output_First_data *Out_first;   	   //�������1����
extern Output_Second_Data *Out_Second[8];  //�������2����
extern Output_Third_Data *Out_Third[8];    //�������3����
extern Output_Four_data *Out_Four[8];      //�������4����

//GEN_OUT
extern Gen_First_Data *Gen_first;      //GEN_OUT����1����
extern Gen_Second_Data *Gen_second;    //GEN_OUT����2����
extern Gen_Third_Data	*Gen_third;	   //GEN_OUT����3����
extern Gen_Four_Data	*Gen_four[2];  //GEN_OUT����4����
extern Gen_Five_Data	*Gen_five;	   //GEN_OUT����5����

//MODE
extern Mode_First_Data	*Mode_first;	//MODE����1����

//SYS
extern System_First_Data *System_first; //SYS����1����
extern System_Second_Data* Sys_Second;  //SYS����2����

//TIME
extern Time_First_Data *Time_first;  			//TIME����1����

//METER
extern Meter_First_Data *Meter_first;   //METER��������

//RTA
extern RTA_First_Data	*RTA_first;      //RTA��������

int g_interface_data(void);        //���붯̬�ڴ�

//���ݴ���
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

//���
void Data_output_delay(u8 channel,unsigned int delay_data);
void Data_output_limiter_rmstc(u8 channel,unsigned int millisecond);
void Data_output_limiter_thres(u8 channel,unsigned int millisecond);
void Data_output_limiter_decay (u8 channel,unsigned int millisecond,s16 atk_value);
void Data_output_pass(u8 channel,unsigned int frequency,double gain,u8 type,u8 high_low,u8 pass,u8 in_or_out);

//������
void Data_gen_enable(u8 Item,u8 sta);

#endif

