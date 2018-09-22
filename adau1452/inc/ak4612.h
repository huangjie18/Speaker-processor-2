#ifndef __AK4612_H__
#define __AK4612_H__	 
#include "sys.h"
#include "spi.h"
#include "delay.h"
#include "usart.h"	 
void ak4612_init(void);		

void ak4612_write(u8 addr,u8 data);
void ak4612_read(u8 addr) ;  

#endif


