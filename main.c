/*
 * Lab5.c
 *
 * Created: 2020-03-09 18:24:47
 * Author : Robin
 */ 

#include <avr/io.h>
#include "USART.h"
#include "TinyTimber.h"
#include "LCD.h"
#include "Controler.h"


//object instances
Controller contr = initController();
LCD lcd = initLCD(&contr);
USART usart = initUSART(&contr);

int main(void)
{
    init();
	
	INSTALL(&usart,USARTRecieved, IRQ_USART0_RX); // RX for "receive interrupt"
	
	return TINYTIMBER(&lcd,updateLCD,0); // print and give tinytimber the control and wait for interrupt.
}

