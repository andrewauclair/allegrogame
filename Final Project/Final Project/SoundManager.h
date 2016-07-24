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

#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <allegro.h>
#include "Enemy.h"
#include "EventListener.h"

class SoundManager : public EventListener
{
private:
	SAMPLE* mWanderingMusic;
	SAMPLE* mBattleMusic;
	SAMPLE* mBossMusic;
	SAMPLE* mCreditMusic;

	SAMPLE* mCaelGasp;
	SAMPLE* mCaelGrunt;
	SAMPLE* mCaelGrunt2;
	SAMPLE* mCaelGrunt3;
	SAMPLE* mCaelPain;
	SAMPLE* mCreatureHit;
	SAMPLE* mDragonRoar;
	SAMPLE* mFireball;
	SAMPLE* mHealing;
	SAMPLE* mLoading;
	SAMPLE* mSatanMorrocDying;
	SAMPLE* mSatanMorrocRoar;
	SAMPLE* mSatanPain;
	SAMPLE* mSatanPain2;
	SAMPLE* mSatanPain3;
	SAMPLE* mSatanPain4;
	SAMPLE* mSatanGrowl;
	SAMPLE*	mSatanGrowl2;
	SAMPLE*	mSatanGrowl3;
	SAMPLE*	mSatanGrowl4;

	SAMPLE* mMenuSelect;
	SAMPLE* mMenuBack;
	SAMPLE* mMenuInvalid;
	SAMPLE* mMenuTraverse;
	SAMPLE* mMenuOpen;
	SAMPLE* mMenuExit;
	SAMPLE*	mSavingGame;
	SAMPLE* mItemDrop;

	SAMPLE* mAquaAttack;
	SAMPLE* mAquaAttack2;
	SAMPLE* mAquaDeath;
	SAMPLE* mAquaPain;
	SAMPLE* mAquaPain2;

	SAMPLE* mBoitataPain;
	SAMPLE* mBoitataPain2;

	SAMPLE* mDevilingAttack;
	SAMPLE* mDevilingAttack2;
	SAMPLE* mDevilingDeath;
	SAMPLE* mDevilingHit;
	SAMPLE* mDevilingHit2;
	SAMPLE* mDevilingHit3;

	SAMPLE* mDracoHit;
	SAMPLE* mDracoHit2;

	SAMPLE* mDragonDeath;

	SAMPLE* mSeekerAttack;
	SAMPLE* mSeekerAttack2;
	SAMPLE* mSeekerDeath;
	SAMPLE* mSeekerHit;
	SAMPLE* mSeekerHit2;

	
	SAMPLE* mGoblinAttack;
	SAMPLE* mGoblinAttack2;
	SAMPLE* mGoblinAttack3;
	SAMPLE* mGoblinDeath;
	SAMPLE* mGoblinHit;
	SAMPLE* mGoblinHit2;


	SAMPLE* mWolfAttack;
	SAMPLE* mWolfAttack2;
	SAMPLE* mWolfDeath;
	SAMPLE* mWolfHit;
	SAMPLE* mWolfHit2;

	SAMPLE* mDragonAttack;
	SAMPLE* mDracoAttack;
	
	SAMPLE* mSalamanderAttack;
	SAMPLE* mSalamanderHit;

	SAMPLE* mBoitataAttack;
	SAMPLE* mBoitataAttack2;
	SAMPLE* mBoitataDeath;
	SAMPLE* mDracoDeath;





	bool mSoundOn;

public:
	SoundManager();
	~SoundManager();

	void init();

	void playMenuSelect();
	void playMenuBack();
	void playMenuInvalid();
	void playMenuTraverse();
	void playMenuOpen();
	void playMenuExit();
	void playItemDrop();

	void playSavingGame();

	void playWanderingMusic();
	void playBattleMusic();
	void playBossMusic();
	void playCreditMusic();

	void playCaelGasp();
	void chooseGrunt();
	void choosePain();

	void playCaelGrunt();
	void playCaelGrunt2();
	void playCaelGrunt3();

	void playCaelPain();
	void playCreatureHit();
	void playDragonRoar();
	void playFireball();
	void playHealing();
	void playLoading();
	void playSatanMorrocDying();
	void playSatanMorrocRoar();

	void stopWanderingMusic();
	void stopBattleMusic();
	void stopBossMusic();
	void stopLoading();
	void stopCreditMusic();

	void playEnemyHitSound(ENEMY_NAMES enemy);
	void playEnemyDeathSound(ENEMY_NAMES enemy);
	void playEnemyGrowl(ENEMY_NAMES enemy);

	void stopAllSounds();

	bool isSoundOn();

	virtual void handleEvent(Event* theEvent);
};

#endif