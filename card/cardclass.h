#ifndef CardClass_H
#define CardClass_H

class Card{
public:
    char Kind; //   'M' 是怪兽卡，'T' 是陷阱卡 'S'是魔法卡
    Card(char a);
    virtual int stars();
    virtual int attributes();
    virtual int race();
};

#endif