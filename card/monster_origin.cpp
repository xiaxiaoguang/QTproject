#include "monster.h"

//光、暗、地、风、水、炎、神 7种属性

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

class Sky_Striker_Ace_Zeke : public LinkMonster{
public:
    Sky_Striker_Ace_Zeke():LinkMonster(1500,2,"machine",2,Pressure(3,7)){
        Keyword+="SkyStriker";
    }
};

int main(){

}