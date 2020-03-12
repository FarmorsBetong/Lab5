<<<<<<< HEAD
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



typedef struct {
	Object super;
	Controller *contr;
}LCD;

#define initLCD(contr) {initObject(),contr}

//methods
void writeChar(char ch, int i);
void printAt(long num, int pos); 
void init();
void updateLCD(LCD *self);

=======
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

>>>>>>> 6614d39e31bce8ad9da081216ea49e67f09a33fa
#endif /* LCD_H_ */