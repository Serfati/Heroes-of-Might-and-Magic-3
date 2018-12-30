/*
 * Army.h
 *
 *  Created on: Dec 25, 2018
 *      Author: serfati
 */
#ifndef ARMY_H_
#define ARMY_H_
#include<string>
#include<vector>
#include "Creature.h"
#include "Vampire.h"
#include "Archer.h"
#include "BlackDragon.h"
#include "Zombie.h"
#include "Wizard.h"

using namespace std;

class Army {
public:
	Army();
	Army(vector <int>);
	bool isDestroyed();
	bool addUnit(int , int );
	int getArmySize();
	void eraseKilled();
	string showArmy();
	string saveArmy();
	void buildArmy(int,int,int,int,int);
	~Army();

public:
	vector <int> armyList;
	vector <Creature*> realArmy;
};


#endif /* ARMY_H_ */
