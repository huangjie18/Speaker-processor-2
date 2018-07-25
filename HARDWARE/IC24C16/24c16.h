#ifndef __24C16_H
#define __24C16_H
#include "sys.h"

#define EEPROM_PAGE_SIZE   16  /* 24xx16��ҳ���С */
#define EEPROM_SIZE		   2048	/* 24xx16������ */
enum
{
	Fail = 0,    //ʧ��
	Success, //�ɹ�
};

u8 AT24C16_Check(void);
u8 AT24C16_PageWrite(u8 *_pWriteBuf,u16 _usAddress,u16 _usSize);
u8 AT24C16_PageRead(u8 *_pReadBuf,u16 _usAddress, u16 _usSize);
#endif
