/*
 * Vampire.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Vampire.h"

Vampire::Vampire() : Creature(4,4,80,vampire){}

//NO SPECIAL SKILL
void Vampire::specialAbility(Creature &c){return;}

double Vampire::attackAnother(Creature &c) {
    double ratio = ((double) getAttackPoints() / c.getDefendPoints());
    return ratio;
}
CreatureType Vampire::getType(){return vampire;}
Vampire::~Vampire(){}

void Vampire::reset() {
    this->defendPoints = 4;
    this->attackPoints = 4;
}
