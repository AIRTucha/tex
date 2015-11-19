#include "L4_123.h"
#include "L5_12.h"
#include "L5_5.h"
#include <avr/io.h>
#include <avr/interrupt.h>

long ElapsedTime(unsigned switchNumber){
	int i,switchPin=1;
	for(i=1;i<switchNumber;i++)
	switchPin*=2;
	while(PINA & switchPin);
	BeginTimer();
	while(!(PINA & switchPin)); // wait until released
	i=RunnedTime();
	cli();
	
	return i;
}