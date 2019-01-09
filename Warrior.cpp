/*
 * Warrior.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Warrior.h"

Warrior::Warrior() { setType(warrior); }

Warrior::Warrior(string name) : Hero(warrior,name,1,750,false,false) {}

bool Warrior::specialAbility(Hero &s) {
    if ( isAlive ) {
        addGold(50);
        cout << "Gold added successfully" << endl;
        return true;
    }
    return false;
}

Warrior::~Warrior() {}