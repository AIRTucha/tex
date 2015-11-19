#include "L4_123.h"
#include "L8_4.h"
#include <asf.h>
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main (void)
{
	int result; 
// variale to read integer value from ADC
	
	int i=0; 
// variable to initialize ADC ports in a loop
	
	double voltage; 
// double type value to convert ADC value
	char string[30]="ADC starts.. "; 
// print the string in the beginning
	SetLineParameters( 0, 9600, EVEN_PARITY, BIT_FORMAT_8bit, STOP_BIT_2bit ); // init board
	WriteString((unsigned) 0, string); 
// write the started string in the terminal
		
	while (1) // infinite loop
	{
		for (i=0;i<8;i++)
		{
			ADC_Init(i);
 // initialize the new port
			result=ADC_Read(); 
// read a new port
			voltage=(double)result;
 // convert the integer value to double
			voltage=(voltage*2.5)/1023; 
// convert to decimal
			sprintf(string,"\r\nResult ADC%i = %.5f Volts",i, voltage); 
// set to the string
			WriteString((unsigned) 0, string); 
// show the string on a screen
		}
		_delay_ms(10000); 
// wait 10 seconds
		WriteString((unsigned) 0, "\033[2J");
 // clear the terminal window for new values
	}
}

