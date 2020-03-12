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
		self->NorthQueue += 1;
		updateLCDNorth();
	}
}