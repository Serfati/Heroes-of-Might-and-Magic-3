/*
 * Archer.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Creature.h"

using namespace std;

class Archer: public Creature{

public:
	Archer();
	virtual ~Archer();
	void attackAnother(Creature &c);
	void specialAbility(Creature &c);
	int getCost(){return 80;}
	string displayType(){return "Archer";}
	CreatureType getType();
};

#endif /* ARCHER_H_ */