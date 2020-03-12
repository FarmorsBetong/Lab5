/*
 * Queues.h
 *
 * Created: 2020-03-11 16:56:48
 *  Author: Robin
 */ 


#ifndef QUEUES_H_
#include "TinyTimber.h"
#define QUEUES_H_

typedef struct {
	Object super;
	int NorthQueue;
	int southQueue;
}Controller;

#define initController() {initObject(),0,0}
	
//Methods

void dataReceieved(Controller *self);






#endif /* QUEUES_H_ */