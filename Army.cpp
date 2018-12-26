/*
 * Army.cpp
 *
 *  Created on: Dec 25, 2018
 *      Author: serfati
 */

#include "Army.h"
#include "string.h"
#include <iostream>
#include <string>
using namespace std;

Army::Army() {
	vector<int> vect( 7 ); // emty army
	army =vect ;
	vect.clear();
}

Army::Army(vector <int> army){
	this->army = army;
}

bool Army::isDestroyed()
{
	return getArmySize()>0;
}

bool Army::addUnit(int creatureType, int quantity)
{
	army[creatureType] += quantity; return 1;
}

void Army::eraseKilled()
{
	int size = army.size();
	for (int i = 0; i < size; i++)
	{
		if (army[i] <= 0)
			army.erase(army.begin() + i);
	}
}

int Army::getArmySize(){
	int size = 0;
	for (int i = 0; i < army.size(); i++)
		size += army[i];
	return size;

}

string Army::showArmy(){
	string showArmy = "" ;
	Creature c ;
	for (int i = 5; i >= 0 ; i--)
	{
	if( army[i] != 0) {
		showArmy += std::to_string(army[i]);
		showArmy += " " + c.creaType(i) ;
		if(i!=0 )
			showArmy += " ";
		else
			showArmy += ".";
	}
	}
	c.~Creature();

	return showArmy;
}

Army::~Army() {army.clear();}


