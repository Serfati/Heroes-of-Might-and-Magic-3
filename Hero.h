/*
 * Hero.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef SOURCE_HERO_H_
#define SOURCE_HERO_H_

#include<fstream>
#include <sstream>
#include <math.h>

#include "Creature.h"
#include "Army.h"

using namespace std;

enum Type {
    warrior,       // 0
    thief,        // 1
    necromancer, // 2
    UnknownType  // 3
};

class Hero {

public:
    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
    Hero();

    Hero(Hero &);

    Hero(Type , string , bool live = 1, int gold = 750);

    ~Hero() { delete army; name.clear();}

    //^^^^^^^^^^^^^^^^ LOAD and SAVE ^^^^^^^^^^^^^^^^^//
    bool load(string name);

    void save();

    string saveArmy();

    bool mkdir();

    void rmdir();

    int typeFromFile(string heroName);

    //^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
    bool attackEnemy(Hero &enemy);

    bool buyCreature(double budget,int creatureType,int quantity,int unitPrice);

    void showHero();

    void showHeroFight();

    string showArmy();

    bool addGold(double);


    //Virtuals
    void getDailyGold() { addGold(100); }

    virtual bool specialAbility(Hero &);


    //^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
    void setType(int);

    void setGold(double);

    bool setName(const string);

    double getGold() const;

    Type getType();

    string displayType();

    string getName();

    bool inLife() const { return isAlive; };

protected:
    string name;
    Type type;
    double gold;
    bool isAlive;
    Army *army;
};

#endif /* SOURCE_HERO_H_ */