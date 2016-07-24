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

#include "UnitManager.h"
#include "Cael.h"
#include "Enemy.h"
#include "Game.h"
#include <vector>
using namespace std;

UnitManager::UnitManager()
{
}

UnitManager::~UnitManager()
{
	for (unsigned int i = 0; i < mUnits.size(); i++)
	{
		delete mUnits[i];
	}
}

void UnitManager::init(vector<Unit*> units)
{
	for (unsigned int i = 0; i < units.size(); i++)
	{
		mUnits.push_back(units[i]);
	}
}

void UnitManager::update()
{
	for (unsigned int i = 0; i < mUnits.size(); i++)
	{
		mUnits[i]->update();
	}
}

Unit* UnitManager::getUnit(int index)
{
	return mUnits[index];
}

void UnitManager::killUnit(int index)
{
	mDeadUnits.push_back(mUnits[index]);
	mUnits.erase(mUnits.begin() + index);
}

int UnitManager::getNumberOfUnits()
{
	return mUnits.size();
}

void UnitManager::reset()
{
	while (mDeadUnits.size() > 0)
	{
		mUnits.push_back(mDeadUnits[0]);
		mDeadUnits.erase(mDeadUnits.begin());
	}

	for (unsigned int i = 0; i < mUnits.size(); i++)
	{
		mUnits[i]->reset();
	}
}