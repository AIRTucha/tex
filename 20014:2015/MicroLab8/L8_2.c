#include "L4_123.h"
#include "L8_2.h"
#include <asf.h>
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define _CRT_SECURE_NO_WARNINGS 
#define F_CPU 16000000

int ADC_DiffRead(void)
{
	ADCSRA|=(1<<ADSC);//start conversion
	while(!(ADCSRA&(1<<ADSC))); //wait conversion
	return ADCW;
}

void ADC_DiffInit(char port1, char port2)
{
	if ((port1 == 0)&&(port2 == 1))
	{
			ADMUX =(1 << REFS0)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC0 and ADC1 with gain x1
			ADCSRA |= (1 << ADEN); // ADC Enable 
	}
	if ((port1 == 1)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX4);
 // enable Vref=5 volts and MUX for difference between ADC1 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 2)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX1)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC2 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 3)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX1)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC3 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 4)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX2)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC4 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 5)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX2)|(1<<MUX4);
 // enable Vref=5 volts and MUX for difference between ADC5 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 6)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC6 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 7)&&(port2 == 1))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX4);
 // enable Vref=5 volts and MUX for difference between ADC7 and ADC1 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	
	if ((port1 == 0)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX3)|(1<<MUX4);
 // enable Vref=5 volts and MUX for difference between ADC0 and ADC2 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 1)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX3)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC1 and ADC2 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 2)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX1)|(1<<MUX3)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC2 and ADC2 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 3)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX1)|(1<<MUX3)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC3 and ADC2 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 4)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC4 and ADC2 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
	if ((port1 == 5)&&(port2 == 2))
	{
		ADMUX =(1 << REFS0)|(1<<MUX0)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4); 
// enable Vref=5 volts and MUX for difference between ADC4 and ADC2 with gain x1
		ADCSRA |= (1 << ADEN); // ADC Enable
	}
}

