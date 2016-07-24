/*
	Author:			Erin Trzcinski and Andrew Auclair
	Class:			EGP 310 01
	Assignment:		Final Project: Dance with the Devil	
	Date Assigned:	2011 03 30
	Due Date:		2011 04 27 at 1:00PM

	Description:	To create a create a game using the architecture 
					we've learned in class

	Certification of Authenticity:
		We certify that this assignment is entirely our own work. 
		Save for the art, music, sound effects, A* pathfinding, etc.
*/

#ifndef CHANGEMAPEVENT_H
#define CHANGEMAPEVENT_H

#include "Event.h"

enum MAP_DIRECTION
{
	MAP_LEFT = 0,
	MAP_UP,
	MAP_RIGHT,
	MAP_DOWN
};

class ChangeMapEvent : public Event
{
public:
	ChangeMapEvent(int direction);

	int getDirection() const { return mDirection;};

private:
	int mDirection;
};

#endif