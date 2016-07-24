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

#ifndef BATTLE_H
#define BATTLE_H

#include "Enemy.h"
#include "Cael.h"
#include "EventListener.h"
#include <string>
using namespace std;

class Battle : public EventListener
{
public:
	Battle();
	Battle(vector<Enemy*> enemies, int mapNum);
	~Battle();

	void start();
	void update();
	void reset(int map = -1);

	virtual void handleEvent(Event* theEvent);

private:
	vector<Enemy*> mEnemies;
	vector<Enemy*> mDeadEnemies;

	int mCurrentEnemy;
	int mCaelAnimation;
	int mEnemyAnimation;

	bool mEnemyHand;
	bool mEnemiesTurn;
	bool mCaelAnimating;
	bool mEnemyAnimating;
	bool mBattleOver;
	bool mGameOver;

	Unit* mFire;
	Point mFireLocation;

	Timer mEnemyTurnTimer;
	Timer mBattleOverTimer;
};

#endif