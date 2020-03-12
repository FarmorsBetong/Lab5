<<<<<<< HEAD
/*
 * LCD.c
 *
 * Created: 2020-03-02 17:23:06
 *  Author: Robin
 */ 

#include <avr/io.h>
#include "LCD.h"

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
		LCDDR0 = (SCC_ch[0] << 4*i) | (LCDDR0&mask);
		LCDDR5 = (SCC_ch[1] << 4*i) | (LCDDR5&mask);
		LCDDR10 = (SCC_ch[2] << 4*i) | (LCDDR10&mask);
		LCDDR15 = (SCC_ch[3] << 4*i) | (LCDDR15&mask);
		
	} else if ((i == 2) | (i == 3))
	{
		LCDDR1 = (SCC_ch[0] << 4*(i%2)) | (LCDDR1&mask);
		LCDDR6 = (SCC_ch[1] << 4*(i%2)) | (LCDDR6&mask);
		LCDDR11 = (SCC_ch[2] << 4*(i%2)) | (LCDDR11&mask);
		LCDDR16 = (SCC_ch[3] << 4*(i%2)) | (LCDDR16&mask);
		
	} else if ((i == 4) | (i == 5))
	{
		LCDDR2 = (SCC_ch[0] << 4*(i%2)) | (LCDDR2&mask);
		LCDDR7 = (SCC_ch[1] << 4*(i%2)) | (LCDDR7&mask);
		LCDDR12 = (SCC_ch[2] << 4*(i%2)) | (LCDDR12&mask);
		LCDDR17 = (SCC_ch[3] << 4*(i%2)) | (LCDDR17&mask);
	}
}

void printAt(long num, int pos) {
=======
/*
 * LCD.c
 *
 * Created: 2020-03-02 17:23:06
 *  Author: Emil Hallman
 */ 

#include "LCD.h"
#include <avr/io.h>
#include <stdio.h>

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

void printAt(long num, int pos) 
{
>>>>>>> 6614d39e31bce8ad9da081216ea49e67f09a33fa
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
<<<<<<< HEAD
}

void init(){
	//clock prescaler
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	// --- LCD ----
	LCDCRB = 0xB7;	//LCD Control and status register B, duty and num of segments, and async clock selection
	LCDFRR = 0x7;	//LCD Frame rate register, prescaler divider (D) = 8
	LCDCCR = 0xF;	//Contrast control register, 300 sec and 3,35 V
	LCDCRA = 0xC0;	//LCD Control and status register A
	
	//Enable interrupt
	EIMSK = (1 << PCIE1) | (1 << PCIE0); //Enables you to enable pins 15-0 as interrupt pins
	EIFR = (1 << PCIF1) | (1 << PCIF0);
	PCMSK1 |= 0xD0; //Enable interrupt for PORT B
	PCMSK0 |= 0x0C; //Enables interrupt for PORT E, left and right
	
	PORTB = 0xD0; //Enables joysticks pins, up, down, press.
	PORTE = 0x0C; // left and right
	
	LCDDR3 = 1;	//enables right pulse.
}

//Uses the value of the pulse generator to print its value.

void updateLCD(LCD *self)
{
	printAt(self->g1->freqValue,0);	//Prints value of pulse gen 1 to the left
	printAt(self->g2->freqValue,4);	//Prints value of pulse gen 2  to the rigt
=======
}

void init()
{
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	LCDCRA= (1<<LCDEN) | (1<<LCDAB);
	LCDCRB= (1<<LCDMUX1) | (1<<LCDMUX0) | (1<<LCDPM2) | (1<<LCDPM1) | (1<<LCDPM0) | (1<<LCDCS);
	LCDCCR= (1<<LCDCC3) | (1<<LCDCC2) | (1<<LCDCC1) | (1<<LCDCC0);
	LCDFRR= (1<<LCDCD2) | (1<<LCDCD1) | (1<<LCDCD0);
	
	EIMSK = (1<<PCIE1) | (1<<PCIE0);
	EIFR = (1<<PCIF1) | (1<<PCIF0); 
	
	UBRR0 = MYUBRR;
	
	UCSR0B = (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
>>>>>>> 6614d39e31bce8ad9da081216ea49e67f09a33fa
}