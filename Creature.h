/*
 * Creature.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#ifndef CREATURE_H_
#define CREATURE_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum CreatureType
{
	zombie,
	archer,
	vampire,
	wizard,
	blackDragon,
	Unknown
};

class Creature {

public:
	//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
	Creature();
	Creature(Creature& another);
	Creature(int , int , int ,CreatureType );
	virtual ~Creature();

	//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
	virtual void attackAnother(Creature &c); //todo
	virtual void specialAbility(Creature &c);
	void showCreature();

	//^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
	virtual CreatureType getType(){return cType;}
	virtual int getCost(){return -1;}
	virtual string displayType(){return "Unknown";}
	void setType(int type);
	string creaType(int type);
	int getPrice(int type);


protected:
	int attackPoints;
	int defendPoints;
	int cost;
	CreatureType cType;

};



#endif /* CREATURE_H_ */
