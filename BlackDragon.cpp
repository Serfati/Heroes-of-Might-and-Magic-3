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

double BlackDragon::attackAnother(Creature &c){
    cout << "BlackDragon go for attack" << endl;
    double ratio;
    if (c.getType() == 3) c.specialAbility(*this);
    ratio = getAttackPoints() / c.getDefendPoints();
    return ratio;

}

CreatureType BlackDragon::getType(){return blackDragon;}

BlackDragon::~BlackDragon(){}