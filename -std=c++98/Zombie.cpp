/*
 * Zombie.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Zombie.h"


Zombie::Zombie() : Creature(2,5,50,zombie) {}

//ONLY ON ATTACK ARCHER
void Zombie::specialAbility(Creature &c) {
    if ( 1 == c.getType())
        this->attackPoints += attackPoints;
}

double Zombie::attackAnother(Creature &c) {
    this->specialAbility(c);
    double x = (double) getAttackPoints();
    double y = (double) c.getDefendPoints();
    return x / y;
}

void Zombie::reset() {
    this->defendPoints = 5;
    this->attackPoints = 2;
}

CreatureType Zombie::getType() { return zombie; }

Zombie::~Zombie() {}




