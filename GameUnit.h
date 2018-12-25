/*
 * GameUnit.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#ifndef HEROS_GAMEUNIT_H_
#define HEROS_GAMEUNIT_H_

#include <iostream>
#include <string>
#include <vector>

#include "Creature.h"
#include "Vampire.h"
#include "Archer.h"
#include "BlackDragon.h"
#include "Zombie.h"
#include "Wizard.h"

#include "Hero.h"
#include "Thief.h"
#include "Warrior.h"
#include "Necomancer.h"

using namespace std;

class GameUnit {
public:
	GameUnit();
	void load();
	virtual bool die(int);
	bool isCreature(string name);
	virtual ~GameUnit();
};

#endif /* HEROS_GAMEUNIT_H_ */
