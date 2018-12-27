/*
 * Warrior.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "Hero.h"

using namespace std;

class Warrior: public Hero
{
public:
	Warrior();
	Warrior( string name );
	Warrior(Warrior& another);
	virtual bool specialAbility();
	virtual ~Warrior();
};


#endif /* WARRIOR_H_ */
