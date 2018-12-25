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
#include "Zombie.h"
#include "Archer.h"
#include "Vampire.h"
#include "Wizard.h"
#include "BlackDragon.h"

using namespace std;

class Army {
public:
	Army();
	Army(vector <int>);
	bool isDestroyed();
	bool addUnit(int , int );
	int getSize();
	int getArmySize();
	void eraseKilled();
	string showArmy();
	~Army();

private:
	vector <int> army;
};


#endif /* ARMY_H_ */
