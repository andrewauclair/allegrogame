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

#include "InputSystem.h"
#include "Game.h"
#include "MoveEvent.h"
#include <iostream>
using namespace std;

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::init()
{
	install_keyboard();
	cout << "Installed Keyboard" << endl;
}

void InputSystem::update()
{
	if (!gpGame->isPaused() && !gpGame->getCael()->isInBattle() && !gpGame->isAtTitleScreen())
	{
		if (key[KEY_LEFT])
		{
			MoveEvent* moveEvent = new MoveEvent(LEFT);
			gpGame->getEventSystem()->addEvent(moveEvent);
		}
		else if (key[KEY_RIGHT])
		{
			MoveEvent* moveEvent = new MoveEvent(RIGHT);
			gpGame->getEventSystem()->addEvent(moveEvent);
		}
		else if (key[KEY_UP])
		{
			MoveEvent* moveEvent = new MoveEvent(UP);
			gpGame->getEventSystem()->addEvent(moveEvent);
		}
		else if (key[KEY_DOWN])
		{
			MoveEvent* moveEvent = new MoveEvent(DOWN);
			gpGame->getEventSystem()->addEvent(moveEvent);
		}
		else
		{
			Event* moveEvent = new Event(INVALID_EVENT_TYPE);
			gpGame->getEventSystem()->addEvent(moveEvent);
		}
	}

	while (keypressed())
	{
		// get next key off of buffer and make event
		int key = readkey();

		cout << key << endl;

		switch (key)
		{
		case 15131: // other wise known as escape
			{
				Event* newEvent = new Event(QUIT_EVENT);
				gpGame->getEventSystem()->addEvent(newEvent);
			}
			break;
		case 19232: // space bar
			{
				Event* newEvent = new Event(PAUSE_EVENT);
				gpGame->getEventSystem()->addEvent(newEvent);
			}
			break;
		case 21504: // up key
			{
				Event* newEvent = new Event(MENU_UP_EVENT);
				gpGame->getEventSystem()->addEvent(newEvent);
			}
			break;
		case 21760: // down key
			{
				Event* newEvent = new Event(MENU_DOWN_EVENT);
				gpGame->getEventSystem()->addEvent(newEvent);
			}
			break;
		case 17165: // enter key
			{
				Event* newEvent = new Event(ENTER_EVENT);
				gpGame->getEventSystem()->addEvent(newEvent);
			}
			break;
		case 20992: // left key
			{
				if (gpGame->getCael()->isInBattle())
				{
					Event* newEvent = new Event(LEFT_EVENT);
					gpGame->getEventSystem()->addEvent(newEvent);
				}
			}
			break;
		case 21248: // right key
			{
				if (gpGame->getCael()->isInBattle())
				{
					Event* newEvent = new Event(RIGHT_EVENT);
					gpGame->getEventSystem()->addEvent(newEvent);
				}
			}
			break;
		}
	}
}