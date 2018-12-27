/*
 * Creature.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Creature.h"

Creature::Creature():attackPoints(1), defendPoints(1), cost(50), cType(Unknown)
{

}
Creature::Creature( Creature& another )
{
	if(another.attackPoints >1 && another.defendPoints >1 &&another.cost >50 && another.cType != Unknown &&
			another.attackPoints <10 && another.defendPoints >10 &&another.cost >200){
	this->attackPoints=another.attackPoints;
	this->defendPoints=another.defendPoints;
	this->cost=another.cost;
	this->cType=another.cType;
	}
}
Creature::Creature(int _ap  , int _dp, int _c ,CreatureType ct ):
attackPoints(_ap), defendPoints(_dp), cost(_c), cType(ct)
{

}
void Creature::showCreature()
{
	cout<< "Attack level:"<< attackPoints <<",Defense level:"<<defendPoints<<endl;
}
void Creature::specialAbility(Creature &c)
{
	cout << "Just inherit me already" << endl;
}
void Creature::attackAnother(Creature &c)
{
	 cout << "Just inherit me already" << endl;
}
void Creature::setType(int type)
{
	switch (type)
	{
	case 0:
		this->cType = zombie;
		break;
	case 1:
		this->cType = archer;
		break;
	case 2:
		this->cType = vampire;
		break;
	case 3:
		this->cType = wizard;
		break;
	case 4:
		this->cType = blackDragon;
		break;
	default:
		this->cType = Unknown;
	}
}
string Creature::creaType(int vtype)
{
	switch (vtype)
	{
	case 0:
		return "Zombie";
	case 1:
		return "Archer";
	case 2:
		return "Vampire";
	case 3:
		return "Wizard";
	case 4:
		return "Black_Dragon";
	default:
		return "Unknown";
	}
}
int Creature::getPrice(int vtype)
{
	switch (vtype)
	{
	case 0:
		return 50;
	case 1:
		return 80;
	case 2:
		return 90;
	case 3:
		return 150;
	case 4:
		return 200;
	default:
		return -1;
	}
}
Creature::~Creature()
{

}
