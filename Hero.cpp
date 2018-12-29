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
	file << "isAlive|BD=WZ=ARC=[ ARMY ]=VMP=ZMB=|type|gold;";
	file << endl << inLife()  << " " << showArmy() <<" " << type << " " << gold;
	file.close();
}
Hero::Hero(): name("NoNameHero"), type(UnknownType), gold(750), isAlive(1)
{
	army = Army();
}
Hero::~Hero()
{}
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
	if(showArmy() != "")
		cout << showArmy() <<endl;
}
void Hero::showHeroFight()
{
	cout << getName() << " ";
	cout << displayType() << ":"<< endl;
	if(showArmy() != "")
		cout << showArmy() <<endl;
}
bool Hero::specialAbility()
{
	cout << "just inheirit already"<<endl;
	return true;
};
bool Hero::attackEnemy(Hero &enemy)
{
	string attack, toAttack , line;
	if (!enemy.army.isDestroyed() && !army.isDestroyed())
	{
		cout << this->getName() << "'s turn:" << endl;
		Creature c;
		getline(cin, line);
		stringstream ss( line );
		ss >> attack >> toAttack;
		if(enemy.army.army[c.creaTypeByName(attack)] < 1
		|| this->army.army[c.creaTypeByName(toAttack)] < 1) {
			cout << "throw exception" << endl; //TODO
			return this->attackEnemy(enemy);
		}

		//BATTEL+UPADTE



		//SHOW
		enemy.showHeroFight();
		this->showHeroFight();
		return enemy.attackEnemy(*this);
	}

	//TODO
	if(enemy.army.isDestroyed())
	{
		cout << "victorious" << endl;
		army.eraseKilled();
		enemy.rmdir();
		return 1;
	}
	if(army.isDestroyed())
	{
		cout << "You have been perished" << endl;
		enemy.army.eraseKilled();
		this->rmdir();
		return 0;
	}
	return 0;
}
bool Hero::addGold(int amount)
{
	if(isAlive){
		if(gold + amount < 2500)
			this->gold+=100;
		else
			gold = 2500;
		cout<<"**Gold Added***‬‬"<<endl; //TODO delete before assaign
		return true;
	}
	return false;
}
//^^^^^^^^^^^^^^^^ LOAD and SAVE ^^^^^^^^^^^^^^^^^//
bool Hero::load(string newName)
{
	setName(newName);

	string path = newName+"/Hero_Deatils.txt";

	ifstream in;
	in.open(path);

	if (!in)
	{
		cout << "Error reading from file..." << endl;
		return 0;
	}

	string cleanHeader;
	getline(in, cleanHeader, ';');
	bool _isA;
	int _gold;
	int _type;
	//Army @param
	int BD;
	int WZ;
	int ARC;
	int VMP;
	int ZMB;

	in  >> _isA  >> BD  >> WZ  >> ARC  >> VMP  >> ZMB  >> _type >> _gold;

	army.buildArmy(BD,WZ,ARC,VMP,ZMB);
	this->isAlive = _isA;
	setGold(_gold);
	setType(_type);
	in.close();
	cout << "Hero loaded successfully!" << endl;
	return 1;
}
void Hero::save()
{
	ofstream out;
	out.open(getName()+"/Hero_Deatils.txt");
	out << "isAlive|BD=WZ=ARC=[ ARMY ]=VMP=ZMB=|type|gold;"<<endl;
	out << isAlive  << " " << saveArmy() << " " << getType() << " "<< gold;
}
string Hero::saveArmy()
{
	return army.saveArmy();
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
	isAlive = false;
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

