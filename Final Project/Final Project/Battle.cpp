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

#include "Battle.h"
#include "Game.h"
#include "Attack.h"
#include "Magic.h"
#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdlib>
using namespace std;

Battle::Battle()
{
	mEnemyHand = false;
	mEnemiesTurn = false;
	mCaelAnimating = false;
	mEnemyAnimating = false;
	mBattleOver = false;
	mGameOver = false;

	mCaelAnimation = 0;
	mEnemyAnimation = 0;

	mEnemyTurnTimer = Timer();

	mCurrentEnemy = 0;

	vector<AnimatedSprite*> animation;
	animation.push_back(gpGame->getAssetManager()->getSprite(FIRE));

	mFire = new Unit(animation, Point(0, 0));
}

Battle::Battle(vector<Enemy*> enemies, int mapNum)
{
	for (unsigned int i = 0; i < enemies.size(); i++)
	{
		mEnemies.push_back(enemies[i]);
		
		mEnemies[i]->setCurrentHP(gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[i]->getEnemyName(), mapNum).getHP());
	}

	mEnemyHand = false;
	mEnemiesTurn = false;
	mCaelAnimating = false;
	mEnemyAnimating = false;
	mBattleOver = false;
	mGameOver = false;

	mEnemyTurnTimer = Timer();

	mCurrentEnemy = 0;

	mCaelAnimation = 0;
	mEnemyAnimation = 0;

	vector<AnimatedSprite*> animation;
	animation.push_back(gpGame->getAssetManager()->getSprite(FIRE));

	mFire = new Unit(animation, Point(0, 0));
}

Battle::~Battle()
{
	for (unsigned int i = 0; i < mEnemies.size(); i++)
	{
		delete mEnemies[i];
	}
}


void Battle::start()
{
	gpGame->getSoundManager()->stopWanderingMusic();
	
	//start battle music
	if(gpGame->getMapManager()->getCurrentMap()->getNumber() == 11)
	{
		gpGame->getSoundManager()->playBossMusic();
	}
	else
	{
		if(gpGame->getSoundManager()->isSoundOn())
		{
			gpGame->getSoundManager()->playBattleMusic();
		}
	}

	//play enemy starting roar
	for(unsigned int i = 0; i < mEnemies.size(); i++)
	{
		if(mEnemies[i]->getEnemyName() == SATAN_MORROC)
		{
			if(gpGame->getSoundManager()->isSoundOn())
			{
				gpGame->getSoundManager()->playSatanMorrocRoar();
			}
		}
		else if(mEnemies[i]->getEnemyName() == NIDHOGGR || mEnemies[i]->getEnemyName() == GOPINICH)
		{
			if(gpGame->getSoundManager()->isSoundOn())
			{
				gpGame->getSoundManager()->playDragonRoar();
			}
		}
	}

	gpGame->getEventSystem()->addListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->addListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->addListener(ATTACK_EVENT, this);
	gpGame->getEventSystem()->addListener(MAGIC_EVENT, this);
	gpGame->getEventSystem()->addListener(LEFT_EVENT, this);
	gpGame->getEventSystem()->addListener(RIGHT_EVENT, this);
	gpGame->getEventSystem()->addListener(USE_POTION_EVENT, this);
	gpGame->getEventSystem()->addListener(END_TURN_EVENT, this);
}

void Battle::update()
{
	//if not playing a special animation
	if (!gpGame->getCael()->playAnimationOnce(mCaelAnimation, gpGame->getCael()->getBattleLocation()))
	{
		mCaelAnimating = false;

		if(gpGame->getCael()->getCurrentHP() > 0)
		{
			gpGame->getCael()->update();
		}
		else if(mBattleOver == false)
		{
			mBattleOverTimer.start();
			mBattleOver = true;
		}
		//draw Cael's dead body
		else if (gpGame->getCael()->getCurrentHP() <= 0)
		{
			gpGame->getGraphicsSystem()->draw(gpGame->getCael()->getBattleLocation(), gpGame->getCael()->getSprites()[7]->getFrames()[3], true);
		}
	}
	
	//go through enemies and update them accordingly 
	for(unsigned int i = 0; i < mEnemies.size(); i++)
	{
		if (mCurrentEnemy != i)
		{
			mEnemies[i]->update();
		}
		else
		{
			//non specially animating enemies
			if (!mEnemies[mCurrentEnemy]->playAnimationOnce(mEnemyAnimation, mEnemies[mCurrentEnemy]->getLocation()))
			{
				if (mEnemyAnimating)
				{
					if(mEnemies[mCurrentEnemy]->getCurrentHP() > 0)
					{
						gpGame->getSoundManager()->choosePain();
					}					
					mEnemyTurnTimer.start();
				}

				mEnemyAnimating = false;
				
				if (mEnemies[mCurrentEnemy]->getCurrentHP() <= 0)
				{
					mDeadEnemies.push_back(mEnemies[mCurrentEnemy]);
					mEnemies.erase(mEnemies.begin() + mCurrentEnemy);

					if (mEnemiesTurn)
					{
						mCurrentEnemy = -1;
					}

					if(mEnemies.empty())
					{
						mBattleOver = true;
						mBattleOverTimer.start();
					}
				}
				else
				{
					mEnemies[i]->update();
				}
			}
		}
	}

	if (!mFire->playAnimationOnce(0, mFireLocation))
	{
	}

	// draw hand next to selected enemy
	if (mEnemyHand)
	{
		int x = mEnemies[mCurrentEnemy]->getLocation().getX() - 60;
		int y = mEnemies[mCurrentEnemy]->getLocation().getY() + (mEnemies[mCurrentEnemy]->getSprites()[0]->getBitmap()->h / 2) - 18;
		gpGame->getGraphicsSystem()->draw(Point(x, y), gpGame->getAssetManager()->getSprite(HAND_ICON)->getBitmap(), true);
	}

	stringstream ss;

	// draw hp and mp on menu
	ss.str("");
	ss << "HP: ";
	ss << gpGame->getCael()->getCurrentHP();
	ss << "/";
	ss << gpGame->getLevelManager()->getCurrentLevel().getHP();
	
	gpGame->getGraphicsSystem()->drawText(Point(500, 450), ss.str(), 40, false);

	ss.str("");
	ss << "MP: ";
	ss << gpGame->getCael()->getCurrentMP();
	ss << "/";
	ss << gpGame->getLevelManager()->getCurrentLevel().getMP();

	gpGame->getGraphicsSystem()->drawText(Point(500, 500), ss.str(), 40, false);


	// draw the enemies health
	for (unsigned int i = 0; i < mEnemies.size(); i++)
	{
		ss.str("");
		ss << mEnemies[i]->getCurrentHP();
		
		ss << "/";

		ss << gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[i]->getEnemyName(), gpGame->getMapManager()->getCurrentMap()->getNumber()).getHP();
		
		int x = mEnemies[i]->getLocation().getX() + mEnemies[i]->getSprites()[0]->getBitmap()->h / 3;
		int y = mEnemies[i]->getLocation().getY() - 5;
		gpGame->getGraphicsSystem()->drawText(Point(x, y), ss.str(), 12, false);
	}

	if (mEnemiesTurn)
	{		
			//go through the enemies and attack Cael
		if (mEnemyTurnTimer.getElapsedTime() > 1000)
		{
			if (mEnemiesTurn && !mEnemyAnimating && !mCaelAnimating)
			{
				// next enemies turn to attack
				int size = mEnemies.size() - 1;
				if (mCurrentEnemy >= size)
				{
					// enemies are done attacking
					mEnemyTurnTimer.stop();
					mCurrentEnemy = 0;
					mEnemiesTurn = false;
					gpGame->getMenuSystem()->getCurrentMenu()->unfreeze();

				}
				else
				{
					
					mCurrentEnemy++;
				}
			}

			if((mEnemiesTurn && mEnemies.size() > 0) && !mEnemyAnimating && !mCaelAnimating)
			{
				if (mEnemies[mCurrentEnemy]->getCurrentHP() > 0)
				{
					//play growl and calculate damage
					gpGame->getSoundManager()->playEnemyGrowl(mEnemies[mCurrentEnemy]->getEnemyName());

					int attack = gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[mCurrentEnemy]->getEnemyName(), gpGame->getMapManager()->getCurrentMap()->getNumber()).getStrength();
					int defense = gpGame->getLevelManager()->getCurrentLevel().getDefense();
					double power = gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[mCurrentEnemy]->getEnemyName(), gpGame->getMapManager()->getCurrentMap()->getNumber()).getPower();

					int hit = ceil(((attack)-defense)*power);

					if(hit <= 0)
					{
						hit = 1;
					}

					//if the green dragon, play fire on Cael
					if(mEnemies[mCurrentEnemy]->getEnemyName() == GOPINICH)
					{
						int x = (gpGame->getCael()->getBattleLocation().getX() + 50) + (gpGame->getCael()->getSprites()[0]->getBitmap()->w - 50)/2 - (mFire->getSprites()[0]->getBitmap()->w/2);
						int y = gpGame->getCael()->getBattleLocation().getY() + (gpGame->getCael()->getSprites()[0]->getBitmap()->h - mFire->getSprites()[0]->getBitmap()->h);

						mFireLocation = Point(x, y);

						mFire->playAnimationOnce(0, Point(x, y), true);
						gpGame->getSoundManager()->playFireball();
					}

					gpGame->getCael()->setCurrentHP(gpGame->getCael()->getCurrentHP() - hit);
					
					// enemy needs to animate
					mEnemyAnimation = 5;
					mEnemies[mCurrentEnemy]->playAnimationOnce(mEnemyAnimation, mEnemies[mCurrentEnemy]->getLocation(), true);	
					mEnemyAnimating = true;
				}
				else
				{
					
				}

				// check to see if cael has died
				if (gpGame->getCael()->getCurrentHP() <= 0)
				{
					// cael died
					gpGame->getCael()->setCurrentHP(0);
					//mBattleOver = true;

					mCaelAnimation = 7;
					gpGame->getCael()->playAnimationOnce(mCaelAnimation, gpGame->getCael()->getBattleLocation(), true);
					mCaelAnimating = true;

					mEnemyTurnTimer.stop();
					mCurrentEnemy = 0;
					mEnemiesTurn = false;

				}

				
			}
		}
	}

	//if the battle is over
	if(mBattleOver && !mCaelAnimating && !mEnemyAnimating)
	{
		//wait a second
		if(mBattleOverTimer.getElapsedTime() > 1500)
		{
			//if Cael Died
			if(gpGame->getCael()->getCurrentHP() <= 0)
			{
				gpGame->getGraphicsSystem()->draw(Point(0,0), gpGame->getAssetManager()->getSprite(GAME_OVER_SCREEN)->getFrames()[gpGame->getLocalizationSystem()->getCurrentLanguage()], false);
				
				if (!mGameOver)
				{
					mGameOver = true;
					gpGame->getEventSystem()->addEvent(new Event(GAME_OVER_EVENT));
				}

				if(gpGame->getMapManager()->getCurrentMap()->getNumber() == 11)
				{
					gpGame->getSoundManager()->stopBossMusic();
				}
				else
				{
					gpGame->getSoundManager()->stopBattleMusic();
				}
			}
			//Cael Won
			else
			{
				gpGame->getEventSystem()->addEvent(new Event(END_BATTLE_EVENT));
			
				gpGame->getCael()->setInBattle(false);

				//If you beat the Boss
				if(gpGame->getMapManager()->getCurrentMap()->getNumber() == 11)
				{
					gpGame->getSoundManager()->stopBossMusic();

					// fire credits event
					gpGame->getSoundManager()->playCreditMusic();
					Event* newEvent = new Event(CREDITS_EVENT);
					gpGame->getEventSystem()->addEvent(newEvent);
				}
				//End regular battle
				else
				{
					gpGame->getSoundManager()->stopBattleMusic();
					gpGame->getSoundManager()->playWanderingMusic();
				}			
				//reset the monsters in the battle
				reset();
			}
		}
		
	}
}

//reset all of the monsters and integers
void Battle::reset(int map)
{
	mBattleOver = false;

	mEnemyHand = false;
	mEnemiesTurn = false;
	mCaelAnimating = false;
	mEnemyAnimating = false;

	mCurrentEnemy = 0;
	mCaelAnimation = 0;
	mEnemyAnimation = 0;

	mEnemyTurnTimer = Timer();
	mBattleOverTimer = Timer();

	int mapNum;
	
	if (map == -1)
	{
		mapNum = gpGame->getMapManager()->getCurrentMap()->getNumber();
	}
	else
	{
		mapNum = map;
	}

	while (mDeadEnemies.size() > 0)
	{
		mEnemies.push_back(mDeadEnemies[0]);
		mDeadEnemies.erase(mDeadEnemies.begin());
	}

	for(unsigned int i = 0; i < mEnemies.size(); i++)
	{
		mEnemies[i]->setCurrentHP(gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[i]->getEnemyName(), mapNum).getHP());
	}

	//get rid of all the listeners
	gpGame->getEventSystem()->removeListener(MENU_UP_EVENT, this);
	gpGame->getEventSystem()->removeListener(MENU_DOWN_EVENT, this);
	gpGame->getEventSystem()->removeListener(ATTACK_EVENT, this);
	gpGame->getEventSystem()->removeListener(MAGIC_EVENT, this);
	gpGame->getEventSystem()->removeListener(LEFT_EVENT, this);
	gpGame->getEventSystem()->removeListener(RIGHT_EVENT, this);
	gpGame->getEventSystem()->removeListener(END_TURN_EVENT, this);
}

void Battle::handleEvent(Event* theEvent)
{
	if (!mEnemiesTurn)
	{
		if (theEvent->getType() == MENU_UP_EVENT)
		{
			mEnemyHand = false;
		}
		else if (theEvent->getType() == MENU_DOWN_EVENT)
		{
			mEnemyHand = false;
		}
		else if (theEvent->getType() == ATTACK_EVENT)
		{
			gpGame->getSoundManager()->playMenuSelect();

			if (mEnemyHand)
			{
				mEnemyHand = false;

				//call the attack function and calculate the damage
				Attack::attackEnemy(gpGame->getCael(), mEnemies[mCurrentEnemy]);

				gpGame->getSoundManager()->chooseGrunt();

				if (mEnemies[mCurrentEnemy]->getCurrentHP() > 0)
				{
					gpGame->getSoundManager()->playEnemyHitSound(mEnemies[mCurrentEnemy]->getEnemyName());
					mCurrentEnemy = -1;
				}
				else
				{
					//killed the enemy
					mEnemies[mCurrentEnemy]->setCurrentHP(0);

					gpGame->getSoundManager()->playEnemyDeathSound(mEnemies[mCurrentEnemy]->getEnemyName());

					//calculate the experience gained
					ENEMY_NAMES name = mEnemies[mCurrentEnemy]->getEnemyName();
					int map = gpGame->getMapManager()->getCurrentMap()->getNumber();
					gpGame->getCael()->setExperience(gpGame->getCael()->getExperience() +
						(gpGame->getEnemyLevelManager()->getEnemyLevel(name, map).getEXP() * gpGame->getEXPMultiplier()));

					//level up accordingly
					while (gpGame->getCael()->getExperience() >= gpGame->getLevelManager()->getCurrentLevel().getEXP())
					{
						gpGame->getLevelManager()->getNextLevel();
						gpGame->getCael()->setCurrentHP(gpGame->getLevelManager()->getCurrentLevel().getHP());
						gpGame->getCael()->setCurrentMP(gpGame->getLevelManager()->getCurrentLevel().getMP());
					}

					//see if you get an item
					int num = rand()%(100)+1;

					if (num <= gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[mCurrentEnemy]->getEnemyName(), 1).getDropRate())
					{
						gpGame->getSoundManager()->playItemDrop();
						// you got an item
						int num = rand()%2;

						if (num == 0)
						{
							// potion
							gpGame->getCael()->setNumPotions(gpGame->getCael()->getNumPotions() + 1);
						}
						else
						{
							//ether
							gpGame->getCael()->setNumEthers(gpGame->getCael()->getNumEthers() + 1);
						}
					}

					//enemy death animation
					mEnemyAnimation = 6;
					mEnemies[mCurrentEnemy]->playAnimationOnce(mEnemyAnimation, mEnemies[mCurrentEnemy]->getLocation(), true);
					mEnemyAnimating = true;
				}

				// it is now the enemies turn
				mEnemiesTurn = true;
				
				mEnemyTurnTimer.start();

				// freeze menu until your turn again
				gpGame->getMenuSystem()->getCurrentMenu()->freeze();

				// play attack animation
				mCaelAnimation = 5;
				gpGame->getCael()->playAnimationOnce(mCaelAnimation, gpGame->getCael()->getBattleLocation(), true);
				mCaelAnimating = true;
			}
			else
			{
				mEnemyHand = true;
				mCurrentEnemy = 0;
			}
		}
		else if (theEvent->getType() == MAGIC_EVENT)
		{
			if (mEnemyHand)
			{
				if (gpGame->getCael()->getCurrentMP() >= 10)
				{
					gpGame->getSoundManager()->playMenuSelect();

					// hand is over enemy and we just selected one to use magic attack
					mEnemyHand = false;

					//FIRE
					int x = mEnemies[mCurrentEnemy]->getLocation().getX() + mEnemies[mCurrentEnemy]->getSprites()[0]->getBitmap()->w/2 - mFire->getSprites()[0]->getBitmap()->w/2;
					int y = mEnemies[mCurrentEnemy]->getLocation().getY() + (mEnemies[mCurrentEnemy]->getSprites()[0]->getBitmap()->h - mFire->getSprites()[0]->getBitmap()->h);

					mFireLocation = Point(x, y);

					mFire->playAnimationOnce(0, Point(x, y), true);
					
					gpGame->getSoundManager()->chooseGrunt();
					gpGame->getSoundManager()->playFireball();

					//magic function and damage calculation
					Magic::magic(gpGame->getCael(), mEnemies[mCurrentEnemy]);
				
					gpGame->getCael()->setCurrentMP(gpGame->getCael()->getCurrentMP() - 10);


					//play sound
					if (mEnemies[mCurrentEnemy]->getCurrentHP() <= 0)
					{
						gpGame->getSoundManager()->playEnemyDeathSound(mEnemies[mCurrentEnemy]->getEnemyName());
					}
					else
					{	
						gpGame->getSoundManager()->playEnemyHitSound(mEnemies[mCurrentEnemy]->getEnemyName());
					}

					// check to see if the enemy has died
					if (mEnemies[mCurrentEnemy]->getCurrentHP() <= 0)
					{
						mEnemies[mCurrentEnemy]->setCurrentHP(0);


						//items
						int num = rand()%(100)+1;

						if (num <= gpGame->getEnemyLevelManager()->getEnemyLevel(mEnemies[mCurrentEnemy]->getEnemyName(), 1).getDropRate())
						{
							gpGame->getSoundManager()->playItemDrop();
							// you got an item
							int num = rand()%2;

							if (num == 0)
							{
								// potion
								gpGame->getCael()->setNumPotions(gpGame->getCael()->getNumPotions() + 1);
							}
							else
							{
								//ether
								gpGame->getCael()->setNumEthers(gpGame->getCael()->getNumEthers() + 1);
							}
						}
						
						//calculate experience
						ENEMY_NAMES name = mEnemies[mCurrentEnemy]->getEnemyName();
						int map = gpGame->getMapManager()->getCurrentMap()->getNumber();
						gpGame->getCael()->setExperience(gpGame->getCael()->getExperience() + (gpGame->getEnemyLevelManager()->getEnemyLevel(name, map).getEXP() * gpGame->getEXPMultiplier()));

						if (gpGame->getCael()->getExperience() >= gpGame->getLevelManager()->getCurrentLevel().getEXP())
						{
							gpGame->getLevelManager()->getNextLevel();
							gpGame->getCael()->setCurrentHP(gpGame->getLevelManager()->getCurrentLevel().getHP());
							gpGame->getCael()->setCurrentMP(gpGame->getLevelManager()->getCurrentLevel().getMP());
						}								

						if(mEnemies.empty())
						{
							mBattleOver = true;
							
							mBattleOverTimer.start();
						}

						//death animation
						mEnemyAnimation = 6;
						mEnemies[mCurrentEnemy]->playAnimationOnce(mEnemyAnimation, mEnemies[mCurrentEnemy]->getLocation(), true);
						mEnemyAnimating = true;
					}
					else
					{
						mCurrentEnemy = -1;
					}

					// it is now the enemies turn
					mEnemiesTurn = true;
					mEnemyTurnTimer.start();

					//cael magic animation
					mCaelAnimation = 6;
					gpGame->getCael()->playAnimationOnce(mCaelAnimation, gpGame->getCael()->getBattleLocation(), true);
					mCaelAnimating = true;
				}
				else
				{
					gpGame->getSoundManager()->playMenuInvalid();
				}
			}
			else
			{
				gpGame->getSoundManager()->playMenuSelect();
				mEnemyHand = true;
			}
		}
		//go through enemies
		else if (theEvent->getType() == LEFT_EVENT)
		{
			if (mEnemyHand)
			{
				gpGame->getSoundManager()->playMenuTraverse();

				if (mCurrentEnemy <= 0)
				{
					mCurrentEnemy = mEnemies.size() - 1;
				}
				else
				{
					mCurrentEnemy--;
				}
			}
		}
		else if (theEvent->getType() == RIGHT_EVENT)
		{
			if (mEnemyHand)
			{
				gpGame->getSoundManager()->playMenuTraverse();

				if ((unsigned)mCurrentEnemy >= mEnemies.size() - 1)
				{
					mCurrentEnemy = 0;
				}
				else
				{
					mCurrentEnemy++;
				}
			}
		}
		else if (theEvent->getType() == END_TURN_EVENT)
		{
			mEnemiesTurn = true;
			mCurrentEnemy = -1;
			mEnemyTurnTimer.start();
		}
	}
}