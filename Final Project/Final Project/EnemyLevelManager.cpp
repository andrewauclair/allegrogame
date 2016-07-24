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

#include "EnemyLevelManager.h"
#include <fstream>

EnemyLevelManager::EnemyLevelManager()
{
}

EnemyLevelManager::~EnemyLevelManager()
{
}

//get the enemy's level
EnemyLevel EnemyLevelManager::getEnemyLevel(ENEMY_NAMES key, int index)
{
	if (key == SATAN_MORROC)
	{
		return mSatanMorroc;
	}

	return mEnemyLevels.find(key)->second[index-1];
}

EnemyLevel EnemyLevelManager::getSatanMorrocLevel()
{
	return mSatanMorroc;
}

//load all of the enemies' levels
void EnemyLevelManager::loadLevels()
{
	ifstream fin;

	EnemyLevel level;

	int combatLevel, hp, str, def, exp, dropRate;
	double pow;

	fin.open("Levels/aquaElementalStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mAquaElemental.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(AQUA, mAquaElemental));

	fin.open("Levels/boitataStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mBoitata.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(BOITATA, mBoitata));

	fin.open("Levels/desertWolfStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mDesertWolf.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(DESERT_WOLF, mDesertWolf));

	fin.open("Levels/devilingStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mDeviling.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(DEVILING, mDeviling));

	fin.open("Levels/dracoStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mDraco.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(DRACO, mDraco));

	fin.open("Levels/goblinStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mGoblin.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(GOBLIN, mGoblin));

	fin.open("Levels/gopinichStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mGopinich.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(GOPINICH, mGopinich));

	fin.open("Levels/nidhoggrStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mNidhoggr.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(NIDHOGGR, mNidhoggr));

	fin.open("Levels/salamanderStats.txt");

	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mSalamander.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(SALAMANDER, mSalamander));

	fin.open("Levels/seekerStats.txt");
	fin >> combatLevel;

	while(!fin.eof())
	{
		level.setCombatLevel(combatLevel);

		fin >> hp;

		level.setHP(hp);

		fin >> str;

		level.setStrength(str);

		fin >> def;

		level.setDefense(def);

		fin >> pow;

		level.setPower(pow);

		fin >> exp;

		level.setEXP(exp);

		fin >> dropRate;

		level.setDropRate(dropRate);

		mSeeker.push_back(level);

		fin >> combatLevel;
	}

	fin.close();
	fin.clear();

	mEnemyLevels.insert(pair<ENEMY_NAMES, vector<EnemyLevel>>(SEEKER, mSeeker));

	fin.open("Levels/satanMorrocStats.txt");

	fin >> combatLevel;	
	mSatanMorroc.setCombatLevel(combatLevel);

	fin >> hp;
	mSatanMorroc.setHP(hp);

	fin >> str;
	mSatanMorroc.setStrength(str);

	fin >> def;
	mSatanMorroc.setDefense(def);

	fin >> pow;
	mSatanMorroc.setPower(pow);

	fin >> exp;
	mSatanMorroc.setEXP(exp);

	fin >> dropRate;
	mSatanMorroc.setDropRate(dropRate);

	fin.close();
	fin.clear();
}