/*
 * Controller.c
 *
 * Created: 2020-03-12 13:26:58
 *  Author: Robin
 */ 

void dataReceieved(Controller *self, uint8_t data)
{
	if((data & 1) == 1) 
	{
		self->NorthQueue++;
		ASYNC(self,trafficLight,data);
	}
	else if(((data >> 1) & 1) == 1)
	{
		if(self->bridge > 0)
		{
			self->NorthQueue--;
		}
		self->bridge += 1;
		ASYNC(self,trafficLight,data);
	}
	else if(((data >> 2) & 1) == 1)
	{
		self->southQueue++;
	}
	else if(((data >> 3) & 1) == 1)
	{
		if(self->southQueue > 0) 
		{
			self->southQueue--;
		}
	}
	
}

void trafficLight(Controller *self , uint8_t data)
{
	if()
}