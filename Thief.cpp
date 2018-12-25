/*
 * Thief.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Thief.h"

using namespace std;
Thief::Thief(Type type , string name , Army army ,bool live, int gold) : Hero(thief, name ,army ,live, gold){}

Thief::Thief(Thief &another) :Hero(another){}

//TODO need to thief from another user/
bool Thief::specialAbility()
{
	string toRob;
	//cout<<"Please insert hero name:"<<endl;‬‬
	 if(isAlive){
		 gold+= 50 ;
		 return 1;
	 }
	 return 0;
 }

Thief::~Thief() {}


