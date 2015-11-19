
#include "L4_123.h"
#include "L8_3.h"
#include <asf.h>
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define _CRT_SECURE_NO_WARNINGS 
#define F_CPU 16000000


void ADC_GainInit(char port1, char port2)
{
	// set frequency 1MHz / 8 = 125kHz
	ADCSRA = (1<<ADPS1) | (1<<ADPS0); 
//prescale
	
	if ((port1 == 0)&&(port2 == 0))
	{
		ADMUX =(1 << REFS0)|(1<<MUX3); 
// enable Vref=5 volts and MUX for difference between ADC0 and ADC1 with gain x10
	}
	if ((port1 == 1)&&(port2 == 0))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX3);
 // enable Vref=5 volts and MUX for difference between ADC1 and ADC1 with gain x10
	}
	if ((port1 == 2)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX2)|(1<<MUX3);
 // enable Vref=5 volts and MUX for difference between ADC2 and ADC1 with gain x10
	}
	if ((port1 == 3)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX2)|(1<<MUX3);
 // enable Vref=5 volts and MUX for difference between ADC3 and ADC1 with gain x10
	}
	
	ADCSRA |= (1 << ADEN); // ADC Enable 
}

int ADC_Read(void)
{
	ADCSRA|=(1<<ADSC);//start conversion
	while(!(ADCSRA&(1<<ADSC))); //wait conversion
	return ADCW;
}
//------------------------------------------------
int Voltage(unsigned gain)
{
	if (gain==10) // if gain 10, all MUX1 sets to zero for both ports
		ADMUX|=(0<<MUX1);
	else
		ADMUX|=(1<<MUX1); // if gain 200, all MUX1 sets to 1 for both ports
	return ADC_Read();// and we go to reading ADC values
}

