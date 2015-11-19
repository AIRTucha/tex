#include "L4_123.h"
#include "L4_4.h"
#include <asf.h>
#include <stdlib.h>

int WriteString(unsigned port, char *szOutput)
{
	do{
		WriteCharacter(port,*(szOutput++));
	}while(*szOutput!='\0');
	return 0;
}
char* ReadString( unsigned port)
{
	static char buffer[80] = {0};
	int i=0;
	do{
		buffer[i]=ReadCharacter(port);
		if(buffer[i] < 15)
		return buffer;
		else
		i++;
		
	}while(1);
	
}