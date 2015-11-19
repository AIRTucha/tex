#include "L4_123.h"
#include <asf.h>
#include <stdlib.h>

void SetLineParameters( unsigned port, unsigned speed, unsigned parity, unsigned cDataBits, unsigned cStopBits )
{
	
	if ( port == 0)
	{
			/* Set baud rate for 16MHz */
		switch (speed)
		{
			case 2400:
			UBRR0L = 160; // speed 2400 BD
			UBRR0H = 1; // = 256 + 
				UCSR0A = (1<<U2X0);
			break;
		
			case 4800:
			UBRR0L = 207; // speed 4800 BD
			UBRR0H = 0; // 
			break;
		
			case 9600:
			UBRR0L = 103; // speed 9600 BD
			UBRR0H = 0; //
			UCSR0A = (0<<U2X0);
			break;
		
			case 19200:
			UBRR0L = 51; // speed 19200 BD
			UBRR0H = 0; //
		}
			//-------------------------------
 
    
			/* Set Parity */
			switch(parity){
			case OFF_PARITY : UCSR0C |=( 0 << UPM01) | ( 0 << UPM00);
				break;
			case ODD_PARITY : UCSR0C |=( 1 << UPM01) | ( 1 << UPM00);
				break;
			case EVEN_PARITY : UCSR0C |=( 1 << UPM01) | ( 0 << UPM00);			
			}
			//-------------------------------

	
				/* Data Bits Format */
				if(cDataBits==BIT_FORMAT_8bit)

			//-------------------------------

			/* Stop Bit */
			if(cStopBits==STOP_BIT_2bit)
			 UCSR0C = (1<<USBS0)|(3<<UCSZ00);
		
			//-------------------------------
	

			/*Set transmitter and receiver in UCSR0B port*/
			UCSR0B = ( 1 << TXEN0) | ( 1 << RXEN0); 
// enable transmitter and receiver	
	} else		
	if ( port == 1)
	{
			/* Set baud rate for 16MHz */
		switch (speed)
		{
			case 2400:
			UBRR1L = 160; // speed 2400 BD
			UBRR1H = 1; // = 256 + 
				UCSR1A = (1<<U2X1);
			break;
		
			case 4800:
			UBRR1L = 207; // speed 4800 BD
			UBRR1H = 0; // 
			break;
		
			case 9600:
			UBRR1L = 103; // speed 9600 BD
			UBRR1H = 0; //
			UCSR1A = (0<<U2X1);
			break;
		
			case 19200:
			UBRR1L = 51; // speed 19200 BD
			UBRR1H = 0; //
		}
			//-------------------------------
 
    
			/* Set Parity */
			switch(parity){
			case OFF_PARITY : UCSR1C |=( 0 << UPM11) | ( 0 << UPM10);
				break;
			case ODD_PARITY : UCSR1C |=( 1 << UPM11) | ( 1 << UPM10);
				break;
			case EVEN_PARITY : UCSR1C |=( 1 << UPM11) | ( 0 << UPM10);			
			}
			//-------------------------------

	
				/* Data Bits Format */
				if(cDataBits==BIT_FORMAT_8bit)

			//-------------------------------

			/* Stop Bit */
			if(cStopBits==STOP_BIT_2bit)
			 UCSR1C = (1<<USBS1)|(3<<UCSZ10);
		
			//-------------------------------
	

			/*Set transmitter and receiver in UCSR0B port*/
			UCSR1B = ( 1 << TXEN1) | ( 1 << RXEN1); 
// enable transmitter and receiver	
	}
}
void WriteCharacter(unsigned port,unsigned char character)
{
	if(port==0)
	{
		while ( !( UCSR0A & (1<<UDRE0)) );		
		UDR0=character;
	} else
		if(port==1)
	{
		while ( !( UCSR1A & (1<<UDRE1)) );		
		UDR1=character;
	} else
		if(port==2)
	{
		while ( !( UCSR2A & (1<<UDRE2)) );		
		UDR2=character;
	}
}
int CharacterReady(unsigned port)
{
	if(potr==0)
		if ((UCSR0A & (1 << RXC0)))
		return 1;
			else
		return 0;
	else if(port==1)
		if ((UCSR1A & (1 << RXC1)))
		return 1;
			else
		return 0;
	else if(port==2)
		if ((UCSR2A & (1 << RXC2)))
		return 1;
			else
		return 0;
}
unsigned char ReadCharacter(unsigned port)
{		
	int a;
	if(port==0){
		while ( !(UCSR0A & (1<<RXC0)) );
		a=(unsigned char) UDR0;
	} else
	if(port==1){
		while ( !(UCSR1A & (1<<RXC1)) );
		a=(unsigned char) UDR1;
	} else
	if(port==2){
		while ( !(UCSR2A & (1<<RXC2)) );
		a=(unsigned char) UDR2;
	}
	return a; // return newly come character
}
