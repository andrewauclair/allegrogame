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

#ifndef ENEMY_H
#define ENEMY_H

#include "Unit.h"
#include "Timer.h"
#include <string>
using namespace std;

enum ENEMY_NAMES
{
	DEVILING = 0,
	DRACO,
	GOBLIN,
	DESERT_WOLF,
	AQUA,
	SEEKER,
	SALAMANDER,
	NIDHOGGR,
	GOPINICH,
	BOITATA,
	SATAN_MORROC
};

class Enemy : public Unit
{
private:
	bool mMoving;
	bool mShowOnScreen;

	Timer mTimer;

	ENEMY_NAMES mEnemyName;

public:
	Enemy();
	Enemy(vector<AnimatedSprite*> sprites);
	Enemy(vector<AnimatedSprite*> sprites, int mapNum);
	Enemy(vector<AnimatedSprite*> sprites, Point position);
	~Enemy();

	virtual void update();

	ENEMY_NAMES getEnemyName();
	void setEnemyName(ENEMY_NAMES name);

	virtual void handleEvent(Event* theEvent);
};

#endif