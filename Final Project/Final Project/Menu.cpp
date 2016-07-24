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

#include "Menu.h"
#include "Game.h"
#include <sstream>
using namespace std;

Menu::Menu(MENU_NAME name)
{
	mName = name;
	mFrozen = false;
}

Menu::~Menu()
{
	gpGame->getEventSystem()->removeListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->removeListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->removeListener(ENTER_EVENT, this);
}

void Menu::init(vector<LANGUAGE_NUMBER> options, vector<Event*> events, vector<Point> locations, int width)
{
	mOptions = options;
	mEvents = events;
	mLocations = locations;
	mWidth = width;
	mHandX = 0;
	mCurrentOption = 1;

	// find the longest string of text
	for (unsigned int i = 0; i < options.size(); i++)
	{
		int temp = gpGame->getGraphicsSystem()->getPixelWidthOfText(gpGame->getLocalizationSystem()->getText(options[i]), 40);

		if (temp > mHandX)
		{
			mHandX = temp;
		}
	}

	mHandIcon = gpGame->getAssetManager()->getSprite(HAND_ICON);
	
	// find where to draw the hand
	mHandX = locations[0].getX() + ((width/2) - (mHandX/2) - 60);

	gpGame->getEventSystem()->addListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->addListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->addListener(ENTER_EVENT, this);
}

void Menu::update()
{
	// draw all the options at their locations on the screen
	for (unsigned int i = 0; i < mOptions.size(); i++)
	{
		gpGame->getGraphicsSystem()->drawText(mLocations[i], gpGame->getLocalizationSystem()->getText(mOptions[i]), 40, true, mWidth);
	}

	// draw hand
	gpGame->getGraphicsSystem()->draw(Point(mHandX, mLocations[mCurrentOption-1].getY()), mHandIcon->getBitmap(), true);
}

void Menu::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == MENU_UP_EVENT)
	{
		gpGame->getSoundManager()->playMenuTraverse();

		if (mCurrentOption <= 1)
		{
			mCurrentOption = mOptions.size();
		}
		else
		{
			mCurrentOption--;
		}
	}
	else if (theEvent->getType() == MENU_DOWN_EVENT)
	{
		gpGame->getSoundManager()->playMenuTraverse();

		if ((unsigned)mCurrentOption < mOptions.size())
		{
			mCurrentOption++;
		}
		else
		{
			mCurrentOption = 1;
		}
	}
 	else if (theEvent->getType() == ENTER_EVENT)
	{
		if (!mFrozen)
		{
			gpGame->getEventSystem()->addEvent(mEvents[mCurrentOption-1]);
		}
	}
}

MENU_NAME Menu::getName()
{
	return mName;
}

void Menu::freeze()
{
	mFrozen = true;
}

void Menu::unfreeze()
{
	mFrozen = false;
}