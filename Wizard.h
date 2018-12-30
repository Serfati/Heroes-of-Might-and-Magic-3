/*
 * Wizard.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef WIZARD_H_
#define WIZARD_H_

#include "Creature.h"

using namespace std;

class Wizard: public Creature {
public:
	Wizard();
	virtual ~Wizard();

    int attackAnother(Creature &c);
	void specialAbility(Creature &c);
	int getCost(){return 150;}
	string displayType(){return "Wizard";}
	CreatureType getType();
};
#endif /* WIZARD_H_ */