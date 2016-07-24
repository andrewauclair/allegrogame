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

#ifndef CAEL_H
#define CAEL_H

#include "Unit.h"

class Cael : public Unit
{
private:
	bool mMoving;

	int mNumPotions;
	int mNumEthers;

	int mTotalEXP;
	bool mInBattle;

	Point mBattleLocation;

	Unit* mSparkles;

public:
	Cael(int x, int y);
	~Cael();

	int getExperience();
	void setExperience(int exp);

	int getNumPotions();
	int getNumEthers();
	
	void setNumPotions(int potions);
	void setNumEthers(int ethers);	

	virtual void update();
	virtual void handleEvent(Event* theEvent);

	bool isInBattle();
	void setInBattle(bool battle);

	Point getBattleLocation();
};

#endif