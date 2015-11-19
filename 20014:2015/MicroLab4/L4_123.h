#ifndef L4_123_H_
#define L4_123_H_

#define F_CPU 16000000

//Parity 0
#define OFF_PARITY 0
#define ODD_PARITY 1
#define EVEN_PARITY 2
#define BIT_FORMAT_8bit 1
//StopBit
#define STOP_BIT_1bit 1
#define STOP_BIT_2bit 2

void SetLineParameters( unsigned port, unsigned speed, unsigned parity, 
unsigned cDataBits, unsigned cStopBits );
void WriteCharacter( unsigned port, unsigned char character);
int CharacterReady( unsigned port); 
unsigned char ReadCharacter( unsigned port);
int WriteString(unsigned port, char *szOutput);
char* ReadString( unsigned port);

#endif