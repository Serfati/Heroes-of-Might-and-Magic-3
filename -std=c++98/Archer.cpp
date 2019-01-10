/*
 * Archer.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#include "Archer.h"

Archer::Archer() : Creature(5,4,90,archer) {}

Archer::~Archer() {}

//ONLY ON DEFENCE vs BlackDragon
void Archer::specialAbility(Creature &c) {
    if ( c.getType() == blackDragon )
        this->attackPoints += attackPoints * 0.2;
}

double Archer::attackAnother(Creature &c) {
    this->specialAbility(c);
    double ratio = ((double) getAttackPoints() / c.getDefendPoints());
    return ratio;
}

void Archer::reset() {
    this->defendPoints = 4;
    this->attackPoints = 5;
}

CreatureType Archer::getType() {
    return archer;
}
