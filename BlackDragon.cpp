/*
 * BlackDragon.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "BlackDragon.h"

BlackDragon::BlackDragon() : Creature(9,10,200,blackDragon) {}

//NO SPECIAL
void BlackDragon::specialAbility(Creature &c) { return; }

double BlackDragon::attackAnother(Creature &c) {
    if ( c.getType() == wizard ) c.specialAbility(*this);
    double ratio = ((double) getAttackPoints() / c.getDefendPoints());
    return ratio;
}

CreatureType BlackDragon::getType() { return blackDragon; }

void BlackDragon::reset() {
    this->defendPoints = 10;
    this->attackPoints = 9;
}

BlackDragon::~BlackDragon() {}