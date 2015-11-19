#include "L5_12.h"
#include "L6_2.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>


void SetLedPower(unsigned percent){
double t;	
int off=0;
	BeginTimer();
	t=sizeof(RunnedTime())-sizeof(RunnedTime())*(double)(percent/100);
	while(1)
	if(RunnedTime()>t){
		time=0;
		PORTA^= (1 << 1);
		}
}