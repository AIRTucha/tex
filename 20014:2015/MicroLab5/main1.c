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


#define number_of_times 100000

int main(void){
		char string[10];
		unsigned long long int i,prevTime;
		
	SetLineParameters( 0, 9600, EVEN_PARITY, BIT_FORMAT_8bit, STOP_BIT_2bit );

	BeginTimer();
	
	//program loop
	while(true){
		i++;
		if(i>number_of_times){
			sprintf(string,"\n\r%d",RunnedTime()-prevTime);
// show time from previous n loops
			WriteString(0,string);	
			prevTime=RunnedTime();
			i=0;
		}
	}
}