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

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Level.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const string LEVELS_FILE = "Levels/caelLevels.txt";

class LevelManager
{
private:
	vector<Level>  mLevels;

	int mLevelIndex;
	int mMaxLevel;

public:
	LevelManager();
	~LevelManager();

	Level getCurrentLevel();
	int getMaxLevel();

	void setCurrentLevel(int level);

	void getNextLevel();	
	void loadLevels();
};

#endif