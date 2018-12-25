/*
 * Warrior.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Warrior.h"


Warrior::Warrior(Type type , string name , Army army ,bool live, int gold) : Hero(warrior, name ,army ,live, gold){}
Warrior::Warrior(Warrior &another) :Hero(another)
{}

bool Warrior::specialAbility(){
	if(isAlive){
		if(gold+50 <= 2500)
			this->gold += 50;
		else
			gold = 2500;
		cout<<"Gold added successuly"<<endl;
		return true;
	}
	return false;
}



Warrior::~Warrior() {}


