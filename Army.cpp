/*
 * Army.cpp
 *
 *  Created on: Dec 25, 2018
 *      Author: serfati
 */

#include "Army.h"

using namespace std;



Army::Army() {
	vector<int> vect( 6 , 0 ); // emty army
	army = vect;
}

Army::Army(vector <int> army){
	this->army = army;
}

bool Army::isDestroyed()
{
	int size = army.size();
	for (int i = 0; i < size; i++)
		if (army[i] > 0) return 0;
	return 1;
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

int Army::getSize(){return army.size();}

string Army::showArmy(){
	string showArmy = "";
	Creature c ;
	int size = army.size();
	for (int i = size; i > 0 ; i++)
	{

		if(army[i]>0){
			showArmy += c.creaType(i);
			showArmy+=" "+army[i];
		}
	}
	c.~Creature();
	return showArmy;
}

Army::~Army() {army.clear();}


