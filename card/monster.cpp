#include "monster.h"

MonsterCard::MonsterCard(int atk,int def,int stars,int attributes,const char* race):Card('M'){
    ATK=atk;
    DEF=def;
    Stars=stars;
    Attributes=attributes;
    Race=race;
    Keyword={};
}

LinkMonster::LinkMonster(int atk,int attributes,const char *race,int lknumbers,int lks):MonsterCard(atk,-1,-1,attributes,race)
{
    Linknumber = lknumbers;
    Links = lks;
}