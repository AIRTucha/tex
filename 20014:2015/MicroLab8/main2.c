#include "L4_123.h"
#include "L8_2.h"
#include <asf.h>
#include <stdio.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main (void)
{
	int result;
	
	//task 2
	ADC_DiffInit(2,1); 
// define which ports we measure
	
	double voltage; 
// double type value to convert ADC value
	char string[30]="ADC starts.. ";
 // print the string in the beginning
	SetLineParameters( 0, 9600, EVEN_PARITY, BIT_FORMAT_8bit, STOP_BIT_2bit ); 
// init board
	WriteString((unsigned) 0, string); 
// write the started string in the terminal
	
	//Task 2
	while(1)
	{
		result=ADC_DiffRead();
// read integer difference value
		voltage=(double)result; 
// convert to double
		voltage=(voltage*5)/511; 
// convert to decimal
		sprintf(string,"\rResult = %.5f Volts", voltage);
 // set double value to string
		WriteString((unsigned) 0, string); 
// write the voltage on the screen
		_delay_ms(1000);
 // wait 1 second before clean the screen
		WriteString((unsigned) 0, "\033[2J"); 
// clean a screen to measure again
		
	}
}
