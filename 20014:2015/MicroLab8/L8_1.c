#include "L4_123.h"
#include "L8_1.h"
#include <asf.h>
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define _CRT_SECURE_NO_WARNINGS 
#define F_CPU 16000000


int ADC_Read(void)
{
	int  result = 0;
	
	// reset the converter
	ADCSRA |= (1<<ADSC); //
	while(!(ADCSRA & (1 << ADIF))); // ADIF turns on after reset
	ADCSRA |= (1<<ADSC); // start conversion
	while(!(ADCSRA & (1 << ADIF))); // ADIF turns on after conversion
	result = ADCL;         // read 1st lower part
	result += (ADCH << 8); // read upper part
	return result;
}

void ADC_Init(char port)
{
		
		if (port < 15)
		{
		ADMUX = (1 << REFS1) | (1 << REFS0) | port; // ref Volage – 2.5V
		
		// set frequency 1MHz / 8 = 125kHz
		ADCSRA = (1<<ADPS1) | (1<<ADPS0); //prescale 

		ADCSRA |= 1 << ADEN; // ADC Enable	
		}
}


