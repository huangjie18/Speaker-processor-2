#include "sigmastudiofw.h"


//��ʼ��SPI FLASH��IO��
void sigma_init(void)
{	
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA, ENABLE );//PORTBʱ��ʹ�� 

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_8;  // PB12 ���� 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
 	GPIO_SetBits(GPIOA,GPIO_Pin_4);

  GPIO_ResetBits(GPIOA,GPIO_Pin_8);	//DSP ��λ
	delay_ms(1000);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
  delay_ms(1000);
	
	
	SPI1_Init();		   	//��ʼ��SPI
	SPI1_SetSpeed(SPI_BaudRatePrescaler_16);//����Ϊ18Mʱ��,����ģʽ
  SIGMA_CLATCH=1;	//��SIGMA_CLATCH�������Σ���sigmadsp����Ϊspiģʽ			
  delay_ms(1);
  SIGMA_CLATCH=0;				
  delay_ms(1);	
  SIGMA_CLATCH=1;				
  delay_ms(1);
  SIGMA_CLATCH=0;				
  delay_ms(1);	
  SIGMA_CLATCH=1;				
  delay_ms(1);
  SIGMA_CLATCH=0;				
  delay_ms(1);	
	
	
  SIGMA_CLATCH=1;		//ȡ��Ƭѡ 		
	

}




void SIGMA_WRITE_REGISTER_BLOCK(int devAddress, int address, int length, ADI_REG_TYPE *pData ) 
{
    int i=0;
	  SIGMA_CLATCH=0;                         //ʹ������   
	  SPI1_ReadWriteByte(devAddress);      	  //оƬ��ַ[6:0],R/W 
	  SPI1_ReadWriteByte((u8)((address)>>8)); //�ӵ�ַ[15:8]  
	  SPI1_ReadWriteByte((u8)address);        //�ӵ�ַ[7:0]
    for(i =0;i < length;i++)
    {
        /* 4.дһ�ֽ����� */
        SPI1_ReadWriteByte(pData[i]); 
   }	  
	  SIGMA_CLATCH=1;                         //ȡ��Ƭѡ 

	
}


void SIGMA_WRITE_REGISTER_BLOCK_CONST(int devAddress, int address, int length, ADI_REG_TYPE const *pData ) 
{
    int i=0;
	  SIGMA_CLATCH=0;                         //ʹ������   
	  SPI1_ReadWriteByte(devAddress);      	  //оƬ��ַ[6:0],R/W 
	  SPI1_ReadWriteByte((u8)((address)>>8)); //�ӵ�ַ[15:8]  
	  SPI1_ReadWriteByte((u8)address);        //�ӵ�ַ[7:0]
    for(i =0;i < length;i++)
    {
        /* 4.дһ�ֽ����� */
        SPI1_ReadWriteByte(pData[i]); 
   }	  
	  SIGMA_CLATCH=1;                         //ȡ��Ƭѡ 
	
}

void SIGMA_READ_REGISTER_BLOCK(int devAddress, int address, int length, ADI_REG_TYPE *pData ) 
{
 int i=0;
	  SIGMA_CLATCH=0;                         //ʹ������   
	  SPI1_ReadWriteByte(devAddress|0x01);      	  //оƬ��ַ[6:0],R/W 
	  SPI1_ReadWriteByte((u8)((address)>>8)); //�ӵ�ַ[15:8]  
	  SPI1_ReadWriteByte((u8)address);        //�ӵ�ַ[7:0]
    for(i =0;i < length;i++)
    {
        /* ��һ�ֽ����� */
        pData[i]=SPI1_ReadWriteByte(0xff); 
   }	  
	  SIGMA_CLATCH=1;                         //ȡ��Ƭѡ 

}





void SIGMA_WRITE_DELAY(int devAddress, int length, ADI_REG_TYPE *pData )
{
//	int cnt=0;
	int nCount=0;
	//int data_length = length - Address_Length;
//	ADI_REG_TYPE data[4]={0x05, 0xF5, 0xE1, 0x00};
//	for(cnt=0; cnt<data_length; cnt++)
//	{
//		nCount &= pData[cnt] >> (8*cnt);
//	}
//	for(cnt=0; cnt<4; cnt++)
//	{
//		nCount +=  data[cnt];
//		nCount = nCount<<(8);
//		
//	}
//nCount=0xFFFFFF;
//nCount=0x15752A00;	 //5 secs approx
//nCount=0x05F5E100;	 //5 secs approx
nCount=0xFFFFF;
	for(; nCount != 0; nCount--);
	
}































