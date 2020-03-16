/*
 * USART.h
 *
 * Created: 2020-03-12 13:11:05
 *  Author: Emil
 */

#ifndef USART_H_
#include "TinyTimber.h"
#include "Controller.h"
#include <avr/io.h>
#define USART_H_

typedef struct {
	Object super;	
	Controller *controller;
} USART;

#define initUSART(controller) {initObject(), controller}

void USARTReceived(USART *self, int arg);

#endif /* USART_H_ */