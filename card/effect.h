#ifndef Effect_H
#define Effect_H

#include<iostream>
#include<cstring>
using std::string;


class Effect{
    string text;
    int speed;
    virtual void func();
};

#endif