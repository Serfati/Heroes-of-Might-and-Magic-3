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

enum CreatureType {
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

    Creature(Creature &another);

    Creature(int,int,int,CreatureType);

    virtual ~Creature();

    //^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
    virtual double attackAnother(Creature &c);

    virtual void specialAbility(Creature &c);

    void showCreature();

    virtual void reset();

    //^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
    virtual CreatureType getType() { return cType; }

    string creaType(int type);

    int creaTypeByName(string vtype);

    int getPrice();

    virtual int getAttackPoints() const { return attackPoints; }

    virtual int getDefendPoints() const { return defendPoints; }

protected:
    int attackPoints;
    int defendPoints;
    int cost;
    CreatureType cType;

};

#endif /* CREATURE_H_ */