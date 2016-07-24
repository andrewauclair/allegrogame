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

#include "MenuSystem.h"
#include "Game.h"
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "ItemsMenu.h"
#include "ChangeLanguageEvent.h"
#include "NewGameEvent.h"
#include "BattleMenu.h"
#include <iostream>
using namespace std;

MenuSystem::MenuSystem()
{
}

MenuSystem::~MenuSystem()
{
	delete mCurrentMenu;
}

void MenuSystem::init()
{
	vector<LANGUAGE_NUMBER> options;
	options.push_back(NEW_GAME);
	options.push_back(LOAD_GAME);
	options.push_back(OPTIONS);
	options.push_back(QUIT);

	vector<Event*> events;
	events.push_back(new Event(DIFFICULTY_EVENT));
	events.push_back(new Event(LOAD_GAME_EVENT));
	events.push_back(new Event(OPTIONS_EVENT));
	events.push_back(new Event(QUIT_EVENT));

	vector<Point> locations;
	locations.push_back(Point(0, 370));
	locations.push_back(Point(0, 420));
	locations.push_back(Point(0, 470));
	locations.push_back(Point(0, 520));

	mCurrentMenu = new Menu(TITLE_MENU);
	mCurrentMenu->init(options, events, locations, 900);

	mMajorMenu = TITLE_MENU;

	mBackground = gpGame->getAssetManager()->getSprite(TITLE_MENU_BACKGROUND);

	gpGame->getEventSystem()->addListener(BACK_EVENT, this);
	gpGame->getEventSystem()->addListener(QUIT_EVENT, this);
	gpGame->getEventSystem()->addListener(ITEMS_EVENT, this);
	gpGame->getEventSystem()->addListener(NEW_GAME_EVENT, this);
	gpGame->getEventSystem()->addListener(OPTIONS_EVENT, this);
	gpGame->getEventSystem()->addListener(PAUSE_EVENT, this);
	gpGame->getEventSystem()->addListener(LANGUAGES_EVENT, this);
	gpGame->getEventSystem()->addListener(DIFFICULTY_EVENT, this);
	gpGame->getEventSystem()->addListener(BATTLE_EVENT, this);
	gpGame->getEventSystem()->addListener(END_BATTLE_EVENT, this);
	gpGame->getEventSystem()->addListener(LOAD_GAME_EVENT, this);
	gpGame->getEventSystem()->addListener(GAME_OVER_EVENT, this);
	gpGame->getEventSystem()->addListener(END_TURN_EVENT, this);
}

void MenuSystem::update()
{
	// check to see if current menu exists
	if (mCurrentMenu != NULL)
	{
		// draw the background
		if (mMajorMenu == TITLE_MENU)
		{
			gpGame->getGraphicsSystem()->draw(Point(0, 0), mBackground->getFrames()[gpGame->getLocalizationSystem()->getCurrentLanguage()], false);
		}
		else if (mMajorMenu == MAIN_MENU)
		{
			gpGame->getGraphicsSystem()->draw(Point(0, 0), mBackground->getBitmap(), false);
		}

		// update menu
		mCurrentMenu->update();
	}
}

void MenuSystem::handleEvent(Event* theEvent)
{
	//go back to previous menu
	if (theEvent->getType() == BACK_EVENT)
	{
		gpGame->getSoundManager()->playMenuBack();

		if (mCurrentMenu->getName() == OPTIONS_MENU)
		{
			vector<LANGUAGE_NUMBER> options;
			vector<Event*> events;
			vector<Point> locations;

			//go back to title
			if (mMajorMenu == TITLE_MENU)
			{
				delete mCurrentMenu;
				mCurrentMenu = new Menu(TITLE_MENU);
				
				options.push_back(NEW_GAME);
				options.push_back(LOAD_GAME);
				options.push_back(OPTIONS);
				options.push_back(QUIT);

				events.push_back(new Event(DIFFICULTY_EVENT));
				events.push_back(new Event(LOAD_GAME_EVENT));
				events.push_back(new Event(OPTIONS_EVENT));
				events.push_back(new Event(QUIT_EVENT));

				locations.push_back(Point(0, 370));
				locations.push_back(Point(0, 420));
				locations.push_back(Point(0, 470));
				locations.push_back(Point(0, 520));

				mCurrentMenu->init(options, events, locations, 900);
			}
			//go back to main menu
			else if (mMajorMenu == MAIN_MENU)
			{
				options.push_back(ITEMS);
				options.push_back(OPTIONS);
				options.push_back(SAVE);
				options.push_back(QUIT);

				events.push_back(new Event(ITEMS_EVENT));
				events.push_back(new Event(OPTIONS_EVENT));
				events.push_back(new Event(SAVE_EVENT));
				events.push_back(new Event(QUIT_EVENT));

				locations.push_back(Point(600, 100));
				locations.push_back(Point(600, 190));
				locations.push_back(Point(600, 280));
				locations.push_back(Point(600, 370));

				delete mCurrentMenu;
				mCurrentMenu = new Menu(MAIN_MENU);
				mCurrentMenu->init(options, events, locations, 300);
			}

			
		}
		//go back to options menu
		else if (mCurrentMenu->getName() == LANGUAGES_MENU)
		{
			gpGame->getSoundManager()->playMenuSelect();

			vector<Point> locations;

			if (mMajorMenu == TITLE_MENU)
			{
				locations.push_back(Point(0, 370));
				locations.push_back(Point(0, 420));
				locations.push_back(Point(0, 470));
				
				delete mCurrentMenu;
				mCurrentMenu = new OptionsMenu(locations, 900);
			}
			else if (mMajorMenu == MAIN_MENU)
			{
				locations.push_back(Point(600, 100));
				locations.push_back(Point(600, 190));
				locations.push_back(Point(600, 280));

				delete mCurrentMenu;
				mCurrentMenu = new OptionsMenu(locations, 300);
			}
		}
		else if (mCurrentMenu->getName() == ITEMS_MENU)
		{
			gpGame->getSoundManager()->playMenuSelect();

			if (mMajorMenu == MAIN_MENU)
			{
				// go back to main menu
				vector<LANGUAGE_NUMBER> options;
				options.push_back(ITEMS);
				options.push_back(OPTIONS);
				options.push_back(SAVE);
				options.push_back(QUIT);

				vector<Event*> events;
				events.push_back(new Event(ITEMS_EVENT));
				events.push_back(new Event(OPTIONS_EVENT));
				events.push_back(new Event(SAVE_EVENT));
				events.push_back(new Event(QUIT_EVENT));

				vector<Point> locations;
				locations.push_back(Point(600, 100));
				locations.push_back(Point(600, 190));
				locations.push_back(Point(600, 280));
				locations.push_back(Point(600, 370));

				delete mCurrentMenu;
				mCurrentMenu = new Menu(MAIN_MENU);
				mCurrentMenu->init(options, events, locations, 300);
			}
			else if (mMajorMenu == BATTLE_MENU)
			{
				vector<Point> locations;
				locations.push_back(Point(0, 420));
				locations.push_back(Point(0, 470));
				locations.push_back(Point(0, 520));

				delete mCurrentMenu;
				mCurrentMenu = new BattleMenu();
				((BattleMenu*)mCurrentMenu)->init(locations, 350);
			}
		}
		else if (mCurrentMenu->getName() == DIFFICULTY_MENU)
		{
			delete mCurrentMenu;
			mCurrentMenu = new Menu(TITLE_MENU);
			
			vector<LANGUAGE_NUMBER> options;
			vector<Event*> events;
			vector<Point> locations;

			options.push_back(NEW_GAME);
			options.push_back(LOAD_GAME);
			options.push_back(OPTIONS);
			options.push_back(QUIT);

			events.push_back(new Event(DIFFICULTY_EVENT));
			events.push_back(new Event(LOAD_GAME_EVENT));
			events.push_back(new Event(OPTIONS_EVENT));
			events.push_back(new Event(QUIT_EVENT));

			locations.push_back(Point(0, 370));
			locations.push_back(Point(0, 420));
			locations.push_back(Point(0, 470));
			locations.push_back(Point(0, 520));

			mCurrentMenu->init(options, events, locations, 900);
		}
	}
	//quit the game
	else if (theEvent->getType() == QUIT_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();
		
		if (mMajorMenu == TITLE_MENU)
		{
			// quit the game
			gpGame->setShouldExit(true);
		}
		else
		{
			gpGame->getSoundManager()->stopWanderingMusic();
			gpGame->getSoundManager()->stopBattleMusic();
			gpGame->getSoundManager()->stopBossMusic();
			gpGame->getSoundManager()->stopCreditMusic();
			gpGame->getSoundManager()->stopAllSounds();

			// return to the title menu
			mMajorMenu = TITLE_MENU;
			delete mCurrentMenu;
			mCurrentMenu = new Menu(TITLE_MENU);

			vector<LANGUAGE_NUMBER> options;
			options.push_back(NEW_GAME);
			options.push_back(LOAD_GAME);
			options.push_back(OPTIONS);
			options.push_back(QUIT);

			vector<Event*> events;
			events.push_back(new Event(DIFFICULTY_EVENT));
			events.push_back(new Event(LOAD_GAME_EVENT));
			events.push_back(new Event(OPTIONS_EVENT));
			events.push_back(new Event(QUIT_EVENT));

			vector<Point> locations;
			locations.push_back(Point(0, 370));
			locations.push_back(Point(0, 420));
			locations.push_back(Point(0, 470));
			locations.push_back(Point(0, 520));

			mCurrentMenu->init(options, events, locations, 900);

			mBackground = gpGame->getAssetManager()->getSprite(TITLE_MENU_BACKGROUND);

			gpGame->setPaused(false);
			gpGame->setIsAtTitleScreen(true);
		}
	}
	else if (theEvent->getType() == ITEMS_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();

		delete mCurrentMenu;
		mCurrentMenu = new ItemsMenu();
		if (mMajorMenu == MAIN_MENU)
		{
			vector<Point> locations;
			locations.push_back(Point(600, 100));
			locations.push_back(Point(600, 190));
			locations.push_back(Point(600, 280));

			((ItemsMenu*)mCurrentMenu)->init(locations, 300);
		}
		else if (mMajorMenu == BATTLE_MENU)
		{
			vector<Point> locations;
			locations.push_back(Point(0, 420));
			locations.push_back(Point(0, 470));
			locations.push_back(Point(0, 520));

			((BattleMenu*)mCurrentMenu)->init(locations, 350);
		}
	}
	else if (theEvent->getType() == OPTIONS_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();

		// create new options menu
		vector<Point> locations;

		if (mMajorMenu == TITLE_MENU)
		{
			locations.push_back(Point(0, 370));
			locations.push_back(Point(0, 420));
			locations.push_back(Point(0, 470));
			
			delete mCurrentMenu;
			mCurrentMenu = new OptionsMenu(locations, 900);
		}
		else if (mMajorMenu == MAIN_MENU)
		{
			locations.push_back(Point(600, 100));
			locations.push_back(Point(600, 190));
			locations.push_back(Point(600, 280));

			delete mCurrentMenu;
			mCurrentMenu = new OptionsMenu(locations, 300);
		}

		
	}
	else if (theEvent->getType() == NEW_GAME_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();

		// remove the current menu
		delete mCurrentMenu;
		mCurrentMenu = NULL;

		mMajorMenu = NO_MENU;

		gpGame->setIsAtTitleScreen(false);
	}
	else if (theEvent->getType() == PAUSE_EVENT)
	{
		// pause or unpause the game
		if (gpGame->isPaused())
		{
			gpGame->getSoundManager()->playMenuExit();

			// un pause the game
			gpGame->setPaused(false);
			delete mCurrentMenu;
			mCurrentMenu = NULL;
		}
		else
		{
			// pause the game if cael isn't in battle or at title menu
			if (mMajorMenu != TITLE_MENU)
			{
				if (!gpGame->getCael()->isInBattle())
				{
					gpGame->getSoundManager()->playMenuOpen();

					gpGame->setPaused(true);

					mMajorMenu = MAIN_MENU;
					delete mCurrentMenu;
					
					vector<LANGUAGE_NUMBER> options;
					options.push_back(ITEMS);
					options.push_back(OPTIONS);
					options.push_back(SAVE);
					options.push_back(QUIT);

					vector<Event*> events;
					events.push_back(new Event(ITEMS_EVENT));
					events.push_back(new Event(OPTIONS_EVENT));
					events.push_back(new Event(SAVE_EVENT));
					events.push_back(new Event(QUIT_EVENT));

					vector<Point> locations;
					locations.push_back(Point(600, 100));
					locations.push_back(Point(600, 190));
					locations.push_back(Point(600, 280));
					locations.push_back(Point(600, 370));

					delete mCurrentMenu;
					mCurrentMenu = new Menu(MAIN_MENU);
					mCurrentMenu->init(options, events, locations, 300);

					mBackground = gpGame->getAssetManager()->getSprite(MENU_BACKGROUND);
				}
			}
		}
	}
	else if (theEvent->getType() == LANGUAGES_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();

		vector<LANGUAGE_NUMBER> options;
		options.push_back(ENGLISH);
		options.push_back(JAPANESE);
		options.push_back(BACKWARDS);
		options.push_back(BACK);

		vector<Event*> events;
		events.push_back(new ChangeLanguageEvent(0));
		events.push_back(new ChangeLanguageEvent(1));
		events.push_back(new ChangeLanguageEvent(2));
		events.push_back(new Event(BACK_EVENT));

		vector<Point> locations;

		if (mMajorMenu == MAIN_MENU)
		{
			locations.push_back(Point(600, 100));
			locations.push_back(Point(600, 190));
			locations.push_back(Point(600, 280));
			locations.push_back(Point(600, 370));

			delete mCurrentMenu;
			mCurrentMenu = new Menu(LANGUAGES_MENU);
			mCurrentMenu->init(options, events, locations, 300);
		}
		else if (mMajorMenu == TITLE_MENU)
		{
			locations.push_back(Point(0, 370));
			locations.push_back(Point(0, 420));
			locations.push_back(Point(0, 470));
			locations.push_back(Point(0, 520));

			delete mCurrentMenu;
			mCurrentMenu = new Menu(LANGUAGES_MENU);
			mCurrentMenu->init(options, events, locations, 900);
		}
	}
	else if (theEvent->getType() == DIFFICULTY_EVENT)
	{
		gpGame->getSoundManager()->playMenuSelect();

		vector<LANGUAGE_NUMBER> options;
		options.push_back(EASY);
		options.push_back(MEDIUM);
		options.push_back(HARD);
		options.push_back(BACK);

		vector<Event*> events;
		events.push_back(new NewGameEvent(5));
		events.push_back(new NewGameEvent(3));
		events.push_back(new NewGameEvent(1));
		events.push_back(new Event(BACK_EVENT));

		vector<Point> locations;
		locations.push_back(Point(0, 370));
		locations.push_back(Point(0, 420));
		locations.push_back(Point(0, 470));
		locations.push_back(Point(0, 520));

		delete mCurrentMenu;
		mCurrentMenu = new Menu(DIFFICULTY_MENU);
		mCurrentMenu->init(options, events, locations, 900);
	}
	else if (theEvent->getType() == BATTLE_EVENT)
	{
		// create battle menu
		mMajorMenu = BATTLE_MENU;

		vector<Point> locations;
		locations.push_back(Point(0, 420));
		locations.push_back(Point(0, 470));
		locations.push_back(Point(0, 520));

		delete mCurrentMenu;
		mCurrentMenu = new BattleMenu();
		((BattleMenu*)mCurrentMenu)->init(locations, 350);
	}
	else if (theEvent->getType() == END_BATTLE_EVENT)
	{
		mMajorMenu = NO_MENU;

		delete mCurrentMenu;
		mCurrentMenu = NULL;
	}
	else if (theEvent->getType() == LOAD_GAME_EVENT)
	{
		mMajorMenu = NO_MENU;

		delete mCurrentMenu;
		mCurrentMenu = NULL;
	}
	else if (theEvent->getType() == GAME_OVER_EVENT)
	{
		if (gpGame->getCael()->getCurrentHP() <= 0)
		{
			vector<LANGUAGE_NUMBER> options;
			options.push_back(LOAD_GAME);
			options.push_back(QUIT);

			vector<Event*> events;
			events.push_back(new Event(LOAD_GAME_EVENT));
			events.push_back(new Event(QUIT_EVENT));

			vector<Point> locations;
			locations.push_back(Point(0, 420));
			locations.push_back(Point(0, 470));

			delete mCurrentMenu;
			mCurrentMenu = new Menu(GAME_OVER_MENU);

			mCurrentMenu->init(options, events, locations, 900);
		}
		else
		{
			vector<LANGUAGE_NUMBER> options;
			options.push_back(SAVE);
			options.push_back(LOAD_GAME);
			options.push_back(QUIT);

			vector<Event*> events;
			events.push_back(new Event(SAVE_EVENT));
			events.push_back(new Event(LOAD_GAME_EVENT));
			events.push_back(new Event(QUIT_EVENT));

			vector<Point> locations;
			locations.push_back(Point(0, 450));
			locations.push_back(Point(0, 500));
			locations.push_back(Point(0, 550));

			delete mCurrentMenu;
			mCurrentMenu = new Menu(GAME_OVER_MENU);

			mCurrentMenu->init(options, events, locations, 900);
		}
	}
	else if(theEvent->getType() == END_TURN_EVENT)
	{		
		// create battle menu
		mMajorMenu = BATTLE_MENU;

		vector<Point> locations;
		locations.push_back(Point(0, 420));
		locations.push_back(Point(0, 470));
		locations.push_back(Point(0, 520));

		delete mCurrentMenu;
		mCurrentMenu = new BattleMenu();
		((BattleMenu*)mCurrentMenu)->init(locations, 350);
	}
}

Menu* MenuSystem::getCurrentMenu()
{
	return mCurrentMenu;
}