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

#include "Map.h"
#include "Game.h"
#include "Point.h"
#include <stdlib.h>

Map::Map()
{
}

Map::Map(BITMAP* foreground, BITMAP* background)
{
	mForeground = foreground;
	mBackground = background;

	mLeftMap = -1;
	mRightMap = -1;
	mUpMap = -1;
	mDownMap = -1;

	mUnitManager = new UnitManager();

	gpGame->getEventSystem()->addListener(BATTLE_EVENT, this);
}

Map::Map(BITMAP* foreground, BITMAP* background, int num, int left, int right, int up, int down)
{
	mNum = num;

	mForeground = foreground;
	mBackground = background;

	mLeftMap = left;
	mRightMap = right;
	mUpMap = up;
	mDownMap = down;

	mUnitManager = new UnitManager();

	gpGame->getEventSystem()->addListener(BATTLE_EVENT, this);
}

Map::~Map()
{
	for (unsigned int i = 0; i < mBattles.size(); i++)
	{
		delete mBattles[i];
	}

	delete mUnitManager;
}

void Map::drawForeground()
{
	gpGame->getGraphicsSystem()->draw(Point(0, 0), mForeground, true);
}

void Map::drawBackground()
{
	gpGame->getGraphicsSystem()->draw(Point(0, 0), mBackground, false);
}


void Map::setForeground(BITMAP* foreground)
{
	mForeground = foreground;
}

void Map::setBackground(BITMAP* background)
{
	mBackground = background;
}

int Map::getLeftMap()
{
	return mLeftMap;
}

int Map::getRightMap()
{
	return mRightMap;
}

int Map::getUpMap()
{
	return mUpMap;
}

int Map::getDownMap()
{
	return mDownMap;
}

void Map::setLeftMap(int left)
{
	mLeftMap = left;
}

void Map::setRightMap(int right)
{
	mRightMap = right;
}

void Map::setUpMap(int up)
{
	mUpMap = up;
}

void Map::setDownMap(int down)
{
	mDownMap = down;
}

void Map::addCollision(Point point1, Point point2)
{
	mCollisionsStart.push_back(point1);
	mCollisionsEnd.push_back(point2);
}

bool Map::checkCollisions(Point &loc)
{
	for (unsigned int i = 0; i < mCollisionsStart.size(); i++)
	{
		if (loc.getX() > mCollisionsStart[i].getX() && loc.getY() > mCollisionsStart[i].getY())
		{
			if (loc.getX() < mCollisionsEnd[i].getX() && loc.getY() < mCollisionsEnd[i].getY())
			{
				return true;
			}
		}
	}

	return false;
}

bool Map::checkCollisions(Unit* unit1, Unit* unit2)
{
	int left1, left2;
	int right1, right2;
	int top1, top2;
	int bottom1, bottom2;

	left1 = unit1->getLocation().getX();
	right1 = (unit1->getLocation().getX() + 50) + unit1->getSprites()[0]->getBitmap()->w;
	top1 = unit1->getLocation().getY();
	bottom1 = unit1->getLocation().getY() + unit1->getSprites()[0]->getBitmap()->h;

	left2 = unit2->getLocation().getX();
	right2 = unit2->getLocation().getX() + unit2->getSprites()[0]->getBitmap()->w;
	top2 = unit2->getLocation().getY();
	bottom2 = unit2->getLocation().getY() + unit2->getSprites()[0]->getBitmap()->h;

	if (bottom1 < top2)
	{
		return false;
	}

	if (top1 > bottom2)
	{
		return false;
	}

	if (right1 < left2)
	{
		return false;
	}

	if (left1 > right2)
	{
		return false;
	}

	return true;
}

bool Map::checkCollisions(Point &loc, int width, int height)
{
	if (loc.getX() < -10 || loc.getY() < -10 || loc.getX() + (width-10) > mBackground->w || loc.getY() + (height-10) > mBackground->h)
	{
		return true;
	}

	if (checkCollisions(loc) || checkCollisions(Point(loc.getX() + width, loc.getY())) ||
		checkCollisions(Point(loc.getX(), loc.getY() + height)) || 
		checkCollisions(Point(loc.getX() + width, loc.getY() + height)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Map::checkEnemyCollisions(Point &start, Point &loc, int width, int height)
{
	int left1, left2;
	int right1, right2;
	int top1, top2;
	int bottom1, bottom2;
	int width2, height2;

	left1 = loc.getX();
	right1 = loc.getX() + width;
	top1 = loc.getY();
	bottom1 = loc.getY() + height;

	int total = mUnitManager->getNumberOfUnits();

	for (int i = 0; i < total; i++)
	{

		Unit* unit = mUnitManager->getUnit(i);

		if (unit->getLocation().getX() == start.getX() && unit->getLocation().getY() == start.getY())
		{
			continue;
		}

		width2 = unit->getSprites()[0]->getBitmap()->w;
		height2 = unit->getSprites()[0]->getBitmap()->h;

		left2 = unit->getLocation().getX();
		right2 = unit->getLocation().getX() + width2;
		top2 = unit->getLocation().getY();
		bottom2 = unit->getLocation().getY() + height2;

		if (bottom1 < top2)
		{
			continue;
		}

		if (top1 > bottom2)
		{
			continue;
		}

		if (right1 < left2)
		{
			continue;
		}

		if (left1 > right2)
		{
			continue;
		}

		return true;
	}

	return false;
}

bool Map::checkEnemyCollisions(Point &start, Point& loc)
{

	int total = mUnitManager->getNumberOfUnits();

	// check against every other enemy
	for (int i = 0; i < total; i++)
	{
		Unit* unit = mUnitManager->getUnit(i);

		if (unit->getLocation().getX() == start.getX() && unit->getLocation().getY() == start.getY())
		{
			continue;
		}

		Point point1 = unit->getLocation();
		Point point2(unit->getLocation().getX() + unit->getSprites()[0]->getBitmap()->w, unit->getLocation().getY() + unit->getSprites()[0]->getBitmap()->h);

		if (point1.getX() > loc.getX() && point1.getY() > loc.getY())
		{
			if (point2.getX() < loc.getX() && point2.getY() < loc.getY())
			{
				return true;
			}
		}
	}

	return false;
}

UnitManager* Map::getUnitManager()
{
	return mUnitManager;
}

void Map::addEnemies(vector<Unit*> enemies)
{
	mUnitManager->init(enemies);
}

//battles for the map
void Map::addBattles(vector<Battle*> battles)
{
	for (unsigned int i = 0; i < battles.size(); i++)
	{
		mBattles.push_back(battles[i]);
	}
}

vector<Battle*> Map::getBattles()
{
	return mBattles;
}

int Map::getNumber()
{
	return mNum;
}

void Map::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == BATTLE_EVENT)
	{
		if (mNum == gpGame->getMapManager()->getCurrentMap()->getNumber())
		{
			// kill enemy
			// loop till you find the enemy that cael hit
			for (int i = 0; i < mUnitManager->getNumberOfUnits(); i++)
			{
				if (checkCollisions(gpGame->getCael(), mUnitManager->getUnit(i)))
				{
					mUnitManager->killUnit(i);
					break;
				}
			}

			// start the random battle
			mBattleNum = rand() % mBattles.size();
			mBattles[mBattleNum]->start();
		}
	}
}


void Map::update()
{
	if (gpGame->getCael()->isInBattle())
	{
		mBattles[mBattleNum]->update();
	}
	else
	{
		mUnitManager->update();
	}
}

//reset the enemies
void Map::reset()
{
	mUnitManager->reset();

	for (unsigned int i = 0; i < mBattles.size(); i++)
	{
		mBattles[i]->reset(mNum);
	}
}

void Map::setStartPoint(Point location)
{
	mStartPosition = location;
}

Point Map::getStartPoint()
{
	return mStartPosition;
}