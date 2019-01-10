/*
 * Thief.h
 *
 *  Created on: Dec 24, 2018
 *      Author: serfati
 */
#pragma once
#ifndef THIEF_H_
#define THIEF_H_

#include "Hero.h"

using namespace std;

class Thief : public Hero {
public:

    Thief() { setType(thief); }

    Thief(string name);

    virtual bool specialAbility(Hero &);

    virtual ~Thief();

};

#endif /* THIEF_H_ */