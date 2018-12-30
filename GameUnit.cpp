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
    cout<<"Loading...‬‬"<<endl;

    string path = "game/Game_Details.txt";
    ifstream in;
    in.open(path);
    if (!in)
        cout << "GD: Error reading from file..." << endl;
    string cleanHeader;
    getline(in, cleanHeader, ';');
    in  >> currentTurn >> ::roundNumber >> ::numberOfPlayers;
    in.close();

    // Second Level
    path = "game/Real_Order.txt";
    ifstream ina;
    vector<string> HeroesNames;
    ina.open(path);
    if (!ina)
        cout << "RO: Error reading from file..." << endl;
    getline( ina, cleanHeader, ';');
    string word;
    while( ina >> word )
        HeroesNames.push_back(word);
    ina.close();

    for (std::string i : HeroesNames) {
        Hero *s = nullptr;
        s->load(i); //TODO load hero type
        realOrder.push_back(s);
    }
    turnOrder = realOrder;
    shuffle();
    mainMenu(turnOrder[currentTurn]);
}
GameUnit::GameUnit (const int w,const int t,const int n)
{
    std::cout<<"/* 	welcome to  Heroes of Might and Magic® 3  */"<<endl;
    rmdir();
    string _name;
    try{
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
            std::cout<<"Please insert necromancer number "<< i+1 << " name:"<<endl;
            getline(cin, _name);
            realOrder.push_back(new Necromancer(_name));
        }
    }
    catch (std::bad_alloc &exc) {
        cout << exc.what() << endl;
    }
    catch (std::invalid_argument &exc ) {
        cout << exc.what() << endl;
    }
    ::numberOfPlayers = w+t+n;
    ::roundNumber ++;
    turnOrder = realOrder; /*  just a pointer to a shuffled realOrder    */
    this->currentTurn = 0;
    mkdir();    shuffle();      save();
    mainMenu(turnOrder[currentTurn]);
}
GameUnit::~GameUnit()
{
    realOrder.clear();
    turnOrder.clear();
}

//   ******** Game Main Menu *******    //
GameUnit GameUnit::mainMenu(Hero *turn)
{
    if(turn->inLife()){
        bool isTurnRun = 1, got = 0;
        string  index;string toRob;
        int choosenType;
        Creature c; Hero *ptr = nullptr;
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
                    if(::roundNumber > 3)
                        attackMenu(turn);
                    else cout << "Can'nt attack before round 4, You're still on round "<< ::roundNumber << endl;
                    save();
                    if(::numberOfPlayers < 2) { // last player
                        cout << realOrder[0]->getName() + " is the winner!" << endl;
                        close();
                    }
                    break;

                case 2:    /*	Get daily gold	*/
                    if(!got) {
                        turn->getDailyGold();
                        got = 1;
                    } else cout<< "You already got your daily gold!" << endl;
                    break;

                case 3: /*	Buy creatures	*/
                    try {
                        choosenType = storeMenu();
                        int count;
                        cout << "How many please?" << endl;
                        cin >> count;
                        if (c.getPrice(choosenType) * count > turn->getGold())
                            throw std::invalid_argument("Not enough gold!");
                        turn->buyCreature(turn->getGold(), choosenType, count);
                    }
                    catch (std::invalid_argument &e ){
                        cout<< e.what() <<endl;
                    }
                    break;

                case 4:    /*	Show details	*/
                    turn->showHero();
                    break;

                case 5:    /*	Special skill‬‬‬‬	*/

                    try {
                        if(turn->getType() == thief) {
                            std::cout << "Please insert hero name:" << endl;
                            cin >> toRob;
                            ptr = getHeroByName(toRob);
                            if (ptr == NULL)
                                throw std::invalid_argument("Hero to rob not found! try again.");
                            turn->specialAbility(*ptr);
                            break;
                        }

                    }
                    catch (std::invalid_argument &e ){
                        cout<< e.what() <<endl;
                    }
                    turn->specialAbility(*ptr);
                    break;

                case 6:    /*	End of my turn	*/
                    save();
                    isTurnRun = false;
                    nextTurn();
                    break;

                case 7: /* 	‫‪Exit‬‬‬‬  */
                    save();
                    close(); //TODO remove before ass!
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
    Hero *ptr = nullptr;
    string heroToAttack = "" ,index;

    while ( 1 > 0 ) {
        cout<<"‫‪1. Show me my opponents"<<endl;
        cout<<"2. Attack Hero"<<endl;
        cin>>index;
        int choice = atoi(index.c_str());
        switch( choice )
        {
            case 1:	/*	Show me my opponents	*/
                showHeroes();
                break;
            case 2:	/*  Attack Hero by name	   */
                try {
                    cout << "Please insert your opponent name:" << endl;
                    cin >> heroToAttack;
                    ptr = getHeroByName(heroToAttack);
                    if (ptr == NULL)
                        throw std::invalid_argument("Hero not found! try again.");
                }
                catch (std::invalid_argument &e ){
                    cout<< e.what() <<endl;
                    return 0;
                }
                me->showHeroFight();
                ptr->showHeroFight();
                me->attackEnemy(*ptr);
                ::numberOfPlayers--;
                eraseKilled();
                delete ptr;
                return 1;
            default:
                return 0;
        }
    }
    return 0;
}
int GameUnit::storeMenu()
{
    Creature c;
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
void  GameUnit::eraseKilled()
{
    unsigned long size = realOrder.size();

    for (int i = 0; i < size; i++)
    {
        if (realOrder[i]->inLife() == 0 || realOrder[i]->showArmy() == "") {
            realOrder[i]->rmdir();
            realOrder.erase(realOrder.begin() + i);
        }
    }
    realOrder.shrink_to_fit();
    turnOrder.shrink_to_fit();
}

//^^^^^^^^^^^^^^^^ MAINTENANCE ^^^^^^^^^^^^^^^^^//
void  GameUnit::save()
{
    string HeroesNames = "";
    for (int i = 0; i < ::numberOfPlayers; ++i)
        realOrder[i]->save();
    ofstream out;
    out.open("game/Game_Deatils.txt");
    out << "=[ Heroes Names ]= | TURN | Round# | #OP;"<<endl;
    out << currentTurn << " " << ::roundNumber << " " <<::numberOfPlayers << endl;
    out << getTurnOrder() ;

    for (int i = 0; i < ::numberOfPlayers; ++i)
        HeroesNames += realOrder[i]->getName()+" ";
    ofstream out2;
    out2.open("game/Real_Order.txt");
    out2 << "=[ Heroes Names ]=;"<<endl;
    out2 << HeroesNames;

    out2.close();
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
        //string comand = "rm -rf game";
        string comand ="find * -type d | grep -v \"^CMakeFiles\" | xargs rm -rf" ;
        const char *runComand = comand.c_str();
        system(runComand);
    }
    catch (std::exception & e)
    {
        cout << "Error deleting directory!n" << endl;
    }
}
void GameUnit::close()
{
    for (Hero* i : realOrder)
        i->rmdir();
    realOrder.clear();
    turnOrder.clear();
    rmdir();
    (*this).~GameUnit();
    exit(1);
}
//^^^^^^^^^^^^^^ Getters and Setters ^^^^^^^^^^^^^^//
string GameUnit::getTurnOrder( )
{
    string turnList = "";
    for (Hero* i : turnOrder )
        turnList += i->getName() +" ";
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