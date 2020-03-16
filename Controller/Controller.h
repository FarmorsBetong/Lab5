/*
 * Controller.h
 *
 * Created: 2020-03-11 16:56:48
 *  Author: Emil
 */ 

#ifndef CONTROLLER_H_
#include "TinyTimber.h"
#include <avr/io.h>
#include "LCD.h"
#define CONTROLLER_H_

typedef struct {
	Object super;
	int northQueue;
	int southQueue;
	int *otherQueue;
	int bridge;
	uint8_t lightState;
	LCD *lcd;
} Controller;

#define initController(lcd) {initObject(), 0, 0, 0, 0, 0xA, lcd}

void dataReceieved(Controller *self, uint8_t data);

void bridgePassing(Controller *self, int arg);

void bridgePassComplete(Controller *self, int arg);

void updateLCD(Controller *self, int arg);

void dataTransmit(Controller *self, uint8_t data);

#endif /* CONTROLLER_H_ */