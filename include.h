#include "STC15Fxxxx.H"
#include <stdio.h>		
#include <math.h>
#include <string.h>

/* Define configue */
#define		MAIN_Fosc		11059200
#define		Baudrate1		9600L

#define  ADC_POWER    0x80	//ADC开关
#define  ADC_FLAG     0x10	//ADC转换标志
#define  ADC_START    0x08	//ADC启动转换
#define  ADC_SPEEDLL  0x00	//540个转换周期
#define  ADC_SPEEDL   0x20	//360个转换周期
#define  ADC_SPEEDH   0x40	//180个转换周期
#define  ADC_SPEEDHH  0x60	//90个转换周期

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