/*
 * BlackDragon.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_

#include "Creature.h"

using namespace std;

class BlackDragon: public Creature {

public:
	BlackDragon();

	virtual ~BlackDragon();

    double attackAnother(Creature &c);
	void specialAbility(Creature &c);
	int getCost(){return 200;}
	string displayType(){return "Black_Dragon";}

    void reset();
	CreatureType getType();

    int getAttackPoints() const override { return attackPoints; }

    int getDefendPoints() const override { return defendPoints; }
};
#endif /* BLACKDRAGON_H_ */