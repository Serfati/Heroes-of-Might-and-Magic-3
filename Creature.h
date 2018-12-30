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
	virtual int attackAnother(Creature &);
	virtual void specialAbility(Creature &c);
	void showCreature();

	//^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
	virtual CreatureType getType(){return cType;}
	virtual int getCost(){return -1;}
	virtual string displayType(){return "Unknown";}
	string creaType(int type);
	int creaTypeByName(string vtype);
	int getPrice(int type);

	int getAttackPoints() const { return attackPoints; }

	void setAttackPoints(int attackPoints) { Creature::attackPoints = attackPoints; }

	int getDefendPoints() const { return defendPoints; }

	void setDefendPoints(int defendPoints) { Creature::defendPoints = defendPoints; }

protected:
	int attackPoints;
	int defendPoints;
	int cost;
	CreatureType cType;

};
#endif /* CREATURE_H_ */