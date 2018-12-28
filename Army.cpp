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
	vector<int> vect( 6 ); // emty army
	army = vect ;
	vect.clear();
}
Army::Army(vector <int> army)
{
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
	unsigned long size = army.size();

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
string Army::showArmy()
{
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
std::string Army::saveArmy() {
	std::string saveArmy = "";
	for (int i = 4; i >= 0; i--) {
		saveArmy += std::to_string(army[i]);
		if (i != 0)
			saveArmy += " ";
		else
			saveArmy += "";
	}
	return saveArmy;
}
void Army::buildArmy(int BD ,int WZ,int ARC,int VMP,int ZMB){
	army[4]=BD; army[3]=WZ; army[2]=ARC; army[1]=VMP; army[0]=ZMB;
}



