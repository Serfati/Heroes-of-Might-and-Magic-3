/*
 * Hero.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#ifndef SOURCE_HERO_H_
#define SOURCE_HERO_H_

#include <iostream>
#include<fstream>
#include <sstream>
#include <math.h>

#include "Creature.h"
#include "Army.h"

using namespace std;

enum Type {
    warrior ,       // 0
    thief ,        // 1
    necromancer , // 2
    UnknownType  // 3
};

class Hero {

public:
    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
    Hero ();

    Hero (Hero &);

    Hero (Type , string , Army *a = NULL , bool live = true , int gold = 750);

    virtual ~Hero () { army->~Army (); }

    //Load and Save
    bool load (string name);

    void save ();

    string saveArmy ();

    bool mkdir ();

    void rmdir ();

    //^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
    bool attackEnemy (Hero &enemy);

    bool buyCreature(int budget,int creatureType,int quantity,int unitPrice);

    void showHero ();

    void showHeroFight ();

    string showArmy ();

    bool addGold (int);


    //Virtuals
    void getDailyGold () { addGold (100); }

    virtual bool specialAbility (Hero &);


    //Getters and Setters
    void setType (int);

    void setGold (int);

    bool setName (const string);

    int getGold () const;

    Type getType ();

    string displayType ();

    string getName ();

    bool inLife () const { return isAlive; };

protected:
    string name;
    Type type;
    int gold;
    bool isAlive;
    Army *army;

};

#endif /* SOURCE_HERO_H_ */