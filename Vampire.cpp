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
void Vampire::attackAnother(Creature &c) {
    cout << "Vampire go for attack" << endl;
}
CreatureType Vampire::getType(){return vampire;}
Vampire::~Vampire(){}

