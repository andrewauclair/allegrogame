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

#ifndef MENU_H
#define MENU_H

#include "AnimatedSprite.h"
#include "LocalizationSystem.h"
#include "Event.h"
#include "EventListener.h"
#include <vector>
using namespace std;

enum MENU_NAME
{
	NO_MENU = -1,
	TITLE_MENU,
	MAIN_MENU,
	OPTIONS_MENU,
	ITEMS_MENU,
	LANGUAGES_MENU,
	DIFFICULTY_MENU,
	BATTLE_MENU,
	GAME_OVER_MENU
};

class Menu : public EventListener
{
public:
	Menu(MENU_NAME name);
	virtual ~Menu();

	virtual void init(vector<LANGUAGE_NUMBER> options, vector<Event*> events, vector<Point> locations, int width);
	virtual void update();

	virtual void handleEvent(Event* theEvent);

	MENU_NAME getName();

	void freeze();
	void unfreeze();

protected:
	int mCurrentOption;
	int mWidth;
	int mHandX;

	vector<LANGUAGE_NUMBER> mOptions;
	vector<Event*> mEvents;
	vector<Point> mLocations;

	AnimatedSprite* mHandIcon;

	bool mFrozen;

	MENU_NAME mName;
};

#endif