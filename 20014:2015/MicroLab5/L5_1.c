#include "L4_123.h"
#include "L5_12.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

unsigned long long int time=0;

unsigned int hours  = 0;
unsigned int minutes= 0;
unsigned int seconds= 0;

ISR(TIMER1_OVF_vect){
	time+=8;
	}

void BeginTimer(){
	TCCR1A = 0;        // set entire TCCR1A register to 0
	TIMSK1=1<<TOIE1;
	TCNT1=0;
	TCCR1B=1;
	sei();

}
unsigned RunnedTime(){
	return time;
}
