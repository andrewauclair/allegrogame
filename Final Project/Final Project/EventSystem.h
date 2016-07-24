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

#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <map>
#include "Event.h"
#include "EventListener.h"
#include <vector>
using namespace std;

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	void addEvent(Event* theEvent );
	void addListener( EVENT_TYPE type, EventListener* pListener );
	void removeListener( EVENT_TYPE type, EventListener* pListener );
	void removeListenerFromAllEvents( EventListener* pListener );
	void fireAllEvents();

private:
	multimap< EVENT_TYPE, EventListener* > mListenerMap;

	void dispatchAllEvents(Event* theEvent );

	
	vector<Event*> mEvents;
};

extern EventSystem* gpEventSystem;

#endif