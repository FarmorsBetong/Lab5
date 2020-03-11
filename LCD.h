/*
 * LCD.h
 *
 * Created: 2020-03-02 17:23:24
 *  Author: Emil Hallman
 */ 

#ifndef LCD_H_
#include "TinyTimber.h"
#define LCD_H_

void writeChar(char ch, int i);

void printAt(long num, int pos); 

void init();

#endif /* LCD_H_ */