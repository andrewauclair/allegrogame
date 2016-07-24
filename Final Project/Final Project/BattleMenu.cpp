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

#include "BattleMenu.h"
#include "Game.h"
#include <sstream>
using namespace std;

BattleMenu::BattleMenu()
:Menu(BATTLE_MENU)
{
}

BattleMenu::~BattleMenu()
{
}

void BattleMenu::init(vector<Point> locations, int width)
{
	mOptions.push_back(ATTACK);
	mOptions.push_back(MAGIC);
	mOptions.push_back(ITEMS);

	mEvents.push_back(new Event(ATTACK_EVENT));
	mEvents.push_back(new Event(MAGIC_EVENT));
	mEvents.push_back(new Event(ITEMS_EVENT));

	mLocations = locations;

	stringstream ss;
	ss << gpGame->getLocalizationSystem()->getText(mOptions[1]);
	ss << " 10";

	mHandX = gpGame->getGraphicsSystem()->getPixelWidthOfText(ss.str(), 40);

	mHandX = locations[0].getX() + ((width/2) - (mHandX/2) - 60);

	mHandIcon = gpGame->getAssetManager()->getSprite(HAND_ICON);

	mCurrentOption = 1;

	mWidth = width;

	gpGame->getEventSystem()->addListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->addListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->addListener(ENTER_EVENT, this);
}

void BattleMenu::update()
{
	// draw menu
	gpGame->getGraphicsSystem()->drawText(mLocations[0], gpGame->getLocalizationSystem()->getText(mOptions[0]), 40, true, mWidth);
	
	stringstream ss;
	ss << gpGame->getLocalizationSystem()->getText(mOptions[1]);
	ss << " 10";

	gpGame->getGraphicsSystem()->drawText(mLocations[1], ss.str(), 40, true, mWidth);

	gpGame->getGraphicsSystem()->drawText(mLocations[2], gpGame->getLocalizationSystem()->getText(mOptions[2]), 40, true, mWidth);
	
	// draw hand
	gpGame->getGraphicsSystem()->draw(Point(mHandX, mLocations[mCurrentOption-1].getY()), mHandIcon->getBitmap(), true);
}

void BattleMenu::handleEvent(Event* theEvent)
{
	Menu::handleEvent(theEvent);
}