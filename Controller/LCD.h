/*
 * LCD.h
 *
 * Created: 2020-03-02 17:23:24
 *  Author: Emil Hallman
 */ 

#ifndef LCD_H_
#include "TinyTimber.h"
#include <avr/io.h>
#define LCD_H_

typedef struct {
	Object super;
} LCD;

#define initLCD() {initObject()}
	
void writeChar(char ch, int i);

void writeLong(long i);

void printAt(long num, int pos); 

void updateNorth(LCD *self, int data);

void updateBridge(LCD *self, int data);

void updateSouth(LCD *self, int data);

void init();

#endif /* LCD_H_ */