/*
 * Necomancer.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */

#ifndef NECOMANCER_H_
#define NECOMANCER_H_

#include "Hero.h"
#include "Creature.h"
#include "Zombie.h"

using namespace std;

class Necomancer: public Hero {
public:
	Necomancer(Type type , string name , Army army ,bool live, int gold);
	Necomancer(Necomancer& another);
	virtual bool specialAbility();
	virtual ~Necomancer();
};


#endif /* NECOMANCER_H_ */
