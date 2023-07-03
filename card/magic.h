#ifndef Magic_H
#define Magic_H

#include "cardclass.h"
#include "effect.h"

#include<iostream>
using std::string;

class MagicCard : public Card{
    int type; //仪式魔法/永续魔法/装备魔法/场地魔法/速攻魔法
    Effect a;
public:
    const char kd = 'G';
};

#endif