/*
 * Wizard.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef WIZARD_H_
#define WIZARD_H_

#include "Creature.h"

using namespace std;

class Wizard : public Creature {
public:
    Wizard();

    virtual ~Wizard();

    double attackAnother(Creature &c);

    void specialAbility(Creature &c);

    CreatureType getType();

    void reset();

    int getAttackPoints() const { return attackPoints; }

    int getDefendPoints() const { return defendPoints; }
};

#endif /* WIZARD_H_ */

