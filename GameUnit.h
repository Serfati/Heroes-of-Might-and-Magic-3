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

#include "Army.h"

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

	//^^^^^^^^^^ STATIC VARs ^^^^^^^^^^//
	static int numberOfPlayers;
	static int roundNumber;
public:
	//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
	GameUnit(string);
	GameUnit(const int,const int,const int );
	~GameUnit();

	//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
	GameUnit openHeroMenu(Hero*);
	bool attackMenu();
	int storeMenu();
	int ChooseHeroes();
	virtual bool die(int);
	bool isCreature(string name);

	// save and load
	GameUnit loadGame();
	void save();
	bool mkdir();

private:
	vector<Hero*> players;
	std::string heroesNames;

};

#endif /* HEROS_GAMEUNIT_H_ */
