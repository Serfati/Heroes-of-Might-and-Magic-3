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

Army::Army()
{
	realArmy = {new Zombie(), new Vampire(), new Archer(), new Wizard(), new BlackDragon()};
	vector<int> vect( 6 ); // emty armyList
	armyList = vect ;
	vect.clear();
}
bool Army::isDestroyed()
{
	return getArmySize()<1;
}
bool Army::addUnit(int creatureType, int quantity)
{
	armyList[creatureType] += quantity; return 1;
}
int Army::getArmySize()
{
	int size = 0;
	for(int i : armyList)
		size += i ;
	return size;
}
string Army::showArmy()
{
	string showArmy = "" ;
	Creature c ;
	for (int i = 5; i >= 0 ; i--)
	{
		if( armyList[i] != 0) {
			showArmy += std::to_string(armyList[i]);
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
Army::~Army()
{
	realArmy.clear();
	armyList.clear();
}
std::string Army::saveArmy()
{
	std::string saveArmy = "";
	for (int i = 4; i >= 0; i--) {
		saveArmy += std::to_string(armyList[i]);
		if (i != 0)
			saveArmy += " ";
		else
			saveArmy += "";
	}
	return saveArmy;
}
void Army::buildArmy(int BD ,int WZ,int ARC,int VMP,int ZMB)
{
	armyList[4]=BD; armyList[3]=WZ; armyList[2]=ARC; armyList[1]=VMP; armyList[0]=ZMB;
}