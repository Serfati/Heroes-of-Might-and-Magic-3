/*
 * Wizard.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Wizard.h"

Wizard::Wizard() : Creature(8,2,150,wizard){}

//ONLY ON Attack vs BlackDragon
void Wizard::specialAbility(Creature &c){
	if(4 == c.getType())
		this->defendPoints+=defendPoints;}
void  Wizard::attackAnother(Creature &c) {
	cout << "Wizard go for attack" << endl;
}
CreatureType Wizard::getType(){return wizard;}

Wizard::~Wizard(){}
