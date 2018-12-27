/*
 * Hero.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#ifndef SOURCE_HERO_H_
#define SOURCE_HERO_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include<fstream>

#include "Creature.h"
#include "Army.h"

using namespace std;

enum Type
{
	warrior,    // 0
	thief,      // 1
	necomancer, // 2
	UnknownType // 3
};

class Hero{

public:
	//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
    Hero();
	Hero(Hero&);
	Hero(Type , string , Army ,bool live = true, int gold = 750);
	virtual ~Hero();

	//Load and Save
	bool load(string name);
	void save();
	bool mkdir();

	//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
	bool attackEnemy(Hero &enemy);
	bool buyCreature(int budget, int creatureType, int quantity);
	void showHero();
	string showArmy();

	void die();

	//Virtuals
	virtual bool getDailyGold();
	virtual bool specialAbility();

	//Getters and Setters
	void setARMY(Army newArmy);
	void setType(int);
	void setGold(int);
	bool setName(const string);

	int armySize();
	int getGold() const;
	Type getType();
	string displayType();
	string getName();
	bool inLife() const{return isAlive;};


protected:
	string  name;
	Type type;
	int gold;
	bool isAlive;
	Army  army;

};

#endif /* SOURCE_HERO_H_ */
