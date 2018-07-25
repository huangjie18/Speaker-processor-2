#ifndef __24C16_H
#define __24C16_H
#include "sys.h"

#define EEPROM_PAGE_SIZE   16  /* 24xx16的页面大小 */
#define EEPROM_SIZE		   2048	/* 24xx16总容量 */
enum
{
	Fail = 0,    //失败
	Success, //成功
};

u8 AT24C16_Check(void);
u8 AT24C16_PageWrite(u8 *_pWriteBuf,u16 _usAddress,u16 _usSize);
u8 AT24C16_PageRead(u8 *_pReadBuf,u16 _usAddress, u16 _usSize);
#endif
