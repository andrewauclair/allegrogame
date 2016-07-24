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

#include "LevelManager.h"
#include <fstream>

/***********************************************
 * Pre: Instance must be created 
 * Post: Data is initialized and listeners added
 * Purpose: To initialize the data and listeners
 ***********************************************/
LevelManager::LevelManager()
{
	mLevelIndex = 0;
	mMaxLevel = 0;
}


/***********************************************
 * Pre: Instance must be created 
 * Post: Levels are erased
 * Purpose: To erase the levels
 ***********************************************/
LevelManager::~LevelManager()
{
	mLevels.erase(mLevels.begin(), mLevels.end());
}


/***********************************************
 * Pre: Instance must be created 
 * Post: Current Level is returned
 * Purpose: To return the current level
 ***********************************************/
Level LevelManager::getCurrentLevel()
{
	return mLevels[mLevelIndex];
}

/***********************************************
 * Pre: Instance must be created 
 * Post: MaxLevel Number is returned
 * Purpose: To return the max level number
 ***********************************************/
int LevelManager::getMaxLevel()
{
	return mMaxLevel;
}

/***********************************************
 * Pre: Instance must be created 
 * Post: Level is increased
 * Purpose: To switch levels
 ***********************************************/
void LevelManager::getNextLevel()
{
	//if we aren't on the last level (last level continues on indefinitely)
	if(mLevelIndex < mMaxLevel)
	{
		mLevelIndex++;		
	}	
}

/***********************************************
 * Pre: Instance must be created and file must exist
 * Post: Level data is loaded from file
 * Purpose: To get all of the data for the levels
 ***********************************************/
void LevelManager::loadLevels()
{
	ifstream fin;

	Level level;

	int levelNum, hp, mp, str, mag, def, exp;
	double pow;

	fin.open(LEVELS_FILE.c_str());
	
	fin >> levelNum;

	while(!fin.eof())
	{
		//get data
		level.setLevelNum(levelNum);

		fin >> hp;

		level.setHP(hp);

		fin >> mp;

		level.setMP(mp);

		fin >> str;

		level.setStrength(str);

		fin >> mag;

		level.setMagic(mag);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		//add level to the vector
		mLevels.push_back(level);

		fin >> levelNum;
	}

	//the last level in the file becomes the max level
	mMaxLevel = levelNum;

	fin.close();
}

void LevelManager::setCurrentLevel(int level)
{
	mLevelIndex = level - 1;
}
