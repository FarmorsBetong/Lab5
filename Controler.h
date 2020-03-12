/*
 * Controller.h
 *
 * Created: 2020-03-11 16:56:48
 *  Author: Robin
 */ 


#ifndef CONTROLLER_H_
#include "TinyTimber.h"
#define CONTROLLER_H_

typedef struct {
	Object super;
	int NorthQueue;
	int southQueue;
}Controller;

#define initController() {initObject(),0,0}
	
//Methods

void dataReceieved(Controller *self);






#endif /* CONTROLLER_H_ */