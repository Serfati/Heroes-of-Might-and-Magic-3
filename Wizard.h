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

    double attackAnother(Creature &c);
	void specialAbility(Creature &c);
	int getCost(){return 150;}
	string displayType(){return "Wizard";}
	CreatureType getType();

    void reset();

    int getAttackPoints() const override;

    int getDefendPoints() const override;
};
#endif /* WIZARD_H_ */

