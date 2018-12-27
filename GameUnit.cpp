//
// Created by serfati on 12/27/18.
//
#include "GameUnit.h"

using namespace std;

static int numberOfPlayers = 0;
static int roundNumber = 0;

GameUnit::GameUnit (const int w,const int t,const int n){
 std::cout<<"/***************************************/"
            "/* 	  Heroes of Might and Magic® 3	*/"
            "/***************************************/"<<endl;

 mkdir();
 string _name;
 for (int i = 0; i < w; ++i) {
  std::cout<<"Please insert warrior name number :"<< i+1 <<endl;
  getline(cin, _name);
  players.push_back(new Warrior(_name));
  heroesNames+= _name+" ";
 }
 for (int i = 0; i < t; ++i) {
  std::cout<<"Please insert thief name number :"<< i+1 <<endl;
  getline(cin, _name);
  players.push_back(new Thief(_name));
  heroesNames+= _name+" ";
 }
 for (int i = 0; i < n; ++i) {
  std::cout<<"Please insert necomancer name number :"<< i+1 <<endl;
  getline(cin, _name);
  players.push_back(new Necomancer(_name));
  heroesNames+= _name+" ";
 }
 ::numberOfPlayers = w+t+n;
 ::roundNumber ++;
 std::cout<<"^*^*^*^*Enjoy your game*^*^*^*^*^"<<endl;
 save();
 openHeroMenu(players[0]); //TODO random

}
GameUnit GameUnit::loadGame(){
 return *this;
}

//   ******** Hero Main Menu *********  //
GameUnit GameUnit::openHeroMenu(Hero* turn){
 int choice, choosenType;
 if(turn->inLife()){
  bool isTurnRun = true;
  while ( isTurnRun  ) {
   cout << "What is your next step in the path to victory?" << endl;
   cout << "‫‪1. Attack‬‬" << endl;
   cout << "2. Get daily gold" << endl; //
   cout << "‫‪3.‬‬ Buy creatures‬‬" << endl; //
   cout << "4. Show details" << endl; //
   cout << "‫‪5‬‬.‬‬ Special skill‬‬‬‬" << endl; //
   cout << "6. End of my turn" << endl;
   cout << "7.‬ Exit‬‬‬‬" << endl;
   cin >> choice;
   switch (choice) {
    case 1:    /*	Attack‬‬	*/
     //turn->attackEnemy(*turn);
     break;

    case 2:    /*	Get daily gold	*/
     turn->getDailyGold();
           break;

    case 3: /*	Buy creatures	*/
     choosenType = storeMenu();
           int count;
           cout << "How many please?" << endl;
           cin >> count;
           turn->buyCreature(turn->getGold(), choosenType, count);
           break;

    case 4:    /*	Show details	*/
     turn->showHero();
           break;

    case 5:    /*	Special skill‬‬‬‬	*/
     turn->specialAbility();
           break;

    case 6:    /*	End of my turn	*/
     save();
           isTurnRun = false;
           break;
    case 7: /* 	‫‪Exit‬‬‬‬  */
     ::roundNumber ++;
     this->~GameUnit();
    return *this;

    default:
     cout << "please choose a valid number" << endl;
   }
  }
 }
}

GameUnit::GameUnit( string heroTurn ){

}

void  GameUnit::save(){
 for (int i = 0; i < ::numberOfPlayers; ++i)
  players[i]->save();

 ofstream out;
 out.open("game/Game_Deatils.txt");
 out << "=[ Heroes Names ]= | TURN | Round# | #OP;"<<endl;
 out << heroesNames  << " " << "TODO" << " " << ::roundNumber << " " <<::numberOfPlayers;
}

bool  GameUnit::isCreature(string name){

}
int  GameUnit::ChooseHeroes(){

}
bool GameUnit::mkdir(){
 try {
  string comand = "mkdir game";
  const char *runComand = comand.c_str();
  const int dir_err = system(runComand);
 }
 catch (std::exception & e)
 {
  cout << "Error creating directory!n" << endl;
  return 0;
 }
 return 1;
}

int GameUnit::storeMenu(){
 int choice;
 while ( 1 > 0 ) {
  cout<<"‫‪1. Buy Zombies."<<endl;
  cout<<"2. Buy Archers."<<endl;
  cout<<"‫‪3.‬‬ Buy Vampire."<<endl;
  cout<<"4. Buy Wizard."<<endl;
  cout<<"‫‪5‬‬.‬‬ Buy Black Dragon."<<endl;
  cin >> choice;
  switch( choice  )
  {
   case 1:	/*	Buy Zombies 	*/
    return 0;
   case 2:	/*  Buy	Archers	   */
    return 1;
   case 3: /*	Buy Vampire	   */
    return 2;
   case 4:	/*	Buy Wizard	   */
    return 3;
   case 5:	/*	Buy Black Dragon  */
    return 4;
   default:
    cout<<"please choose a valid number"<<endl;
  }
 }
}
GameUnit::~GameUnit(){
 players.clear();
 heroesNames.clear();
}