/*
 * Army.h
 *
 *  Created on: Dec 25, 2018
 *      Author: serfati
 */
#pragma once
#ifndef ARMY_H_
#define ARMY_H_
#include "Creature.h"
#include "Vampire.h"
#include "Archer.h"
#include "BlackDragon.h"
#include "Zombie.h"
#include "Wizard.h"

using namespace std;

class Army {
public:
    Army();

    bool isDestroyed();

    bool addUnit(int,int);

    int getArmySize();

    string showArmy();

    string saveArmy();

    void buildArmy(int,int,int,int,int);

    void reBuild();

    ~Army();

    const vector<int> &getArmyList() const { return armyList; }

    void setAtArmyList(int i,int x) { Army::armyList[i] = x; }

    const vector<Creature *> &getRealArmy() const { return realArmy; }

    std::string IntToString ( int number );

private:
    vector<int> armyList;
    vector<Creature *> realArmy;
};

#endif /* ARMY_H_ */