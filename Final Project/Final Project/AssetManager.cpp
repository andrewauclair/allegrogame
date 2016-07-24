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

#include "AssetManager.h"
#include <vector>
#include <allegro.h>
#include <iostream>
using namespace std;

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
	multimap<ASSET_NUMBER, AnimatedSprite*>::iterator iter;

	for (iter = mAssetMap.begin(); iter != mAssetMap.end(); ++iter )
	{
		delete iter->second;
	}
}

void AssetManager::loaded(int total)
{
	done++;
	//cout << done << "/" << total << endl;
}

//Load all of the art assets into sprites
void AssetManager::init()
{
	int stuff = 76;

	done = 0;

	AnimatedSprite* caelAttack = new AnimatedSprite();
	caelAttack->setSpeed(150);
	
	//Cael Attack 
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack2.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack3.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack4.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack5.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack6.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack7.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack8.bmp", NULL));
	caelAttack->addFrame(load_bitmap("Assets/Cael/mcAttack9.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_ATTACK, caelAttack));
	
	loaded(stuff);

	//Cael Up
	AnimatedSprite* caelUp = new AnimatedSprite();
	caelUp->setSpeed(75);
	
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack2.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack3.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack4.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack5.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack6.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack7.bmp", NULL));
	caelUp->addFrame(load_bitmap("Assets/Cael/mcBack8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_UP, caelUp));

	loaded(stuff);

	//Cael Dying 
	AnimatedSprite* caelDying = new AnimatedSprite();
	caelDying->setSpeed(150);

	caelDying->addFrame(load_bitmap("Assets/Cael/mcDying.bmp", NULL));
	caelDying->addFrame(load_bitmap("Assets/Cael/mcDying2.bmp", NULL));
	caelDying->addFrame(load_bitmap("Assets/Cael/mcDying3.bmp", NULL));
	caelDying->addFrame(load_bitmap("Assets/Cael/mcDying4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_DYING, caelDying));

	loaded(stuff);

	//Cael Down
	AnimatedSprite* caelDown = new AnimatedSprite();
	caelDown->setSpeed(75);

	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward2.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward3.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward4.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward5.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward6.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward7.bmp", NULL));
	caelDown->addFrame(load_bitmap("Assets/Cael/mcForward8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_DOWN, caelDown));

	loaded(stuff);

	//Cael Idle
	AnimatedSprite* caelIdle = new AnimatedSprite();
	caelIdle->setSpeed(175);

	caelIdle->addFrame(load_bitmap("Assets/Cael/mcIdle.bmp", NULL));
	caelIdle->addFrame(load_bitmap("Assets/Cael/mcIdle2.bmp", NULL));
	caelIdle->addFrame(load_bitmap("Assets/Cael/mcIdle3.bmp", NULL));
	caelIdle->addFrame(load_bitmap("Assets/Cael/mcIdle4.bmp", NULL));
	caelIdle->addFrame(load_bitmap("Assets/Cael/mcIdle5.bmp", NULL));
	caelIdle->addFrame(load_bitmap("Assets/Cael/mcIdle6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_IDLE, caelIdle));

	loaded(stuff);

	//Cael Left
	AnimatedSprite* caelLeft = new AnimatedSprite();
	caelLeft->setSpeed(75);

	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft2.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft3.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft4.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft5.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft6.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft7.bmp", NULL));
	caelLeft->addFrame(load_bitmap("Assets/Cael/mcLeft8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_LEFT, caelLeft));

	loaded(stuff);

	//Cael Magic
	AnimatedSprite* caelMagicAttack = new AnimatedSprite();
	caelMagicAttack->setSpeed(150);

	caelMagicAttack->addFrame(load_bitmap("Assets/Cael/mcMagicAttack.bmp", NULL));
	caelMagicAttack->addFrame(load_bitmap("Assets/Cael/mcMagicAttack2.bmp", NULL));
	caelMagicAttack->addFrame(load_bitmap("Assets/Cael/mcMagicAttack3.bmp", NULL));
	caelMagicAttack->addFrame(load_bitmap("Assets/Cael/mcMagicAttack4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_MAGIC, caelMagicAttack));

	loaded(stuff);

	//Cael Right
	AnimatedSprite* caelRight = new AnimatedSprite();
	caelRight->setSpeed(75);

	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight2.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight3.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight4.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight5.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight6.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight7.bmp", NULL));
	caelRight->addFrame(load_bitmap("Assets/Cael/mcRight8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CAEL_RIGHT, caelRight));

	loaded(stuff);

	//Aqua Elemental Attack
	AnimatedSprite* aquaAttack = new AnimatedSprite();
	aquaAttack->setSpeed(150);
	
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack2.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack3.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack4.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack5.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack6.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack7.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack8.bmp", NULL));
	aquaAttack->addFrame(load_bitmap("Assets/Aqua Elemental/aquaAttack9.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(AQUA_ATTACK, aquaAttack));

	loaded(stuff);

	//Aqua Dying
	AnimatedSprite* aquaDying = new AnimatedSprite();
	aquaDying->setSpeed(150);

	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying.bmp", NULL));
	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying2.bmp", NULL));
	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying3.bmp", NULL));
	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying4.bmp", NULL));
	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying5.bmp", NULL));
	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying6.bmp", NULL));
	aquaDying->addFrame(load_bitmap("Assets/Aqua Elemental/aquaDying7.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(AQUA_DYING, aquaDying));

	loaded(stuff);

	//Aqua Idle
	AnimatedSprite* aquaIdle = new AnimatedSprite();
	aquaIdle->setSpeed(150);

	aquaIdle->addFrame(load_bitmap("Assets/Aqua Elemental/aquaIdle.bmp", NULL));
	aquaIdle->addFrame(load_bitmap("Assets/Aqua Elemental/aquaIdle2.bmp", NULL));
	aquaIdle->addFrame(load_bitmap("Assets/Aqua Elemental/aquaIdle3.bmp", NULL));
	aquaIdle->addFrame(load_bitmap("Assets/Aqua Elemental/aquaIdle4.bmp", NULL));
	aquaIdle->addFrame(load_bitmap("Assets/Aqua Elemental/aquaIdle5.bmp", NULL));
	aquaIdle->addFrame(load_bitmap("Assets/Aqua Elemental/aquaIdle6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(AQUA_IDLE, aquaIdle));

	loaded(stuff);

	//Boitata Attack
	AnimatedSprite* boitataAttack = new AnimatedSprite();
	boitataAttack->setSpeed(150);

	boitataAttack->addFrame(load_bitmap("Assets/Boitata/boitataAttack.bmp", NULL));
	boitataAttack->addFrame(load_bitmap("Assets/Boitata/boitataAttack2.bmp", NULL));
	boitataAttack->addFrame(load_bitmap("Assets/Boitata/boitataAttack3.bmp", NULL));
	boitataAttack->addFrame(load_bitmap("Assets/Boitata/boitataAttack4.bmp", NULL));
	boitataAttack->addFrame(load_bitmap("Assets/Boitata/boitataAttack5.bmp", NULL));
	boitataAttack->addFrame(load_bitmap("Assets/Boitata/boitataAttack6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(BOITATA_ATTACK, boitataAttack));

	loaded(stuff);

	//Boitata Dying
	AnimatedSprite* boitataDying = new AnimatedSprite();
	boitataDying->setSpeed(150);

	boitataDying->addFrame(load_bitmap("Assets/Boitata/boitataDying.bmp", NULL));
	boitataDying->addFrame(load_bitmap("Assets/Boitata/boitataDying2.bmp", NULL));
	boitataDying->addFrame(load_bitmap("Assets/Boitata/boitataDying3.bmp", NULL));
	boitataDying->addFrame(load_bitmap("Assets/Boitata/boitataDying4.bmp", NULL));
	boitataDying->addFrame(load_bitmap("Assets/Boitata/boitataDying5.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(BOITATA_DYING, boitataDying));

	loaded(stuff);

	//Boitata Idle
	AnimatedSprite* boitataIdle = new AnimatedSprite();
	boitataIdle->setSpeed(150);

	boitataIdle->addFrame(load_bitmap("Assets/Boitata/boitataIdle.bmp", NULL));
	boitataIdle->addFrame(load_bitmap("Assets/Boitata/boitataIdle2.bmp", NULL));
	boitataIdle->addFrame(load_bitmap("Assets/Boitata/boitataIdle3.bmp", NULL));
	boitataIdle->addFrame(load_bitmap("Assets/Boitata/boitataIdle4.bmp", NULL));
	boitataIdle->addFrame(load_bitmap("Assets/Boitata/boitataIdle5.bmp", NULL));
	boitataIdle->addFrame(load_bitmap("Assets/Boitata/boitataIdle6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(BOITATA_IDLE, boitataIdle));

	loaded(stuff);

	//Desert Wolf Attack
	AnimatedSprite* wolfAttack = new AnimatedSprite();
	wolfAttack->setSpeed(150);

	wolfAttack->addFrame(load_bitmap("Assets/Desert Wolf/wolfAttack.bmp", NULL));
	wolfAttack->addFrame(load_bitmap("Assets/Desert Wolf/wolfAttack2.bmp", NULL));
	wolfAttack->addFrame(load_bitmap("Assets/Desert Wolf/wolfAttack3.bmp", NULL));
	wolfAttack->addFrame(load_bitmap("Assets/Desert Wolf/wolfAttack4.bmp", NULL));
	wolfAttack->addFrame(load_bitmap("Assets/Desert Wolf/wolfAttack5.bmp", NULL));
	wolfAttack->addFrame(load_bitmap("Assets/Desert Wolf/wolfAttack6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(WOLF_ATTACK, wolfAttack));

	loaded(stuff);

	//Desert Wolf Dying
	AnimatedSprite* wolfDying = new AnimatedSprite();
	wolfDying->setSpeed(250);

	wolfDying->addFrame(load_bitmap("Assets/Desert Wolf/wolfDying.bmp", NULL));
	wolfDying->addFrame(load_bitmap("Assets/Desert Wolf/wolfDying2.bmp", NULL));
	wolfDying->addFrame(load_bitmap("Assets/Desert Wolf/wolfDying3.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(WOLF_DYING, wolfDying));

	loaded(stuff);

	//Desert Wolf Idle
	AnimatedSprite* wolfIdle = new AnimatedSprite();
	wolfIdle->setSpeed(150);

	wolfIdle->addFrame(load_bitmap("Assets/Desert Wolf/wolfIdle.bmp", NULL));
	wolfIdle->addFrame(load_bitmap("Assets/Desert Wolf/wolfIdle2.bmp", NULL));
	wolfIdle->addFrame(load_bitmap("Assets/Desert Wolf/wolfIdle3.bmp", NULL));
	wolfIdle->addFrame(load_bitmap("Assets/Desert Wolf/wolfIdle4.bmp", NULL));
	wolfIdle->addFrame(load_bitmap("Assets/Desert Wolf/wolfIdle5.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(WOLF_IDLE, wolfIdle));

	loaded(stuff);

	//Deviling Attack
	AnimatedSprite* devilingAttack = new AnimatedSprite();
	devilingAttack->setSpeed(150);

	devilingAttack->addFrame(load_bitmap("Assets/Deviling/devilingAttack.bmp", NULL));
	devilingAttack->addFrame(load_bitmap("Assets/Deviling/devilingAttack2.bmp", NULL));
	devilingAttack->addFrame(load_bitmap("Assets/Deviling/devilingAttack3.bmp", NULL));
	devilingAttack->addFrame(load_bitmap("Assets/Deviling/devilingAttack4.bmp", NULL));
	devilingAttack->addFrame(load_bitmap("Assets/Deviling/devilingAttack5.bmp", NULL));
	devilingAttack->addFrame(load_bitmap("Assets/Deviling/devilingAttack6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DEVILING_ATTACK, devilingAttack));

	loaded(stuff);

	//Deviling Up
	AnimatedSprite* devilingUp = new AnimatedSprite();
	devilingUp->setSpeed(150);

	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle2.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle3.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle4.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle5.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle6.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle7.bmp", NULL));
	devilingUp->addFrame(load_bitmap("Assets/Deviling/devilingBackIdle8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DEVILING_UP, devilingUp));

	loaded(stuff);

	//Deviling Up and Right
	AnimatedSprite* devilingUpRight = new AnimatedSprite();
	devilingUpRight->setSpeed(150);

	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight2.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight3.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight4.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight5.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight6.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight7.bmp", NULL));
	devilingUpRight->addFrame(load_bitmap("Assets/Deviling/devilingBackIdleRight8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DEVILING_UP_RIGHT, devilingUpRight));

	loaded(stuff);

	//Deviling Dying
	AnimatedSprite* devilingDying = new AnimatedSprite();
	devilingDying->setSpeed(150);

	devilingDying->addFrame(load_bitmap("Assets/Deviling/devilingHurt.bmp", NULL));
	devilingDying->addFrame(load_bitmap("Assets/Deviling/devilingHurt2.bmp", NULL));
	devilingDying->addFrame(load_bitmap("Assets/Deviling/devilingHurt3.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DEVILING_DYING, devilingDying));

	loaded(stuff);

	//Deviling Idle
	AnimatedSprite* devilingIdle = new AnimatedSprite();
	devilingIdle->setSpeed(150);

	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle2.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle3.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle4.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle5.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle6.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle7.bmp", NULL));
	devilingIdle->addFrame(load_bitmap("Assets/Deviling/devilingIdle8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DEVILING_IDLE, devilingIdle));

	loaded(stuff);

	//Deviling Idle
	AnimatedSprite* devilingIdleRight = new AnimatedSprite();
	devilingIdleRight->setSpeed(150);

	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight2.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight3.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight4.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight5.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight6.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight7.bmp", NULL));
	devilingIdleRight->addFrame(load_bitmap("Assets/Deviling/devilingIdleRight8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DEVILING_IDLE_RIGHT, devilingIdleRight));

	loaded(stuff);

	//Draco Attack
	AnimatedSprite* dracoAttack = new AnimatedSprite();
	dracoAttack->setSpeed(150);

	dracoAttack->addFrame(load_bitmap("Assets/Draco/dracoAttack.bmp", NULL));
	dracoAttack->addFrame(load_bitmap("Assets/Draco/dracoAttack2.bmp", NULL));
	dracoAttack->addFrame(load_bitmap("Assets/Draco/dracoAttack3.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_ATTACK, dracoAttack));

	loaded(stuff);

	//Draco Up
	AnimatedSprite* dracoUp = new AnimatedSprite();
	dracoUp->setSpeed(150);

	dracoUp->addFrame(load_bitmap("Assets/Draco/dracoBack.bmp", NULL));
	dracoUp->addFrame(load_bitmap("Assets/Draco/dracoBack2.bmp", NULL));
	dracoUp->addFrame(load_bitmap("Assets/Draco/dracoBack3.bmp", NULL));
	dracoUp->addFrame(load_bitmap("Assets/Draco/dracoBack4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_UP, dracoUp));

	loaded(stuff);

	//Draco Up Right
	AnimatedSprite* dracoUpRight = new AnimatedSprite();
	dracoUp->setSpeed(150);

	dracoUpRight->addFrame(load_bitmap("Assets/Draco/dracoBackRight.bmp", NULL));
	dracoUpRight->addFrame(load_bitmap("Assets/Draco/dracoBackRight2.bmp", NULL));
	dracoUpRight->addFrame(load_bitmap("Assets/Draco/dracoBackRight3.bmp", NULL));
	dracoUpRight->addFrame(load_bitmap("Assets/Draco/dracoBackRight4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_UP_RIGHT, dracoUpRight));

	loaded(stuff);

	//Draco Dying
	AnimatedSprite* dracoDying = new AnimatedSprite();
	dracoDying->setSpeed(150);

	dracoDying->addFrame(load_bitmap("Assets/Draco/dracoDying.bmp", NULL));
	dracoDying->addFrame(load_bitmap("Assets/Draco/dracoDying2.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_DYING, dracoDying));

	loaded(stuff);

	//Draco Idle
	AnimatedSprite* dracoIdle = new AnimatedSprite();
	dracoIdle->setSpeed(150);

	dracoIdle->addFrame(load_bitmap("Assets/Draco/dracoIdle.bmp", NULL));
	dracoIdle->addFrame(load_bitmap("Assets/Draco/dracoIdle2.bmp", NULL));
	dracoIdle->addFrame(load_bitmap("Assets/Draco/dracoIdle3.bmp", NULL));
	dracoIdle->addFrame(load_bitmap("Assets/Draco/dracoIdle4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_IDLE, dracoIdle));

	loaded(stuff);

	//Draco Left
	AnimatedSprite* dracoLeft = new AnimatedSprite();
	dracoLeft->setSpeed(150);

	dracoLeft->addFrame(load_bitmap("Assets/Draco/dracoLeft.bmp", NULL));
	dracoLeft->addFrame(load_bitmap("Assets/Draco/dracoLeft2.bmp", NULL));
	dracoLeft->addFrame(load_bitmap("Assets/Draco/dracoLeft3.bmp", NULL));
	dracoLeft->addFrame(load_bitmap("Assets/Draco/dracoLeft4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_LEFT, dracoLeft));

	loaded(stuff);

	//Draco Right
	AnimatedSprite* dracoRight = new AnimatedSprite();
	dracoRight->setSpeed(150);

	dracoRight->addFrame(load_bitmap("Assets/Draco/dracoRight.bmp", NULL));
	dracoRight->addFrame(load_bitmap("Assets/Draco/dracoRight2.bmp", NULL));
	dracoRight->addFrame(load_bitmap("Assets/Draco/dracoRight3.bmp", NULL));
	dracoRight->addFrame(load_bitmap("Assets/Draco/dracoRight4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(DRACO_RIGHT, dracoRight));

	loaded(stuff);

	//Goblin Attack
	AnimatedSprite* goblinAttack = new AnimatedSprite();
	goblinAttack->setSpeed(150);

	goblinAttack->addFrame(load_bitmap("Assets/Goblin/goblinAttack.bmp", NULL));
	goblinAttack->addFrame(load_bitmap("Assets/Goblin/goblinAttack2.bmp", NULL));
	goblinAttack->addFrame(load_bitmap("Assets/Goblin/goblinAttack3.bmp", NULL));
	goblinAttack->addFrame(load_bitmap("Assets/Goblin/goblinAttack4.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GOBLIN_ATTACK, goblinAttack));

	loaded(stuff);

	//Goblin Dying
	AnimatedSprite* goblinDying = new AnimatedSprite();
	goblinDying->setSpeed(150);

	goblinDying->addFrame(load_bitmap("Assets/Goblin/goblinDying.bmp", NULL));
	goblinDying->addFrame(load_bitmap("Assets/Goblin/goblinDying2.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GOBLIN_DYING, goblinDying));

	loaded(stuff);

	//Goblin Idle
	AnimatedSprite* goblinIdle = new AnimatedSprite();
	goblinIdle->setSpeed(150);

	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle.bmp", NULL));
	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle2.bmp", NULL));
	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle3.bmp", NULL));
	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle4.bmp", NULL));
	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle5.bmp", NULL));
	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle6.bmp", NULL));
	goblinIdle->addFrame(load_bitmap("Assets/Goblin/goblinIdle7.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GOBLIN_IDLE, goblinIdle));

	loaded(stuff);

	//Gopinich Attack
	AnimatedSprite* gopinichAttack = new AnimatedSprite();
	gopinichAttack->setSpeed(150);

	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack.bmp", NULL));
	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack2.bmp", NULL));
	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack3.bmp", NULL));
	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack4.bmp", NULL));
	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack5.bmp", NULL));
	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack6.bmp", NULL));
	gopinichAttack->addFrame(load_bitmap("Assets/Gopinich/gopinichAttack7.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GOPINICH_ATTACK, gopinichAttack));

	loaded(stuff);

	//Gopinich Dying
	AnimatedSprite* gopinichDying = new AnimatedSprite();
	gopinichDying->setSpeed(150);

	gopinichDying->addFrame(load_bitmap("Assets/Gopinich/gopinichDying.bmp", NULL));
	gopinichDying->addFrame(load_bitmap("Assets/Gopinich/gopinichDying2.bmp", NULL));
	gopinichDying->addFrame(load_bitmap("Assets/Gopinich/gopinichDying3.bmp", NULL));
	
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GOPINICH_DYING, gopinichDying));

	loaded(stuff);

	//Gopinich Idle
	AnimatedSprite* gopinichIdle = new AnimatedSprite();
	gopinichIdle->setSpeed(150);

	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle2.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle3.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle4.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle5.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle6.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle7.bmp", NULL));
	gopinichIdle->addFrame(load_bitmap("Assets/Gopinich/gopinichIdle8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GOPINICH_IDLE, gopinichIdle));

	loaded(stuff);

	//Map 1
	AnimatedSprite* map1Foreground = new AnimatedSprite();
	map1Foreground->addFrame(load_bitmap("Assets/Maps/map1Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP1_FOREGROUND, map1Foreground));

	loaded(stuff);

	AnimatedSprite* map1Background = new AnimatedSprite();
	map1Background->addFrame(load_bitmap("Assets/Maps/map1Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP1_BACKGROUND, map1Background));

	loaded(stuff);

	//Map 2
	AnimatedSprite* map2Foreground = new AnimatedSprite();
	map2Foreground->addFrame(load_bitmap("Assets/Maps/map2Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP2_FOREGROUND, map2Foreground));
	
	loaded(stuff);

	AnimatedSprite* map2Background = new AnimatedSprite();
	map2Background->addFrame(load_bitmap("Assets/Maps/map2Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP2_BACKGROUND, map2Background));
	
	loaded(stuff);

	//Map 3
	AnimatedSprite* map3Foreground = new AnimatedSprite();
	map3Foreground->addFrame(load_bitmap("Assets/Maps/map3Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP3_FOREGROUND, map3Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map3Background = new AnimatedSprite();
	map3Background->addFrame(load_bitmap("Assets/Maps/map3Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP3_BACKGROUND, map3Background));
	
	loaded(stuff);

	//Map 4
	AnimatedSprite* map4Foreground = new AnimatedSprite();
	map4Foreground->addFrame(load_bitmap("Assets/Maps/map4Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP4_FOREGROUND, map4Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map4Background = new AnimatedSprite();
	map4Background->addFrame(load_bitmap("Assets/Maps/map4Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP4_BACKGROUND, map4Background));
	
	loaded(stuff);

	//Map 5
	AnimatedSprite* map5Foreground = new AnimatedSprite();
	map5Foreground->addFrame(load_bitmap("Assets/Maps/map5Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP5_FOREGROUND, map5Foreground));
	 
	loaded(stuff);
	
	AnimatedSprite* map5Background = new AnimatedSprite();
	map5Background->addFrame(load_bitmap("Assets/Maps/map5Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP5_BACKGROUND, map5Background));
	
	loaded(stuff);

	//Map 6
	AnimatedSprite* map6Foreground = new AnimatedSprite();
	map6Foreground->addFrame(load_bitmap("Assets/Maps/map6Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP6_FOREGROUND, map6Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map6Background = new AnimatedSprite();
	map6Background->addFrame(load_bitmap("Assets/Maps/map6Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP6_BACKGROUND, map6Background));
	
	loaded(stuff);

	//Map 7
	AnimatedSprite* map7Foreground = new AnimatedSprite();
	map7Foreground->addFrame(load_bitmap("Assets/Maps/map7Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP7_FOREGROUND, map7Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map7Background = new AnimatedSprite();
	map7Background->addFrame(load_bitmap("Assets/Maps/map7Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP7_BACKGROUND, map7Background));
	
	loaded(stuff);

	//Map 8
	AnimatedSprite* map8Foreground = new AnimatedSprite();
	map8Foreground->addFrame(load_bitmap("Assets/Maps/map8Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP8_FOREGROUND, map8Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map8Background = new AnimatedSprite();
	map8Background->addFrame(load_bitmap("Assets/Maps/map8Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP8_BACKGROUND, map8Background));
	
	loaded(stuff);

	//Map 9
	AnimatedSprite* map9Foreground = new AnimatedSprite();
	map9Foreground->addFrame(load_bitmap("Assets/Maps/map9Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP9_FOREGROUND, map9Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map9Background = new AnimatedSprite();
	map9Background->addFrame(load_bitmap("Assets/Maps/map9Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP9_BACKGROUND, map9Background));
	
	loaded(stuff);

	//Map 10
	AnimatedSprite* map10Foreground = new AnimatedSprite();
	map10Foreground->addFrame(load_bitmap("Assets/Maps/map10Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP10_FOREGROUND, map10Foreground));
	 
	loaded(stuff);

	AnimatedSprite* map10Background = new AnimatedSprite();
	map10Background->addFrame(load_bitmap("Assets/Maps/map10Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP10_BACKGROUND, map10Background));
	
	loaded(stuff);

	//Map 11
	AnimatedSprite* map11Foreground = new AnimatedSprite();
	map11Foreground->addFrame(load_bitmap("Assets/Maps/map11Foreground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP11_FOREGROUND, map11Foreground));

	loaded(stuff);

	AnimatedSprite* map11Background = new AnimatedSprite();
	map11Background->addFrame(load_bitmap("Assets/Maps/map11Background.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MAP11_BACKGROUND, map11Background));

	loaded(stuff);

	//Battle Background
	AnimatedSprite* battleBackground = new AnimatedSprite();
	battleBackground->addFrame(load_bitmap("Assets/Battle Background/battleBackground.bmp", NULL));
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(BATTLE_BACKGROUND, battleBackground));

	loaded(stuff);

	//Nidhoggr Attack
	AnimatedSprite* nidhoggrAttack = new AnimatedSprite();
	nidhoggrAttack->setSpeed(150);

	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack2.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack3.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack4.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack5.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack6.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack7.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack8.bmp", NULL));
	nidhoggrAttack->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrAttack9.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(NIDHOGGR_ATTACK, nidhoggrAttack));

	loaded(stuff);

	//Nidhoggr Dying
	AnimatedSprite* nidhoggrDying = new AnimatedSprite();
	nidhoggrDying->setSpeed(150);

	nidhoggrDying->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrDying.bmp", NULL));
	nidhoggrDying->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrDying2.bmp", NULL));
	nidhoggrDying->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrDying3.bmp", NULL));
	nidhoggrDying->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrDying4.bmp", NULL));
	nidhoggrDying->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrDying5.bmp", NULL));
	nidhoggrDying->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrDying6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(NIDHOGGR_DYING, nidhoggrDying));

	loaded(stuff);

	//Nidhoggr Idle
	AnimatedSprite* nidhoggrIdle = new AnimatedSprite();
	nidhoggrIdle->setSpeed(150);

	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle.bmp", NULL));
	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle2.bmp", NULL));
	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle3.bmp", NULL));
	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle4.bmp", NULL));
	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle5.bmp", NULL));
	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle6.bmp", NULL));
	nidhoggrIdle->addFrame(load_bitmap("Assets/Nidhoggr/nidhoggrIdle7.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(NIDHOGGR_IDLE, nidhoggrIdle));

	loaded(stuff);

	//Salamander Attack
	AnimatedSprite* salamanderAttack = new AnimatedSprite();
	salamanderAttack->setSpeed(150);

	salamanderAttack->addFrame(load_bitmap("Assets/Salamander/salamanderAttack.bmp", NULL));
	salamanderAttack->addFrame(load_bitmap("Assets/Salamander/salamanderAttack2.bmp", NULL));
	salamanderAttack->addFrame(load_bitmap("Assets/Salamander/salamanderAttack3.bmp", NULL));
	salamanderAttack->addFrame(load_bitmap("Assets/Salamander/salamanderAttack4.bmp", NULL));
	salamanderAttack->addFrame(load_bitmap("Assets/Salamander/salamanderAttack5.bmp", NULL));
	salamanderAttack->addFrame(load_bitmap("Assets/Salamander/salamanderAttack6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SALAMANDER_ATTACK, salamanderAttack));

	loaded(stuff);

	//Salamander Dying
	AnimatedSprite* salamanderDying = new AnimatedSprite();
	salamanderDying->setSpeed(150);

	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying.bmp", NULL));
	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying2.bmp", NULL));
	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying3.bmp", NULL));
	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying4.bmp", NULL));
	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying5.bmp", NULL));
	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying6.bmp", NULL));
	salamanderDying->addFrame(load_bitmap("Assets/Salamander/salamanderDying7.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SALAMANDER_DYING, salamanderDying));

	loaded(stuff);

	//Salamander Idle
	AnimatedSprite* salamanderIdle = new AnimatedSprite();
	salamanderIdle->setSpeed(150);

	salamanderIdle->addFrame(load_bitmap("Assets/Salamander/salamanderIdle.bmp", NULL));
	salamanderIdle->addFrame(load_bitmap("Assets/Salamander/salamanderIdle2.bmp", NULL));
	salamanderIdle->addFrame(load_bitmap("Assets/Salamander/salamanderIdle3.bmp", NULL));
	salamanderIdle->addFrame(load_bitmap("Assets/Salamander/salamanderIdle4.bmp", NULL));
	salamanderIdle->addFrame(load_bitmap("Assets/Salamander/salamanderIdle5.bmp", NULL));
	salamanderIdle->addFrame(load_bitmap("Assets/Salamander/salamanderIdle6.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SALAMANDER_IDLE, salamanderIdle));

	loaded(stuff);

	//Satan Morroc Attack
	AnimatedSprite* satanMorrocAttack = new AnimatedSprite();
	satanMorrocAttack->setSpeed(150);

	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack2.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack3.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack4.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack5.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack6.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack7.bmp", NULL));
	satanMorrocAttack->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocAttack8.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SATAN_MORROC_ATTACK, satanMorrocAttack));

	loaded(stuff);

	//Satan Morroc Dying
	AnimatedSprite* satanMorrocDying = new AnimatedSprite();
	satanMorrocDying->setSpeed(250);

	satanMorrocDying->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocDying.bmp", NULL));
	satanMorrocDying->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocDying2.bmp", NULL));
	satanMorrocDying->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocDying3.bmp", NULL));
	satanMorrocDying->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocDying4.bmp", NULL));
	satanMorrocDying->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocDying5.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SATAN_MORROC_DYING, satanMorrocDying));

	loaded(stuff);

	//Satan Morroc Idle
	AnimatedSprite* satanMorrocIdle = new AnimatedSprite();
	satanMorrocIdle->setSpeed(150);

	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle2.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle3.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle4.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle5.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle6.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle7.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle8.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle9.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle10.bmp", NULL));
	satanMorrocIdle->addFrame(load_bitmap("Assets/Satan Morroc/satanMorrocIdle11.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SATAN_MORROC_IDLE, satanMorrocIdle));
	
	loaded(stuff);

	//Seeker Attack
	AnimatedSprite* seekerAttack = new AnimatedSprite();
	seekerAttack->setSpeed(150);

	seekerAttack->addFrame(load_bitmap("Assets/Seeker/seekerAttack.bmp", NULL));
	seekerAttack->addFrame(load_bitmap("Assets/Seeker/seekerAttack2.bmp", NULL));
	seekerAttack->addFrame(load_bitmap("Assets/Seeker/seekerAttack3.bmp", NULL));
	seekerAttack->addFrame(load_bitmap("Assets/Seeker/seekerAttack4.bmp", NULL));
	seekerAttack->addFrame(load_bitmap("Assets/Seeker/seekerAttack5.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SEEKER_ATTACK, seekerAttack));
	
	loaded(stuff);

	//Seeker Dying
	AnimatedSprite* seekerDying = new AnimatedSprite();
	seekerDying->setSpeed(250);

	seekerDying->addFrame(load_bitmap("Assets/Seeker/seekerDying.bmp", NULL));
	seekerDying->addFrame(load_bitmap("Assets/Seeker/seekerDying2.bmp", NULL));
	seekerDying->addFrame(load_bitmap("Assets/Seeker/seekerDying3.bmp", NULL));
	
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SEEKER_DYING, seekerDying));

	loaded(stuff);

	//Seeker Idle
	AnimatedSprite* seekerIdle = new AnimatedSprite();
	seekerIdle->setSpeed(150);

	seekerIdle->addFrame(load_bitmap("Assets/Seeker/seekerIdle.bmp", NULL));
	seekerIdle->addFrame(load_bitmap("Assets/Seeker/seekerIdle2.bmp", NULL));
	seekerIdle->addFrame(load_bitmap("Assets/Seeker/seekerIdle3.bmp", NULL));
	seekerIdle->addFrame(load_bitmap("Assets/Seeker/seekerIdle4.bmp", NULL));
	
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SEEKER_IDLE, seekerIdle));

	loaded(stuff);

	
	//Fire Right
	AnimatedSprite* fire = new AnimatedSprite();
	fire->setSpeed(150);

	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight2.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight3.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight4.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight5.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight4.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight3.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight2.bmp", NULL));
	fire->addFrame(load_bitmap("Assets/Special Effects/fireRight.bmp", NULL));
	
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(FIRE, fire));

	loaded(stuff);

	//Portal Init
	AnimatedSprite* portalInit = new AnimatedSprite();
	portalInit->setSpeed(150);

	portalInit->addFrame(load_bitmap("Assets/Special Effects/portal.bmp", NULL));
	portalInit->addFrame(load_bitmap("Assets/Special Effects/portal2.bmp", NULL));
	portalInit->addFrame(load_bitmap("Assets/Special Effects/portal3.bmp", NULL));
	portalInit->addFrame(load_bitmap("Assets/Special Effects/portal4.bmp", NULL));
	
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(PORTAL_INIT, portalInit));

	loaded(stuff);

	//Portal Open
	AnimatedSprite* portalOpen = new AnimatedSprite();
	portalOpen->setSpeed(150);

	portalOpen->addFrame(load_bitmap("Assets/Special Effects/portalOpen.bmp", NULL));
	portalOpen->addFrame(load_bitmap("Assets/Special Effects/portalOpen2.bmp", NULL));
	portalOpen->addFrame(load_bitmap("Assets/Special Effects/portalOpen3.bmp", NULL));
	portalOpen->addFrame(load_bitmap("Assets/Special Effects/portalOpen4.bmp", NULL));
	portalOpen->addFrame(load_bitmap("Assets/Special Effects/portalOpen5.bmp", NULL));
	
	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(PORTAL_OPEN, portalOpen));

	loaded(stuff);

	//Sparkles
	AnimatedSprite* sparkles = new AnimatedSprite();
	sparkles->setSpeed(150);

	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles2.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles3.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles4.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles5.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles6.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles7.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles8.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles9.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles10.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles11.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles.bmp", NULL));
	sparkles->addFrame(load_bitmap("Assets/Special Effects/sparkles2.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(SPARKLES, sparkles));

	loaded(stuff);

	AnimatedSprite* menuBackground = new AnimatedSprite();

	menuBackground->addFrame(load_bitmap("Assets/menuBackground.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(MENU_BACKGROUND, menuBackground));

	AnimatedSprite* hand = new AnimatedSprite();

	hand->addFrame(load_bitmap("Assets/handIcon.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(HAND_ICON, hand));

	AnimatedSprite* titleBackground = new AnimatedSprite();

	titleBackground->addFrame(load_bitmap("Assets/titleBackgroundEnglish.bmp", NULL));
	titleBackground->addFrame(load_bitmap("Assets/titleBackgroundJapanese.bmp", NULL));
	titleBackground->addFrame(load_bitmap("Assets/titleBackgroundBackwards.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(TITLE_MENU_BACKGROUND, titleBackground));

	AnimatedSprite* gameOverScreen = new AnimatedSprite();

	gameOverScreen->addFrame(load_bitmap("Assets/gameOverEnglish.bmp", NULL));
	gameOverScreen->addFrame(load_bitmap("Assets/gameOverJapanese.bmp", NULL));
	gameOverScreen->addFrame(load_bitmap("Assets/gameOverBackwards.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(GAME_OVER_SCREEN, gameOverScreen));

	AnimatedSprite* credits = new AnimatedSprite();

	credits->addFrame(load_tga("Assets/creditsEnglish.tga", NULL));
	credits->addFrame(load_tga("Assets/creditsJapanese.tga", NULL));
	credits->addFrame(load_tga("Assets/creditsBackwards.tga", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CREDITS, credits));

	AnimatedSprite* creditsBackground = new AnimatedSprite();

	creditsBackground->addFrame(load_bitmap("Assets/creditsBackground.bmp", NULL));

	mAssetMap.insert(pair<ASSET_NUMBER, AnimatedSprite*>(CREDITS_BACKGROUND, creditsBackground));
}

//access a sprite
AnimatedSprite* AssetManager::getSprite(ASSET_NUMBER number)
{
	return mAssetMap.find(number)->second;
}