/*
 * GameUnit.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#ifndef HEROS_GAMEUNIT_H_
#define HEROS_GAMEUNIT_H_


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

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
#include "Necomancer.h"

using namespace std;

class GameUnit {

	//^^^^^^^^^^ STATIC VARs ^^^^^^^^^^//
	static int numberOfPlayers;
	static int roundNumber;

public:
	//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
	GameUnit (); // Load Last Game
	GameUnit( const int , const int , const int );
	virtual ~GameUnit();

	//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
	GameUnit mainMenu(Hero *);
	bool attackMenu( Hero* );
	int storeMenu();
	void nextTurn();
    void kill(Hero*) ;

	//^^^^^^^^^^^^^^^^ MAINTENACE ^^^^^^^^^^^^^^^^^/
	void save();
	bool mkdir();
	void shuffle();
    void rmdir();
	void close();

	//^^^^^^^^^^^^^^ Getters and Setters ^^^^^^^^^^^^^^//
	Hero* getHeroByName( string );
	string getCurrentTurnName(){ return realOrder[currentTurn]->getName(); }
	string getTurnOrder() ;
	void showHeroes();

private:
	vector<Hero*> realOrder;
	vector<Hero*> turnOrder; //just a pointer to a shuffled realOrder
	int currentTurn; // index in turnOrder
};

#endif /* HEROS_GAMEUNIT_H_ */