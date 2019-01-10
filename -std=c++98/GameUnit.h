/*
 * GameUnit.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef HEROS_GAMEUNIT_H_
#define HEROS_GAMEUNIT_H_

#include <algorithm>

#include "Army.h"

#include "Creature.h"
#include "Vampire.h"
#include "Archer.h"
#include "BlackDragon.h"
#include "Zombie.h"
#include "Wizard.h"

#include "Hero.h"
#include "Thief.h"
#include "Warrior.h"
#include "Necromancer.h"

using namespace std;

class GameUnit {

public:
    //^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
    GameUnit(); // Load Last Game

    GameUnit(const int,const int,const int);

    ~GameUnit();


    //^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
private:
    bool mainMenu(Hero *);

    bool attackMenu(Hero *);

    int storeMenu(Hero *me);

    void nextTurn();

    void eraseKilled();

    //^^^^^^^^^^^^^^^^ MAINTENACE ^^^^^^^^^^^^^^^^^/
    void save();

    void load(vector<std::string>);

    bool mkdir();

    void shuffle();

    void rmdir();

    //^^^^^^^^^^^^^^ Getters and Setters ^^^^^^^^^^^^^^//
    Hero *getHeroByName(string);

    string getTurnOrder();

    void showHeroes();

    vector<Hero *> realOrder;
    vector<Hero *> turnOrder; //just a pointer to a shuffled realOrder
    int currentTurn; // index in turnOrder
};

#endif /* HEROS_GAMEUNIT_H_ */