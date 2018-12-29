//
// Created by serfati on 12/27/18.
//
#include "GameUnit.h"

using namespace std;

static int numberOfPlayers = 0;
static int roundNumber = 0;

//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
GameUnit::GameUnit()
{

    // First Level
    cout<<"Loading...‬‬"<<endl;

    //TODO load game;
    // First Level
    string path = "game/Game_Deatils";
    path += ".txt";
    ifstream in;
    in.open(path);
    if (!in)
        cout << "Error reading from file..." << endl;

    string cleanHeader;
    getline(in, cleanHeader, ';');

    string HN;
    in  >> HN >> currentTurn >> ::roundNumber >> ::numberOfPlayers;


    // Second Level
    vector<string> HeroesNames;
    path = "game/Real_Order.txt";
    in.open(path);
    if (!in)
        cout << "Error reading from file..." << endl;
    getline( in, cleanHeader, ';');
    string word;
    while( in >> word )
        HeroesNames.push_back(word);
    in.close();


    for (std::string i : HeroesNames) {
        Hero *s = new Hero(); //TODO
        s->load(i);
        realOrder.push_back(s);
    }
}
GameUnit::GameUnit (const int w,const int t,const int n)
{
    std::cout<<"/* 	welcome to  Heroes of Might and Magic® 3  */"<<endl;

    rmdir(); //TODO delete all hero folders
    string _name;
    for (int i = 0; i < w; ++i) {
        std::cout<<"Please insert warrior number "<< i+1 << " name:"<<endl;
        getline(cin, _name);
        realOrder.push_back(new Warrior(_name));
    }
    for (int i = 0; i < t; ++i) {
        std::cout<<"Please insert thief name number "<< i+1 << " name:"<<endl;
        getline(cin, _name);
        realOrder.push_back(new Thief(_name));
    }
    for (int i = 0; i < n; ++i) {
        std::cout<<"Please insert necomancer number "<< i+1 << " name:"<<endl;
        getline(cin, _name);
        realOrder.push_back(new Necomancer(_name));
    }
    ::numberOfPlayers = w+t+n;
    ::roundNumber ++;
    turnOrder = realOrder; /*  just a pointer to a shuffled realOrder    */
    std::cout<<" ^=^=^=^= [ Enjoy your game ] ^=^=^=^= "<<endl;
    try {
        mkdir();    shuffle();      save();
    }
    catch (__exception_ptr::exception_ptr) {
        cout << " ^=^=^=^= CATCH ^=^=^=^= " << endl;
    }

    this->currentTurn = 0;
    mainMenu(turnOrder[currentTurn]);
}
GameUnit::~GameUnit()
{
    realOrder.clear();
    turnOrder.clear();
}
//   ******** Hero Main Menu *********   //
GameUnit GameUnit::mainMenu(Hero *turn)
{
    if(turn->inLife()){
        bool isTurnRun = true, got = 0;
        string  index;
        int choosenType;
        Creature c;
        while ( isTurnRun  ) {
            cout << "What is your next step in the path to victory?" << endl;
            cout << "‫‪1. Attack‬‬" << endl;
            cout << "2. Get daily gold" << endl;
            cout << "‫‪3.‬‬ Buy creatures‬‬" << endl;
            cout << "4. Show details" << endl;
            cout << "‫‪5‬‬.‬‬ Special skill‬‬‬‬" << endl;
            cout << "6. End of my turn" << endl;
            cout << "7.‬ Exit‬‬‬‬" << endl;
            cin >> index;
            int choice = atoi(index.c_str());
            switch (choice) {
                case 1:    /*	Attack‬‬	*/
                    if(::roundNumber > -1)
                        attackMenu(turn);
                    else cout << "Can'nt attack before round 4, You're still on round "<< ::roundNumber << endl;
                    save();
                    if(::numberOfPlayers < 2) { // last player
                        cout << realOrder[0]->getName() + " is the winner!" << endl; //TODO
                        close();
                    }
                    break;

                case 2:    /*	Get daily gold	*/
                    if(!got)
                        turn->getDailyGold();
                    got= 1;
                    break;

                case 3: /*	Buy creatures	*/
                    choosenType = storeMenu();
                    int count; cout << "How many please?" << endl;
                    cin >> count;
                    if(c.getPrice(choosenType)*count > turn->getGold())
                        cout << "throw std::invalid_argument(Invalid syntax)‬‬" << endl;
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
                    nextTurn();
                    break;

                case 7: /* 	‫‪Exit‬‬‬‬  */
                    save();
                    this->~GameUnit();
                    return *this;

                default:
                    cout << "please choose a valid number" << endl;
                    break;
            }
        }
    }
    return *this;
}
bool GameUnit::attackMenu(Hero* me)
{
    Hero *ptr;
    string heroToAttack = "" , index = "";

    while ( 1 > 0 ) {
        cout<<"‫‪1. Show me my opponents"<<endl;
        cout<<"2. Attack Hero"<<endl;
        if(getline ( cin, index ) && index.empty() && cin.get() == '\n') //pressed Enter
            return 0;
        int choice = atoi(index.c_str());
        if (index.empty())
            return 0;
        switch( choice )
        {
            case 1:	/*	Show me my opponents	*/
                showHeroes();
                break;
            case 2:	/*  Attack Hero by name	   */
                cout<<"Please insert your opponent name:"<<endl;
                cin >> heroToAttack;
                ptr = getHeroByName(heroToAttack);
                if(ptr == NULL) {
                    cout << "throw std::invalid_argument(Invalid syntax)‬‬" << endl;
                    return 0; //TODO
                }
                me->showHeroFight();
                ptr->showHeroFight(); //TODO
                me->attackEnemy(*ptr);
                ::numberOfPlayers--;
                return 1;
            default:
                return 0;
        }
    }
    return 0;
}
int GameUnit::storeMenu()
{
    string  index;
    while ( 1 > 0 ) {
        cout<<"‫‪1. Buy Zombies."<<endl;
        cout<<"2. Buy Archers."<<endl;
        cout<<"‫‪3.‬‬ Buy Vampire."<<endl;
        cout<<"4. Buy Wizard."<<endl;
        cout<<"‫‪5‬‬.‬‬ Buy Black Dragon."<<endl;
        cin >> index;
        int choice = atoi(index.c_str());
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
void GameUnit::kill(Hero* toKill)
{
    toKill->kill();
    //delete from real and turn orders//
    ::numberOfPlayers--;
}
void GameUnit::nextTurn()
{
    int check = currentTurn;
    if( check+1 >= ::numberOfPlayers )
    {        currentTurn=0;
        ::roundNumber++;
        mainMenu(turnOrder[currentTurn]);
    }
    else {
        currentTurn++;
        mainMenu(turnOrder[currentTurn]);
    }
}
//^^^^^^^^^^^^^^^^ MAINTENACE ^^^^^^^^^^^^^^^^^//
void  GameUnit::save()
{
    string HeroesNames = "";
    for (int i = 0; i < ::numberOfPlayers; ++i)
        realOrder[i]->save();
    ofstream out;
    out.open("game/Game_Deatils.txt");
    out << "=[ Heroes Names ]= | TURN | Round# | #OP;"<<endl;
    out << getTurnOrder()  << " " << currentTurn << " " << ::roundNumber << " " <<::numberOfPlayers;

    for (int i = 0; i < ::numberOfPlayers; ++i)
        HeroesNames += realOrder[i]->getName()+",";

    out.open("game/Real_Order.txt");
    out << "=[ Heroes Names ]=;"<<endl;
    out << HeroesNames;

    out.close();
}
bool GameUnit::mkdir()
{
    try {
        string comand = "mkdir game";
        const char *runComand = comand.c_str();
        system(runComand);
    }
    catch (std::exception & e)
    {
        cout << "Error creating directory!n" << endl;
        return 0;
    }
    return 1;
}
void GameUnit::shuffle()
{
    std::random_shuffle(std::begin(turnOrder), std::end(turnOrder));
}
void GameUnit::rmdir()
{
    try {
        string comand = "rm -rf game";
        const char *runComand = comand.c_str();
        system(runComand);
    }
    catch (std::exception & e)
    {
        cout << "Error deleting directory!n" << endl;
    }

    for (Hero* i : realOrder)
        i->~Hero();
}
void GameUnit::close(){
    for (Hero* i : realOrder) {
        i->rmdir();
        i->~Hero();
    }
    rmdir();
    (*this).~GameUnit();
    exit(1);
}
//^^^^^^^^^^^^^^ Getters and Setters ^^^^^^^^^^^^^^//
string GameUnit::getTurnOrder( )
{
    string turnList = "";
    for (Hero* i : turnOrder )
        turnList += i->getName() +",";
    return turnList;
}
Hero* GameUnit::getHeroByName( string heroName )
{
    for (int i = 0; i < ::numberOfPlayers; ++i)
        if(realOrder[i]->getName() == heroName)
            return realOrder[i];
    return NULL;
}
void GameUnit::showHeroes( )
{
    for (int i = 0; i < ::numberOfPlayers; ++i) {
        if (realOrder[i]->getName() != turnOrder[currentTurn]->getName()) {
            cout << realOrder[i]->getName() << " ";
            cout << realOrder[i]->displayType() << endl;
        }
    }
}


