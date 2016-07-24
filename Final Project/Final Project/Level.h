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

#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
using namespace std;

class Level
{
private:
	int mLevelNum;
	int mHP;
	int mMP;
	int mStrength;
	int mMagic;
	int mDefense;
	double mPower;
	int mEXPtoNextLevel;

public:
	Level();
	~Level();

	int getLevelNum();
	int getHP();
	int getMP();
	int getStrength();
	int getMagic();
	int getDefense();
	double getPower();
	int getEXP();

	void setLevelNum(int level);
	void setHP(int hp);
	void setMP(int mp);
	void setStrength(int strength);
	void setMagic(int magic);
	void setDefense(int defense);
	void setPower(double power);
	void setEXP(int exp);
};


#endif