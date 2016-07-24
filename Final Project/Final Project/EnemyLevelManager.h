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

#ifndef ENEMYLEVELMANAGER_H
#define ENEMYLEVELMANAGER_H

#include "EnemyLevel.h"
#include "Enemy.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class EnemyLevelManager
{
private:
	vector<EnemyLevel> mAquaElemental;
	vector<EnemyLevel> mBoitata;
	vector<EnemyLevel> mDesertWolf;
	vector<EnemyLevel> mDeviling;
	vector<EnemyLevel> mDraco;
	vector<EnemyLevel> mGoblin;
	vector<EnemyLevel> mGopinich;
	vector<EnemyLevel> mNidhoggr;
	vector<EnemyLevel> mSalamander;
	vector<EnemyLevel> mSeeker;

	multimap<ENEMY_NAMES, vector<EnemyLevel>> mEnemyLevels;

	EnemyLevel mSatanMorroc;

public:
	EnemyLevelManager();
	~EnemyLevelManager();

	EnemyLevel getEnemyLevel(ENEMY_NAMES key, int index);

	EnemyLevel getSatanMorrocLevel();

	void loadLevels();
};

#endif