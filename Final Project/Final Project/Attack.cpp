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

#include "Attack.h"
#include "Game.h"
#include "Enemy.h"
#include <math.h>
using namespace std;

Attack::Attack()
{
}

Attack::~Attack()
{
}

void Attack::attackEnemy(Unit* attacker, Unit* target)
{
	int attack = gpGame->getLevelManager()->getCurrentLevel().getStrength();
	int defense = gpGame->getEnemyLevelManager()->getEnemyLevel(((Enemy*)target)->getEnemyName(), gpGame->getMapManager()->getCurrentMap()->getNumber()).getDefense();
	double power = gpGame->getLevelManager()->getCurrentLevel().getPower();

	int hit = ceil((double)(attack - defense) * power);

	if(hit <= 0)
	{
		hit = 1;
	}

	target->setCurrentHP(target->getCurrentHP() - hit);
}

void Attack::attackCael(Unit* attacker, Unit* target)
{
}