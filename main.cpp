/*
 ============================================================================
 Name        : Heroes of Might and Magic® 3
 Author      : Avihai Serfati (204520803)
 Version     : 0.8
 Copyright   : Read Only
 Dialect     : C++
 Description : implements Heroes of Might and Magic 3 a turn-based
  	  	  	   strategy game developed by Jon Van Caneghem in 1999-2000
 ============================================================================
 */

//#include "GameUnit.h"
#include <iostream>
#include <string>
#include <vector>
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

/* this is the main routine where all the glue logic fits     */

/***************************************/
/* 	  Heroes of Might and Magic® 3	  */
/***************************************/

int main(int argc , char* argv[]){

    int choice;

    //arguments
    string playOrLoad = argv[1];
    int warriors = atoi(argv[2]);
    int thieves = atoi(argv[3]);
    int Necromancers = atoi(argv[4]);




    //GameUnit gamePlay = GameUnit(warriors, thieves, Necromancers);
//    bool isRun = true;
//    Hero *a = new Warrior( "Avi" );
//    Hero *g = new Thief( "Guy" );
//    Hero *s = new Necomancer("Samu");
//    Hero *l= new Hero();
//
//    a->specialAbility();
//    g->specialAbility();
//    s->specialAbility();
//    l->specialAbility();
//
//    a->buyCreature(s->getGold(), 2 , 2 );
//    cout<< a->armySize() ;
//    cout<< a->showArmy() << endl;
//
//    g->buyCreature(s->getGold(), 2 , 2 );
//    cout<< g->armySize() ;
//    cout<< g->showArmy() << endl;
//
//    s->buyCreature(s->getGold(), 2 , 2 );
//    cout<< s->armySize() ;
//    cout<< s->showArmy() << endl;
//
//    a->showHero();
//    g->showHero();
//    s->showHero();




    cout<<"***END OF MAIN***‬‬"<<endl;



