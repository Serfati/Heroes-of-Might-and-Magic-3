/*
 * Archer.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef ARCHER_H_
#define ARCHER_H_

#include "Creature.h"

using namespace std;

class Archer : public Creature {

public:
    Archer();

    virtual ~Archer();

    double attackAnother(Creature &c);

    void specialAbility(Creature &c);

    void reset();

    CreatureType getType();

    int getAttackPoints() const override { return attackPoints; }

    int getDefendPoints() const override { return defendPoints; }

};

#endif /* ARCHER_H_ */