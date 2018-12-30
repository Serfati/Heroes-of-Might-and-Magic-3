/*
 * Archer.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#include "Archer.h"

Archer::Archer() : Creature(5,4,90,archer){}

//ONLY ON DEFENCE vs BlackDragon
void Archer::specialAbility(Creature &c){
	if(4 == c.getType())
		this->attackPoints += attackPoints*0.2;}

int Archer::attackAnother(Creature &c) {
	cout << "Archer go for attack" << endl;
    int ratio;
    this->specialAbility(c);
    ratio = getAttackPoints() / c.getDefendPoints();
    return ratio;
}
CreatureType Archer::getType(){return archer;}
Archer::~Archer(){}