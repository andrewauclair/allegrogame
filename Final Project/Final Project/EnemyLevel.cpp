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

#include "EnemyLevel.h"

//initialize everything in an enemy level
EnemyLevel::EnemyLevel()
{
	mCombatLevel = 0;
	mHP = 0;
	mStrength = 0;
	mDefense = 0;
	mPower = 0.0;
	mEXP = 0;
	mDropRate = 0;
}

EnemyLevel::~EnemyLevel()
{
}

int EnemyLevel::getCombatLevel()
{
	return mCombatLevel;
}

int EnemyLevel::getHP()
{
	return mHP;
}

int EnemyLevel::getStrength()
{
	return mStrength;
}

int EnemyLevel::getDefense()
{
	return mDefense;
}

double EnemyLevel::getPower()
{
	return mPower;
}

int EnemyLevel::getEXP()
{
	return mEXP;
}

int EnemyLevel::getDropRate()
{
	return mDropRate;
}

void EnemyLevel::setCombatLevel(int level)
{
	mCombatLevel = level;
}

void EnemyLevel::setHP(int hp)
{
	mHP = hp;
}

void EnemyLevel::setStrength(int str)
{
	mStrength = str;
}

void EnemyLevel::setDefense(int def)
{
	mDefense = def;
}

void EnemyLevel::setPower(double pow)
{
	mPower = pow;
}

void EnemyLevel::setEXP(int exp)
{
	mEXP = exp;
}

void EnemyLevel::setDropRate(int drop)
{
	mDropRate = drop;
}