/*
 * Vampire.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Creature.h"

using namespace std;

class Vampire : public Creature {

public:
    Vampire();

    virtual ~Vampire();

    double attackAnother(Creature &c);

    void specialAbility(Creature &c);

    CreatureType getType();

    void reset();

    int getAttackPoints() const override { return attackPoints; }

    int getDefendPoints() const override { return defendPoints; }
};

#endif /* VAMPIRE_H_ */