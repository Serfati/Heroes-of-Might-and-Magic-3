/*
 * Hero.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */


#include "Hero.h"

using namespace std;

//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
Hero::Hero(Hero &another) {
    setName(another.getName());
    this->type = another.getType();
    this->gold = another.getGold();
    this->army = another.army;
    isAlive = another.isAlive;;
}

Hero::Hero(Type type,string name,bool live,int gold,bool gotDG,bool usedSA) {
    if ( name.length() < 31 && gold < 2500) {
        setName(name);
        mkdir();
        name = "Heros/" + getName() + "/Details.txt";
        ofstream file;
        file.open(name);
        this->army = new(nothrow) Army();
        if ( nullptr == this->army ) cout << "Error: memory could not be allocated" << endl;
        setType(type);
        setGold(gold);
        this->isAlive = live;
        this->gotDG = false;
        this->usedSA = false;

        //SAVE
        file << "live|B:W:A:V:Z|type|gold|DG|SA;";
        file << endl << inLife() << " " << showArmy() << " " << type << " " << gold << " " << gotDG << " " << usedSA;
        file.close();
    }
    else
        throw std::invalid_argument("received invalid user arguments! try again.");
}

Hero::Hero() : name("NoNameHero"),type(UnknownType),gold(750),isAlive(1) {
    this->army = new (nothrow) Army();
    if ( nullptr == this->army ) cout << "Error: memory could not be allocated" << endl;
}

//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
bool Hero::buyCreature(double budget,int creatureType,int quantity,int unitPrice) {
    Creature c;
    if ( quantity > 0 && budget > 0 && creatureType >= 0 ) {
        army->addUnit(creatureType,quantity);
        this->gold -= unitPrice * quantity;
        c.~Creature();
        return true;
    } else return false;
}

string Hero::showArmy() {
    return army->showArmy();
}

void Hero::showHero() {
    cout << getName() << " ";
    cout << displayType() << ":" << endl;
    cout << getGold() << endl;
    if ( showArmy() != "." )
        cout << showArmy() << endl;
}

void Hero::showHeroFight() {
    cout << getName() << " ";
    cout << displayType() << ":" << endl;
    if ( showArmy() != "." )
        cout << showArmy() << endl;
}

bool Hero::specialAbility(Hero &s) {
    cout << "just inheirit already" << endl;
    return true;
};

bool Hero::attackEnemy(Hero &enemy) {
    int attackCount,defendCount;
    double ratio,howMuchToDelete;
    string attack,toAttack,line;
    Creature c;
    if ( ! enemy.army->isDestroyed() && ! army->isDestroyed()) {
        cout << this->getName() << "'s turn:" << endl;
        /* -~=[  Gets creature to attack and creature to defend  ]~=- */
        do {
            try {
                if ( std::cin.peek() == '\n' )
                    std::cin.ignore();
                getline(cin , line);
                stringstream ss(line);
                ss >> attack >> toAttack;
                if ( enemy.army->getArmyList()[c.creaTypeByName(toAttack)] < 1 ||
                     this->army->getArmyList()[c.creaTypeByName(attack)] < 1 )
                    throw std::invalid_argument("Creature to attack not found! try again.");
            }
            catch( std::invalid_argument &e ) {
                cout << e.what() << endl;
            }
        } while ( enemy.army->getArmyList()[c.creaTypeByName(toAttack)] < 1 ||
                  this->army->getArmyList()[c.creaTypeByName(attack)] < 1 );

        /* -~=[  Battle | Update | Save | Show and Return   ]=~- */

        //attack!
        ratio = (army->getRealArmy()[c.creaTypeByName(attack)]->attackAnother(
                *enemy.army->getRealArmy()[c.creaTypeByName(toAttack)]));
        attackCount = army->getArmyList()[c.creaTypeByName(attack)];
        defendCount = enemy.army->getArmyList()[c.creaTypeByName(toAttack)];
        howMuchToDelete = floor(ratio * attackCount);

        //delete destroyed and update
        int x = int(howMuchToDelete >= defendCount ? 0 : (defendCount - howMuchToDelete));
        enemy.army->setAtArmyList(c.creaTypeByName(toAttack),x);

        //reset creatures details
        army->reBuild();
        enemy.army->reBuild();
        //saves
        save();
        enemy.save();
        //SHOW
        if ( !enemy.army->isDestroyed() && !army->isDestroyed()) {
            enemy.showHeroFight();
            this->showHeroFight();
        }
        return enemy.attackEnemy(*this);
    }
    /* -~=[  Check if Eliminated  ]=~- */
    if ( army->isDestroyed()) {

        cout << "victorious" << endl;
        enemy.addGold(this->getGold());
        isAlive = false;
        this->rmdir();
        return 1;
    }
    if ( enemy.army->isDestroyed()) {
        cout << "You have been perished" << endl;
        this->addGold(enemy.getGold());
        enemy.isAlive = false;
        enemy.rmdir();
        return 0;
    }
    return 0;
}

bool Hero::addGold(double amount) {
    if ( ! isAlive ) return false;
    gold + amount < 2500 ? (this->gold += amount) : (gold = 2500);
    return true;
}

//^^^^^^^^^^^^^^^^ LOAD and SAVE ^^^^^^^^^^^^^^^^^//
bool Hero::load(string newName) {
    setName(newName);
    string path = "Heros/" + newName + "/Details.txt";
    ifstream in;
    in.open(path);
    if ( ! in ) {
        cout << "HERO: Error reading from file..." << endl;
        return 0;
    }
    string cleanHeader;
    getline(in,cleanHeader,';');

    //Hero @param
    int bd,wz,arc,vmp,zmb,_type;
    double _gold;
    bool _is,_DG,_SA;
    in >> _is >> bd >> wz >> arc >> vmp >> zmb >> _type >> _gold >> _DG >> _SA;

    army->buildArmy(bd,wz,arc,vmp,zmb);
    this->isAlive = _is;
    this->gotDG = _DG;
    this->usedSA = _SA;
    setGold(_gold);
    setType(_type);
    in.close();
    return 1;
}

void Hero::save() {
    ofstream out;
    out.open("Heros/" + getName() + "/Details.txt");
    out << "live|B:W:A:V:Z|type|gold|DG|SA;" << endl;
    out << isAlive << " " << saveArmy() << " " << getType() << " " << gold << " " << gotDG << " " << usedSA;
}

string Hero::saveArmy() {
    return army->saveArmy();
}

bool Hero::mkdir() {
    errno = 0;
    try {
        string command = "mkdir -p Heros/" + getName();
        auto runCommand = command.c_str();
        int dir_result = system(runCommand);
        if ( dir_result != 0 && errno != EEXIST )
            return 0;
    }
    catch( std::exception &e ) {
        cout << "Error creating directory!n" << endl;
        return 0;
    }
    return 1;
}

void Hero::rmdir() {
    isAlive = false;
    try {
        string command = "rm -rf Heros/" + getName();
        const char *runCommand = command.c_str();
        system(runCommand);
    }
    catch( std::exception &e ) {
        cout << "Error deleting directory!n" << endl;
    }
}

int Hero::typeFromFile(string heroName) {
    string path = "Heros/" + heroName + "/Details.txt";
    ifstream in;
    in.open(path);
    if ( ! in ) {
        cout << "HERO: Error reading from file..." << endl;
        return -1;
    }
    string cleanHeader;
    getline(in,cleanHeader,';');
    int  type;
    //Hero @param
    int bd,wz,arc,vmp,zmb;
    double _gold;
    bool _is;
    in >> _is >> bd >> wz >> arc >> vmp >> zmb >> type >> _gold;
    in.close();

    return type;
}

//^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
bool Hero::setName(const string nName) {
    if ( nName.size() < 0 )
        return 0;
    this->name = nName;
    return 1;
}

void Hero::setGold(double newBudget) {
    this->gold = 0 > newBudget ? 0 : 2500 < newBudget ? 2500 : newBudget;
}

void Hero::setType(int type) {
    switch ( type ) {
        case 0:
            this->type = warrior;
            break;
        case 1:
            this->type = thief;
            break;
        case 2:
            this->type = necromancer;
            break;
        default:
            this->type = UnknownType;
    }
}

Type Hero::getType() {
    return this->type;
}

string Hero::getName() {
    return this->name;
}

double Hero::getGold() const {
    return gold;
}

string Hero::displayType() {
    switch ( type ) {
        case 0:
            return "Warrior";

        case 1:
            return "Thief";

        case 2:
            return "Necromancer";

        default:
            return "UnknownType";
    }
}