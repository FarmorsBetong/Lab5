/*
 * Controller.c
 *
 * Created: 2020-03-12 13:26:58
 *  Author: Emil
 */ 

#include "Controller.h"
#include "LCD.h"
#include <avr/io.h>
#include <ctype.h>
#include <avr/portpins.h>

#define ALT_AFTER 5

int carsPassed = 0;

void dataReceieved(Controller *self, uint8_t data)
{	
	if (data & 0x1)
	{
		self->northQueue++;
		ASYNC(self->lcd, updateNorth, self->northQueue);
		if (self->lightState == 0xA && self->southQueue == 0 && self->bridge == 0)
		{
			self->otherQueue = &self->southQueue;
			ASYNC(self, dataTransmit, 0x9);
		}
	} 
	else if (data & 0x2)
	{
		self->northQueue--;
		ASYNC(self, bridgePassing, 0);
	} 
	else if (data & 0x4)
	{
		self->southQueue++;		
		ASYNC(self->lcd, updateSouth, self->southQueue);
		if (self->lightState == 0xA && self->northQueue == 0 && self->bridge == 0)
		{
			self->otherQueue = &self->northQueue;
			ASYNC(self, dataTransmit, 0x6);
		}
	} 
	else if (data & 0x8)
	{
		self->southQueue--;
		ASYNC(self, bridgePassing, 0);
	}
	
	if ((self->northQueue == 0 && self->lightState == 0x9) || (self->southQueue == 0 && self->lightState == 0x6)) 
	{
		ASYNC(self, dataTransmit, 0xA);
	} 
	else if (carsPassed >= ALT_AFTER && self->otherQueue != 0) 
	{
		AFTER(MSEC(5000), self, dataTransmit, ~self->lightState);
		ASYNC(self, dataTransmit, 0xA);
	}
}

void bridgePassing(Controller *self, int arg) 
{
	self->bridge++;
	carsPassed++;
	ASYNC(self, updateLCD, 0);
	AFTER(MSEC(5000), self, bridgePassComplete, 0);
}

void bridgePassComplete(Controller *self, int arg) 
{
	self->bridge--;
	ASYNC(self->lcd, updateBridge, self->bridge);
}

void updateLCD(Controller *self, int arg)
{
	ASYNC(self->lcd, updateNorth, self->northQueue);
	ASYNC(self->lcd, updateBridge, self->bridge);
	ASYNC(self->lcd, updateSouth, self->southQueue);*/
}

void dataTransmit(Controller *self, uint8_t data) 
{
	self->lightState = data;
	UDR0 = data;
}