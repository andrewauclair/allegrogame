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

#include "ItemsMenu.h"
#include "Game.h"
#include <sstream>

ItemsMenu::ItemsMenu()
:Menu(ITEMS_MENU)
{
}

ItemsMenu::~ItemsMenu()
{
	gpGame->getEventSystem()->removeListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->removeListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->removeListener(ENTER_EVENT, this);
}

void ItemsMenu::init(vector<Point> locations, int width)
{
	mLocations = locations;
	mWidth = width;

	mOptions.push_back(POTION);
	mOptions.push_back(ETHER);
	mOptions.push_back(BACK);

	mEvents.push_back(new Event(USE_POTION_EVENT));
	mEvents.push_back(new Event(USE_ETHER_EVENT));
	mEvents.push_back(new Event(BACK_EVENT));

	mWidth = width;
	mHandX = 0;
	mCurrentOption = 1;

	stringstream ss;
	ss << gpGame->getLocalizationSystem()->getText(mOptions[0]);
	ss << " x";
	ss << gpGame->getCael()->getNumPotions();

	int temp = gpGame->getGraphicsSystem()->getPixelWidthOfText(ss.str(), 40);

	if (temp > mHandX)
	{
		mHandX = temp;
	}

	ss.str("");

	ss << gpGame->getLocalizationSystem()->getText(mOptions[1]);
	ss << " x";
	ss << gpGame->getCael()->getNumEthers();

	temp = gpGame->getGraphicsSystem()->getPixelWidthOfText(ss.str(), 40);

	if (temp > mHandX)
	{
		mHandX = temp;
	}

	mHandIcon = gpGame->getAssetManager()->getSprite(HAND_ICON);


	// find where to draw the hand
	mHandX = locations[0].getX() + ((width/2) - (mHandX/2) - 60);

	gpGame->getEventSystem()->addListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->addListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->addListener(ENTER_EVENT, this);
}

void ItemsMenu::update()
{
	//gpGame->getGraphicsSystem()->drawText(mLocations[0], gpGame->getLocalizationSystem()->getText(mOptions[0]), 40, true, 300);
	stringstream ss;
	ss << gpGame->getLocalizationSystem()->getText(mOptions[0]);
	ss << " x";
	ss << gpGame->getCael()->getNumPotions();

	gpGame->getGraphicsSystem()->drawText(mLocations[0], ss.str(), 40, true, mWidth);

	ss.str("");
	ss << gpGame->getLocalizationSystem()->getText(mOptions[1]);
	ss << " x";
	ss << gpGame->getCael()->getNumEthers();

	gpGame->getGraphicsSystem()->drawText(mLocations[1], ss.str(), 40, true, mWidth);

	gpGame->getGraphicsSystem()->drawText(mLocations[2], gpGame->getLocalizationSystem()->getText(mOptions[2]), 40, true, mWidth);

	// draw the hand
	gpGame->getGraphicsSystem()->draw(Point(mHandX, mLocations[mCurrentOption-1].getY()), mHandIcon->getBitmap(), true);
}

void ItemsMenu::handleEvent(Event* theEvent)
{
	Menu::handleEvent(theEvent);
}