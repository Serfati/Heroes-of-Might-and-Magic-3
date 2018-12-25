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
Hero::Hero(Type type , string name , Army army ,bool live, int gold){
	setName(name);
	name = "Heroes\\" + name;
	name += ".txt";
	ofstream file;
	this->isAlive =true;

	file.open(name);
	if(army.getSize()>0)
		setARMY(army);
	else	army = Army();
	setType(type);
	setGold(gold);
	string showArmy =  Hero::showArmy();

	cout << endl << "Hero has been successfully created!" << endl;

	//SAVE
	file <<  "isAlive *****ARMY***** type gold;"<<endl;
	file << isAlive  << " " << showArmy << " " << type << " " << gold;
	file.close();
}
Hero::~Hero() {}
//^^^^^^^^^^^^^^^^^^ GAME LOGIC ^^^^^^^^^^^^^^^^^^//
bool Hero::buyCreature(int &budget, int creatureType, int quantity){
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
	cout << "Hero Name: " << getName() <<  endl;
	cout << "Type: " << displayType() <<  endl;
	cout << "Gold: " << getGold() <<  endl;
	cout << "Army: "; showArmy(); cout <<endl;
}
void Hero::die(){
	isAlive = false;
	cout << getName() << " has died!" << endl;
}
bool Hero::specialAbility(){
	cout << "just inheirit already"<<endl;
};
//^^^^^^^^^^^^^^^^ LOAD and SAVE ^^^^^^^^^^^^^^^^^//
bool Hero::load(string name)
{
	setName(name);
	name = "Heroes\\" + name;
	name += ".txt";

	ifstream in;
	in.open(name);

	if (!in)
	{
		cout << "Error reading from file..." << endl;
		return 0;
	}

	string cleanHeader;
	getline(in, cleanHeader, ';');
	int gold;
	int type;
	string st;
	in  >> gold ;
	in  >> type;
	setGold(gold);
	setType(type);
	in.close();
	cout << "Hero loaded successfully!" << endl;
	return 1;
}
void Hero::save()
{
	ofstream out;
	out.open("Heroes\\" + getName() + ".txt");
	out << "isAlive *****ARMY***** type gold;"<<endl;
	string showArmy =  Hero::showArmy();
	out << isAlive  << " " << showArmy << " " << getType() << " "<< getGold();
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
		return true;
	}
	return false;
}
Type Hero::getType()
{
	return type;
}
string Hero::getName()
{return getName();}
int Hero::getGold()
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
