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

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include "AnimatedSprite.h"
using namespace std;

enum ASSET_NUMBER
{
	CAEL_IDLE  = 0,
	CAEL_LEFT, 
	CAEL_UP,
	CAEL_RIGHT,
	CAEL_DOWN,
	CAEL_ATTACK,
	CAEL_MAGIC,
	CAEL_DYING,
	AQUA_ATTACK,
	AQUA_DYING,
	AQUA_IDLE,
	BOITATA_ATTACK,
	BOITATA_DYING,
	BOITATA_IDLE,
	WOLF_ATTACK,
	WOLF_DYING,
	WOLF_IDLE,
	DEVILING_ATTACK,
	DEVILING_UP,
	DEVILING_UP_RIGHT, 
	DEVILING_DYING,
	DEVILING_IDLE,
	DEVILING_IDLE_RIGHT,
	DRACO_ATTACK,
	DRACO_UP,
	DRACO_UP_RIGHT,
	DRACO_DYING,
	DRACO_IDLE,
	DRACO_LEFT,
	DRACO_RIGHT,
	GOBLIN_ATTACK,
	GOBLIN_DYING,
	GOBLIN_IDLE,
	GOPINICH_ATTACK,
	GOPINICH_DYING,
	GOPINICH_IDLE,
	MAP1_FOREGROUND,
	MAP1_BACKGROUND,
	MAP2_FOREGROUND,
	MAP2_BACKGROUND,
	MAP3_FOREGROUND,
	MAP3_BACKGROUND,
	MAP4_FOREGROUND,
	MAP4_BACKGROUND,
	MAP5_FOREGROUND,
	MAP5_BACKGROUND,
	MAP6_FOREGROUND,
	MAP6_BACKGROUND,
	MAP7_FOREGROUND,
	MAP7_BACKGROUND,
	MAP8_FOREGROUND,
	MAP8_BACKGROUND,
	MAP9_FOREGROUND,
	MAP9_BACKGROUND,
	MAP10_FOREGROUND,
	MAP10_BACKGROUND,
	MAP11_FOREGROUND,
	MAP11_BACKGROUND,
	BATTLE_BACKGROUND,
	NIDHOGGR_ATTACK,
	NIDHOGGR_DYING,
	NIDHOGGR_IDLE,
	SALAMANDER_ATTACK,
	SALAMANDER_DYING,
	SALAMANDER_IDLE,
	SATAN_MORROC_ATTACK,
	SATAN_MORROC_DYING,
	SATAN_MORROC_IDLE,
	SEEKER_ATTACK,
	SEEKER_DYING,
	SEEKER_IDLE,
	FIRE,
	PORTAL_INIT,
	PORTAL_OPEN,
	SPARKLES,
	MENU_BACKGROUND,
	TITLE_MENU_BACKGROUND,
	HAND_ICON,
	GAME_OVER_SCREEN,
	CREDITS_BACKGROUND,
	CREDITS
};

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void init();

	AnimatedSprite* getSprite(ASSET_NUMBER number);
	
private:
	multimap<ASSET_NUMBER, AnimatedSprite*> mAssetMap;

	int done;

	void loaded(int total);
};

#endif