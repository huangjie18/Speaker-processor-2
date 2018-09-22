#include "data.h"
#include  "DIALOG.h"
#include "ak4612.h"	
#include "algorithm.h"
/*****************************************************************************
***
***此文件用来处理数据
*****************************************************************************/
//定义关于各个页面需要的变量
//数据结构体指针
/*输入界面*/
Input_First_data *  In_first;    //输入界面1数据
Input_Second_data * Data_p[8]; 	 //输入界面2数据
Input_Third_data * In_Third[8];  //输入界面3数据
Input_Four_data* In_Four[8];     //输入界面4数据
Input_Five_data* In_Five[8];	 //输入界面5数据

/*输出界面*/
Output_First_data *Out_first;        //输出界面1数据
Output_Second_Data *Out_Second[8];   //输出界面2数据
Output_Third_Data *Out_Third[8];     //输出界面3数据
Output_Four_data *Out_Four[8];       //输出界面4数据

/*GEN_OUT界面*/
Gen_First_Data *Gen_first;      //GEN_OUT界面1数据
Gen_Second_Data *Gen_second;    //GEN_OUT界面2数据
Gen_Third_Data	*Gen_third;		//GEN_OUT界面3数据
Gen_Four_Data	*Gen_four[2];	//GEN_OUT界面4数据
Gen_Five_Data	*Gen_five;		//GEN_OUT界面5数据

/*MODE 界面*/
Mode_First_Data	*Mode_first;	//MODE界面1数据

/*SYSTEM 界面*/
System_First_Data *System_first; //SYS界面1数据
System_Second_Data* Sys_Second;  //SYS界面2数据

/*TIME 界面*/
Time_First_Data *Time_first;     //TIME界面1数据

/*METER 界面*/
Meter_First_Data *Meter_first;   //METER界面数据


/*RTA 界面*/
RTA_First_Data	*RTA_first;      //RTA界面数据
//定义函数指针
typedef struct 
{
	void (*eq_param)(unsigned int,double,unsigned int, unsigned int,double,double,unsigned char );  //参量均衡函数
	void (*eq_hight)(unsigned int,double,unsigned int, unsigned int,double,double,unsigned char );  //高棚架函数
	void (*eq_low)(unsigned int,double,unsigned int, unsigned int,double,double,unsigned char );	 //低棚架函数
}eq_transfer;

static eq_transfer eq_shelf =
{
	parametric_EQ_calculation,  //具体赋值
	high_shelf,
	low_shelf,
};
//申请动态内存
int g_interface_data(void)
{
	u8 i;
	
	/*INPUT*/
	//输入界面1
	In_first = (Input_First_data *)mymalloc(0,sizeof(Input_First_data));
	if(In_first == NULL) //如果申请不成功，会错误
		return 0;
	
	//输入界面2
	for (i = 0; i<8; i++)
	{
		Data_p[i] = (Input_Second_data *)mymalloc(0,sizeof(Input_Second_data)); //申请动态内存
		if(Data_p[i] == NULL) //如果申请不成功，会错误
			return 0;
	}
	
	//输入界面3
	for (i = 0; i<8; i++)
	{
		In_Third[i] = (Input_Third_data *)mymalloc(0,sizeof(Input_Third_data));
		if(In_Third[i] == NULL)
		{
			return 0;
		}
	}
	
	//输入界面4
	for (i = 0; i<8; i++)
	{
		In_Four[i] = (Input_Four_data *)mymalloc(0,sizeof(Input_Four_data));
		if(In_Four[i] == NULL)
		{
			return 0;
		}
	}
	
	//输入界面5
	for (i = 0; i<8; i++)
	{
		In_Five[i] = (Input_Five_data *)mymalloc(0,sizeof(Input_Five_data));
		if(In_Five[i] == NULL)
		{
			return 0;
		}
	}
	
	/*OUTPUT*/
	//输出界面1
	Out_first = (Output_First_data *)mymalloc(0,sizeof(Output_First_data));
	if(Out_first == NULL)
	{
		return 0;
	}
	
	//输出界面2
	for (i = 0; i<8; i++)
	{
		Out_Second[i] = (Output_Second_Data *)mymalloc(0,sizeof(Output_Second_Data));
		if(Out_Second[i] == NULL)
		{
			return 0;
		}
	}
	
	//输出界面3
	for(i = 0; i<8; i++)
	{
		Out_Third[i] = (Output_Third_Data *)mymalloc(0,sizeof(Output_Third_Data));
		if(Out_Third[i] == NULL)
		{
			return 0;
		}
	}
	
	//输出界面4
	for(i = 0; i<8; i++)
	{
		Out_Four[i] = (Output_Four_data *)mymalloc(0,sizeof(Output_Four_data));
		if(Out_Four[i] == NULL)
		{
			return 0;
		}
	}
	
	
	/*GEN_OUT1界面*/
	Gen_first = (Gen_First_Data *)mymalloc(0,sizeof(Gen_First_Data));
	if(Gen_first == NULL)
	{
		return 0;
	}
	
	/*GEN_OUT2界面*/
	Gen_second = (Gen_Second_Data *)mymalloc(0,sizeof(Gen_Second_Data));
	if(Gen_second == NULL)
	{
		return 0;
	}
	
	/*GEN_OUT3界面*/
	Gen_third = (Gen_Third_Data *)mymalloc(0,sizeof(Gen_Third_Data));
	if(Gen_third == NULL)
	{
		return 0;
	}
	
	/*GEN_OUT4界面*/
	for(i = 0; i<2; i++)
	{
		Gen_four[i] = (Gen_Four_Data *)mymalloc(0,sizeof(Gen_Four_Data));
		if(Gen_four[i] == NULL)
		{
			return 0;
		}
	}
	
	/* GEN_OUT5 界面*/
	Gen_five = (Gen_Five_Data *)mymalloc(0,sizeof(Gen_Five_Data));
	if(Gen_five == NULL)
	{
		return 0;
	}
	
	//MODE界面
	Mode_first = (Mode_First_Data *)mymalloc(0,sizeof(Mode_First_Data));
	if(Mode_first == NULL)
	{
		return 0;
	}
	
	//SYS界面
	System_first = (System_First_Data *)mymalloc(0,sizeof(System_First_Data));
	if(System_first == NULL)
	{
		return 0;
	}
	
	//SYS2界面
	Sys_Second = (System_Second_Data *)mymalloc(0,sizeof(System_Second_Data));
	if(Sys_Second == NULL)
	{
		return 0;
	}
	
	//TIME界面
	Time_first = (Time_First_Data *)mymalloc(0,sizeof(Time_First_Data));
	if(Time_first == NULL)
	{
		return 0;  //申请内存失败
	}
	
	/*METER界面*/
	Meter_first = (Meter_First_Data *)mymalloc(0,sizeof(Meter_First_Data));
	if(Meter_first == NULL)
	{
		return 0;
	}
	
	
	/*RTA界面*/
	RTA_first = (RTA_First_Data *)mymalloc(0,sizeof(RTA_First_Data));
	if(RTA_first == NULL)
	{
		return 0;
	}
	
	//都成功申请内存
	return 1;
	
}

//EEPROM数据初始化
void g_data_init(void)
{
	//读取EEPROM中的数据来进行动态变量的赋值
	//没有保存在EEPROM中的数据则在各自的文件中初始化
}

/*
*******************************************************************************************
* 函 数 名: Data_mute_transfer
* 功能说明: 静音数据传输
* 形 参: 输入或输出标志位 , 通道号，开关
* 返 回 值: 无
*******************************************************************************************
*/

void Data_mute_transfer(u8 flag,u8 channel,u8 sw)
{
	//判断输入还是输出
	if(flag == input_flag)
	{
		//输入
		switch(channel)
		{
			//通道1
			case 0:
				if(sw == MUTE)
				{
					mute(IN1_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(IN1_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			//通道2
			case 1:
				if(sw == MUTE)
				{
					mute(IN2_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(IN2_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			//通道3
			case 2:
				if(sw == MUTE)
				{
					mute(IN3_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(IN3_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			//通道4
			case 3:
				if(sw == MUTE)
				{
					mute(IN4_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(IN4_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			//通道5
			case 4:
				if(sw == MUTE)
				{
					mute(IN5_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(IN5_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			//通道6
			case 5:
				if(sw == MUTE)
				{
					mute(IN6_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(IN6_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			//通道COA_L
			case 6:
				if(sw == MUTE)
				{
					mute(COAX_L_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(COAX_L_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			//通道COA_R
			case 7:
				if(sw == MUTE)
				{
					mute(COAX_R_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(COAX_R_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
		}
	}
	else
	{
		//输出
		switch(channel)
		{
			case 0:
				if(sw == MUTE)
				{
					mute(OUT1_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT1_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 1:
				if(sw == MUTE)
				{
					mute(OUT2_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT2_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 2:
				if(sw == MUTE)
				{
					mute(OUT3_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT3_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 3:
				if(sw == MUTE)
				{
					mute(OUT4_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT4_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 4:
				if(sw == MUTE)
				{
					mute(OUT5_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT5_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 5:
				if(sw == MUTE)
				{
					mute(OUT6_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT6_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 6:
				if(sw == MUTE)
				{
					mute(OUT7_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT7_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
			
			case 7:
				if(sw == MUTE)
				{
					mute(OUT8_MUTE_ADDR,MUTE);//输入静音
				}
				else
				{
					mute(OUT8_MUTE_ADDR,UMUTE);//输入静音
				}
				break;
		}
	}
}


/*
*******************************************************************************************
* 函 数 名: Data_invert_transfer
* 功能说明: 反相数据传输
* 形 参: 输入或输出标志位 , 通道号，开关
* 返 回 值: 无
*******************************************************************************************
*/
void Data_invert_transfer(u8 flag,u8 channel,u8 sw)
{
	//判断输入还是输出
	if(flag == input_flag)
	{
		switch(channel)
		{
			//通道1
			case 0:
				if(sw == INVERT)
				{
					invert(IN1_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(IN1_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 1:
				if(sw == INVERT)
				{
					invert(IN2_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(IN2_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 2:
				if(sw == INVERT)
				{
					invert(IN3_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(IN3_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 3:
				if(sw == INVERT)
				{
					invert(IN4_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(IN4_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 4:
				if(sw == INVERT)
				{
					invert(IN5_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(IN5_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 5:
				if(sw == INVERT)
				{
					invert(IN6_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(IN6_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 6:
				if(sw == INVERT)
				{
					invert(COAX_L_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(COAX_L_INVERT_ADDR,UINVERT);
				}
				break;
				
			case 7:
				if(sw == INVERT)
				{
					invert(COAX_R_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(COAX_R_INVERT_ADDR,UINVERT);
				}
				break;
		}
	}
	else
	{
		switch(channel)
		{
			//通道1
			case 0:
				if(sw == INVERT)
				{
					invert(OUT1_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT1_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 1:
				if(sw == INVERT)
				{
					invert(OUT2_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT2_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 2:
				if(sw == INVERT)
				{
					invert(OUT3_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT3_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 3:
				if(sw == INVERT)
				{
					invert(OUT4_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT4_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 4:
				if(sw == INVERT)
				{
					invert(OUT5_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT5_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 5:
				if(sw == INVERT)
				{
					invert(OUT6_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT6_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 6:
				if(sw == INVERT)
				{
					invert(OUT7_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT7_INVERT_ADDR,UINVERT);
				}
				break;
			
			case 7:
				if(sw == INVERT)
				{
					invert(OUT8_INVERT_ADDR,INVERT);//输入反相
				}
				else
				{
					invert(OUT8_INVERT_ADDR,UINVERT);
				}
				break;
		}
	}
}
/*
*******************************************************************************************
* 函 数 名: Data_input_gate_RMS
* 功能说明: 噪声门数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_gate_RMS(u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			noise_gate_RMS_TC_ms(IN1_NOISE_TC_ADDR,millisecond);
			break;
		
		case 1:
			noise_gate_RMS_TC_ms(IN2_NOISE_TC_ADDR,millisecond);
			break;
		
		case 2:
			noise_gate_RMS_TC_ms(IN3_NOISE_TC_ADDR,millisecond);
			break;
		
		case 3:
			noise_gate_RMS_TC_ms(IN4_NOISE_TC_ADDR,millisecond);
			break;
		
		case 4:
			noise_gate_RMS_TC_ms(IN5_NOISE_TC_ADDR,millisecond);
			break;
		
		case 5:
			noise_gate_RMS_TC_ms(IN6_NOISE_TC_ADDR,millisecond);
			break;
		
		case 6:
			noise_gate_RMS_TC_ms(COAX_L_NOISE_TC_ADDR,millisecond);
			break;
		
		case 7:
			noise_gate_RMS_TC_ms(COAX_R_NOISE_TC_ADDR,millisecond);
			break;
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_gate_decay
* 功能说明: 噪声门数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_gate_decay(u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			noise_gate_decay_ms(IN1_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 1:
			noise_gate_decay_ms(IN2_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 2:
			noise_gate_decay_ms(IN3_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 3:
			noise_gate_decay_ms(IN4_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 4:
			noise_gate_decay_ms(IN5_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 5:
			noise_gate_decay_ms(IN6_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 6:
			noise_gate_decay_ms(COAX_L_NOISE_DECAY_ADDR,millisecond);
			break;
		
		case 7:
			noise_gate_decay_ms(COAX_R_NOISE_DECAY_ADDR,millisecond);
			break;
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_gate_thres
* 功能说明: 噪声门数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_gate_thres(u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			noise_gate_threshold(IN1_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 1:
			noise_gate_threshold(IN2_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 2:
			noise_gate_threshold(IN3_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 3:
			noise_gate_threshold(IN4_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 4:
			noise_gate_threshold(IN5_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 5:
			noise_gate_threshold(IN6_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 6:
			noise_gate_threshold(COAX_L_NOISE_GATE_ADDR,millisecond);
			break;
		
		case 7:
			noise_gate_threshold(COAX_R_NOISE_GATE_ADDR,millisecond);
			break;
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_gain
* 功能说明: 增益控制
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_gain(char Item,u16 param)
{
	switch(Item)
	{
		case slider_0:
			gain_control(IN1_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_1:
			gain_control(IN2_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_2:
			gain_control(IN3_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_3:
			gain_control(IN4_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_4:
//			gain_control(IN5_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_5:
//			gain_control(IN6_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_6:
			gain_control(COAX_L_GAIN_ADDR,-(param*0.04));
			break;
		
		case slider_7:
//			gain_control(COAX_R_GAIN_ADDR,-(param*0.04));
			break;
		
		default:
			break;
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_compressor_ATK
* 功能说明: 动态压缩启动时间数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_compressor_ATK(u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			compressor_RMS_TC_ms(IN1_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 1:
			compressor_RMS_TC_ms(IN2_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 2:
			compressor_RMS_TC_ms(IN3_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 3:
			compressor_RMS_TC_ms(IN4_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 4:
			compressor_RMS_TC_ms(IN5_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 5:
			compressor_RMS_TC_ms(IN6_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 6:
			compressor_RMS_TC_ms(COAX_L_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
		case 7:
			compressor_RMS_TC_ms(COAX_R_CMOPRESSOR_RMS_TC_ADDR,millisecond);//压缩器的启动时间
			break;
		
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_compressor_RELEASE
* 功能说明: 动态压缩释放时间数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_compressor_RELEASE (u8 channel,unsigned int millisecond,s16 atk_value)
{
	unsigned int release;  //作为RELEASE的中间值
	
	switch(millisecond)
	{
		case 0:
			release = atk_value * 2;
			break;
		
		case 1:
			release = atk_value * 4;
			break;
		
		case 2:
			release = atk_value * 6;
			break;
		
		case 3:
			release = atk_value * 8;
			break;
		
		case 4:
			release = atk_value * 12;
			break;
		
		case 5:
			release = atk_value * 16;
			break;
		
		case 6:
			release = atk_value * 24;
			break;
		
		case 7:
			release = atk_value * 32;
			break;
	}
	
	switch(channel)
	{
		case 0:
			compressor_decay_ms(IN1_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 1:
			compressor_decay_ms(IN2_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 2:
			compressor_decay_ms(IN3_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 3:
			compressor_decay_ms(IN4_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 4:
			compressor_decay_ms(IN5_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 5:
			compressor_decay_ms(IN6_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 6:
			compressor_decay_ms(COAX_L_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
		case 7:
			compressor_decay_ms(COAX_R_CMOPRESSOR_DECAY_ADDR,release);//压缩器的释放时间
			break;
		
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_compressor_HOLD
* 功能说明: 动态压缩释放时间数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_compressor_HOLD (u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			compressor_hold_ms(IN1_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 1:
			compressor_hold_ms(IN2_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 2:
			compressor_hold_ms(IN3_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 3:
			compressor_hold_ms(IN4_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 4:
			compressor_hold_ms(IN5_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 5:
			compressor_hold_ms(IN6_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 6:
			compressor_hold_ms(COAX_L_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
		case 7:
			compressor_hold_ms(COAX_R_CMOPRESSOR_HOLD_ADDR,millisecond);//压缩器的保持时间
			break;
		
	}
}
/*
*******************************************************************************************
* 函 数 名: Data_input_compressor_threshold_ratio
* 功能说明: 动态压缩阀值和压缩率的数据传输
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_compressor_threshold_ratio(u8 channel,s16 threshold,double ratio)
{
	switch(channel)
	{
		case 0:
			compressor_threshold_ratio(IN1_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 1:
			compressor_threshold_ratio(IN2_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 2:
			compressor_threshold_ratio(IN3_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 3:
			compressor_threshold_ratio(IN4_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 4:
			compressor_threshold_ratio(IN5_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 5:
			compressor_threshold_ratio(IN6_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 6:
			compressor_threshold_ratio(COAX_L_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
		
		case 7:
			compressor_threshold_ratio(COAX_R_CMOPRESSOR_THRESHOLD_RATIO_ADDR,threshold,ratio);//压缩器的阀值
			break;
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_eq_param
* 功能说明: 输入通道的eq的参数发送
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_eq_param(u8 channel,s16 band,double boost,unsigned int frequency,double Q,u8 type,u8 flag,u8 pass)
{

	void (*p)(unsigned int,double,unsigned int, unsigned int,double,double,unsigned char );  //定义一个函数指针
	u8 bypass;
	if(pass == 0)
	{
		bypass = UNBYPASS;
	}
	else
	{
		bypass = BYPASS;
	}
	
	if(type == 0)
	{
		p = eq_shelf.eq_param;  //关于参量均衡的函数
	}
	else if(type == 1)
	{
		p = eq_shelf.eq_hight;  //关于高棚架的函数
	}
	else if(type == 2)
	{
		p = eq_shelf.eq_low;   //关于低棚架的函数
	}
	//输入
	if(flag == input_flag)
	{
		switch(channel)
		{
			//输入通道1
			case 0:
				switch(band)
				{
					//频段1
					case 1:
						p(IN1_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(IN1_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(IN1_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(IN1_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(IN1_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(IN1_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(IN1_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
	//			p(IN1_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q);
				break;
			
			case 1:
				switch(band)
				{
					//频段1
					case 1:
						p(IN2_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(IN2_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(IN2_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(IN2_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(IN2_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(IN2_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(IN2_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 2:
				switch(band)
				{
					//频段1
					case 1:
						p(IN3_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(IN3_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(IN3_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(IN3_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(IN3_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(IN3_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(IN3_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 3:
				switch(band)
				{
					//频段1
					case 1:
						p(IN4_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(IN4_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(IN4_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(IN4_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(IN4_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(IN4_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(IN4_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 4:
				switch(band)
				{
					//频段1
					case 1:
						p(IN5_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(IN5_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(IN5_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(IN5_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(IN5_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(IN5_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(IN5_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;

			case 5:
				switch(band)
				{
					//频段1
					case 1:
						p(IN6_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(IN6_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(IN6_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(IN6_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(IN6_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(IN6_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(IN6_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 6:
				switch(band)
				{
					//频段1
					case 1:
						p(COAX_L_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(COAX_L_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(COAX_L_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(COAX_L_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(COAX_L_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(COAX_L_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(COAX_L_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 7:
				switch(band)
				{
					//频段1
					case 1:
						p(COAX_R_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					//频段2
					case 2:
						p(COAX_R_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 3:
						p(COAX_R_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 4:
						p(COAX_R_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 5:
						p(COAX_R_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 6:
						p(COAX_R_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
					
					case 7:
						p(COAX_R_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
		}
	}
	//输出
	else if(flag == output_flag)
	{
		switch(channel)
		{
			//输入通道1
			case 0:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT1_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT1_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT1_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT1_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT1_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT1_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT1_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
	//			p(IN1_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q);
				break;
			
			case 1:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT2_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT2_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT2_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT2_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT2_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT2_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT2_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 2:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT3_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT3_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT3_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT3_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT3_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT3_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT3_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 3:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT4_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT4_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT4_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT4_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT4_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT4_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT4_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 4:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT5_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT5_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT5_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT5_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT5_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT5_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT5_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;

			case 5:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT6_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT6_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT6_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT6_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT6_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT6_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT6_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 6:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT7_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT7_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT7_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT7_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT7_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT7_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT7_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
			
			case 7:
				switch(band)
				{
					//频段1
					case 1:
						p(OUT8_PEQ_POINT0_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					//频段2                                                      
					case 2:                                                    
						p(OUT8_PEQ_POINT1_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 3:                                                    
						p(OUT8_PEQ_POINT2_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 4:                                                    
						p(OUT8_PEQ_POINT3_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 5:                                                    
						p(OUT8_PEQ_POINT4_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 6:                                                    
						p(OUT8_PEQ_POINT5_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;                                                 
					                                                           
					case 7:                                                    
						p(OUT8_PEQ_POINT6_ADDR,boost,frequency, SAMPLE_RATE,0,Q,bypass);
						break;
				}
				break;
		
		}
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_input_mixer_gain
* 功能说明: 输入通道的mix参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_mixer_gain(u8 channel,u8 item,double gain)
{
	gain = -gain;
	switch(channel)
	{
		//输入通道1
		case 0:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(IN1_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(IN1_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(IN1_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(IN1_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(IN1_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(IN1_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(IN1_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(IN1_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
		
		case 1:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(IN2_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(IN2_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(IN2_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(IN2_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(IN2_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(IN2_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(IN2_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(IN2_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
		
		case 2:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(IN3_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(IN3_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(IN3_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(IN3_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(IN3_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(IN3_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(IN3_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(IN3_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
		
		case 3:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(IN4_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(IN4_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(IN4_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(IN4_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(IN4_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(IN4_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(IN4_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(IN4_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
		
		case 4:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(IN5_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(IN5_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(IN5_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(IN5_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(IN5_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(IN5_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(IN5_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(IN5_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
		
		case 5:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(IN6_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(IN6_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(IN6_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(IN6_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(IN6_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(IN6_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(IN6_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(IN6_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
		
		case 6:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(COAX_L_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(COAX_L_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(COAX_L_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(COAX_L_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(COAX_L_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(COAX_L_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(COAX_L_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(COAX_L_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
			
		case 7:
			switch(item)
			{
				case aux1_slider:
					aux_mixer_gain(COAX_R_Aux1MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux2_slider:
					aux_mixer_gain(COAX_R_Aux2MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux3_slider:
					aux_mixer_gain(COAX_R_Aux3MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux4_slider:
					aux_mixer_gain(COAX_R_Aux4MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux5_slider:
					aux_mixer_gain(COAX_R_Aux5MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux6_slider:
					aux_mixer_gain(COAX_R_Aux6MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux7_slider:
					aux_mixer_gain(COAX_R_Aux7MixerGain_ADDR,gain);//总线派送量
					break;
				
				case aux8_slider:
					aux_mixer_gain(COAX_R_Aux8MixerGain_ADDR,gain);//总线派送量
					break;
				
			}
			break;
	}
	
}

/*
*******************************************************************************************
* 函 数 名: Data_input_mixer_sw
* 功能说明: 输入通道的mix参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_input_mixer_sw(u8 channel, u8 item,unsigned char sw)
{
	switch(channel)
	{
		//通道1
		case 0:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(IN1_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(IN1_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(IN1_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(IN1_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(IN1_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(IN1_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(IN1_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(IN1_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
			
		case 1:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(IN2_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(IN2_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(IN2_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(IN2_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(IN2_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(IN2_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(IN2_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(IN2_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
			
		case 2:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(IN3_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(IN3_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(IN3_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(IN3_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(IN3_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(IN3_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(IN3_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(IN3_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
			
		case 3:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(IN4_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(IN4_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(IN4_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(IN4_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(IN4_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(IN4_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(IN4_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(IN4_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
			
		case 4:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(IN5_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(IN5_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(IN5_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(IN5_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(IN5_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(IN5_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(IN5_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(IN5_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
		
		case 5:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(IN6_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(IN6_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(IN6_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(IN6_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(IN6_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(IN6_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(IN6_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(IN6_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
			
		case 6:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(COAX_L_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
			
		case 7:
			switch(item)
			{
				case aux1_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux1MixerGainSw_ADDR,sw);
					break;
				
				case aux2_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux2MixerGainSw_ADDR,sw);
					break;
				
				case aux3_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux3MixerGainSw_ADDR,sw);
					break;
				
				case aux4_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux4MixerGainSw_ADDR,sw);
					break;
				
				case aux5_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux5MixerGainSw_ADDR,sw);
					break;
				
				case aux6_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux6MixerGainSw_ADDR,sw);
					break;
				
				case aux7_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux7MixerGainSw_ADDR,sw);
					break;
				
				case aux8_checkbox:
					aux_mixer_gain_sw(COAX_R_Aux8MixerGainSw_ADDR,sw);
					break;
				
			}
			break;
	}
}


/*
*******************************************************************************************
* 函 数 名: Data_output_delay
* 功能说明: 输出通道的delay参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_output_delay(u8 channel,unsigned int delay_data)
{
	switch(channel)
	{
		case 0:
			delay(OUT1_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 1:
			delay(OUT2_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 2:
			delay(OUT3_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 3:
			delay(OUT4_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 4:
			delay(OUT5_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 5:
			delay(OUT6_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 6:
			delay(OUT7_DELAY_ADDR,delay_data);//输出延时
			break;
		
		case 7:
			delay(OUT8_DELAY_ADDR,delay_data);//输出延时
			break;
		
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_output_limiter_rmstc
* 功能说明: 输出通道的limiter参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_output_limiter_rmstc(u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			limit_RMS_TC_ms(OUT1_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 1:
			limit_RMS_TC_ms(OUT2_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 2:
			limit_RMS_TC_ms(OUT3_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 3:
			limit_RMS_TC_ms(OUT4_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 4:
			limit_RMS_TC_ms(OUT5_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 5:
			limit_RMS_TC_ms(OUT6_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 6:
			limit_RMS_TC_ms(OUT7_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 7:
			limit_RMS_TC_ms(OUT8_LIMIT_RMS_TC_ADDR,millisecond);//限幅器启动时间
			break;
		
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_output_limiter_thres
* 功能说明: 输出通道的limiter参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_output_limiter_thres(u8 channel,unsigned int millisecond)
{
	switch(channel)
	{
		case 0:
			limit_threshold(OUT1_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 1:
			limit_threshold(OUT2_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 2:
			limit_threshold(OUT3_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 3:
			limit_threshold(OUT4_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 4:
			limit_threshold(OUT5_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 5:
			limit_threshold(OUT6_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 6:
			limit_threshold(OUT7_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
		
		case 7:
			limit_threshold(OUT8_LIMIT_THRESHOLD_ADDR,millisecond);//限幅器启动时间
			break;
	}
}
/*
*******************************************************************************************
* 函 数 名: Data_output_limiter_decay
* 功能说明: 输出通道的limiter参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/

void Data_output_limiter_decay (u8 channel,unsigned int millisecond,s16 atk_value)
{
	unsigned int release;  //作为decay的中间值
	
	switch(millisecond)
	{
		case 0:
			release = atk_value * 2;
			break;
		
		case 1:
			release = atk_value * 4;
			break;
		
		case 2:
			release = atk_value * 6;
			break;
		
		case 3:
			release = atk_value * 8;
			break;
		
		case 4:
			release = atk_value * 12;
			break;
		
		case 5:
			release = atk_value * 16;
			break;
		
		case 6:
			release = atk_value * 24;
			break;
		
		case 7:
			release = atk_value * 32;
			break;
	}
	
	switch(channel)
	{
		case 0:
			limit_decay_ms(OUT1_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 1:
			limit_decay_ms(OUT2_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 2:
			limit_decay_ms(OUT3_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 3:
			limit_decay_ms(OUT4_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 4:
			limit_decay_ms(OUT5_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 5:
			limit_decay_ms(OUT6_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 6:
			limit_decay_ms(OUT7_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		case 7:
			limit_decay_ms(OUT8_LIMIT_DECAY_ADDR,release);	//限幅器释放时间
			break;
		
		
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_output_pass
* 功能说明: 输出通道的limiter参数
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_output_pass(u8 channel,unsigned int frequency,double gain,u8 type,u8 high_low,u8 pass,u8 in_or_out)
{
	unsigned int addr;
	unsigned int addr2;
	u8 bypass;
	void (*p)(unsigned int ,unsigned int, unsigned int,double,unsigned char);
	void (*filter)(unsigned int ,unsigned char );
	filter = filter_switch;
	//获得对应函数
	if(high_low == 0)
	{
		if(type == BESSEL_12_TYPE)
		{
			p = Bessel_12_dB_oct_lowpass;
		}
		else if(type == BUTTER_12_TYPE)
		{
			p = Butterworth_12_dB_oct_lowpass;
		}
		else if(type == BESSEL_24_TYPE)
		{
			p = Bessel_24_dB_oct_lowpass;
		}
		else if(type == BUTTER_24_TYPE)
		{
			p = Butterworth_24_dB_oct_lowpass;
		}
	}
	else if(high_low == 1)
	{
		if(type == BESSEL_12_TYPE)
		{
			p = Bessel_12_dB_oct_highpass;
		}
		else if(type == BUTTER_12_TYPE)
		{
			p = Butterworth_12_dB_oct_highpass;
		}
		else if(type == BESSEL_24_TYPE)
		{
			p = Bessel_24_dB_oct_highpass;
		}
		else if(type == BUTTER_24_TYPE)
		{
			p = Butterworth_24_dB_oct_highpass;
		}
	}
	if(pass == 0)
	{
		bypass = UNBYPASS;
	}
	else
	{
		bypass = BYPASS;
	}
	switch(channel)
	{
		//通道1
		case 0:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN1_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN1_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN1_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关	
					}
					
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT1_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT1_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT1_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关	
					}
					
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN1_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN1_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN1_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT1_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT1_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT1_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
					
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道2
		case 1:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN2_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN2_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN2_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT2_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT2_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT2_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN2_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN2_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN2_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT2_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT2_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT2_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道3
		case 2:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN3_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN3_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN3_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT3_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT3_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT3_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN3_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN3_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN3_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT3_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT3_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT3_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道4
		case 3:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN4_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN4_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN4_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT4_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT4_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT4_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN4_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN4_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN4_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT4_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT4_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT4_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道5
		case 4:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN5_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN5_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN5_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT5_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT5_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT5_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN5_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN5_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN5_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT5_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT5_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT5_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道6
		case 5:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN6_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN6_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN6_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT6_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT6_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT6_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = IN6_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = IN6_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = IN6_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT6_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT6_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT6_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道7
		case 6:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = COAX_L_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = COAX_L_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = COAX_L_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT7_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT7_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT7_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = COAX_L_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = COAX_L_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = COAX_L_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT7_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT7_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT7_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
		
		//通道8
		case 7:
			if(high_low == 0)  //低通
			{
				if(in_or_out == input_flag)
				{
					addr2 = COAX_R_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = COAX_R_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = COAX_R_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT8_LOWPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT8_LOWPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT8_LOWPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				
			}
			else
			{
				if(in_or_out == input_flag)
				{
					addr2 = COAX_R_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = COAX_R_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = COAX_R_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
				else if(in_or_out == output_flag)
				{
					addr2 = OUT8_HIGHPASS_SW;
					if((type == BESSEL_12_TYPE)||(type == BUTTER_12_TYPE))
					{
						addr = OUT8_HIGHPASS_12_ADDR;
						filter_switch(addr2,FILTER_12dB );//12dB和24dB斜率切换开关
					}
					else if((type == BESSEL_24_TYPE)||(type == BUTTER_24_TYPE))
					{
						addr = OUT8_HIGHPASS_24_ADDR;
						filter_switch(addr2,FILTER_24dB );//12dB和24dB斜率切换开关
					}
				}
			}
			p(addr,frequency, SAMPLE_RATE,gain,bypass);
			break;
	}
}

/*
*******************************************************************************************
* 函 数 名: Data_gen_enable
* 功能说明: 发生器的使能数据发送
* 形 参: 
* 返 回 值: 无
*******************************************************************************************
*/
void Data_gen_enable(u8 Item,u8 sta)
{
	switch(Item)
	{
		case First_Item:
			white_noise_enable(WHITE_NOISE_ENABLE_ADDR,sta);//白噪声发生器使能
			break;
		
		case Second_Item:
			sine_enable(SINE_ENABLE_ADDR,sta);//正弦波发生器使能
			break;
		
		case Third_Item:
			square_enable(SQUARE_ENABLE_ADDR,sta);//方波发生器使能
			break;
		
		case Four_Item:
			sweepfreq_enable(SweepFreq_ENABLE_ADDR,sta);//扫频使能
			break;
		
		case Five_Item:
			pulse_enable(PULSE_ENABLE_ADDR,sta);//脉冲发生器使能
			break;
		
		case Six_Item:
			white_noise_enable(PINK_NOISE_ENABLE_ADDR,sta);//粉噪声发生器使能
			break;
	}
}
