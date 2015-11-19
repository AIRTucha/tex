#include "L4_123.h"
#include "L5_12.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

unsigned long long int time=0;

unsigned int hours  = 0;
unsigned int minutes= 0;
unsigned int seconds= 0;

void watch(void){
	static char string[10];
	sprintf(string,"\r%d:%d:%d",hours,minutes,seconds);
	WriteString(0,string);
	if(time>999){	
		seconds++;
		time=0;
		if(seconds>59){
			minutes++;
			seconds=0;
			if(minutes>59){
				hours++;
				minutes=0;
				WriteString(0,"\r        ");
			}
			if(hours>23)
			hours=0;
			WriteString(0,"\r        ");
			}
}
}
ISR(TIMER1_OVF_vect){
	time+=8;
	watch();
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

//time setters 
void set_minutes(int m){
	if(m>0 && m<60)
		minutes=m;
	else
		minutes=0;
}
void set_hours(int h){
	if(h>0 && h<24)
	hours=h;
	else
	hours=0;
}
