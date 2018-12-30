/*
 * Zombie.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Zombie.h"


Zombie::Zombie() : Creature(2,5,50,zombie){}

//ONLY ON ATTACK ARCHER
void Zombie::specialAbility(Creature &c){
	if(1 == c.getType())
		this->attackPoints+=attackPoints;}

void Zombie::attackAnother(Creature &c){
	cout<<"zombie go for attack"<<endl;
}
CreatureType Zombie::getType(){return zombie;}

Zombie::~Zombie() {}