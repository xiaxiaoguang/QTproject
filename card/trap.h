#ifndef Trap_H
#define Trap_H

#include "cardclass.h"
#include "effect.h"
#include<iostream>
using std::string;

class TrapCard : public Card{
    int type; //通常魔法/反击陷阱/永续陷阱
    Effect a;
public:
    const char kd = 'T';
    TrapCard(int tp);
};

#endif