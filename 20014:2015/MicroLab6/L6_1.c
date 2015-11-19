#include "L5_12.h"
#include "L6_1.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


void SetFrequency(unsigned long freq){
double t;	
int off=0;
	BeginTimer();
	t=1/freq/resolutionOfTimer/2;
	while(1)
	if(RunnedTime()>t){
		time=0;
		PORTA^= (1 << 1);
		}
}