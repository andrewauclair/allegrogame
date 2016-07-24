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

#include "Game.h"
#include "NewGameEvent.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	srand(time(NULL));

	if (allegro_init() != 0)
	{
		cout << "Failed to initialize Allegro" << endl;
	}

	mEventSystem = new EventSystem();

	mSoundManager = new SoundManager();
	mSoundManager->init();
	mSoundManager->playLoading();
	
	mShouldExit = false;
	mAtTitleScreen = true;

	mEXPMultiplier = 0;

	mGraphicsSystem = new GraphicsSystem();
	mGraphicsSystem->init();

	set_window_title("Dance With The Devil");

	mAssetManager = new AssetManager();
	mAssetManager->init();

	mLocalizationSystem = new LocalizationSystem();
	mLocalizationSystem->loadLanguages();
	
	// initialize input system
	mInputSystem = new InputSystem();
	mInputSystem->init();

	mLevelManager = new LevelManager();
	mLevelManager->loadLevels();

	mEnemyLevelManager = new EnemyLevelManager();
	mEnemyLevelManager->loadLevels();
	
	// initialize map manager
	mMapManager = new MapManager();
	mMapManager->init();

	mPathFindingSystem = new PathFindingSystem();

	// initialize unit manager
	mCael = new Cael(100, 100);

	mEventSystem->addListener(CREDITS_EVENT, this);
	mEventSystem->addListener(NEW_GAME_EVENT, this);
	mEventSystem->addListener(SAVE_EVENT, this);
	mEventSystem->addListener(LOAD_GAME_EVENT, this);

	mSoundManager->stopLoading();
	//mSoundManager->playWanderingMusic();

	mMenuSystem = new MenuSystem();
	mMenuSystem->init();

	mPaused = false;
	mCreditsRolling = false;

	mCredits = new Credits();

	mMainMenu = new MainMenu();
}

void Game::shutDown()
{
	delete mMainMenu;
	delete mCredits;
	delete mMenuSystem;
	delete mPathFindingSystem;
	delete mMapManager;
	delete mCael;
	delete mLevelManager;
	delete mEnemyLevelManager;
	delete mAssetManager;
	delete mGraphicsSystem;
	delete mInputSystem;
	delete mSoundManager;
	delete mLocalizationSystem;
	delete mEventSystem;

	mEventSystem = NULL;
}

void Game::run()
{
	while (!mShouldExit)
	{
		mLoopTimer.start();

		mInputSystem->update();

		mEventSystem->fireAllEvents();
		
		if (!mPaused && !mAtTitleScreen)
		{
			// draw background of map
			mMapManager->drawMapBackground();

			// update Cael
			mCael->update();

			// update current map
			mMapManager->update();
		
			// draw foreground of map
			mMapManager->drawMapForeground();
		}
		

		mEventSystem->fireAllEvents();

		if (mCreditsRolling)
		{
			mCredits->update();
		}
		
		mMenuSystem->update();

		if (mPaused)
		{
			mMainMenu->update();
		}

		// swap buffer with screen
		mGraphicsSystem->swap();

		mLoopTimer.sleepUntilElapsed(60.0);
	}
}

void Game::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == NEW_GAME_EVENT)
	{
		mCael->setInBattle(false);

		NewGameEvent* newGame = (NewGameEvent*)theEvent;
		mEXPMultiplier = newGame->getDifficulty();

		mAtTitleScreen = false;

		mSoundManager->playMenuSelect();
		mSoundManager->playWanderingMusic();

		mLevelManager->setCurrentLevel(1);
		mCael->setCurrentHP(mLevelManager->getCurrentLevel().getHP());
		mCael->setCurrentMP(mLevelManager->getCurrentLevel().getMP());
		mCael->setExperience(0);
		mCael->setNumEthers(5);
		mCael->setNumPotions(5);

		mMapManager->setCurrentMap(1);
		mCael->setLocation(mMapManager->getMap(0)->getStartPoint());
			
		mMapManager->reset();
	}
	else if (theEvent->getType() == CREDITS_EVENT)
	{
		mCreditsRolling = true;
	}
	else if (theEvent->getType() == LOAD_GAME_EVENT)
	{
		mCael->setInBattle(false);

		mCreditsRolling = false;

		mSoundManager->stopCreditMusic();

		loadGame();

		mAtTitleScreen = false;

		mSoundManager->playMenuSelect();
		mSoundManager->playWanderingMusic();

		mCael->setInBattle(false);

		mMapManager->reset();
	}
	else if (theEvent->getType() == SAVE_EVENT)
	{
		saveGame();
		mSoundManager->playSavingGame();
	}
}

GraphicsSystem* Game::getGraphicsSystem()
{
	return mGraphicsSystem;
}

InputSystem* Game::getInputSystem()
{
	return mInputSystem;
}

EnemyLevelManager* Game::getEnemyLevelManager()
{
	return mEnemyLevelManager;
}

EventSystem* Game::getEventSystem()
{
	return mEventSystem;
}

LevelManager* Game::getLevelManager()
{
	return mLevelManager;
}

MapManager* Game::getMapManager()
{
	return mMapManager;
}

Cael* Game::getCael()
{
	return mCael;
}

AssetManager* Game::getAssetManager()
{
	return mAssetManager;
}

PathFindingSystem* Game::getPathFindingSystem()
{
	return mPathFindingSystem;
}

SoundManager* Game::getSoundManager()
{
	return mSoundManager;
}

MenuSystem* Game::getMenuSystem()
{
	return mMenuSystem;
}

LocalizationSystem* Game::getLocalizationSystem()
{
	return mLocalizationSystem;
}

bool Game::isPaused()
{
	return mPaused;
}

bool Game::isAtTitleScreen()
{
	return mAtTitleScreen;
}

void Game::setIsAtTitleScreen(bool titleScreen)
{
	mAtTitleScreen = titleScreen;
}

void Game::setPaused(bool paused)
{
	mPaused = paused;
}

void Game::setShouldExit(bool exit)
{
	mShouldExit = exit;
}

void Game::loadGame()
{
	ifstream fin;

	fin.open("SaveData/saveData.txt");

	int number;

	fin >> number;
	mCael->setCurrentHP(number);

	fin >> number;
	mCael->setCurrentMP(number);

	fin >> number;
	mLevelManager->setCurrentLevel(number);

	fin >> number;
	mCael->setExperience(number);

	fin >> number;
	mCael->setNumPotions(number);

	fin >> number;
	mCael->setNumEthers(number);

	fin >> number;
	mMapManager->setCurrentMap(number);

	fin >> number;
	mEXPMultiplier = number;

	// set location
	gpGame->getCael()->setLocation(mMapManager->getCurrentMap()->getStartPoint());
	
	fin.close();
	fin.clear();
}

void Game::saveGame()
{
	ofstream fout;

	fout.open("SaveData/saveData.txt");

	fout << mCael->getCurrentHP() << endl;
	fout << mCael->getCurrentMP() << endl;
	fout << mLevelManager->getCurrentLevel().getLevelNum() << endl;
	fout << mCael->getExperience() << endl;
	fout << mCael->getNumPotions() << endl;
	fout << mCael->getNumEthers() << endl;
	fout << mMapManager->getCurrentMap()->getNumber() << endl;
	fout << mEXPMultiplier << endl;

	fout.close();
	fout.clear();

}

int Game::getEXPMultiplier()
{
	return mEXPMultiplier;
}

