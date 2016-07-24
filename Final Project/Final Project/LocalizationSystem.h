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

#ifndef LOCALIZATIONSYSTEM_H
#define LOCALIZATIONSYSTEM_H

#include "EventListener.h"
#include <map>
#include <string>

enum LANGUAGE_NUMBER
{
	NEW_GAME = 0,
	LOAD_GAME,
	OPTIONS,
	ENGLISH,
	JAPANESE,
	BACKWARDS,
	ATTACK,
	MAGIC,
	ITEMS,
	POTION,
	ETHER,
	BACK,
	GAME_OVER,
	SAVE,
	QUIT,
	LEVEL,
	TOTAL_EXP,
	INTRO_TEXT,
	SOUND,
	LANGUAGES,
	EASY,
	MEDIUM,
	HARD,
	NEXT,
	END_GAME_TEXT
};

class LocalizationSystem : public EventListener
{
private:

	std::multimap<int, std::string> mLanguages[3];
	int mCurrentLanguage;

public:

	LocalizationSystem();
	~LocalizationSystem();

	void loadLanguages();
	const std::string& getText(int key) const;

	int getCurrentLanguage();
	void setCurrentLanguage(int num);

	
	virtual void handleEvent(Event* theEvent);
};

#endif