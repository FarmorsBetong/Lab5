/*
 * lab5.c
 *
 * Created: 2020-03-10 17:52:46
 * Author : Emil
 */ 

#include "LCD.h"
#include "USART.h"
#include "Controller.h"
#include <avr/interrupt.h>
#include <avr/io.h>

LCD lcd = initLCD();
Controller controller = initController(&lcd);
USART usart = initUSART(&controller);

int main(void)
{
	init();
	
	INSTALL(&usart, USARTReceived, IRQ_USART0_RX);
	
	return TINYTIMBER(&controller, updateLCD, 0);
}