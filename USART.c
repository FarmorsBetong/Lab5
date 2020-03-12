/*
 * USART.c
 *
 * Created: 2020-03-12 13:09:57
 *  Author: Robin
 */ 

#include "USART.h"

void USARTRecieved(USART *self)
{
	uint8_t data = UDR0;
	ASYNC(self->contr,dataReceieved, data);
}
