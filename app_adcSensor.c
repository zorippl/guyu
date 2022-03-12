#include "include.h"

void adcInit(void)
{
	u8 ch2 = 2;
	/* use ADC Channel 2 */
	P1ASF = 0x06;
	ADC_RES = 0;
	ADC_RESL = 0;
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ADC_START | ch2;
	Delay(20);
}

static unsigned int sensorRead(void)
{
	float tmp;
	unsigned int result;
	u8 ch2 = 2;
	Delay(3);
	ADC_CONTR &= !ADC_FLAG;
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ADC_START |ch2;
	Delay(3);
	ADC_CONTR &= ~ADC_FLAG;
	result = ADC_RES;
	result=result << 2;													
	tmp = result;																
	tmp = tmp / 1024 * 5 * 20;
	return (unsigned int)tmp;
}

unsigned char sensorTask(void)
{
	static unsigned int value = 1;
	value = sensorRead();
	if (value > 255) {
		value = 255;
	}else if(value < 0) {
		value = 0;
	}
	
	if (value > 0) {
		ledOn();
	}else {
		ledOff();
	}
	return (unsigned char)value;
}