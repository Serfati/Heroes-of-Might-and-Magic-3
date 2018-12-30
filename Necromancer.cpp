/*
 * Necromancer.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Necromancer.h"


Necromancer::Necromancer(string name) : Hero(necomancer, name ,army ){}

Necromancer::Necromancer(Necromancer &another) :Hero(another){}

bool Necromancer::specialAbility(Hero &s){
	if (isAlive){
		 army.addUnit(0 , 1);
		 cout<< "Zombie added ‫‪successfully‬‬"<<endl;
		 return 1;
	}
	return 0;

 }

Necromancer::~Necromancer()
{}


