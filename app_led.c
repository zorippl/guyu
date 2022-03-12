#include "include.h"

void ledInit(void)
{
	P0M1 = 0x00;									 							
	P0M0 = 0x24;
}

void ledOn(void)
{
	P05 = 1;
}

void ledOff(void)
{
	P05 = 0;
}