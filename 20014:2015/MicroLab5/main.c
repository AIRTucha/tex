//std libs
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
//my libs
#include "L4_123.h"
#include "L5_12.h"
//avr libs
#include <avr/io.h>
#include <avr/interrupt.h>

void main(void){
	char string[10];
	
	SetLineParameters( 0, 9600, EVEN_PARITY, BIT_FORMAT_8bit, STOP_BIT_2bit );
	WriteString(0,"\033[2J");
	WriteString(0,"\rType hours:");
	strcpy(string,ReadString(0));
	set_hours(atoi(string));
	WriteString(0,string);
	WriteString(0,"\n\rType minutes:");
	strcpy(string,ReadString(0));
	set_minutes(atoi(string));
	WriteString(0,string);
	WriteString(0,"\n");
	BeginTimer();
	watch();
}

