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

#ifndef GAME_H
#define GAME_H

#ifdef _DEBUG
#define ALLEGRO_USE_CONSOLE
#endif

#include "Cael.h"
#include "GraphicsSystem.h"
#include "InputSystem.h"
#include "EventSystem.h"
#include "MapManager.h"
#include "AssetManager.h"
#include "PathFindingSystem.h"
#include "LevelManager.h"
#include "EnemyLevelManager.h"
#include "Timer.h"
#include "SoundManager.h"
#include "Menu.h"
#include "MenuSystem.h"
#include "LocalizationSystem.h"
#include "Credits.h"
#include "MainMenu.h"

class Game : public EventListener
{
public:
	Game();
	~Game();

	void init();
	void shutDown();

	void loadGame();
	void saveGame();

	void run();

	virtual void handleEvent(Event* theEvent);

	GraphicsSystem* getGraphicsSystem();
	InputSystem*	getInputSystem();
	EventSystem*    getEventSystem();
	MapManager*	    getMapManager();
	Cael*			getCael();
	AssetManager*   getAssetManager();
	PathFindingSystem* getPathFindingSystem();
	LevelManager*	getLevelManager();
	EnemyLevelManager* getEnemyLevelManager();
	SoundManager*	getSoundManager();
	MenuSystem*		getMenuSystem();
	LocalizationSystem* getLocalizationSystem();

	bool			isPaused();
	bool			isAtTitleScreen();
	void			setPaused(bool paused);
	void			setIsAtTitleScreen(bool titleScreen);
	void			setShouldExit(bool exit);

	int				getEXPMultiplier();

private:
	GraphicsSystem* mGraphicsSystem;
	InputSystem*    mInputSystem;
	EventSystem*    mEventSystem;
	MapManager*     mMapManager;
	Cael*			mCael;
	AssetManager*   mAssetManager;
	PathFindingSystem* mPathFindingSystem;
	LevelManager*	mLevelManager;
	EnemyLevelManager* mEnemyLevelManager;
	SoundManager*	mSoundManager;
	MenuSystem*		mMenuSystem;
	LocalizationSystem* mLocalizationSystem;
	Credits*		mCredits;
	MainMenu*       mMainMenu;

	bool mShouldExit;
	bool mPaused;
	bool mAtTitleScreen;
	bool mCreditsRolling;

	int mEXPMultiplier;

	Timer mLoopTimer;
};

extern Game* gpGame;

#endif