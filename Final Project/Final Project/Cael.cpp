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

#include "Cael.h"
#include "MoveEvent.h"
#include "Game.h"
#include "ChangeMapEvent.h"
#include <iostream>
using namespace std;

Cael::Cael(int x, int y)
{
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_IDLE));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_LEFT));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_UP));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_RIGHT));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_DOWN));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_ATTACK));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_MAGIC));
	mSprites.push_back(gpGame->getAssetManager()->getSprite(CAEL_DYING));

	mLocation = Point(x, y);

	mCurrentAnimation = 0;

	gpGame->getEventSystem()->addListener(MOVE_EVENT, this);
	gpGame->getEventSystem()->addListener(RESET_CAEL_EVENT, this);
	gpGame->getEventSystem()->addListener(BATTLE_EVENT, this);
	gpGame->getEventSystem()->addListener(INVALID_EVENT_TYPE, this);
	gpGame->getEventSystem()->addListener(USE_POTION_EVENT, this);
	gpGame->getEventSystem()->addListener(USE_ETHER_EVENT, this);

	mInBattle = false;

	mCurrentHP = gpGame->getLevelManager()->getCurrentLevel().getHP();
	mCurrentMP = gpGame->getLevelManager()->getCurrentLevel().getMP();

	mNumPotions = 5;
	mNumEthers = 5;

	mTotalEXP = 0;

	// set battle location
	mBattleLocation = Point(191, 226);

	vector<AnimatedSprite*> animations;
	animations.push_back(gpGame->getAssetManager()->getSprite(SPARKLES));
	mSparkles = new Unit(animations, Point(10, 10));
}

Cael::~Cael()
{
}

void Cael::update()
{
	// check to see if cael has collided with an enemy
	if (gpGame->getMapManager()->getCurrentMap()->checkEnemyCollisions(mLocation, Point(mLocation.getX() + 50, mLocation.getY()), mSprites[0]->getBitmap()->w - 50, mSprites[0]->getBitmap()->h) && mInBattle == false)
	{
		// colliding with an enemy
		Event* newEvent = new Event(BATTLE_EVENT);

		gpGame->getEventSystem()->addEvent(newEvent);
	}
	else if (mInBattle)
	{
		mSprites[mCurrentAnimation]->playAnimation(mBattleLocation);

		// play sparkles for healing
		if (!mSparkles->playAnimationOnce(0, Point(241, 226)))
		{

		}
	}
	else
	{
		mSprites[mCurrentAnimation]->playAnimation(mLocation);
	}
}

void Cael::handleEvent(Event* theEvent)
{
	int speed = 7;

	if (theEvent->getType() == MOVE_EVENT)
	{
		MoveEvent* moveEvent = (MoveEvent*)theEvent;

		mMoving = true;

		//move accordingly
		switch(moveEvent->getDirection())
		{
		case LEFT:
			mLocation.setX(mLocation.getX() - speed);

			mCurrentAnimation = 1;

			if (gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(mLocation.getX() + 50, mLocation.getY()), mSprites[0]->getBitmap()->w - 50, mSprites[0]->getBitmap()->h))
			{
				mLocation.setX(mLocation.getX() + speed);
			}
			break;
		case UP:
			mLocation.setY(mLocation.getY() - speed);

			mCurrentAnimation = 2;
			if (gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(mLocation.getX() + 50, mLocation.getY()), mSprites[0]->getBitmap()->w - 50, mSprites[0]->getBitmap()->h))
			{
				mLocation.setY(mLocation.getY() + speed);
			}
			break;
		case RIGHT:
			mLocation.setX(mLocation.getX() + speed);

			mCurrentAnimation = 3;

			if (gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(mLocation.getX() + 50, mLocation.getY()), mSprites[0]->getBitmap()->w - 50, mSprites[0]->getBitmap()->h))
			{
				mLocation.setX(mLocation.getX() - speed);
			}
			break;
		case DOWN:
			mLocation.setY(mLocation.getY() + speed);

			mCurrentAnimation = 4;

			if (gpGame->getMapManager()->getCurrentMap()->checkCollisions(Point(mLocation.getX() + 50, mLocation.getY()), mSprites[0]->getBitmap()->w - 50, mSprites[0]->getBitmap()->h))
			{
				mLocation.setY(mLocation.getY() - speed);
			}
			break;
		}

		// check to see if he went off the edge of the screen in any direction

		// went off left edge
		if (mLocation.getX() <= -50)
		{
			ChangeMapEvent* changeEvent = new ChangeMapEvent(MAP_LEFT);
			gpGame->getEventSystem()->addEvent(changeEvent);
		}

		// went off upper edge
		if (mLocation.getY() <= 0)
		{
			ChangeMapEvent* changeEvent = new ChangeMapEvent(MAP_UP);
			gpGame->getEventSystem()->addEvent(changeEvent);
		}

		// went off right edge
		if (mLocation.getX() + mSprites[0]->getBitmap()->w > WIDTH)
		{
			ChangeMapEvent* changeEvent = new ChangeMapEvent(MAP_RIGHT);
			gpGame->getEventSystem()->addEvent(changeEvent);
		}

		// went off bottom edge
		if (mLocation.getY() + mSprites[0]->getBitmap()->h > HEIGHT)
		{
			ChangeMapEvent* changeEvent = new ChangeMapEvent(MAP_DOWN);
			gpGame->getEventSystem()->addEvent(changeEvent);
		}
	}
	else if (theEvent->getType() == RESET_CAEL_EVENT)
	{
		ResetCaelEvent* resetEvent = (ResetCaelEvent*)theEvent;

		switch(resetEvent->getDirection())
		{
		case LEFT:
			mLocation.setX(WIDTH - (mSprites[0]->getBitmap()->w + 1));
			break;
		case RIGHT:
			mLocation.setX(-49);
			break;
		case UP:
			mLocation.setY(HEIGHT - (mSprites[0]->getBitmap()->h + 1));
			break;
		case DOWN:
			mLocation.setY(0);
			break;
		}
	}
	else if (theEvent->getType() == BATTLE_EVENT)
	{
		/*cout << "Battle" << endl;*/
		mInBattle = true;
		mCurrentAnimation = 0;
		/*
		gpGame->getMapManager()->getCurrentMap()->getBattles()[0]->start();*/
	}
	else if (theEvent->getType() == USE_POTION_EVENT)
	{
		// use a potion if there are any available and health is less than max
		if (mCurrentHP < gpGame->getLevelManager()->getCurrentLevel().getHP())
		{
			if (mNumPotions > 0)
			{
				// play sparkles
				mSparkles->playAnimationOnce(0, Point(241, 226), true);

				// play menu select
				gpGame->getSoundManager()->playMenuSelect();

				// playing healing sound
				gpGame->getSoundManager()->playHealing();

				mNumPotions--;
				mCurrentHP += gpGame->getLevelManager()->getCurrentLevel().getHP() / 2;

				if (mCurrentHP > gpGame->getLevelManager()->getCurrentLevel().getHP())
				{
					mCurrentHP = gpGame->getLevelManager()->getCurrentLevel().getHP();
				}

				if (mInBattle)
				{
					gpGame->getEventSystem()->addEvent(new Event(END_TURN_EVENT));
				}
			}
			else
			{
				gpGame->getSoundManager()->playMenuInvalid();
			}
		}
		else
		{
			gpGame->getSoundManager()->playMenuInvalid();
		}
	}
	else if (theEvent->getType() == USE_ETHER_EVENT)
	{
		// use an ether if there are any available and mp is less than max
		if (mCurrentMP < gpGame->getLevelManager()->getCurrentLevel().getMP())
		{
			if (mNumEthers > 0)
			{
				// play sparkles
				mSparkles->playAnimationOnce(0, Point(241, 226), true);

				// play menu select
				gpGame->getSoundManager()->playMenuSelect();

				// playing healing sound
				gpGame->getSoundManager()->playHealing();

				mNumEthers--;
				mCurrentMP += gpGame->getLevelManager()->getCurrentLevel().getMP() / 2;

				if (mCurrentMP > gpGame->getLevelManager()->getCurrentLevel().getMP())
				{
					mCurrentMP = gpGame->getLevelManager()->getCurrentLevel().getMP();
				}

				if (mInBattle)
				{
					gpGame->getEventSystem()->addEvent(new Event(END_TURN_EVENT));
				}
			}
			else
			{
				gpGame->getSoundManager()->playMenuInvalid();
			}
		}
		else
		{
			gpGame->getSoundManager()->playMenuInvalid();
		}
	}
	else if (theEvent->getType() == INVALID_EVENT_TYPE)
	{
		mMoving = false;
		mCurrentAnimation = 0;
	}
}

bool Cael::isInBattle()
{
	return mInBattle;
}

int Cael::getNumPotions()
{
	return mNumPotions;
}

int Cael::getNumEthers()
{
	return mNumEthers;
}

void Cael::setNumPotions(int potions)
{
	mNumPotions = potions;
}

void Cael::setNumEthers(int ethers)
{
	mNumEthers = ethers;
}

int Cael::getExperience()
{
	return mTotalEXP;
}

void Cael::setExperience(int exp)
{
	mTotalEXP = exp;
}

void Cael::setInBattle(bool battle)
{
	mInBattle = battle;
}

Point Cael::getBattleLocation()
{
	return mBattleLocation;
}