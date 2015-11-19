#include "L4_123.h"
#include "L8_3.h"
#include <asf.h>
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main (void)
{
	ADC_GainInit(1,0); 
// initialize two ports to measure difference between them with gain
	double voltage; 
// double type value to convert ADC value
	char string[30]="ADC starts.. ";
 // print the string in the beginning
	SetLineParameters( 0, 9600, EVEN_PARITY, BIT_FORMAT_8bit, STOP_BIT_2bit );
 // init board
	WriteString((unsigned) 0, string); 
// write the started string in the terminal
	

	while(1)
	{
		voltage=(double)Voltage(10);
 // read integer ADC with gain x10 or x200, convert to double
		voltage=(voltage*5)/1023; 
// transform to decimal
		sprintf(string,"\rResult = %.5f Volts", voltage); 
// set to string
		WriteString((unsigned) 0, string); 
// print the voltage
		_delay_ms(1000);
 // wait a second before cleaning a screen
		WriteString((unsigned)0, "\033[2J"); 
// clear the terminal to measure again
		
	}
	
}
