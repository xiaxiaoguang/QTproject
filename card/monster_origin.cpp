#include "monster.h"

//光、暗、地、风、水、炎、神 7种属性
//1  2   3  4   5  6  7

// machine 机械族

// 链接怪兽从右上到正上方依次为1，2，3，4，5，6，7，8
// \ | /  7 8 1
// -   -  6   2
// / | \  5 4 3

int Pressure(){
    return 0;
}

template<typename T, typename... Args>
int Pressure(T first,Args... args) {
    return (1<<first)+Pressure(args...);
}

class Surgical_Striker_HAMP : public MonsterCard{
public:
    Surgical_Striker_HAMP():MonsterCard(2500,2500,8,2,"machine"){
        Keyword+="SkyStriker"; //关键字一律以去掉空格+大写字符的方式实现
    }
};

class Sage_of_Strength_Akash : public MonsterCard{
public :
    Sage_of_Strength_Akash():MonsterCard(2400,200,5,6,"machine"){
        Keyword+="SkyStriker";
    }
};

class Sage_of_Wisdom_Himmel : public MonsterCard{
public:
    Sage_of_Wisdom_Himmel():MonsterCard(500,2500,5,3,"machine"){
        Keyword+="SkyStriker";
    }
};

class Aileron : public MonsterCard{
public:
    Aileron():MonsterCard(0,0,1,4,"machine"){
        Keyword+="SkyStriker";
    }
};


class Sky_Striker_Ace_Raye : public MonsterCard{
public:
    Sky_Striker_Ace_Raye():MonsterCard(1500,1500,4,2,"warrior"){
        Keyword+="SkyStriker";
    }
};

class Sky_Striker_Ace_Roze : public MonsterCard{
public:
    Sky_Striker_Ace_Roze():MonsterCard(1500,1500,4,1,"warrior"){
        Keyword+="SkyStriker";
    }
};

class Therion_King_Regulus : public MonsterCard{
public:
    Therion_King_Regulus():MonsterCard(2800,1600,8,3,"machine"){
        Keyword+="SkyStriker";
    }
};

class Therion_Bull_Ain : public MonsterCard{
public:
    Therion_Bull_Ain():MonsterCard(2100,1600,7,6,"warrior"){
        Keyword+="SkyStriker";
    }
};


class Sky_Striker_Ace_Zeke : public LinkMonster{
public:
    Sky_Striker_Ace_Zeke():LinkMonster(1500,2,"machine",2,Pressure(4,8)){
        Keyword+="SkyStriker";
    }
};

class  Sky_Striker_Ace_Azalea : public LinkMonster{
public:
    Sky_Striker_Ace_Azalea():LinkMonster(1500,2,"machine",2,Pressure(3,7)){
        Keyword += "SkyStriker";
    }
};

class Sky_Striker_Ace_Hayate : public LinkMonster{
public:
    Sky_Striker_Ace_Hayate():LinkMonster(1500,4,"machine",1,Pressure(5)){
        Keyword += "SkyStriker";
    }
};

class Sky_Striker_Ace_Kagari : public LinkMonster{
public:
    Sky_Striker_Ace_Kagari():LinkMonster(1500,6,"machine",1,Pressure(7)){
        Keyword+= "SkyStriker";
    }
};

class Sky_Striker_Ace_Kaina : public LinkMonster{
public:
    Sky_Striker_Ace_Kaina():LinkMonster(1500,3,"machine",1,Pressure(3)){
        Keyword += "SkyStriker";
    }
};

class Sky_Striker_Ace_Shizuku : public LinkMonster{
public:
    Sky_Striker_Ace_Shizuku():LinkMonster(1500,5,"machine",1,Pressure(1)){
        Keyword += "SkyStriker";
    }
};
