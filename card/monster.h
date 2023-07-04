#ifndef Monster_H
#define Monster_H

#include "cardclass.h"
#include "effect.h"
#include "specialsummon.h"

#include<iostream>
using std::string;

class MonsterCard : public Card{
public:
    int ATK,DEF;//攻击力防御力
    int Stars;//星级
    int Attributes;//属性
    string Keyword;//关键字段
    string Race;//种族
    Effect a;//效果
    MonsterCard(int atk,int def,int stars,int attributes,const char* race);
    int race();
    int attributes();
    int stars();
};

class LinkMonster : public MonsterCard{
public :
    int Linknumber;
    int Links;
    SpecialSummon a;
    LinkMonster(int atk,int attributes,const char *race,int lknumbers,int lks);
    int race();
    int attributes();
};

#endif