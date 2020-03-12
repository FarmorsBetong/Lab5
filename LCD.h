/*
 * LCD.h
 *
 * Created: 2020-03-02 17:23:24
 *  Author: Robin
 */ 

#ifndef LCD_H_
#include "TinyTimber.h"
#include "Controler.h"
#define LCD_H_


//methods
void writeChar(char ch, int i);
void printAt(long num, int pos); 
void init();
void updateLCDNorth();
void updateLCDSouth();

#endif /* LCD_H_ */