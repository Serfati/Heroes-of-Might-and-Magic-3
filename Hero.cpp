/*
 * Hero.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */


#include "Hero.h"
#include <exception>

using namespace std;

//^^^^^^^^^^ Constructors and Destructor ^^^^^^^^^^//
Hero::Hero(Hero& another)
{
	setName(another.getName());
	this->type = another.getType();
	this->gold = another.getGold();
	this->army=another.army;
	isAlive = another.isAlive;;
}
Hero::Hero( Type type, string name , Army ,bool live , int gold )
{
	if(name.length() > 31 || gold < 0 || gold > 2500 || name.length() < 0 )
		throw std::invalid_argument( "received invalid values" );

	setName(name);
	mkdir();
	name = getName()+"/Hero_Deatils";
	name += ".txt";
	ofstream file;
	file.open(name);

	setType(type);
	setGold(gold);
	this->army =  Army();
	this->isAlive = live;
	cout << "Hero has been successfully created!" << endl;

	//SAVE
	file << "isAlive | =-==-==-=[ ARMY ]=-==-==-= | type | gold;";
	file << endl << isAlive  << " " << showArmy() <<" " << type << " " << gold;
	file.close();
}
Hero::Hero(): name("NoNameHero"), type(UnknownType), gold(750), isAlive(1)
{
	army = Army();
}
Hero::~Hero()
{

}
//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
bool Hero::buyCreature(int budget, int creatureType, int quantity)
{
	Creature c;
	if(quantity<=0 || budget<=0 || creatureType<0)
		return false;
	army.addUnit(creatureType, quantity );
	this->gold -= c.getPrice(creatureType)*quantity;
	c.~Creature();
	return true;
}
string Hero::showArmy()
{
	return army.showArmy();
}
void Hero::showHero()
{
	cout << getName() << " ";
	cout << displayType() << ":"<< endl;
	cout << getGold() <<  endl;
	cout << showArmy() <<endl;
}
void Hero::die()
{
	isAlive = false;
	cout << getName() << " has died!" << endl;
	rmdir();
	delete this;
}
bool Hero::specialAbility()
{
	cout << "just inheirit already"<<endl;
	return true;
};
bool Hero::attackEnemy(Hero &enemy)
{
	//TODO
	if(enemy.army.isDestroyed()) {
		cout << "victorious" << endl;
		enemy.die();
		return 1;
	}
	if(army.isDestroyed()) {
		cout << "You have been perished" << endl;
		this->die();
		return 0;
	}
	string attack, toAttack;
	cout << "enemy creature to attack" << endl;
	getline(cin, toAttack);
	cout << "choose the creature to attack with" << endl;
	getline(cin, attack);







	return attackEnemy (enemy);
}
//^^^^^^^^^^^^^^^^ LOAD and SAVE ^^^^^^^^^^^^^^^^^//
bool Hero::load(string newName)
{
	setName(newName);

	string path = getName()+"/Hero_Deatils";
	path += ".txt";

	ifstream in;
	in.open(path);

	if (!in)
	{
		cout << "Error reading from file..." << endl;
		return 0;
	}

	string cleanHeader;
	getline(in, cleanHeader, ';');
	bool isA;
	int _gold;
	int type;
	string armyToadd;
	in  >> isA >> armyToadd >> type >> _gold;
	this->isAlive = isA;
	setGold(_gold);
	setType(type);
	in.close();
	cout << "Hero loaded successfully!" << endl;
	return 1;
}
void Hero::save()
{
	ofstream out;
	out.open(getName()+"/Hero_Deatils.txt");
	out << "isAlive | =-==-==-=[ ARMY ]=-==-==-= | type | gold;"<<endl;
	out << isAlive  << " " << showArmy() << " " << getType() << " "<< gold;
}
bool Hero::mkdir()
{
	try {
		string comand = "mkdir " + getName();
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
void Hero::rmdir()
{
	try {
		string comand = "rm -rf "+getName();
		const char *runComand = comand.c_str();
		system(runComand);
	}
	catch (std::exception & e)
	{
		cout << "Error deleting directory!n" << endl;
	}
}
//^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
void Hero::setARMY(Army newArmy)
{
	this->army = newArmy;
}
bool Hero::setName(const string nName)
{
    if (nName.size() < 0)
        return 0;
	this->name = nName;
	return 1;
}
void Hero::setGold(int newBudget)
{
	if(newBudget>0 && newBudget<2500)
		this->gold = newBudget;
}
void Hero::setType(int type)
{
	switch (type)
	{
		case 0:
			this->type = warrior;
			break;
		case 1:
			this->type = thief;
			break;
		case 2:
			this->type =necomancer;
			break;
		default:
			this->type = UnknownType;
	}
}
bool Hero::getDailyGold()
{
	if(isAlive){
		if(gold+100 <= 2500)
			this->gold+=100;
		else
			gold = 2500;
		cout<<"**Gold Added***‬‬"<<endl;
		return true;
	}
	cout<<"***You are not alive***‬‬"<<endl;
	return false;
}
Type Hero::getType()
{
	return this->type;
}
string Hero::getName()
{
	return this->name;
}
int Hero::getGold() const
{
	return gold;
}
string Hero::displayType()
{
	switch (type)
	{
		case 0:
			return "Warrior";

		case 1:
			return "Thief";

		case 2:
			return "Necomancer";

		default:
			return "UnknownType";
	}
}

