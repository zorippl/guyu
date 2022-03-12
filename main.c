#include "include.h"

/* Delay Function*/
void Delay(unsigned int n)
{
		unsigned int x;
		while (n--)
		{
			x = 5000;
			while (x--);
		}
}

/* Main Function */
void main()
{
	//system init
	ledInit();
	uartInit();
	adcInit();
	
	ledOff();
	//main loop
	while(1) {
		
		Delay(100);
		USART_SendData(sensorTask());
	}
}