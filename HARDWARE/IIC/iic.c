#include "iic.h"
#include "delay.h"
#include "interface.h"

//IIC��ַ����

u16 IIC_Addr[Addr_num]={0};

/*
*******************************************************************************************
* �� �� ��: IIC_Addr_Init
* ����˵��: ��ʼ����ַ
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/
static void IIC_Addr_Init(void)
{
	IIC_Addr[0] 	=	 0;   										//INPUT_First�����ݴ�ŵ�ַ
	IIC_Addr[1]		=	IIC_Addr[0] + sizeof(Input_First_data);		//IN1_Second�����ݴ�ŵ�ַ
	IIC_Addr[2]  	=	IIC_Addr[1] + sizeof(Input_Data);    		//IN2_Second�����ݴ�ŵ�ַ
	IIC_Addr[3]  	=	IIC_Addr[2] + sizeof(Input_Data);    		//IN3_Second�����ݴ�ŵ�ַ
	IIC_Addr[4]  	=	IIC_Addr[3] + sizeof(Input_Data);    		//IN4_Second�����ݴ�ŵ�ַ
	IIC_Addr[5]  	=	IIC_Addr[4] + sizeof(Input_Data);    		//IN5_Second�����ݴ�ŵ�ַ
	IIC_Addr[6]  	=	IIC_Addr[5] + sizeof(Input_Data);    		//IN6_Second�����ݴ�ŵ�ַ
	IIC_Addr[7]  	=	IIC_Addr[6] + sizeof(Input_Data);    		//IN7_Second�����ݴ�ŵ�ַ
	
}

/*
*******************************************************************************************
* �� �� ��: IIC_Init
* ����˵��: ��ʼ����ӦIO��
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/
void IIC_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(EEPROM_RCC_I2C_PORT, ENABLE);	/* ��GPIOʱ�� */

	GPIO_InitStructure.GPIO_Pin = EEPROM_I2C_SCL_PIN | EEPROM_I2C_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	/* ��©��� */
	GPIO_Init(EEPROM_GPIO_PORT_I2C, &GPIO_InitStructure);
//	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7); 	//PB6,PB7 �����
	IIC_Addr_Init(); //��ʼ��24C16��Ӧ��ŵ�ַ
}

/*
*******************************************************************************************
* �� �� ��: IIC_Start
* ����˵��: ���Ϳ�ʼ�ź�
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/

void IIC_Start(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C���������ź� */
	EEPROM_I2C_SDA_1();
	EEPROM_I2C_SCL_1();
	delay_us(4);
	EEPROM_I2C_SDA_0();
	delay_us(4);
	EEPROM_I2C_SCL_0();
	delay_us(4);
}
/*
*******************************************************************************************
* �� �� ��: IIC_Stop
* ����˵��: ����ֹͣ�ź�
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/

void IIC_Stop(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C����ֹͣ�ź� */
	EEPROM_I2C_SDA_0();
	EEPROM_I2C_SCL_1();
	delay_us(4);
	EEPROM_I2C_SDA_1();
	delay_us(4);
	
	
}

/*
*******************************************************************************************
* �� �� ��: IIC_SendByte
* ����˵��: ����һ���ֽ�
* �� ��: ��
* �� �� ֵ: ��
*******************************************************************************************
*/
void IIC_SendByte(u8 _ucByte)
{
	u8 i;
	EEPROM_I2C_SCL_0();
	for(i=0; i<8; i++)
	{
		if(_ucByte & 0x80)
		{
			EEPROM_I2C_SDA_1();
		}
		else
		{
			EEPROM_I2C_SDA_0();
		}
		delay_us(2);
		EEPROM_I2C_SCL_1();
		delay_us(2);
		EEPROM_I2C_SCL_0();
		delay_us(2);
		_ucByte <<= 1; /* ����һ��bit */
	}
	EEPROM_I2C_SDA_1(); //�ͷ����ߣ����Ƿ�����Ӧ��
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_ReadByte
*	����˵��: CPU��I2C�����豸��ȡ8bit����
*	��    �Σ���
*	�� �� ֵ: ����������
*********************************************************************************************************
*/
u8 IIC_ReadByte(void)
{
	u8 i;
	u8 value = 0;
	
	for(i = 0; i < 8; i++)
	{
		value <<= 1;
		EEPROM_I2C_SCL_1();
		delay_us(2);
		if(EEPROM_I2C_SDA_READ())
		{
			value++;
		}
		EEPROM_I2C_SCL_0();
		delay_us(2);
	}
	return value;
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_WaitAck
*	����˵��: CPU����һ��ʱ�ӣ�����ȡ������ACKӦ���ź�
*	��    �Σ���
*	�� �� ֵ: ����0��ʾ��ȷӦ��1��ʾ��������Ӧ
*********************************************************************************************************
*/
u8 IIC_WaitAck(void)
{
	u8 re;
	u8 time;
	EEPROM_I2C_SDA_1();  /* CPU�ͷ�SDA���� */
	delay_us(2);
	EEPROM_I2C_SCL_1();  /* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
	delay_us(2);
	while(EEPROM_I2C_SDA_READ())  /* CPU��ȡSDA����״̬ */
	{
		time++;
		if(time>250)
		{
			IIC_Stop();
			return 1;   //��Ӧ��
		}   
	}

	EEPROM_I2C_SCL_0();
	delay_us(2);
	return 0;          //��Ӧ��
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_Ack
*	����˵��: CPU����һ��ACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/

void IIC_Ack(void)
{
	EEPROM_I2C_SDA_0();  /* CPU����SDA = 0 */
	delay_us(2);
	EEPROM_I2C_SCL_1();  /* CPU����1��ʱ�� */
	delay_us(2);
	EEPROM_I2C_SCL_0();
	delay_us(2);
	EEPROM_I2C_SDA_1(); /* CPU�ͷ�SDA���� */
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_NAck
*	����˵��: CPU����1��NACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/

void IIC_NAck(void)
{
	EEPROM_I2C_SDA_1(); /* CPU����SDA = 1 */
	delay_us(2);
	EEPROM_I2C_SCL_1();
	delay_us(2);
	EEPROM_I2C_SCL_0();
	delay_us(2);
}


/*************************************************24C16�豸**********************************************/

