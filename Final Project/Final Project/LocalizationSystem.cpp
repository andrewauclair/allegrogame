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

#include "LocalizationSystem.h"
#include "Game.h"
#include "ChangeLanguageEvent.h"
#include <fstream>

LocalizationSystem::LocalizationSystem()
{
	mCurrentLanguage = 0;

	gpGame->getEventSystem()->addListener(CHANGE_LANGUAGE_EVENT, this);
}

LocalizationSystem::~LocalizationSystem()
{
}

//get all of the languages into the maps
void LocalizationSystem::loadLanguages()
{
	ifstream fin;
	int	langNum;

	fin.open("Languages/currentLanguage.txt");

	fin >> langNum;

	mCurrentLanguage = langNum;

	fin.close();
	fin.clear();

	const string files[] = {"Languages/english.txt", "Languages/nihongo.txt", "Languages/sdrawkcab.txt"};

	
	for(int i = 0; i < 3; i++)
	{
		fin.open(files[i].c_str());

		string text;

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(NEW_GAME, text));
		
		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(LOAD_GAME, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(OPTIONS, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(ENGLISH, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(JAPANESE, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(BACKWARDS, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(ATTACK, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(MAGIC, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(ITEMS, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(POTION, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(ETHER, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(BACK, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(GAME_OVER, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(SAVE, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(QUIT, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(LEVEL, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(TOTAL_EXP, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(INTRO_TEXT, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(END_GAME_TEXT, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(SOUND, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(LANGUAGES, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(EASY, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(MEDIUM, text));

		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(HARD, text));
		
		getline(fin, text);
		mLanguages[i].insert(pair<LANGUAGE_NUMBER, string>(NEXT, text));

		fin.close();
		fin.clear();
	}
}

//get text from current language
const string& LocalizationSystem::getText(int key) const
{
	return mLanguages[mCurrentLanguage].find(key)->second;
}

int LocalizationSystem::getCurrentLanguage()
{
	return mCurrentLanguage;
}

//set the current language and save it in the text file
void LocalizationSystem::setCurrentLanguage(int num)
{
	mCurrentLanguage = num;

	ofstream fout;

	fout.open("Languages/currentLanguage.txt");

	fout << mCurrentLanguage;

	fout.close();
	fout.clear();
}

void LocalizationSystem::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == CHANGE_LANGUAGE_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();

		// change language
		ChangeLanguageEvent* changeEvent = (ChangeLanguageEvent*)theEvent;

		setCurrentLanguage(changeEvent->getLanguage());
	}
}