#include "ak4612.h"


u8 debug_value=0x00;
#define AK4612_CS PBout(12)  		//AK4612��Ƭѡ�ź�
#define AK4612_RESET PBout(11)  //AK4612 ��λ����
				

void ak4612_write(u8 addr,u8 tx_data)
{
	u8 addr_temp=0;
	  addr_temp=0x20|addr;
	  AK4612_CS=0;                            	//ʹ������   
    SPI2_ReadWriteByte(addr_temp);      	//C1,C0,R/W,A4,A3,A2,A1   
    SPI2_ReadWriteByte(tx_data);   
	AK4612_CS=1;                            	//ȡ��Ƭѡ 
} 


void ak4612_read(u8 addr)   
{ 										    
	  AK4612_CS=0;                            	//ʹ������   
    SPI2_ReadWriteByte(addr);      	//C1,C0,R/W,A4,A3,A2,A1   
    debug_value=SPI2_ReadWriteByte(0XFF);   	//ѭ������  
	  AK4612_CS=1;  				    	      
} 




//��ʼ��SPI FLASH��IO��
void ak4612_init(void)
{	
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );//PORTBʱ��ʹ�� 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_11;  // PB12 ���� 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOB,GPIO_Pin_12);
 
	SPI2_Init();		   	//��ʼ��SPI
	SPI2_SetSpeed(SPI_BaudRatePrescaler_4);//����Ϊ18Mʱ��,����ģʽ
	
   AK4612_RESET	=0;
	 delay_ms(3000);
   AK4612_RESET	=1;	 
	 delay_ms(300);	
   AK4612_CS=1;				//SPI FLASH��ѡ��	
	
	

ak4612_write(0x00,0x0f);
ak4612_write(0x01,0x07);
ak4612_write(0x02,0x3f);
ak4612_write(0x03,0x20);//
ak4612_write(0x04,0x00);
ak4612_write(0x05,0x55);
ak4612_write(0x06,0x05);
ak4612_write(0x07,0x07);
ak4612_write(0x08,0x0f);
ak4612_write(0x09,0x07);
ak4612_write(0x0a,0x3f);


ak4612_write(0x0b,0x00);
ak4612_write(0x0c,0x00);
ak4612_write(0x0d,0x00);
ak4612_write(0x0e,0x00);
ak4612_write(0x0f,0x00);
ak4612_write(0x10,0x00);
ak4612_write(0x11,0x00);
ak4612_write(0x12,0x00);



	 delay_ms(100);
	 ak4612_read(0x02);	 
	 //printf("debug_value[%d] = %d \n", 1, debug_value);
}  




























