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
	Necomancer( string name );
	Necomancer(Necomancer& another);
	virtual bool specialAbility();
	~Necomancer();
};


#endif /* NECOMANCER_H_ */
