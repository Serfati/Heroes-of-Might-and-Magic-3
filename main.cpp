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
	bool isRun = true;

	//   ******** MENU *********  //
	while ( isRun ) {
		cout<<"What is your next step in the path to victory?"<<endl;
		cout<<"‫‪1. Attack‬‬"<<endl;
		cout<<"2. Get daily gold"<<endl;
		cout<<"‫‪3.‬‬ Buy creatures‬‬"<<endl;
		cout<<"4. Show details"<<endl;
		cout<<"‫‪5‬‬.‬‬ Special skill‬‬‬‬"<<endl;
		cout<<"6. End of my turn"<<endl;
		cout<<"7.‬ Exit‬‬‬‬"<<endl;
		cin >> choice;
		switch( choice  )
		{

		case 1:	/*	Attack‬‬	*/

		case 2:	/*	Get daily gold	*/

		case 3: /*	Buy creatures	*/

		case 4:	/*	Show details	*/

		case 5:	/*	Special skill‬‬‬‬	*/

		case 6:	/*	End of my turn	*/

		case 7: /* 	‫‪Exit‬‬‬‬  */
			exit(1);

		default:
			cout<<"please choose a valid number"<<endl;
		}
	}
}