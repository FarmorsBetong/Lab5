/*
 * LCD.c
 *
 * Created: 2020-03-02 17:23:06
 *  Author: Emil Hallman
 */ 

#include "LCD.h"

#define FOSC 8000000UL
#define BAUD 9600
#define MYUBRR FOSC/16*BAUD - 1

void writeChar(char ch, int i)
{
	unsigned char SCC_ch[4];
	
	switch (ch) {
		case '0' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x5;
		SCC_ch[2] = 0x5;
		SCC_ch[3] = 0x1;
		break;
		
		case '1' :
		SCC_ch[0] = 0x0;
		SCC_ch[1] = 0x1;
		SCC_ch[2] = 0x1;
		SCC_ch[3] = 0x0;
		break;
		
		case '2' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x1;
		SCC_ch[2] = 0xE;
		SCC_ch[3] = 0x1;
		break;
		
		case '3' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x1;
		SCC_ch[2] = 0xB;
		SCC_ch[3] = 0x1;
		break;
		
		case '4' :
		SCC_ch[0] = 0x0;
		SCC_ch[1] = 0x5;
		SCC_ch[2] = 0xB;
		SCC_ch[3] = 0x0;
		break;
		
		case '5' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x4;
		SCC_ch[2] = 0xB;
		SCC_ch[3] = 0x1;
		break;
		
		case '6' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x4;
		SCC_ch[2] = 0xF;
		SCC_ch[3] = 0x1;
		break;
		
		case '7' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x1;
		SCC_ch[2] = 0x1;
		SCC_ch[3] = 0x0;
		break;
		
		case '8' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x5;
		SCC_ch[2] = 0xF;
		SCC_ch[3] = 0x1;
		break;
		
		case '9' :
		SCC_ch[0] = 0x1;
		SCC_ch[1] = 0x5;
		SCC_ch[2] = 0xB;
		SCC_ch[3] = 0x1;
		break;
		
		default:
		SCC_ch[0] = 0x0;
		SCC_ch[1] = 0x0;
		SCC_ch[2] = 0x0;
		SCC_ch[3] = 0x0;
		break;
	}
	
	int mask;
	
	if ((i % 2) == 1) {mask = 0x0F;}
	else {mask = 0xF0;}
	

	if ((i == 0) | (i == 1))
	{
		LCDDR0 = (SCC_ch[0] << 4*i) | (LCDDR0&(mask|0x66));
		LCDDR5 = (SCC_ch[1] << 4*i) | (LCDDR5&mask);
		LCDDR10 = (SCC_ch[2] << 4*i) | (LCDDR10&mask);
		LCDDR15 = (SCC_ch[3] << 4*i) | (LCDDR15&mask);
		
	} else if ((i == 2) | (i == 3))
	{
		LCDDR1 = (SCC_ch[0] << 4*(i%2)) | (LCDDR1&(mask|0x66));
		LCDDR6 = (SCC_ch[1] << 4*(i%2)) | (LCDDR6&mask);
		LCDDR11 = (SCC_ch[2] << 4*(i%2)) | (LCDDR11&mask);
		LCDDR16 = (SCC_ch[3] << 4*(i%2)) | (LCDDR16&mask);
		
	} else if ((i == 4) | (i == 5))
	{
		LCDDR2 = (SCC_ch[0] << 4*(i%2)) | (LCDDR2&(mask|0x66));
		LCDDR7 = (SCC_ch[1] << 4*(i%2)) | (LCDDR7&mask);
		LCDDR12 = (SCC_ch[2] << 4*(i%2)) | (LCDDR12&mask);
		LCDDR17 = (SCC_ch[3] << 4*(i%2)) | (LCDDR17&mask);
	}
}

void writeLong(long i) 
{
	int pos = 5; // where to display a digit
	while (i >= 0) {
		int ch = i % 10; // get the rightmost digit
		writeChar(ch + '0', pos); // use writeChar to display it
		pos--;
		i = i / 10; // remove rightmost digit
	}
}

void printAt(long num, int pos) 
{
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}

void updateNorth(LCD *self, int data) 
{
	printAt(data, 0);
}

void updateBridge(LCD *self, int data) 
{
	printAt(data, 2);
}

void updateSouth(LCD *self, int data)
{
	printAt(data, 4);
}

void init()
{
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	LCDCRA= (1<<LCDEN) | (1<<LCDAB);
	LCDCRB= (1<<LCDMUX1) | (1<<LCDMUX0) | (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0) | (1<<LCDCS);
	LCDCCR= (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1) | (1<<LCDCC0);
	LCDFRR= (1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0);

	UBRR0H = MYUBRR >> 8;
	UBRR0L = MYUBRR;	
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
}