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
bool Thief::specialAbility()
{
	if(isAlive){
	string toRob;
	std::cout<<"Please insert hero name:"<<endl;
	getline(cin, toRob);
		std::cout<<"TODO"<<endl;
		 return 1;
	 }
	std::cout<<"You died!"<<endl;
	 return 0;
 }

Thief::~Thief() {}


