/*
 * BlackDragon.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_

#include "Creature.h"

using namespace std;

class BlackDragon : public Creature {

public:
    BlackDragon();

    virtual ~BlackDragon();

    double attackAnother(Creature &c);

    void specialAbility(Creature &c);

    void reset();

    CreatureType getType();

    int getAttackPoints() const  { return attackPoints; }

    int getDefendPoints() const  { return defendPoints; }
};

#endif /* BLACKDRAGON_H_ */