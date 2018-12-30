/*
 * Thief.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Thief.h"

using namespace std;

Thief::Thief( string name ) : Hero(thief, name ,army ){}

Thief::Thief(Thief &another) :Hero(another){}

//TODO need to thief from another user/
bool Thief::specialAbility(Hero &toRob)
{
	if(isAlive){
		if(toRob.getGold() > 70) {
			this->addGold(350);
			toRob.setGold(toRob.getGold() - 70);
			return 1;
		}
		else {
			addGold(toRob.getGold());
			toRob.setGold(0);
			return 1;
		}
	 }
	std::cout<<"You died!"<<endl;
	 return 0;
 }
Thief::~Thief() {}


