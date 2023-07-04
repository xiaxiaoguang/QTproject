#ifndef Effect_H
#define Effect_H

#include<iostream>
using std::string;

class Effect{
    string text;
    int speed;
public:    
    virtual bool check_conditions();
    virtual void cost();
    virtual void func();
    Effect();
};

#endif