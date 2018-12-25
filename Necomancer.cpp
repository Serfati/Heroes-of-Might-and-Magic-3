/*
 * Necomancer.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Necomancer.h"


Necomancer::Necomancer(Type type , string name , Army army ,bool live, int gold) : Hero(necomancer, name ,army ,live, gold)
{}
Necomancer::Necomancer(Necomancer &another) :Hero(another){}

bool Necomancer::specialAbility(){
	if (isAlive){
		 army.addUnit(0 , 1);
		 cout<< "Zombie added ‫‪successfully‬‬"<<endl;
		 return 1;
	}
	return 0;

 }

Necomancer::~Necomancer()
{}


