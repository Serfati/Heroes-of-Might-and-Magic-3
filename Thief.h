/*
 * Thief.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef THIEF_H_
#define THIEF_H_

#include "Hero.h"

using namespace std;

class Thief: public Hero {
public:
	Thief(Type type , string name , Army army ,bool live, int gold);
	Thief(Thief& another);
	virtual bool specialAbility();
	virtual ~Thief();
};


#endif /* THIEF_H_ */
