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

#include "Level.h"

//initialize everything in one of cael's levels
Level::Level()
{
	mLevelNum = 0;
	mHP = 0;
	mMP = 0;
	mStrength = 0;
	mMagic = 0;
	mDefense = 0;
	mPower = 0.0;
	mEXPtoNextLevel = 0;
}

Level::~Level()
{
}

int Level::getLevelNum()
{
	return mLevelNum;
}

int Level::getHP()
{
	return mHP;
}

int Level::getMP()
{
	return mMP;
}

int Level::getStrength()
{
	return mStrength;
}

int Level::getMagic()
{
	return mMagic;
}

int Level::getDefense()
{
	return mDefense;
}

double Level::getPower()
{
	return mPower;
}

int Level::getEXP()
{
	return mEXPtoNextLevel;
}

void Level::setLevelNum(int level)
{
	mLevelNum = level;
}

void Level::setHP(int hp)
{
	mHP = hp;
}

void Level::setMP(int mp)
{
	mMP = mp;
}

void Level::setStrength(int strength)
{
	mStrength = strength;
}

void Level::setMagic(int magic)
{
	mMagic = magic;
}

void Level::setDefense(int defense)
{
	mDefense = defense;
}

void Level::setPower(double power)
{
	mPower = power;
}

void Level::setEXP(int exp)
{
	mEXPtoNextLevel = exp;
}