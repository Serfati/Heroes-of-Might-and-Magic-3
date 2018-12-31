/*
 * Zombie.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "Creature.h"

using namespace std;

class Zombie: public Creature {

public:
	Zombie();

	virtual ~Zombie();

	double attackAnother(Creature &c);
	void specialAbility(Creature &c);
	int getCost(){return 50;}
	string displayType(){return "Zombie";}
	CreatureType getType();
};
#endif /* ZOMBIE_H_ */