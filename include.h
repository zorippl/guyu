#include "STC15Fxxxx.H"
#include <stdio.h>		
#include <math.h>
#include <string.h>

/* Define configue */
#define		MAIN_Fosc		11059200
#define		Baudrate1		9600L

#define  ADC_POWER    0x80	//ADC����
#define  ADC_FLAG     0x10	//ADCת����־
#define  ADC_START    0x08	//ADC����ת��
#define  ADC_SPEEDLL  0x00	//540��ת������
#define  ADC_SPEEDL   0x20	//360��ת������
#define  ADC_SPEEDH   0x40	//180��ת������
#define  ADC_SPEEDHH  0x60	//90��ת������

/* Function declared */
void Delay(unsigned int n);

//app_uart.c
void SetTimer2Baudraye(u16 dat);
void USART_SendData(u8 ch);
void uartInit(void);

//app_adcSensor.c
void adcInit(void);
unsigned char sensorTask(void);

//app_led.c
void ledInit(void);
void ledOn(void);
void ledOff(void);