#include "L4_123.h"
#include "L5_12.h"
#include "L5_4.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int GetPulse(unsigned switchNumber, unsigned seconds){
	unsigned int bCounter=1;
	int i,switchPin=1;

	for(i=1;i<switchNumber;i++)
		switchPin*=2;

	while(PINA & switchPin);
	while(!(PINA & switchPin));

	BeginTimer();
	while(RunnedTime()<seconds*1000)

	if(!(PINA & switchPin)) // a key is pressed
	{
		bCounter++;
		while(!(PINA & switchPin)); // wait until released		
	}
	cli();
	return ~bCounter;
}
