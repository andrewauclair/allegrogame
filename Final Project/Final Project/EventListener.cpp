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

#include "EventListener.h"
#include "EventSystem.h"
#include "Game.h"

/*
Pre: none
Post: initialized
Purpose: create event listener
*/
EventListener::EventListener()
{
}

/*
Pre: initialized
Post: none
Purpose: destroy event listener
*/
EventListener::~EventListener()
{
	if (gpGame->getEventSystem() != NULL)
	{
		gpGame->getEventSystem()->removeListenerFromAllEvents( this );
	}
}