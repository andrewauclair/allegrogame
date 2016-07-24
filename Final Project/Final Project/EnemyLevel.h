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

#ifndef ENEMYLEVEL_H
#define ENEMYLEVEL_H

class EnemyLevel
{
private:
	int mCombatLevel;
	int mHP;
	int mStrength;
	int mDefense;
	double mPower;
	int mEXP;
	int mDropRate;

public:
	EnemyLevel();
	~EnemyLevel();

	int getCombatLevel();
	int getHP();
	int getStrength();
	int getDefense();
	double getPower();
	int getEXP();
	int getDropRate();

	void setCombatLevel(int level);
	void setHP(int hp);
	void setStrength(int str);
	void setDefense(int def);
	void setPower(double pow);
	void setEXP(int exp);
	void setDropRate(int drop);
};

#endif