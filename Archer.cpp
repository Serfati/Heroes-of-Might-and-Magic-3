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
void Archer::attackAnother(Creature &c) {
	cout << "Archer go for attack" << endl;
}
CreatureType Archer::getType(){return archer;}
Archer::~Archer(){}