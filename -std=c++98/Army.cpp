/*
 * Army.cpp
 *
 *  Created on: Dec 25, 2018
 *      Author: serfati
 */

#include <sstream>
#include "Army.h"


using namespace std;

Army::Army() {
    try {
        vector<Creature*> vectz(5);
        realArmy = vectz;
        realArmy[0] = new Zombie();
        realArmy[1] = new Vampire();
        realArmy[2] = new Archer();
        realArmy[3] = new Wizard();
        realArmy[4] = new BlackDragon();
        vector<int> vect(6); // emty armyList
        armyList = vect;
        vect.clear();
    }
    catch( std::bad_alloc &exc ) {
        cout << exc.what() << endl;
    }
}

bool Army::isDestroyed() {
    return getArmySize() < 1;
}

bool Army::addUnit(int creatureType,int quantity) {
    armyList[creatureType] += quantity;
    return 1;
}

int Army::getArmySize() {
    int size = 0;
//    for (int i : armyList)
//        size += i;
    for (int i = 0; i <armyList.size(); i ++)
        size += armyList[i];

    return size;
}

string Army::showArmy() {
    string showArmy = "",t = " \t\r\f\v";
    Creature c;
    for (int i = 5; i >= 0; i --) {
        if ( armyList[i] != 0 ) {
            string in = "" + IntToString(armyList[i]);
            showArmy += in;
            showArmy += " " + c.creaType(i) + " ";
        }
    }
    showArmy.erase(showArmy.find_last_not_of(t) + 1);
    showArmy += ".";
    return showArmy;
}

Army::~Army() {
   // for(Creature* i : realArmy)
        //delete i;
    for (int i = 0; i <realArmy.size(); i ++)
        delete realArmy[i];
    armyList.clear();
}

std::string Army::saveArmy() {
    std::string saveArmy = "";
    for (int i = 4; i >= 0; i --) {
        string in = "" + IntToString(armyList[i]);
        saveArmy += in;
        if ( i != 0 )
            saveArmy += " ";
        else
            saveArmy += "";
    }
    return saveArmy;
}

void Army::buildArmy(int BD,int WZ,int ARC,int VMP,int ZMB) {
    armyList[4] = BD;
    armyList[3] = WZ;
    armyList[2] = ARC;
    armyList[1] = VMP;
    armyList[0] = ZMB;
}

void Army::reBuild() {
    for (int i = 0; i <realArmy.size(); i ++)
        delete realArmy[i];
    vector<Creature*> vectz(5);
    realArmy = vectz;
    realArmy[0] = new Zombie();
    realArmy[1] = new Vampire();
    realArmy[2] = new Archer();
    realArmy[3] = new Wizard();
    realArmy[4] = new BlackDragon();
}

std::string Army::IntToString ( int number )
{
    std::ostringstream oss;
    oss<< number;
    return oss.str();
}