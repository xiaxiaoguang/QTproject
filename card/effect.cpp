#include "effect.h"

#include<iostream>
using std::string;

void Effect::func(){};
bool Effect::check_conditions(){};
void Effect::cost(){};

Effect::Effect(){
    speed=0;
    text={};
}