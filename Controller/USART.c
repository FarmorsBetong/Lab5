/*
 * USART.c
 *
 * Created: 2020-03-12 12:51:04
 *  Author: Emil
 */ 

#include "USART.h"
#include "LCD.h"
#include <avr/io.h>
#include <avr/portpins.h>
#include <ctype.h>

void USARTReceived(USART *self, int arg) 
{
	uint8_t data = UDR0;
	ASYNC(self->controller, dataReceieved, data);
}