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

#include "SoundManager.h"
#include "Game.h"
#include <iostream>
using namespace std;

SoundManager::SoundManager()
{
	mSoundOn = true;
}

SoundManager::~SoundManager()
{
	destroy_sample(mWanderingMusic);
	destroy_sample(mBattleMusic);
	destroy_sample(mBossMusic);
	destroy_sample(mCaelGasp);
	destroy_sample(mCaelGrunt);
	destroy_sample(mCaelGrunt2);
	destroy_sample(mCaelGrunt3);
	destroy_sample(mCaelPain);
	destroy_sample(mCreatureHit);
	destroy_sample(mDragonRoar);
	destroy_sample(mFireball);
	destroy_sample(mHealing);
	destroy_sample(mLoading);
	destroy_sample(mSatanMorrocDying);
	destroy_sample(mSatanMorrocRoar);
	destroy_sample(mMenuBack);
	destroy_sample(mMenuSelect);
	destroy_sample(mMenuInvalid);
	destroy_sample(mMenuTraverse);
	destroy_sample(mMenuOpen);
	destroy_sample(mMenuExit);
	destroy_sample(mSavingGame);
	destroy_sample(mCreditMusic);
	destroy_sample(mItemDrop);
	destroy_sample(mSatanPain);
	destroy_sample(mSatanPain2);
	destroy_sample(mSatanPain3);
	destroy_sample(mSatanPain4);
	destroy_sample(mSatanGrowl);
	destroy_sample(mSatanGrowl2);
	destroy_sample(mSatanGrowl3);
	destroy_sample(mSatanGrowl4);

	destroy_sample(mAquaAttack);
	destroy_sample(mAquaAttack2);
	destroy_sample(mAquaDeath);
	destroy_sample(mAquaPain);
	destroy_sample(mAquaPain2);
	destroy_sample(mBoitataPain);
	destroy_sample(mBoitataPain2);
	destroy_sample(mDevilingAttack);
	destroy_sample(mDevilingAttack2);
	destroy_sample(mDevilingDeath);
	destroy_sample(mDevilingHit);
	destroy_sample(mDevilingHit2);
	destroy_sample(mDevilingHit3);
	destroy_sample(mDracoHit);
	destroy_sample(mDracoHit2);
	destroy_sample(mSeekerAttack);
	destroy_sample(mSeekerAttack2);
	destroy_sample(mSeekerDeath);
	destroy_sample(mSeekerHit);
	destroy_sample(mSeekerHit2);

	destroy_sample(mWolfAttack);
	destroy_sample(mWolfAttack2);
	destroy_sample(mWolfDeath);
	destroy_sample(mWolfHit);
	destroy_sample(mWolfHit2);
	destroy_sample(mDragonDeath);

	destroy_sample(mDragonAttack);
	destroy_sample(mDracoAttack);
	destroy_sample(mSalamanderAttack);
	destroy_sample(mSalamanderHit);

	destroy_sample(mBoitataAttack);
	destroy_sample(mBoitataAttack2);
	destroy_sample(mBoitataDeath);
	destroy_sample(mDracoDeath);

	destroy_sample(mGoblinAttack);
	destroy_sample(mGoblinAttack2);
	destroy_sample(mGoblinAttack3);
	destroy_sample(mGoblinDeath);
	destroy_sample(mGoblinHit);
	destroy_sample(mGoblinHit2);
}

void SoundManager::init()
{
	if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0) 
    {
        allegro_message("Error initializing sound system");
        return;
    }
	
	mWanderingMusic = load_sample("Sounds/NightofSeclusion.wav");
	mBattleMusic = load_sample("Sounds/Combat.wav");
	mBossMusic = load_sample("Sounds/EntertheDarkness.wav");
	mCaelGasp = load_sample("Sounds/CaelGasp.wav");
	mCaelGrunt = load_sample("Sounds/CaelGrunt.wav");
	mCaelGrunt2 = load_sample("Sounds/CaelGrunt2.wav");
	mCaelGrunt3 = load_sample("Sounds/CaelGrunt3.wav");
	mCaelPain = load_sample("Sounds/CaelPain.wav");
	mCreatureHit = load_sample("Sounds/CreatureHit.wav");
	mDragonRoar = load_sample("Sounds/DragonRoar.wav");
	mFireball = load_sample("Sounds/Fireball.wav");
	mHealing = load_sample("Sounds/Healing.wav");
	mLoading = load_sample("Sounds/Loading.wav");
	mSatanMorrocDying = load_sample("Sounds/SatanPain.wav");
	mSatanMorrocRoar = load_sample("Sounds/SatanRoar.wav");

	mMenuSelect = load_sample("Sounds/menuSelect.wav");
	mMenuBack = load_sample("Sounds/menuBack.wav");
	mMenuInvalid = load_sample("Sounds/Invalid.wav");
	mMenuTraverse = load_sample("Sounds/menuTraverse.wav");
	mMenuOpen = load_sample("Sounds/menuOpen.wav");
	mMenuExit = load_sample("Sounds/menuExit.wav");
	mItemDrop = load_sample("Sounds/itemDrop.wav");
	
	mSavingGame = load_sample("Sounds/saveGame.wav");

	mCreditMusic = load_sample("Sounds/Fulfilled Desire.wav");

	mSatanPain = load_sample("Sounds/satanPain1.wav");
	mSatanPain2 = load_sample("Sounds/satanPain2.wav");
	mSatanPain3 = load_sample("Sounds/satanPain3.wav");
	mSatanPain4 = load_sample("Sounds/satanPain4.wav");

	mSatanGrowl = load_sample("Sounds/satanGrowl.wav");
	mSatanGrowl2 = load_sample("Sounds/satanGrowl2.wav");
	mSatanGrowl3 = load_sample("Sounds/satanGrowl3.wav");
	mSatanGrowl4 = load_sample("Sounds/satanGrowl4.wav");

	mAquaAttack = load_sample("Sounds/aquaAttack.wav");
	mAquaAttack2 = load_sample("Sounds/aquaAttack2.wav");
	mAquaDeath = load_sample("Sounds/aquaDeath.wav");
	mAquaPain = load_sample("Sounds/aquaPain.wav");
	mAquaPain2 = load_sample("Sounds/aquaPain2.wav");

	mBoitataPain = load_sample("Sounds/boitataHit.wav");
	mBoitataPain2 = load_sample("Sounds/boitataHit2.wav");

	mDevilingAttack = load_sample("Sounds/devilingAttack.wav");
	mDevilingAttack2 = load_sample("Sounds/devilingAttack2.wav");
	mDevilingDeath = load_sample("Sounds/devilingDeath.wav");
	mDevilingHit = load_sample("Sounds/devilingHit.wav");
	mDevilingHit2 = load_sample("Sounds/devilingHit2.wav");
	mDevilingHit3 = load_sample("Sounds/devilingHit3.wav");

	mDracoHit = load_sample("Sounds/dracoHit.wav");
	mDracoHit2 = load_sample("Sounds/dracoHit2.wav");

	mSeekerAttack = load_sample("Sounds/seekerAttack.wav");
	mSeekerAttack2 = load_sample("Sounds/seekerAttack2.wav");
	mSeekerDeath = load_sample("Sounds/seekerDeath.wav");
	mSeekerHit = load_sample("Sounds/seekerHit.wav");
	mSeekerHit2 = load_sample("Sounds/seekerHit2.wav");

	mWolfAttack = load_sample("Sounds/wolfAttack.wav");
	mWolfAttack2 = load_sample("Sounds/wolfAttack.wav");
	mWolfDeath = load_sample("Sounds/wolfDeath.wav");
	mWolfHit = load_sample("Sounds/wolfHit.wav");
	mWolfHit2 = load_sample("Sounds/wolfHit2.wav");
	mDragonDeath = load_sample("Sounds/dragonDeath.wav");

	mDragonAttack = load_sample("Sounds/dragonAttack.wav");
	mDracoAttack = load_sample("Sounds/dracoAttack.wav");
	mSalamanderAttack = load_sample("Sounds/salamanderAttack.wav");
	mSalamanderHit = load_sample("Sounds/salamanderHit.wav");

	mBoitataAttack = load_sample("Sounds/boitataAttack.wav");
	mBoitataAttack2 = load_sample("Sounds/boitataAttack2.wav");
	mBoitataDeath = load_sample("Sounds/boitataDeath.wav");
	mDracoDeath = load_sample("Sounds/dracoDeath.wav");

	mGoblinAttack = load_sample("Sounds/goblinAttack.wav");
	mGoblinAttack2 = load_sample("Sounds/goblinAttack2.wav");
	mGoblinAttack3 = load_sample("Sounds/goblinAttack3.wav");
	mGoblinDeath = load_sample("Sounds/goblinDeath.wav");
	mGoblinHit = load_sample("Sounds/goblinHit.wav");
	mGoblinHit2 = load_sample("Sounds/goblinHit2.wav");

	gpGame->getEventSystem()->addListener(SOUND_EVENT, this);
}

void SoundManager::playWanderingMusic()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mWanderingMusic, volume, panning, pitch, TRUE);
	}
}

void SoundManager::playCreditMusic()
{
	int panning = 128;
	int pitch = 1000;
	int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCreditMusic, volume, panning, pitch, TRUE);
	}
}

void SoundManager::playSavingGame()
{
	int panning = 128;
	int pitch = 1000;
	int volume = 255;

	if(mSoundOn)
	{
		play_sample(mSavingGame, volume, panning, pitch, FALSE);
	}
}

void SoundManager::playItemDrop()
{
	int panning = 128;
	int pitch = 1000;
	int volume = 255;

	if(mSoundOn)
	{
		play_sample(mItemDrop, volume, panning, pitch, FALSE);
	}
}

void SoundManager::playMenuExit()
{
	int panning =  128;
	int pitch = 1000;
	int volume = 128;

	if(mSoundOn)
	{
		play_sample(mMenuExit, volume, panning, pitch, FALSE);
	}	
}

void SoundManager::playMenuSelect()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mMenuSelect, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playMenuBack()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mMenuBack, volume, panning, pitch, FALSE);
	}	
}

void SoundManager::playMenuInvalid()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mMenuInvalid, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playMenuTraverse()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mMenuTraverse, volume, panning, pitch, FALSE);
	}	
}

void SoundManager::playMenuOpen()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mMenuOpen, volume, panning, pitch, FALSE);
	}	
}


void SoundManager::playBattleMusic()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mBattleMusic, volume, panning, pitch, TRUE);
	}
	
}

void SoundManager::playBossMusic()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mBossMusic, volume, panning, pitch, TRUE);
	}
	
}

void SoundManager::playCaelGasp()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCaelGasp, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playCaelGrunt()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCaelGrunt, volume, panning, pitch, FALSE);
	}	
}

void SoundManager::playCaelGrunt2()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCaelGrunt2, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playCaelGrunt3()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCaelGrunt3, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playCaelPain()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCaelPain, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playCreatureHit()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mCreatureHit, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playDragonRoar()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mDragonRoar, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playFireball()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mFireball, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playHealing()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mHealing, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playLoading()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 255;

	if(mSoundOn)
	{
		play_sample(mLoading, volume, panning, pitch, TRUE);
	}
	
}

void SoundManager::playSatanMorrocDying()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mSatanMorrocDying, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::playSatanMorrocRoar()
{
	int panning = 128;
    int pitch = 1000;
    int volume = 128;

	if(mSoundOn)
	{
		play_sample(mSatanMorrocRoar, volume, panning, pitch, FALSE);
	}
	
}

void SoundManager::stopWanderingMusic()
{
	stop_sample(mWanderingMusic);	
}

void SoundManager::stopBattleMusic()
{
	stop_sample(mBattleMusic);
}

void SoundManager::stopBossMusic()
{
	stop_sample(mBossMusic);
}

void SoundManager::stopCreditMusic()
{
	stop_sample(mCreditMusic);
}

void SoundManager::stopLoading()
{
	stop_sample(mLoading);
}

void SoundManager::chooseGrunt()
{
	if(mSoundOn)
	{
		int voice = rand()% 3;
		if(voice == 0)
		{
			playCaelGrunt();
		}
		else if(voice == 1)
		{
			playCaelGrunt2();
		}
		else
		{
			playCaelGrunt3();
		}
	}
	
}

void SoundManager::choosePain()
{
	if(mSoundOn)
	{
		int voice = rand()% 2;
		if(voice == 0)
		{
			playCaelGasp();
		}
		else
		{
			playCaelPain();
		}
	}
	
}

void SoundManager::playEnemyHitSound(ENEMY_NAMES enemy)
{
	int panning = 128;
	int pitch = 1000;
	int volume = 128;
	
	if(mSoundOn)
	{
		if(enemy == NIDHOGGR || enemy == GOPINICH)
		{
			playCreatureHit();
		}
		if(enemy == SALAMANDER)
		{
			play_sample(mSalamanderHit, volume, panning, pitch, FALSE);
		}
		if(enemy == SATAN_MORROC)
		{
			int voice = rand()% 4;
			
			if(voice == 0)
			{
				play_sample(mSatanPain, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mSatanPain2, volume, panning, pitch, FALSE);
			}
			else if(voice == 2)
			{
				play_sample(mSatanPain3, volume, panning, pitch, FALSE);
			}
			else if(voice == 3)
			{
				play_sample(mSatanPain4, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == DESERT_WOLF)
		{
			int voice = rand()% 2;
			
			if(voice == 0)
			{
				play_sample(mWolfHit, 255, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mWolfHit2, 255, panning, pitch, FALSE);
			}
		}
		if(enemy == DRACO)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mDracoHit, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mDracoHit2, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == SEEKER)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mSeekerHit, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mSeekerHit2, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == GOBLIN)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mGoblinHit, 255, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mGoblinHit2, 255, panning, pitch, FALSE);
			}
		}
		if(enemy == DEVILING)
		{
			int voice = rand()% 3;

			if(voice == 0)
			{
				play_sample(mDevilingHit, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mDevilingHit2, volume, panning, pitch, FALSE);
			}
			else if(voice == 2)
			{
				play_sample(mDevilingHit3, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == AQUA)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mAquaPain, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mAquaPain2, volume, panning, pitch, FALSE);
			}
			
		}
		if(enemy == BOITATA)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mBoitataPain, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mBoitataPain2, volume, panning, pitch, FALSE);
			}
		}
		
	}
}

void SoundManager::playEnemyDeathSound(ENEMY_NAMES enemy)
{
	int volume = 128;
	int panning = 128;
	int pitch = 1000;

	if(mSoundOn)
	{
		if(enemy == NIDHOGGR || enemy == GOPINICH)
		{
			play_sample(mDragonDeath, volume, panning, pitch, FALSE);
		}
		else if(enemy == SATAN_MORROC)
		{
			playSatanMorrocDying();
		}
		else if(enemy == AQUA)
		{
			play_sample(mAquaDeath, volume, panning, pitch, FALSE);
		}
		else if(enemy == DEVILING)
		{
			play_sample(mDevilingDeath, volume, panning, pitch, FALSE);
		}
		else if(enemy == SEEKER)
		{
			play_sample(mSeekerDeath, volume, panning, pitch, FALSE);
		}
		else if(enemy == GOBLIN)
		{
			play_sample(mGoblinDeath, 255, panning, pitch, FALSE);
		}
		else if(enemy == DESERT_WOLF)
		{
			play_sample(mWolfDeath, 255, panning, pitch, FALSE);
		}
		else if(enemy == SALAMANDER)
		{
			play_sample(mSalamanderHit, volume, panning, pitch, FALSE);
		}
		else if(enemy == BOITATA)
		{
			play_sample(mBoitataDeath, volume, panning, pitch, FALSE);
		}
		else if(enemy == DRACO)
		{
			play_sample(mDracoDeath, 255, panning, pitch, FALSE);
		}
	}	
}

void SoundManager::playEnemyGrowl(ENEMY_NAMES enemy)
{	
	int panning = 128;
	int pitch = 1000;
	int volume = 128;
	
	if(mSoundOn)
	{
		if(enemy == SATAN_MORROC)
		{
			int voice = rand()% 4;
			
			if(voice == 0)
			{
				play_sample(mSatanGrowl, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mSatanGrowl2, volume, panning, pitch, FALSE);
			}
			else if(voice == 2)
			{
				play_sample(mSatanGrowl3, volume, panning, pitch, FALSE);
			}
			else if(voice == 3)
			{
				play_sample(mSatanGrowl4, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == SALAMANDER)
		{
			play_sample(mSalamanderAttack, volume, panning, pitch, FALSE);
		}
		if(enemy == DRACO)
		{
			play_sample(mDracoAttack, 255, panning, pitch, FALSE);
		}
		if(enemy == GOPINICH || enemy == NIDHOGGR)
		{
			play_sample(mDragonAttack, volume, panning, pitch, FALSE);
		}
		if(enemy == DESERT_WOLF)
		{
			int voice = rand()% 2;
			
			if(voice == 0)
			{
				play_sample(mWolfAttack, 255, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mWolfAttack2, 255, panning, pitch, FALSE);
			}
		}
		if(enemy == AQUA)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mAquaAttack, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mAquaAttack2, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == DEVILING)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mDevilingAttack, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mDevilingAttack2, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == SEEKER)
		{
			int voice = rand()% 2;

			if(voice == 0)
			{
				play_sample(mSeekerAttack, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mSeekerAttack2, volume, panning, pitch, FALSE);
			}
		}
		if(enemy == BOITATA)
		{
			int voice = rand()%2;
			
			if(voice == 0)
			{
				play_sample(mBoitataAttack, volume, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mBoitataAttack2, volume, panning, pitch, FALSE);
			}
			
		}
		if(enemy == GOBLIN)
		{
			int voice = rand()% 3;

			
			if(voice == 0)
			{
				play_sample(mGoblinAttack, 255, panning, pitch, FALSE);
			}
			else if(voice == 1)
			{
				play_sample(mGoblinAttack2, 255, panning, pitch, FALSE);
			}
			else if(voice == 2)
			{
				play_sample(mGoblinAttack3, 255, panning, pitch, FALSE);
			}
		}
	}
}

void SoundManager::stopAllSounds()
{
	if(mSoundOn)
	{
		stop_sample(mCaelGasp);
		stop_sample(mCaelGrunt);
		stop_sample(mCaelGrunt2);
		stop_sample(mCaelGrunt3);
		stop_sample(mCaelPain);
		stop_sample(mCreatureHit);
		stop_sample(mDragonRoar);
		stop_sample(mFireball);
		stop_sample(mHealing);
		stop_sample(mLoading);
		stop_sample(mSatanMorrocDying);
		stop_sample(mSatanMorrocRoar);
		stop_sample(mItemDrop);
		stop_sample(mSatanPain);
		stop_sample(mSatanPain2);
		stop_sample(mSatanPain3);
		stop_sample(mSatanPain4);
		stop_sample(mSatanGrowl);
		stop_sample(mSatanGrowl2);
		stop_sample(mSatanGrowl3);
		stop_sample(mSatanGrowl4);

		stop_sample(mAquaAttack);
		stop_sample(mAquaAttack2);
		stop_sample(mAquaDeath);
		stop_sample(mAquaPain);
		stop_sample(mAquaPain2);
		stop_sample(mBoitataPain);
		stop_sample(mBoitataPain2);
		stop_sample(mDevilingAttack);
		stop_sample(mDevilingAttack2);
		stop_sample(mDevilingDeath);
		stop_sample(mDevilingHit);
		stop_sample(mDevilingHit2);
		stop_sample(mDevilingHit3);
		stop_sample(mDracoHit);
		stop_sample(mDracoHit2);
		stop_sample(mSeekerAttack);
		stop_sample(mSeekerAttack2);
		stop_sample(mSeekerDeath);
		stop_sample(mSeekerHit);
		stop_sample(mSeekerHit2);

		stop_sample(mWolfAttack);
		stop_sample(mWolfAttack2);
		stop_sample(mWolfDeath);
		stop_sample(mWolfHit);
		stop_sample(mWolfHit2);
		stop_sample(mDragonDeath);

		stop_sample(mDragonAttack);
		stop_sample(mDracoAttack);
		stop_sample(mSalamanderAttack);
		stop_sample(mSalamanderHit);

		stop_sample(mBoitataAttack);
		stop_sample(mBoitataAttack2);
		stop_sample(mBoitataDeath);
		stop_sample(mDracoDeath);

		stop_sample(mGoblinAttack);
		stop_sample(mGoblinAttack2);
		stop_sample(mGoblinAttack3);
		stop_sample(mGoblinDeath);
		stop_sample(mGoblinHit);
		stop_sample(mGoblinHit2);
	}
}

bool SoundManager::isSoundOn()
{
	return mSoundOn;
}

void SoundManager::handleEvent(Event* theEvent)
{
	if (theEvent->getType() == SOUND_EVENT)
	{
		if (mSoundOn)
		{
			if(!gpGame->isAtTitleScreen())
			{
				stopWanderingMusic();
			}
			
			mSoundOn = false;
		}
		else
		{			
			mSoundOn = true;

			playMenuSelect();
			if(!gpGame->isAtTitleScreen())
			{
				playWanderingMusic();
			}
		}
	}
}