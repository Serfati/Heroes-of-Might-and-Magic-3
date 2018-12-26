/*
 * Hero.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#include "Hero.h"

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
Hero::Hero( Type type, string name , Army ,bool live , int gold ){
	setName(name);
	name += ".txt";
	ofstream file;
	file.open(name);

	setType(type);
	setGold(gold);
	this->army =  Army();
	this->isAlive = live;
	cout << "Hero has been successfully created!" << endl;

	//SAVE
	file <<  "isAlive *********ARMY********* type gold;";
	file << endl << isAlive  << " " << showArmy() <<" " << type << " " << gold;
	file.close();
}
Hero::~Hero() {}
//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
bool Hero::buyCreature(int budget, int creatureType, int quantity){
	Creature c;
	if(quantity<=0 || budget<=0 || creatureType<0)
		return false;
	army.addUnit(creatureType, quantity );
	this->gold -= c.getPrice(creatureType)*quantity;
	c.~Creature();
	return true;
}
string Hero::showArmy(){
	return army.showArmy();
}
void Hero::showHero(){
	cout << getName() << " ";
	cout << displayType() << ":"<< endl;
	cout << getGold() <<  endl;
	cout << showArmy() <<endl;
}
void Hero::die(){
	isAlive = false;
	cout << getName() << " has died!" << endl;

	delete this;
}
bool Hero::specialAbility(){
	cout << "just inheirit already"<<endl;
	return true;
};
//^^^^^^^^^^^^^^^^ LOAD and SAVE ^^^^^^^^^^^^^^^^^//
bool Hero::load(string newName)
{
	setName(newName);
	string path = getName();
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
	out.open(getName() + ".txt");
	out << "isAlive *********ARMY********* type gold;"<<endl;
	out << isAlive  << " " << showArmy() << " " << getType() << " "<< gold;
}
//^^^^^^^^^^^^^^Getters and Setters^^^^^^^^^^^^^^//
void Hero::setARMY(Army newArmy)
{this->army = newArmy;}
void Hero::setName(string name)
{
	if(name.length() < 31)
		this->name = name;
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
	return type;
}
string Hero::getName()
{return this->name;}
int Hero::getGold() const
{return gold;}
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
int Hero::armySize(){
	return this->army.getArmySize();
}

Hero::Hero() {
		setName("NoNameHero");
		gold=0;
		type = UnknownType;
		army = Army();
}
