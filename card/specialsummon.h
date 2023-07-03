#ifndef SpecialSummon_H
#define SpecialSummon_H

#include<iostream>

using std::string;

class SpecialSummon{
public:
    string text;
    virtual bool check_conditions();
    virtual void cost();
    virtual void summon();
    SpecialSummon();
};

#endif