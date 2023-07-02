#include "effect.h"
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

class MonsterCard{
    const char kd = 'M';
    int ATK,DEF;//攻击力防御力
    int Stars;//星级
    int Attributes;//属性
    string Keyword;//关键字段
    int Race;//种族
    Effect a;//效果
};

class TrapCard{
    const char kd = 'T';
    Effect a;
};

class MagicCard{
    const char kd = 'G';
    Effect a;
};


int main(){
    return 0;
}