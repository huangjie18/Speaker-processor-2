#include "algorithm.h"




/********************************************************************************
*******************
** ��������: To824
** ��������: �Ѹ���ת��Ϊ8.24��ʽ
** �������: param_dec(������ֵ)
             param_hex(8.24��ֵ)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void To824(float param_dec, unsigned char* param_hex) 
{ 	
   long param224; 
   long param231; 

    param224 = param_dec * (1 << 24); //multiply decimal number by 2^24 
    param231 = param224 + (1 << 31); //convert to positive binary 
    param_hex[3]=(unsigned char)param231; //get byte 3 (LSBs) of parameter value 
    param_hex[2]=(unsigned char)(param231>>8); //get byte 2 of parameter value 
    param_hex[1]=(unsigned char)(param231>>16); //get byte 1 of parameter value 
    param_hex[0]=(unsigned char)(param231>>24); //get byte 0 (MSBs) of parameter value 
    param_hex[0] = param_hex[0] ^ 0x80; //invert sign bit to get correct sign 
} 




void To32(int param_dec, unsigned char* param_hex) 
{
   param_hex[0] = (param_dec >> 24) & 0xFF;
   param_hex[1] = (param_dec >> 16) & 0xFF;
   param_hex[2] = (param_dec >> 8) & 0xFF;
   param_hex[3] = param_dec & 0xFF;	  
}





/********************************************************************************
*******************
** ��������: mute
** ��������: ��������
** �������: module_addr(ģ���ַ)
             sw(MUTE,UMUTE)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void mute(unsigned int module_addr,unsigned char sw )
{
	    unsigned char  param_hex[8];
	    To824(sw, param_hex) ;
      SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr, 4, param_hex);			/* SWGainOptADAU145XAlg2target */		 
	
	    param_hex[0]=0X00;
	    param_hex[1]=0XFF;
	    param_hex[2]=0X77;
	    param_hex[3]=0X9C;	
	    param_hex[4]=0X00;
	    param_hex[5]=0X00;
	    param_hex[6]=0X88;
	    param_hex[7]=0X64;		
	    SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr+1, 8, param_hex);			/* SWGainOptADAU145XAlg2target */	

}







/********************************************************************************
*******************
** ��������: gain_control
** ��������: �������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void gain_control(unsigned int module_addr,double gain)
{
      unsigned char  param_hex[8];	
	    To824(pow(10,(gain/20)), param_hex) ;
      SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr, 4, param_hex);			/* SWGainOptADAU145XAlg2target */		

	    param_hex[0]=0X00;
	    param_hex[1]=0XFF;
	    param_hex[2]=0XE4;
	    param_hex[3]=0XB3;
	    param_hex[4]=0X00;
	    param_hex[5]=0X00;
	    param_hex[6]=0X1B;
	    param_hex[7]=0X4D;		
      SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr+1, 8, param_hex);			/* SWGainOptADAU145XAlg2target */		  
	
}







/********************************************************************************
*******************
** ��������: invert
** ��������: �������
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             safeload_parameter(INVERT,UINVERT)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void invert(unsigned int  safeload_parameter_addr,unsigned int  safeload_parameter)
{
	unsigned char  param_hex[4];
	unsigned char safeload_parameter_num=1;
	if(safeload_parameter==0)
	{
	param_hex[0]=0x00;
	param_hex[1]=0x00;
	param_hex[2]=0x00;
	param_hex[3]=0x00;		  
	}
else if(safeload_parameter==1)
{
	param_hex[0]=0x00;
	param_hex[1]=0x00;
	param_hex[2]=0x00;
	param_hex[3]=0x01;			  
}

	 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	


	param_hex[0]=0x00;
	param_hex[1]=0x00;
	param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	param_hex[3]=(u8)safeload_parameter_addr;
	SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	



	param_hex[0]=0x00;
	param_hex[1]=0x00;
	param_hex[2]=(u8)((safeload_parameter_num)>>8);
	param_hex[3]=(u8)safeload_parameter_num;
	 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
}







/********************************************************************************
*******************
** ��������:    parametric_EQ_calculation
** ��������:    ��������   
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                boost(min:-60db,max:30db,step:0.1db)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)    
                gainlinear(min:-10db,max:10db,step:0.1db)  
                Q(min:0.05,max:20,step:0.01)    
                bypass(0:unbypass,1:bypass)
** �������:    ��
** ȫ�ֱ���:    ��
** ����ģ��:   To824() ,SIGMA_WRITE_REGISTER_BLOCK()
** �� ��: 
** ��ע: 
********************************************************************************
*******************/
void parametric_EQ_calculation(unsigned int safeload_parameter_addr,double boost,unsigned int frequency, unsigned int Fs,double gainlinear,double Q,unsigned char bypass)
{

double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha,Ax;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];	
unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	

	
	if(!bypass)
	{
      Ax=pow(10,(boost/40));
      omega = 2 * PI * frequency / Fs;	
      sn = sin(omega);
      cs = cos(omega);
      alpha = sn / (2 * (Q));	
	
	    a0 = 1 + (alpha / Ax);
	    A1 = -( 2 * cs) / a0;
	    A2 = (1 - (alpha / Ax)) / a0;
	    gainlinear=(pow(10,(gainlinear/20))/a0);	
	
	    A1=-A1;
	    A2=-A2;
	
	    B0 = (1 + (alpha * Ax)) * gainlinear;
	    B1 = -( 2 * cs) * gainlinear;
	    B2 = (1 - (alpha * Ax)) * gainlinear;				

			To824(B2, B2_param_hex) ;
			To824(B1, B1_param_hex) ;		
		  To824(B0, B0_param_hex) ;	
			To824(A2, A2_param_hex) ;		
			To824(A1, A1_param_hex) ;

SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	param_hex[0]=0x00;
	param_hex[1]=0x00;
	param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	param_hex[3]=(u8)safeload_parameter_addr;
	SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;


	param_hex[0]=0x00;
	param_hex[1]=0x00;
	param_hex[2]=(u8)((safeload_parameter_num)>>8);
	param_hex[3]=(u8)safeload_parameter_num;
  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
  }
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 
		}	
}






/********************************************************************************
*******************
** ��������:    low_shelf
** ��������:    �����
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                boost(min:-60db,max:30db,step:0.1db)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE��    
                gainlinear(min:-10db,max:10db,step:0.1db)  
                Q(min:0.05,max:20,step:0.01)    
                bypass(0:unbypass,1:bypass)
** �������:    ��
** ȫ�ֱ���:    ��
** ����ģ��:   To824() ,SIGMA_WRITE_REGISTER_BLOCK()
** �� ��: 
** ��ע: 
********************************************************************************
*******************/
void low_shelf(unsigned int safeload_parameter_addr,double boost,unsigned int frequency, unsigned int Fs,double gainlinear,double slope,unsigned char bypass)
{

double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha,Ax;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];	
unsigned char param_hex[4];		
unsigned char safeload_parameter_num=5;			
	
     if(!bypass)
		 {
          Ax=pow(10,(boost/40));
          omega = 2 * PI * frequency / Fs;	
          sn = sin(omega);
          cs = cos(omega);
          alpha = sn/2 * sqrt((Ax + 1/Ax)*(1/slope - 1) + 2);
	
          a0 = (Ax+1) + (Ax-1)*cs + 2*sqrt(Ax)*alpha;		
	        A1 = (-2*( (Ax-1) + (Ax+1)*cs ))/a0;
	        A2 = ((Ax+1) + (Ax-1)*cs - 2*sqrt(Ax)*alpha)/a0;
	        gainlinear=(pow(10,(gainlinear/20))/a0);	
	
          B0 = Ax*( (Ax+1) - (Ax-1)*cs + 2*sqrt(Ax)*alpha ) * gainlinear;
          B1 = 2*Ax*( (Ax-1) - (Ax+1)*cs ) * gainlinear;
          B2 = Ax*( (Ax+1) - (Ax-1)*cs - 2*sqrt(Ax)*alpha ) * gainlinear;	
          
	        A1=-A1;
	        A2=-A2;
          
			    To824(B2, B2_param_hex) ;
			    To824(B1, B1_param_hex) ;		
		      To824(B0, B0_param_hex) ;	
			    To824(A2, A2_param_hex) ;		
			    To824(A1, A1_param_hex) ;
          
          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
          
	        param_hex[0]=0x00;
	        param_hex[1]=0x00;
	        param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	        param_hex[3]=(u8)safeload_parameter_addr;
	        SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
          
	        param_hex[0]=0x00;
	        param_hex[1]=0x00;
	        param_hex[2]=(u8)((safeload_parameter_num)>>8);
	        param_hex[3]=(u8)safeload_parameter_num;
          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
				}
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 
		}			 
}         











/********************************************************************************
*******************
** ��������:    low_shelf
** ��������:    �����
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                boost(min:-60db,max:30db,step:0.1db)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs��SAMPLE_RATE ��   
                gainlinear(min:-10db,max:10db,step:0.1db)  
                Q(min:0.05,max:20,step:0.01)    
								bypass(0:unbypass,1:bypass)
** �������:    ��
** ȫ�ֱ���:    ��
** ����ģ��:   To824() ,SIGMA_WRITE_REGISTER_BLOCK()
** �� ��: 
** ��ע: 
********************************************************************************
*******************/
void high_shelf(unsigned int safeload_parameter_addr,double boost,unsigned int frequency, unsigned int Fs,double gainlinear,double slope,unsigned char bypass)
{

double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha,Ax;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];	
unsigned char param_hex[4];		
unsigned char safeload_parameter_num=5;		
	

	   if(!bypass)
		 {
            Ax=pow(10,(boost/40));
            omega = 2 * PI * frequency / Fs;	
            sn = sin(omega);
            cs = cos(omega);
            alpha = sn/2 * sqrt((Ax + 1/Ax)*(1/slope - 1) + 2);
	
            a0 = (Ax+1) - (Ax-1)*cs + 2*sqrt(Ax)*alpha;		
	          A1 = (2*( (Ax-1) - (Ax+1)*cs ))/a0;
	          A2 = ((Ax+1) - (Ax-1)*cs - 2*sqrt(Ax)*alpha)/a0;
	          gainlinear=(pow(10,(gainlinear/20))/a0);	
	
            B0 = Ax*( (Ax+1)+ (Ax-1)*cs + 2*sqrt(Ax)*alpha ) * gainlinear;
            B1 = -2*Ax*( (Ax-1) + (Ax+1)*cs ) * gainlinear;
            B2 = Ax*( (Ax+1) + (Ax-1)*cs - 2*sqrt(Ax)*alpha ) * gainlinear;	

	          A1=-A1;
	          A2=-A2;
            
			      To824(B2, B2_param_hex) ;
			      To824(B1, B1_param_hex) ;		
		        To824(B0, B0_param_hex) ;	
			      To824(A2, A2_param_hex) ;		
			      To824(A1, A1_param_hex) ;
            
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
            
	          param_hex[0]=0x00;
	          param_hex[1]=0x00;
	          param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	          param_hex[3]=(u8)safeload_parameter_addr;
	          SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
            
	          param_hex[0]=0x00;
	          param_hex[1]=0x00;
	          param_hex[2]=(u8)((safeload_parameter_num)>>8);
	          param_hex[3]=(u8)safeload_parameter_num;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;		
					}
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 
		}			 

				
}
















/********************************************************************************
*******************
** ��������: aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr��ģ���ַ��
             sw��OFF,ON��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}









/********************************************************************************
*******************
** ��������: aux_mixer_gain
** ��������: ����������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void aux_mixer_gain(unsigned int module_addr,double gain)
{
     gain_control(module_addr,gain) ;
}







/********************************************************************************
*******************
** ��������: delay
** ��������: ͨ����ʱ
** �������: module_addr��ģ���ַ��
             date��min:0ms,max:180ms,step:1ms��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: delay_s=(1/48000)*data
********************************************************************************
*******************/

void delay(unsigned int module_addr,unsigned int delay)
{
      unsigned char  param_hex[4];	
	    unsigned int temp=0;
	    temp=delay*48;
      param_hex[3]=(unsigned char)temp; //get byte 3 (LSBs) of parameter value 
      param_hex[2]=(unsigned char)(temp>>8); //get byte 2 of parameter value 
      param_hex[1]=(unsigned char)(temp>>16); //get byte 1 of parameter value 
      param_hex[0]=(unsigned char)(temp>>24); //get byte 0 (MSBs) of parameter value 
	    SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr, 4, param_hex);			/* SWGainOptADAU145XAlg2target */		
}









/********************************************************************************
*******************
** ��������: Butterworth_12_dB_oct_highpass
** ��������: ���������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
                gain(0)  
                bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Butterworth 12 dB/oct = One 2 nd order butterworth
********************************************************************************
*******************/
void Butterworth_12_dB_oct_highpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{
double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		 
unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	


	  if(!bypass)
		{
        omega = 2 * PI * frequency / Fs;
        sn = sin(omega);
        cs = cos(omega);
        alpha=sn/(2*(1/sqrt(2)));
        a0 = 1 + alpha;
        A1 = -( 2 * cs) / a0;
        A2 = (1 - alpha) / a0;
        B1=-(1+cs)/a0*(pow(10,(gain/20)));
        B0 = -B1 / 2;
        B2 = B0;
        A1=-A1;
	      A2=-A2;   
 



			To824(B2, B2_param_hex) ;
			To824(B1, B1_param_hex) ;		
		  To824(B0, B0_param_hex) ;	
			To824(A2, A2_param_hex) ;		
			To824(A1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
		}			
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 
		}

}





/********************************************************************************
*******************
** ��������: Butterworth_12_dB_oct_lowpass
** ��������: ���������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
                gain(0)  
                bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Butterworth 12 dB/oct = One 2 nd order butterworth
********************************************************************************
*******************/
void Butterworth_12_dB_oct_lowpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{
double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		 
unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	

	
	if(!bypass)
	{
        omega = 2 * PI * frequency / Fs;
        sn = sin(omega);
        cs = cos(omega);
        alpha=sn/(2*(1/sqrt(2)));
        a0 = 1 + alpha;
        A1 = -( 2 * cs) / a0;
        A2 = (1 - alpha) / a0;
        B1=(1-cs)/a0*(pow(10,(gain/20)));
        B0 = B1 / 2;
        B2 = B0;
        A1=-A1;
	      A2=-A2;
  



			To824(B2, B2_param_hex) ;
			To824(B1, B1_param_hex) ;		
		  To824(B0, B0_param_hex) ;	
			To824(A2, A2_param_hex) ;		
			To824(A1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
		}
else if(bypass==1)
{

			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 	 
}	

}









/********************************************************************************
*******************
** ��������: Bessel_12_dB_oct_highpass
** ��������: �������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
                gain(0)  
                bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Bessel 12 dB/oct = One 2 nd order Bessel
********************************************************************************
*******************/
void Bessel_12_dB_oct_highpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{
double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		 
unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	

	
	
	
	if(!bypass)
	{
               omega = 2 * PI * frequency / Fs;
               sn = sin(omega);
               cs = cos(omega);
               alpha = sn / (2 * (1 / sqrt(3)));
               a0 = 1 + alpha;
               A1 = -( 2 * cs) / a0;
               A2 = (1 - alpha) / a0;
               B1 = -( 1 + cs) / a0 *  (pow(10,(gain/20)));
               B0 = - B1 / 2;
               B2 = B0;
               A1=-A1;
	             A2=-A2; 



			To824(B2, B2_param_hex) ;
			To824(B1, B1_param_hex) ;		
		  To824(B0, B0_param_hex) ;	
			To824(A2, A2_param_hex) ;		
			To824(A1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;		
		}			
else if(bypass==1)
{

			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 	 
}	
}








/********************************************************************************
*******************
** ��������: Bessel_12_dB_oct_lowpass
** ��������: �������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
                gain(0)  
                bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Bessel 12 dB/oct = One 2 nd order Bessel
********************************************************************************
*******************/
void Bessel_12_dB_oct_lowpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{
double B0,B1,B2,A1,A2;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		 
unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	

   if(!bypass)
	 {
               omega = 2 * PI * frequency / Fs;
               sn = sin(omega);
               cs = cos(omega);
               alpha = sn / (2 * (1 / sqrt(3)));
               a0 = 1 + alpha;
               A1 = -( 2 * cs) / a0;
               A2 = (1 - alpha) / a0;
               B1 = (1 - cs) / a0 * (pow(10,(gain/20)));
               B0 = B1 / 2;
               B2 = B0;
               A1=-A1;
	           A2=-A2; 




			To824(B2, B2_param_hex) ;
			To824(B1, B1_param_hex) ;		
		  To824(B0, B0_param_hex) ;	
			To824(A2, A2_param_hex) ;		
			To824(A1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;		
		}

else if(bypass==1)
{

			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				 	 
}			

}
































/********************************************************************************
*******************
** ��������: Butterworth_24_dB_oct_lowpass
** ��������: ���������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
								type(0:LOWPASS,1:HIGHPASS)
                gain(0)  
								bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Butterworth 24 dB/oct = 2 Higher order butterworths
********************************************************************************
*******************/


void Butterworth_24_dB_oct_lowpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{
unsigned char i=1;
double orderindex=4;
double orderangle=0;
double B0_0,B1_0,B2_0,A1_0,A2_0,    B0_1,B1_1,B2_1,A1_1,A2_1;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		

unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	



  if(!bypass)
	{


//2 nd Filter: orderindex = 4, i = 1
           i=1;
           orderindex=4;

           omega = 2 * PI * frequency / Fs;
           sn = sin(omega);
           cs = cos(omega);
           orderangle = (PI / orderindex) * (i + 0.5);
           alpha = sn / (2 * (1 / (2 * sin(orderangle))));
           a0 = 1 + alpha;
           A1_0 = -( 2 * cs) / a0;
           A2_0 = (1 - alpha) / a0;
           B1_0 = (1 - cs) / a0 * (pow(10,(gain/20)));
           B0_0 = B1_0 / 2;
           B2_0 = B0_0 ;	  
           A1_0=-A1_0;
	         A2_0=-A2_0;   





//1 st Filter: orderindex = 4, i = 0
           i=0;
           orderindex=4;
           omega = 2 * PI * frequency / Fs;
           sn = sin(omega);
           cs = cos(omega);
           orderangle = (PI / orderindex) * (i + 0.5);
           alpha = sn / (2 * (1 / (2 * sin(orderangle))));
           a0 = 1 + alpha;
           A1_1 = -( 2 * cs) / a0;
           A2_1 = (1 - alpha) / a0;
           B1_1 = (1 - cs) / a0 * (pow(10,(gain/20)));
           B0_1 = B1_1 / 2;
           B2_1 = B0_1 ;	  
           A1_1=-A1_1;
	         A2_1=-A2_1;   





			To824(B2_0, B2_param_hex) ;
			To824(B1_0, B1_param_hex) ;		
		  To824(B0_0, B0_param_hex) ;	
			To824(A2_0, A2_param_hex) ;		
			To824(A1_0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(B2_1, B2_param_hex) ;
			To824(B1_1, B1_param_hex) ;		
		  To824(B0_1, B0_param_hex) ;	
			To824(A2_1, A2_param_hex) ;		
			To824(A1_1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
		}
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}	
}












/********************************************************************************
*******************
** ��������: Butterworth_24_dB_oct_highpass
** ��������: ���������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
								type(0:LOWPASS,1:HIGHPASS)
                gain(0)  
								bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Butterworth 24 dB/oct = 2 Higher order butterworths
********************************************************************************
*******************/
void Butterworth_24_dB_oct_highpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{
unsigned char i=1;
double orderindex=4;
double orderangle=0;
double B0_0,B1_0,B2_0,A1_0,A2_0,    B0_1,B1_1,B2_1,A1_1,A2_1;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		

unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	


       if(!bypass)
			 {
//2 nd Filter: orderindex = 4, i = 1
           i=1;
           orderindex=4;
           omega = 2 * PI * frequency / Fs;
           sn = sin(omega);
           cs = cos(omega);
           orderangle = (PI / orderindex) * (i + 0.5);
           alpha = sn / (2 * (1 / (2 * sin(orderangle))));
           a0 = 1 + alpha;
           A1_0 = -( 2 * cs) / a0;
           A2_0 = (1 - alpha) / a0;
           B1_0 = -(1 + cs) / a0 * (pow(10,(gain/20)));
           B0_0 = -B1_0 / 2;
           B2_0 = B0_0 ;			   
           A1_0=-A1_0;
	         A2_0=-A2_0; 

		   


//1 st Filter: orderindex = 4, i = 0
           i=0;
           orderindex=4;
           omega = 2 * PI * frequency / Fs;
           sn = sin(omega);
           cs = cos(omega);
           orderangle = (PI / orderindex) * (i + 0.5);
           alpha = sn / (2 * (1 / (2 * sin(orderangle))));
           a0 = 1 + alpha;
           A1_1 = -( 2 * cs) / a0;
           A2_1 = (1 - alpha) / a0;
           B1_1 = -(1 + cs) / a0 * (pow(10,(gain/20)));
           B0_1 = -B1_1 / 2;
           B2_1 = B0_1 ;			   
           A1_1=-A1_1;
	         A2_1=-A2_1; 



			To824(B2_0, B2_param_hex) ;
			To824(B1_0, B1_param_hex) ;		
		  To824(B0_0, B0_param_hex) ;	
			To824(A2_0, A2_param_hex) ;		
			To824(A1_0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(B2_1, B2_param_hex) ;
			To824(B1_1, B1_param_hex) ;		
		  To824(B0_1, B0_param_hex) ;	
			To824(A2_1, A2_param_hex) ;		
			To824(A1_1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
		}
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}			 
}






/********************************************************************************
*******************
** ��������: Bessel_24_dB_oct_lowpass
** ��������: �������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
								type(0:LOWPASS,1:HIGHPASS)
                gain(0)  
								bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Bessel 24 dB/oct = Two 2 nd order Besels
********************************************************************************
*******************/
void Bessel_24_dB_oct_lowpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{

double B0_0,B1_0,B2_0,A1_0,A2_0,    B0_1,B1_1,B2_1,A1_1,A2_1;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		

unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	



   if(!bypass)
	 {

               omega = 2 * PI * frequency / Fs;
               sn = sin(omega);
               cs = cos(omega);
               alpha = sn / (2 * (1 / sqrt(3)));
               a0 = 1 + alpha;
               A1_0 = -( 2 * cs) / a0;
               A2_0 = (1 - alpha) / a0;
               B1_0 = (1 - cs) / a0 * (pow(10,(gain/20)));
               B0_0 = B1_0 / 2;
               B2_0 = B0_0;
               A1_0=-A1_0;
	             A2_0=-A2_0; 


		           B1_1=B1_0;
               B0_1=B0_0 ;
               B2_1=B2_0 ;
               A1_1=A1_0;
	             A2_1=A2_0;

			To824(B2_0, B2_param_hex) ;
			To824(B1_0, B1_param_hex) ;		
		  To824(B0_0, B0_param_hex) ;	
			To824(A2_0, A2_param_hex) ;		
			To824(A1_0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(B2_1, B2_param_hex) ;
			To824(B1_1, B1_param_hex) ;		
		  To824(B0_1, B0_param_hex) ;	
			To824(A2_1, A2_param_hex) ;		
			To824(A1_1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;			
		}
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}	 
}

















/********************************************************************************
*******************
** ��������: Bessel_24_dB_oct_highpass
** ��������: �������˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
								type(0:LOWPASS,1:HIGHPASS)
                gain(0)  
								bypass(0:unbypass,1:bypass)
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Bessel 24 dB/oct = Two 2 nd order Besels
         �̶�gainΪ0
********************************************************************************
*******************/
void Bessel_24_dB_oct_highpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain,unsigned char bypass)
{

double B0_0,B1_0,B2_0,A1_0,A2_0,    B0_1,B1_1,B2_1,A1_1,A2_1;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		

unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	




       if(!bypass)
			 {
               omega = 2 * PI * frequency / Fs;
               sn = sin(omega);
               cs = cos(omega);
               alpha = sn / (2 * (1 / sqrt(3)));
               a0 = 1 + alpha;
               A1_0 = -( 2 * cs) / a0;
               A2_0 = (1 - alpha) / a0;
               B1_0 = -( 1 + cs) / a0 *  (pow(10,(gain/20)));
               B0_0 = - B1_0 / 2;
               B2_0 = B0_0;
               A1_0=-A1_0;
	             A2_0=-A2_0; 	  

		           B1_1=B1_0;
               B0_1=B0_0 ;
               B2_1=B2_0 ;
               A1_1=A1_0;
	             A2_1=A2_0;
		
		
			To824(B2_0, B2_param_hex) ;
			To824(B1_0, B1_param_hex) ;		
		  To824(B0_0, B0_param_hex) ;	
			To824(A2_0, A2_param_hex) ;		
			To824(A1_0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(B2_1, B2_param_hex) ;
			To824(B1_1, B1_param_hex) ;		
		  To824(B0_1, B0_param_hex) ;	
			To824(A2_1, A2_param_hex) ;		
			To824(A1_1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;		
		}			
		else if(bypass==1)
		{
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(0, B2_param_hex) ;
			To824(0, B1_param_hex) ;		
		  To824(1, B0_param_hex) ;	
			To824(0, A2_param_hex) ;		
			To824(0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}
		   
}











/********************************************************************************
*******************
** ��������: Linkwitz_Riley_24dB_oct_lowpass
** ��������: �ֿ���-�����˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
								type(0:LOWPASS,1:HIGHPASS)
                gain(0)  
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��:To824(); SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Linkwitz-Riley �C 24 dB/oct = 2 cascaded 2nd order butterworths (2 biquads)
********************************************************************************
*******************/
void Linkwitz_Riley_24dB_oct_lowpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain)
{
double B0_0,B1_0,B2_0,A1_0,A2_0,    B0_1,B1_1,B2_1,A1_1,A2_1;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		

unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	




        omega = 2 * PI * frequency / Fs;
        sn = sin(omega);
        cs = cos(omega);
        alpha=sn/(2*(1/sqrt(2)));
        a0 = 1 + alpha;
        A1_0 = -( 2 * cs) / a0;
        A2_0 = (1 - alpha) / a0;
        B1_0=(1-cs)/a0*(pow(10,(gain/20)));
        B0_0 = B1_0 / 2;
        B2_0 = B0_0;
        A1_0=-A1_0;
	      A2_0=-A2_0;

 
        B1_1=B1_0;
        B0_1=B0_0 ;
        B2_1=B2_0 ;
        A1_1=A1_0;
	      A2_1=A2_0;


			To824(B2_0, B2_param_hex) ;
			To824(B1_0, B1_param_hex) ;		
		  To824(B0_0, B0_param_hex) ;	
			To824(A2_0, A2_param_hex) ;		
			To824(A1_0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(B2_1, B2_param_hex) ;
			To824(B1_1, B1_param_hex) ;		
		  To824(B0_1, B0_param_hex) ;	
			To824(A2_1, A2_param_hex) ;		
			To824(A1_1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	



}












/********************************************************************************
*******************
** ��������: Linkwitz_Riley_24dB_oct_highpass
** ��������: �ֿ���-�����˲���
** �������:    safeload_parameter_addr(��ȫ����Ŀ���ַ)
                frequency(min:20Hz,max:20000Hz,step:1Hz) 
                Fs(SAMPLE_RATE)   
								type(0:LOWPASS,1:HIGHPASS)
                gain(0)  
                
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Linkwitz-Riley �C 24 dB/oct = 2 cascaded 2nd order butterworths (2 biquads)
********************************************************************************
*******************/
void Linkwitz_Riley_24dB_oct_highpass(unsigned int safeload_parameter_addr,unsigned int frequency, unsigned int Fs,double gain)
{
double B0_0,B1_0,B2_0,A1_0,A2_0,    B0_1,B1_1,B2_1,A1_1,A2_1;
double a0,omega,sn,cs,alpha;
unsigned char A1_param_hex[4];
unsigned char A2_param_hex[4];	
unsigned char B0_param_hex[4];	
unsigned char B1_param_hex[4];	
unsigned char B2_param_hex[4];		

unsigned char param_hex[4];	
unsigned char safeload_parameter_num=5;	




        omega = 2 * PI * frequency / Fs;
        sn = sin(omega);
        cs = cos(omega);
        alpha=sn/(2*(1/sqrt(2)));
        a0 = 1 + alpha;
        A1_0 = -( 2 * cs) / a0;
        A2_0 = (1 - alpha) / a0;
        B1_0=-(1+cs)/a0*(pow(10,(gain/20)));
        B0_0 = -B1_0 / 2;
        B2_0 = B0_0;
        A1_0=-A1_0;
	      A2_0=-A2_0;   

		    B1_1=B1_0;
        B0_1=B0_0 ;
        B2_1=B2_0 ;
        A1_1=A1_0;
	      A2_1=A2_0;

			To824(B2_0, B2_param_hex) ;
			To824(B1_0, B1_param_hex) ;		
		  To824(B0_0, B0_param_hex) ;	
			To824(A2_0, A2_param_hex) ;		
			To824(A1_0, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
									
			To824(B2_1, B2_param_hex) ;
			To824(B1_1, B1_param_hex) ;		
		  To824(B0_1, B0_param_hex) ;	
			To824(A2_1, A2_param_hex) ;		
			To824(A1_1, A1_param_hex) ;
	 	 	 	 
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, B2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, B1_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, B0_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, A2_param_hex ) ;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, A1_param_hex ) ;
 
	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_addr+5)>>8);
	    param_hex[3]=(u8)safeload_parameter_addr+5;
	    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;

	    param_hex[0]=0x00;
	    param_hex[1]=0x00;
	    param_hex[2]=(u8)((safeload_parameter_num)>>8);
	    param_hex[3]=(u8)safeload_parameter_num;
      SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	



}














/********************************************************************************
*******************
** ��������: RMS_convert_ms_to_dbpsecond
** ��������: msת��Ϊdbpsecond
** �������: millisecond
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** �� ��: 
** ��ע: Conversion formula:  TC(ms) = 20/(dbps *ln(10)) *10^3
********************************************************************************
*******************/
double RMS_convert_ms_to_dbpsecond(unsigned int millisecond)
{
	     double dbpsecond;
	     dbpsecond=(20/(millisecond/1000.0))/log(10);
	     return dbpsecond;
		   
}









/********************************************************************************
*******************
** ��������: compressor_RMS_TC_ms
** ��������: ��̬ѹ������ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��min:0,max:100ms,step:1��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: RMS dB/s= abs(1.0 - 10^(rms/10*fs)), where "rms" is the value entered in the block.		
********************************************************************************
*******************/				
void compressor_RMS_TC_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)
{
	  double register_value;
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=1;		
	
	         register_value=RMS_convert_ms_to_dbpsecond(millisecond);
	         register_value=1.0-pow(10,(register_value/(10*SAMPLE_RATE)));
           register_value=fabs(register_value);

	
	
	
	
	
       To824(register_value,param_hex)	;	
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;		   
			
			
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				
	
}






/********************************************************************************
*******************
** ��������: compressor_decay_ms
** ��������: ��̬ѹ���ͷ�ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��attack time*(2��4��6��8��12��16��24��32)��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Decay = dbperseconds /(96.0 * fs);		
********************************************************************************
*******************/							
void compressor_decay_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)
{
	  double register_value;
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=1;		
	
	  register_value=RMS_convert_ms_to_dbpsecond(millisecond);
	  register_value=register_value/(96*SAMPLE_RATE);
	
	
       To824(register_value,param_hex)	;	
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;		   
			
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;							
}











/********************************************************************************
*******************
** ��������: compressor_hold_ms
** ��������: ��̬ѹ������ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��min:0,max:200ms,step:1��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: hold=milliseconds*fs/1000;(here,fs=sample rate)				
********************************************************************************
*******************/								
void compressor_hold_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)
{
	  unsigned int register_value;
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=1;		
	
	  register_value=millisecond*SAMPLE_RATE/1000;
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
		
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
}










/********************************************************************************
*******************
** ��������: compressor_threshold_ratio
** ��������: ��̬ѹ����ֵ��ѹ����
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             threshold��min:-25dB,max:12dB,step:1dB��
             ratio��min:0,max:100,step:0.1��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: hold=milliseconds*fs/1000;(here,fs=sample rate)				
********************************************************************************
*******************/			
#define X_AXIS_MIN -135.0
#define X_AXIS_MAX 20.0
#define Y_AXIS_MIN -135.0
#define Y_AXIS_MAX 20.0
#define POINT 53//1~54
void compressor_threshold_ratio(unsigned int safeload_parameter_addr,double threshold,double ratio)
{
	  double x_step;
	  double input,output;
	  unsigned char point_num;
    double register_value[54];
    unsigned char param_hex_0[4];
    unsigned char param_hex_1[4];	
    unsigned char param_hex_2[4];	
    unsigned char param_hex_3[4];	
    unsigned char param_hex_4[4];		
    unsigned char i;
	
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=5;		
      x_step= 3;//  (X_AXIS_MAX-X_AXIS_MIN)/(POINT)	;  
	  

	  for(point_num=0;point_num<=POINT;point_num++)
	  {
	       input=X_AXIS_MIN+x_step*(point_num);
	       output=(input<=threshold)?input:((input-threshold)/ratio+threshold);
         register_value[point_num]=pow(10,(output-input)/20);  											
	  }
		
		for(i=0;i<11;i++)
		{
			if(i<10)
			{
             To824(register_value[i*5+0],param_hex_0)	;
		         To824(register_value[i*5+1],param_hex_1)	;
		         To824(register_value[i*5+2],param_hex_2)	;
		         To824(register_value[i*5+3],param_hex_3)	;
		         To824(register_value[i*5+4],param_hex_4)	;		
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, param_hex_2 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, param_hex_3 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, param_hex_4 ) ;	
			}			
			 else if(i==10)
			 {
             To824(register_value[i*5+0],param_hex_0)	;
		         To824(register_value[i*5+1],param_hex_1)	;
		         To824(register_value[i*5+2],param_hex_2)	;
		         To824(register_value[i*5+3],param_hex_3)	;		
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, param_hex_2 ) ;
             SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, param_hex_3 ) ;					   
			 }
			
			
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr+i*5)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr+i*5;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}			
		

}


/********************************************************************************
*******************
** ��������: noise_gate_threshold
** ��������: ����������ֵ
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             threshold��min:-100dB,max:-50dB,step:1dB��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: hold=milliseconds*fs/1000;(here,fs=sample rate)				
********************************************************************************
*******************/	

#define X_AXIS_MIN -135.0
#define X_AXIS_MAX 20.0
#define Y_AXIS_MIN -135.0
#define Y_AXIS_MAX 20.0
#define POINT 53//1~54
#define MAX_NOISE_GATE_THRESHOLD_X -50
#define MAX_NOISE_GATE_THRESHOLD_Y -50

void noise_gate_threshold(unsigned int safeload_parameter_addr,double threshold)
{
    double k;
    double current_noise_gate_threshold_x=threshold;
    double current_noise_gate_threshold_y=Y_AXIS_MIN;
    double x_step;
    double input,output;
    unsigned char point_num;
    double register_value[54];
    unsigned char param_hex_0[4];
    unsigned char param_hex_1[4];	
    unsigned char param_hex_2[4];	
    unsigned char param_hex_3[4];	
    unsigned char param_hex_4[4];		
    unsigned char i;
	
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=5;	



      x_step= 3;//  (X_AXIS_MAX-X_AXIS_MIN)/(POINT)	;  
      k=(MAX_NOISE_GATE_THRESHOLD_Y-current_noise_gate_threshold_y)/(MAX_NOISE_GATE_THRESHOLD_X-current_noise_gate_threshold_x);

	  for(point_num=0;point_num<=POINT;point_num++)
	  {
	            input=X_AXIS_MIN+x_step*(point_num);
		   if(input<=threshold)
		   {
			        output=current_noise_gate_threshold_y;
		   }
		   else if(input<=MAX_NOISE_GATE_THRESHOLD_X)
		   {			  
				       output=input*k-MAX_NOISE_GATE_THRESHOLD_X*k+MAX_NOISE_GATE_THRESHOLD_Y; 
		   }
		   else
		   {      
			         output=input;
		   }
                register_value[point_num]=pow(10,(output-input)/20);  
	  }
		for(i=0;i<11;i++)
		{
			if(i<10)
			{
            To824(register_value[i*5+0],param_hex_0)	;
		        To824(register_value[i*5+1],param_hex_1)	;
		        To824(register_value[i*5+2],param_hex_2)	;
		        To824(register_value[i*5+3],param_hex_3)	;
		        To824(register_value[i*5+4],param_hex_4)	;		
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, param_hex_2 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, param_hex_3 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, param_hex_4 ) ;	
			}			
			else if(i==10)
			 {
            To824(register_value[i*5+0],param_hex_0)	;
		        To824(register_value[i*5+1],param_hex_1)	;
		        To824(register_value[i*5+2],param_hex_2)	;
		        To824(register_value[i*5+3],param_hex_3)	;		
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, param_hex_2 ) ;
            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, param_hex_3 ) ;					   
			 }    
			
			
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr+i*5)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr+i*5;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}		
}



/********************************************************************************
*******************
** ��������: noise_gate_RMS_TC_ms
** ��������: ����������ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��min:0,max:1000ms,step:1��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: compressor_RMS_TC_ms
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/				
void noise_gate_RMS_TC_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)	
{
	   compressor_RMS_TC_ms(safeload_parameter_addr,millisecond);
}


/********************************************************************************
*******************
** ��������: noise_gate_decay_ms
** ��������: ���������ͷ�ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��min:0,max:1000ms,step:1��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: compressor_decay_ms
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/							
void noise_gate_decay_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)
{
	   compressor_decay_ms( safeload_parameter_addr, millisecond);
}










/********************************************************************************
*******************
** ��������: limit_threshold
** ��������: �޷�����ֵ
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             threshold��min:-25dB,max:12dB,step:1dB��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: 		
********************************************************************************
*******************/	
void limit_threshold(unsigned int safeload_parameter_addr, double threshold)
{
	    double register_value;
      unsigned char param_hex[4];	
      unsigned char safeload_parameter_num=1;		
	    
	     register_value=pow(10,(threshold/20));
	
	     To824(register_value,param_hex);	
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;		   
			
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
	
}










/********************************************************************************
*******************
** ��������: limit_RMS_TC_ms
** ��������: �޷�������ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��min:0,max:200ms,step:1��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: compressor_RMS_TC_ms
** �� ��: 
** ��ע: RMS dB/s= abs(1.0 - 10^(rms/10*fs)), where "rms" is the value entered in the block.		
********************************************************************************
*******************/	
void limit_RMS_TC_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)
{
    compressor_RMS_TC_ms(safeload_parameter_addr,millisecond);
}













/********************************************************************************
*******************
** ��������: limit_decay_ms
** ��������: �޷����ͷ�ʱ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             millisecond��attack time*(2��4��6��8��12��16��24��32)��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: Decay dB/s = 2^(-decay), where "decay" is the value entered in the block		
********************************************************************************
*******************/						
void limit_decay_ms(unsigned int safeload_parameter_addr,unsigned int millisecond)
{
	  double register_value;
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=1;		
	
	     register_value=RMS_convert_ms_to_dbpsecond(millisecond);
	     register_value=pow(2,-register_value);	
       To824(register_value,param_hex)	;	
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;		   
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;				  
}









/********************************************************************************
*******************
** ��������: white_noise_enable
** ��������: ������������ʹ��
** �������: module_addr(ģ���ַ)
             enable(ON,OFF)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void white_noise_enable(unsigned int module_addr,unsigned char enable)
{ 
	    unsigned char  param_hex[4];	   
	    To824(enable, param_hex) ;
	    SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr, 4, param_hex);		

}











/********************************************************************************
*******************
** ��������: white_noise_gain
** ��������: ����������������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void white_noise_gain(unsigned int module_addr,double gain)
{
	  gain_control( module_addr,gain);
}













/********************************************************************************
*******************
** ��������: white_noise_aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr��ģ���ַ��
             sw(OFF,ON)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void white_noise_aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}


















/********************************************************************************
*******************
** ��������: pink_noise_enable
** ��������: ������������ʹ��
** �������: module_addr(ģ���ַ)
             enable(ON,OFF)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void pink_noise_enable(unsigned int module_addr,unsigned char enable)
{ 
	    unsigned char  param_hex[4];	   
	    To824(enable, param_hex) ;
	    SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, module_addr, 4, param_hex);		

}











/********************************************************************************
*******************
** ��������: pink_noise_gain
** ��������: ����������������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void pink_noise_gain(unsigned int module_addr,double gain)
{
	  gain_control( module_addr,gain);
}













/********************************************************************************
*******************
** ��������: pink_noise_aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr��ģ���ַ��
             sw(OFF,ON)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void pink_noise_aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}




/********************************************************************************
*******************
** ��������: sine_enable
** ��������: ���Ҳ�������ʹ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             enable��ON,OFF��
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void sine_enable(unsigned int safeload_parameter_addr,unsigned char enable)
{ 
	  unsigned char  param_hex[4];	
	  unsigned char safeload_parameter_num=1;	
	
	  To824(enable, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	


	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	 
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	

}











/********************************************************************************
*******************
** ��������: sine_gain
** ��������: ���Ҳ�������������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void sine_gain(unsigned int module_addr,double gain)
{
	  gain_control( module_addr,gain);
}











/********************************************************************************
*******************
** ��������: sine_aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr(ģ���ַ) 
             sw(OFF,ON)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void sine_aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}






/********************************************************************************
*******************
** ��������: sine_frequency
** ��������: ���Ҳ�Ƶ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             frequency(min:20Hz,max:20000Hz,step:1Hz) 
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
#define SINE_SOURCE_K 0.000041663646697998 
void sine_frequency(unsigned int safeload_parameter_addr,unsigned int frequency  )
{
	  double register_value;
	  unsigned char  param_hex[4];
	  unsigned char safeload_parameter_num=1;	
	  
	  register_value=frequency*SINE_SOURCE_K;
	  To824(register_value, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	


	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	 
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	


}











/********************************************************************************
*******************
** ��������: square_enable
** ��������: ����������ʹ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             enable(ON,OFF)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void square_enable(unsigned int safeload_parameter_addr,unsigned char enable)
{ 
	  unsigned char  param_hex[4];	
	  unsigned char safeload_parameter_num=1;	
	
	  To824(enable, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	


	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	 
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
}












/********************************************************************************
*******************
** ��������: square_gain
** ��������: ��������������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void square_gain(unsigned int module_addr,double gain)
{
	  gain_control( module_addr,gain);
}










/********************************************************************************
*******************
** ��������: square_aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr(ģ���ַ)
             sw(OFF,ON)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void square_aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}












/********************************************************************************
*******************
** ��������: square_frequency
** ��������: ����Ƶ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             frequency(min:20Hz,max:20000Hz,step:1Hz) 
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
#define SQUARE_SOURCE_K   SINE_SOURCE_K//���ǹ����������ֵ��
void square_frequency(unsigned int safeload_parameter_addr,unsigned int frequency  )
{
	  double register_value;
	  unsigned char  param_hex[4];
	  unsigned char safeload_parameter_num=1;	
	  
	  register_value=frequency*SQUARE_SOURCE_K;
	  To824(register_value, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	


	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	 
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	


}








/********************************************************************************
*******************
** ��������: pulse_frequency
** ��������: ����Ƶ��
** �������: module_addr(ģ���ַ)
             frequency(min:20Hz,max:20000Hz,step:1Hz) 
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
#define PULSE_SOURCE_K    0.0000208616256713867//�����������ֵ
void pulse_frequency(unsigned int module_addr,unsigned int frequency  )
{
	  double register_value;
	  unsigned char  param_hex[4];
	  
	  register_value=frequency*PULSE_SOURCE_K;
	  To824(register_value, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,module_addr, 4, param_hex ) ;
}










/********************************************************************************
*******************
** ��������: pulse_th
** ��������: ����ռ�ձ�
** �������: module_addr(ģ���ַ)
             percent(min:0%,max:100%,step:1%)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void pulse_th(unsigned int module_addr,double percent )
{
	  double register_value;
	  unsigned char  param_hex[4];
	  register_value=percent/100;
	  To824(register_value, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,module_addr, 4, param_hex ) ;	   
}










/********************************************************************************
*******************
** ��������: pulse_enable
** ��������: ���巢����ʹ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             enable(ON,OFF)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void pulse_enable(unsigned int safeload_parameter_addr,unsigned char enable)
{ 
	  unsigned char  param_hex[4];	
	  unsigned char safeload_parameter_num=1;	
	
	  To824(enable, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	


	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	 
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	
		

}








/********************************************************************************
*******************
** ��������: pulse_gain
** ��������: ���巢��������
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void pulse_gain(unsigned int module_addr,double gain)
{
	  gain_control( module_addr,gain);
}











/********************************************************************************
*******************
** ��������: pulse_aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr(ģ���ַ)
             sw(OFF,ON)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void pulse_aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}







/********************************************************************************
*******************
** ��������: sweepfreq_enable
** ��������: ɨƵʹ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             enable(ON,OFF)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void sweepfreq_enable(unsigned int safeload_parameter_addr,unsigned char enable)
{ 
	  unsigned char  param_hex[4];	
	  unsigned char safeload_parameter_num=1;	
	
	  To824(enable, param_hex) ;	
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex ) ;
	
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	  param_hex[3]=(u8)safeload_parameter_addr;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
	 
	  param_hex[0]=0x00;
	  param_hex[1]=0x00;
	  param_hex[2]=(u8)((safeload_parameter_num)>>8);
	  param_hex[3]=(u8)safeload_parameter_num;
	  SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;	

}











/********************************************************************************
*******************
** ��������: sweepfreq_aux_mixer_gain_sw
** ��������: ���󿪹�
** �������: module_addr(ģ���ַ)
             sw(OFF,ON)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: mute();
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void sweepfreq_aux_mixer_gain_sw(unsigned int module_addr,unsigned char sw )
{
       mute(module_addr, sw );
}









/********************************************************************************
*******************
** ��������: sweepfreq
** ��������: ɨƵ��������
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             start_freq(min:20Hz,max:20000Hz,step:1Hz) 
             stop_freq(min:20Hz,max:20000Hz,step:1Hz) 
             cycles_per_step(min:2,max:48000,step:1 (����ÿ��������(���Ҳ�����)))
             steps(min:1,max:500,step:1 (����ɨ�貽����));
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
** �� ��: 
** ��ע: ��
********************************************************************************
*******************/
void sweepfreq(unsigned int safeload_parameter_addr,double start_freq ,double stop_freq,unsigned int cycles_per_step,double steps)
{
    double register_value;

    unsigned char param_hex_0[4];
    unsigned char param_hex_1[4];	
    unsigned char param_hex_2[4];	
    unsigned char param_hex_3[4];	
    unsigned char param_hex_4[4];		
	
    unsigned char param_hex[4];	
    unsigned char safeload_parameter_num=5;		
	

	  register_value=start_freq*SINE_SOURCE_K; //start_freq
	  To824(register_value, param_hex_0) ;	 


	  register_value=stop_freq*SINE_SOURCE_K; //stop_freq
	  To824(register_value, param_hex_1) ;	

	  To32(cycles_per_step, param_hex_2) ;	//cycles_per_step

    register_value=pow(stop_freq/start_freq,1/(steps-1));//increment
    To824(register_value, param_hex_3) ;	


	  To32(steps, param_hex_4) ;	//setps
		
		
	
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, param_hex_2 ) ;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, param_hex_3 ) ;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, param_hex_4 ) ;			
			 
			 
			 
			 
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	     param_hex[3]=(u8)safeload_parameter_addr;
	     SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			 
	     param_hex[0]=0x00;
	     param_hex[1]=0x00;
	     param_hex[2]=(u8)((safeload_parameter_num)>>8);
	     param_hex[3]=(u8)safeload_parameter_num;
       SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;			
}





/********************************************************************************
*******************
** ��������: sweepfreq_gain
** ��������: ɨƵ����
** �������: module_addr(ģ���ַ)
             gain(min:-80dB,max:0dB,step:0.03dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: gain_control();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void sweepfreq_gain(unsigned int module_addr,double gain)
{
	  gain_control( module_addr,gain);
}










/********************************************************************************
*******************
** ��������: meter
** ��������: ��ȡ��Ƶǿ��
** �������: module_addr(ģ���ַ)
** �������: param_dec(min:-45dB,Max:3dB,step:0.01db)
** ȫ�ֱ���: ��
** ����ģ��:SIGMA_READ_REGISTER_BLOCK
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
//double meter_test0;
unsigned char param_hex_bebug[4]; 
	
double meter(unsigned int module_addr)
{
	 unsigned char param_hex[4];
   double param_dec; 
   long param224=0; 
   long param231=0;   
   unsigned long temp[4];
	

    SIGMA_READ_REGISTER_BLOCK(DEVICE_ADDR_IC_1, module_addr, 4, param_hex ) ;
    param_hex_bebug[0]=	param_hex[0];
	  param_hex_bebug[1]=	param_hex[1];
	  param_hex_bebug[2]=	param_hex[2];
	  param_hex_bebug[3]=	param_hex[3];
	
	
    temp[0]=param_hex[0]^ 0x80;
    temp[1]=param_hex[1];
    temp[2]=param_hex[2];
    temp[3]=param_hex[3];
    
    temp[0]=temp[0]<<24;
    temp[1]=temp[1]<<16;
    temp[2]=temp[2]<<8;
    temp[3]=temp[3]<<0;
    
    param231=temp[0]|temp[1]|temp[2]|temp[3];
    
    param224=param231- (1 << 31);
    param_dec=(double)(param224/(1<<24));
    param_dec=(double)(param224/16777216.0);
    if(!param_dec)param_dec=-96;
		else
    param_dec=10*log10(param_dec);
    return param_dec;
}





/********************************************************************************
*******************
** ��������: read_824_data
** ��������: ��ȡ����
** �������: module_addr(ģ���ַ)
** �������: param_dec
** ȫ�ֱ���: ��
** ����ģ��:SIGMA_READ_REGISTER_BLOCK
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
double read_824_data(unsigned int module_addr)
{
	 unsigned char param_hex[4];
   double param_dec; 
   long param224=0; 
   long param231=0;   
   unsigned long temp[4];
	

    SIGMA_READ_REGISTER_BLOCK(DEVICE_ADDR_IC_1, module_addr, 4, param_hex ) ;	
    temp[0]=param_hex[0]^ 0x80;
    temp[1]=param_hex[1];
    temp[2]=param_hex[2];
    temp[3]=param_hex[3];
    
    temp[0]=temp[0]<<24;
    temp[1]=temp[1]<<16;
    temp[2]=temp[2]<<8;
    temp[3]=temp[3]<<0;
    
    param231=temp[0]|temp[1]|temp[2]|temp[3];
    
    param224=param231- (1 << 31);
    param_dec=(double)(param224/(1<<24));
    param_dec=(double)(param224/16777216.0);
    
    return param_dec;
}



/********************************************************************************
*******************
** ��������: RTA_switch
** ��������: ѡ��Ƶ�׵�ͨ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             sw(OUT1_RTA~COAX_R_RTA)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/
void RTA_switch(unsigned int safeload_parameter_addr,unsigned char sw )
{
	  unsigned char  param_hex[4];	
	  unsigned char safeload_parameter_num=5;	
    unsigned char param_hex_0[4];
    unsigned char param_hex_1[4];	
    unsigned char param_hex_2[4];	
    unsigned char param_hex_3[4];	
    unsigned char param_hex_4[4];			   
	  unsigned char register_value[16];
    unsigned char i;

	  for(i=0;i<16;i++)
		{
			    if(sw==i)
					{
						    register_value[i]=1;
					}
					else
					{
						   register_value[i]=0;
					}
		}

		for(i=0;i<4;i++)
		{
			       if(i<3)
			       {
                 To824(register_value[i*5+0],param_hex_0)	;
		             To824(register_value[i*5+1],param_hex_1)	;
		             To824(register_value[i*5+2],param_hex_2)	;
		             To824(register_value[i*5+3],param_hex_3)	;
		             To824(register_value[i*5+4],param_hex_4)	;		
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR, 4, param_hex_2 ) ;
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR, 4, param_hex_3 ) ;
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR, 4, param_hex_4 ) ;	
			       }			
			       else if(i==3)
			       {
                 To824(register_value[i*5+0],param_hex_0)	;
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ; 
			       }
			     
			     
	            param_hex[0]=0x00;
	            param_hex[1]=0x00;
	            param_hex[2]=(u8)((safeload_parameter_addr+i*5)>>8);
	            param_hex[3]=(u8)safeload_parameter_addr+i*5;
	            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			        
	            param_hex[0]=0x00;
	            param_hex[1]=0x00;
	            param_hex[2]=(u8)((safeload_parameter_num)>>8);
	            param_hex[3]=(u8)safeload_parameter_num;
              SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					
		}	     
		          param_hex[0]=0x00;
			        param_hex[1]=0x00;
			        param_hex[2]=0x20;
			        param_hex[3]=0x8a;
              SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, RTA_SWITCH_SLEW_ADDR, 4, param_hex);			/* SWGainOptADAU145XAlg2target */	
}



/********************************************************************************
*******************
** ��������: filter_switch
** ��������: ѡ��Ƶ�׵�ͨ��
** �������: safeload_parameter_addr(��ȫ����Ŀ���ַ)
             sw(0:FILTER_12dB,1:FILTER_24dB)
** �������: ��
** ȫ�ֱ���: ��
** ����ģ��: To824();SIGMA_WRITE_REGISTER_BLOCK();
** �� ��:
** ��ע: ��
********************************************************************************
*******************/

void filter_switch(unsigned int safeload_parameter_addr,unsigned char sw )
{
	  unsigned char  param_hex[4];	
	  unsigned char safeload_parameter_num=2;	
    unsigned char param_hex_0[4];
    unsigned char param_hex_1[4];			
	  unsigned char register_value[2];


			    if(!sw)
					{
						    register_value[0]=1;
						    register_value[1]=0;
					}
					else if(sw==1)
					{
						    register_value[0]=0;
						    register_value[1]=1;
					}


                 To824(register_value[0],param_hex_0)	;
		             To824(register_value[1],param_hex_1)	;	
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR, 4, param_hex_0 ) ;
                 SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR, 4, param_hex_1 ) ;

			     
			     
	            param_hex[0]=0x00;
	            param_hex[1]=0x00;
	            param_hex[2]=(u8)((safeload_parameter_addr)>>8);
	            param_hex[3]=(u8)safeload_parameter_addr;
	            SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR, 4, param_hex ) ;
			        
	            param_hex[0]=0x00;
	            param_hex[1]=0x00;
	            param_hex[2]=(u8)((safeload_parameter_num)>>8);
	            param_hex[3]=(u8)safeload_parameter_num;
              SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1,MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR, 4, param_hex ) ;					  
		          param_hex[0]=0x00;
			        param_hex[1]=0x00;
			        param_hex[2]=0x20;
			        param_hex[3]=0x8a;
              SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1, RTA_SWITCH_SLEW_ADDR, 4, param_hex);			/* SWGainOptADAU145XAlg2target */	
}









