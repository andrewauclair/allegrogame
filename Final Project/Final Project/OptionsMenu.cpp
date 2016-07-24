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

#include "OptionsMenu.h"
#include "Game.h"
#include "ChangeLanguageEvent.h"
#include <string>

OptionsMenu::OptionsMenu(vector<Point> locations, int width)
:Menu(OPTIONS_MENU)
{
	init(locations, width);
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::init(vector<Point> locations, int width)
{
	mLocations = locations;
	mWidth = width;

	mOptions.push_back(SOUND);
	mOptions.push_back(LANGUAGES);
	mOptions.push_back(BACK);

	mEvents.push_back(new Event(SOUND_EVENT));
	mEvents.push_back(new Event(LANGUAGES_EVENT));
	mEvents.push_back(new Event(BACK_EVENT));

	mHandX = 0;
	mCurrentOption = 1;

	string text = gpGame->getLocalizationSystem()->getText(mOptions[0]);
	text += " OFF";
	
	if (gpGame->getGraphicsSystem()->getPixelWidthOfText(text, 40) > mHandX)
	{
		mHandX = gpGame->getGraphicsSystem()->getPixelWidthOfText(text, 40);
	}

	int temp = gpGame->getGraphicsSystem()->getPixelWidthOfText(gpGame->getLocalizationSystem()->getText(mOptions[1]), 40);

	if (temp > mHandX)
	{
		mHandX = temp;
	}

	mHandIcon = gpGame->getAssetManager()->getSprite(HAND_ICON);

	// find where to draw the hand
	mHandX = mLocations[0].getX() + ((width/2) - (mHandX/2) - 60);

	gpGame->getEventSystem()->addListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->addListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->addListener(ENTER_EVENT, this);
}

void OptionsMenu::update()
{
	// draw the menu
	string text = gpGame->getLocalizationSystem()->getText(mOptions[0]);
	text += " ";

	if (gpGame->getSoundManager()->isSoundOn())
	{
		text += "ON";
	}
	else
	{
		text += "OFF";
	}

	gpGame->getGraphicsSystem()->drawText(mLocations[0], text, 40, true, mWidth);
	gpGame->getGraphicsSystem()->drawText(mLocations[1], gpGame->getLocalizationSystem()->getText(mOptions[1]), 40, true, mWidth);
	gpGame->getGraphicsSystem()->drawText(mLocations[2], gpGame->getLocalizationSystem()->getText(mOptions[2]), 40, true, mWidth);
	
	// draw hand
	gpGame->getGraphicsSystem()->draw(Point(mHandX, mLocations[mCurrentOption-1].getY()), mHandIcon->getBitmap(), true);
}

void OptionsMenu::handleEvent(Event* theEvent)
{
	Menu::handleEvent(theEvent);
}