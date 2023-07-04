#include "monster.h"

MonsterCard::MonsterCard(int atk,int def,int stars,int attributes,const char* race):Card('M'){
    ATK=atk;
    DEF=def;
    Stars=stars;
    Attributes=attributes;
    Race=race;
    Keyword.clear();
}

int MonsterCard::attributes(){
    return Attributes;
}

// machine 机械族   1 
// warrior 战士族   2
// cyberse 电子界族  3
// seaserpent 海龙   4
// dragon      龙    5

const string mp[]={"machine","warrior","cyberse","seaserpent","dragon"};

int MonsterCard::race(){
    for(int i=0;i<5;++i)if(mp[i]==Race)return i+1;
    return -1;
}

int MonsterCard::stars(){
    return Stars;
}

LinkMonster::LinkMonster(int atk,int attributes,const char *race,int lknumbers,int lks):MonsterCard(atk,-1,-1,attributes,race)
{
    Linknumber = lknumbers;
    Links = lks;
}

int LinkMonster::race(){
    for(int i=0;i<5;++i)if(mp[i]==Race)return i+1;
    return -1;
}

int LinkMonster::attributes(){
    return Attributes;
}
