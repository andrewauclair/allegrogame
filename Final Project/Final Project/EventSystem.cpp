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

#include "EventSystem.h"
#include <iostream>
using namespace std;

/*
Pre: none
Post: initialized
Purpose: create event system
*/
EventSystem::EventSystem()
{
}

/*
Pre: initialized
Post: none
Purpose: destroy event system
*/
EventSystem::~EventSystem()
{
}

/*
Pre: initialized
Post: listener added
Purpose: add listener for event type
*/
void EventSystem::addListener(EVENT_TYPE type, EventListener* pListener)
{
	mListenerMap.insert( pair< EVENT_TYPE, EventListener* >(type, pListener) );
}

/*
Pre: initialized
Post: listener removed
Purpose: remove listener from type
*/
void EventSystem::removeListener(EVENT_TYPE type, EventListener *pListener)
{
	pair<multimap<EVENT_TYPE,EventListener*>::iterator,multimap<EVENT_TYPE,EventListener*>::iterator> ret;

	ret = mListenerMap.equal_range( type );
	multimap<EVENT_TYPE,EventListener*>::iterator iter;

	for( iter = ret.first; iter != ret.second; ++iter )
	{
		if( iter->second == pListener )
		{
			mListenerMap.erase( iter );
			break;//to prevent using invalidated iterator
		}
	}
}

/*
Pre: initialized
Post: listener removed from all events
Purpose: remove listener from all events
*/
void EventSystem::removeListenerFromAllEvents( EventListener* pListener )
{
	multimap<EVENT_TYPE,EventListener*>::iterator iter;

	bool allTheWayThrough = false;

	while( !allTheWayThrough )
	{
		allTheWayThrough = true;
		for( iter = mListenerMap.begin(); iter != mListenerMap.end(); ++iter )
		{
			if( iter->second == pListener )
			{
				mListenerMap.erase( iter );
				allTheWayThrough = false; //didn't make it the whole way through
				break;//to prevent using invalidated iterator
			}
		}
	}
}

/*
Pre: initialized
Post: event fired
Purpose: fire an event
*/
void EventSystem::addEvent(Event* theEvent)
{
	mEvents.push_back(theEvent);
}

/*
Pre: initialized
Post: event dispatched to all listeners
Purpose: dispatch the event to all listeners listening for it
*/
void EventSystem::dispatchAllEvents(Event* theEvent )
{
	multimap<EVENT_TYPE, EventListener*>::iterator iter;

	iter = mListenerMap.find(theEvent->getType());

	if (iter == mListenerMap.end())
	{
		return;
	}

	while (iter != mListenerMap.end() && iter->first == theEvent->getType())
	{
		iter->second->handleEvent(theEvent);
		iter++;
	}
}

void EventSystem::fireAllEvents()
{
	for (unsigned int i = 0; i < mEvents.size(); i++)
	{
		dispatchAllEvents(mEvents[i]);
	}

	while (!mEvents.empty())
	{
		mEvents.pop_back();
	}
}