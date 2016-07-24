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

#include "Enemy.h"
#include "Game.h"
#include <stdlib.h>

Enemy::Enemy()
{
}

Enemy::Enemy(vector<AnimatedSprite*> sprites)
:Unit(sprites)
{
	mCurrentAnimation = 4;
	mTimer.start();
}

Enemy::Enemy(vector<AnimatedSprite*> sprites, int mapNum)
:Unit(sprites)
{
	mCurrentAnimation = 4;
	mTimer.start();

	Point loc;
	int width = sprites[0]->getBitmap()->w;
	int height = sprites[0]->getBitmap()->h;

	// pick random location that is not in any objects
	do
	{
		loc.setX(rand() % WIDTH + 1);
		loc.setY(rand() % HEIGHT + 1);
	} while (gpGame->getMapManager()->getMap(mapNum)->checkCollisions(loc, width, height) && 
		gpGame->getMapManager()->getMap(mapNum)->checkEnemyCollisions(loc, loc, width, height));

	mLocation = loc;
}

Enemy::Enemy(vector<AnimatedSprite*> sprites, Point position)
:Unit(sprites, position)
{
	mCurrentAnimation = 4;
	mTimer.start();
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	if(!gpGame->getCael()->isInBattle())
	{
		if (gpGame->getPathFindingSystem()->manhattanDistance(mLocation, gpGame->getCael()->getLocation()) < 300)
		{
			Point oldLocation = mLocation;

			mLocation = gpGame->getPathFindingSystem()->getMove(mSprites[mCurrentAnimation]->getBitmap()->w, mSprites[mCurrentAnimation]->getBitmap()->h, 5, mLocation, gpGame->getCael()->getLocation());
			
			if (oldLocation.getX() < mLocation.getX() && mLocation.getY() == oldLocation.getY())
			{
				// moving right
				mCurrentAnimation = 1;
			}
			else if (oldLocation.getX() > mLocation.getX() && mLocation.getY() == oldLocation.getY())
			{
				// moving left
				mCurrentAnimation = 0;
			}

			if (oldLocation.getY() < mLocation.getY() && mLocation.getX() == oldLocation.getX())
			{
				// moving down
				mCurrentAnimation = 3;
			}
			else if (oldLocation.getY() > mLocation.getY() && mLocation.getX() == oldLocation.getX())
			{
				// moving up
				mCurrentAnimation = 2;
			}

		}
		else
		{
			if (mTimer.getElapsedTime() > 300.0)
			{
				mTimer.start();
				Point oldLocation = mLocation;

				// random move
				mLocation = gpGame->getPathFindingSystem()->getMove(mSprites[mCurrentAnimation]->getBitmap()->w, mSprites[mCurrentAnimation]->getBitmap()->h, 10, mLocation);

				if (oldLocation.getX() < mLocation.getX() && mLocation.getY() == oldLocation.getY())
				{
					// moving right
					mCurrentAnimation = 1;
				}
				else if (oldLocation.getX() > mLocation.getX() && mLocation.getY() == oldLocation.getY())
				{
					// moving left
					mCurrentAnimation = 0;
				}

				if (oldLocation.getY() < mLocation.getY() && mLocation.getX() == oldLocation.getX())
				{
					// moving down
					mCurrentAnimation = 3;
				}
				else if (oldLocation.getY() > mLocation.getY() && mLocation.getX() == oldLocation.getX())
				{
					// moving up
					mCurrentAnimation = 2;
				}
			}
		}
	}

	mSprites[mCurrentAnimation]->playAnimation(mLocation);
}

void Enemy::handleEvent(Event* theEvent)
{
}

ENEMY_NAMES Enemy::getEnemyName()
{
	return mEnemyName;
}

void Enemy::setEnemyName(ENEMY_NAMES name)
{
	mEnemyName = name;
}