/*
 * Vampire.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Creature.h"

using namespace std;

class Vampire: public Creature {

public:
	Vampire();

	virtual ~Vampire();

    double attackAnother(Creature &c);
	void specialAbility(Creature &c);
	int getCost(){return 90;}
	string displayType(){return "Vampire";}
	CreatureType getType();

    void reset();

    int getAttackPoints() const override { return attackPoints; }

    int getDefendPoints() const override { return defendPoints; }
};
#endif /* VAMPIRE_H_ */