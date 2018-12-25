/*
 * BlackDragon.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "BlackDragon.h"

BlackDragon::BlackDragon():Creature(9,10,200,blackDragon){}

//NO SPECIAL
void BlackDragon::specialAbility(Creature &c){return;}
void BlackDragon::attackAnother(Creature &c) {
    cout << "BlackDragon go for attack" << endl;
}
CreatureType BlackDragon::getType(){return blackDragon;}

BlackDragon::~BlackDragon(){}

