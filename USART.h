/*
 * USART.h
 *
 * Created: 2020-03-12 10:23:35
 *  Author: Robin
 */ 


#ifndef USART_H_
#include "Controler.h"
#include "TinyTimber.h"
#define USART_H_

typedef struct {
	Object super;
	Controller *contr;
}USART;

#define initUSART(contr) {initObject(),contr}

//methods

void USARTRecieved(USART *self);





#endif /* USART_H_ */