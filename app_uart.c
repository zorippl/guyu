#include "include.h"

void	SetTimer2Baudraye(u16 dat)						
{
	AUXR &= ~(1<<4);													
	AUXR &= ~(1<<3);													//Timer2 set As Timer
	AUXR |=  (1<<2);													//Timer2 set as 1T mode
	TH2 = dat / 256;
	TL2 = dat % 256;
	IE2  &= ~(1<<2);													
	AUXR |=  (1<<4);													//允许定时器运行													
}

void  USART_SendData(u8 ch)						
{
	SBUF=ch;	
	while(!TI);															
	TI=0;	
}

void uartInit(void)								
{
	AUXR |= 0x01;
	SetTimer2Baudraye(65536UL - (MAIN_Fosc / 4) / Baudrate1);
	SCON = (SCON & 0x3f) | 0x40;																						
	REN = 1;																	
	P_SW1 &= 0x3f;
	P_SW1 |= 0x40;								
}
