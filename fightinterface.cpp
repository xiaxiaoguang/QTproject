#include "fightinterface.h"
#include "ui_fightinterface.h"
#include <iostream>

#include "cardclass.h"
#include "cell.h"
#include "monster.h"
#include <iostream>
#include <algorithm>
#include "monster_origin.h"
#include <QVector>
#include <vector>

using namespace std;

void scoreDemonstrate(int scoreA ,int scoreB);
void cardPileDemonstrate(Cell *);
void ui_coverCard(Card * , Cell *); //把卡盖放在格子上
void ui_frontCard_fightState(Card * , Cell *); //攻击表示
void ui_frontCard_defenceState(Card * , Cell *); //攻击表示
void ui_send2Tomb(Cell *); //Cell里面有belonger

FightInterface::FightInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightInterface)
{
    ui->setupUi(this);

}

FightInterface::FightInterface(MainWindow * main) :
    QWidget(),
    ui(new Ui::FightInterface) , scoreA(8000) , scoreB(8000)
{
    ui->setupUi(this);
    mw = main;
}

FightInterface::~FightInterface()
{
    delete ui;
}


void FightInterface::on_backToMainButton_clicked()
{
    close();
    mw->show();
}

void FightInterface::initialize()
{
    //?显示
    scoreA = scoreB = 8000;
    for (int i = 0 ; i < 5 ; ++ i)
    {
        AMonsters[i].source.clear() ; BMonsters[i].source.clear() ; AMagic[i].source.clear() ; BMagic[i].source.clear();
        AMonsters[i].x = 2; AMonsters[i].y = i + 2; AMagic[i].x = 1; AMagic[i].y = i + 2;
        BMonsters[i].x = 4; BMonsters[i].y = i + 2; BMagic[i].x = 5; BMagic[i].y = i + 2;
    }
    additional_1.x = additional_2.x = 3; additional_1.source.clear();
    additional_1.y = 3; additional_2.y = 5; additional_2.source.clear();
    AVenueMagic.x = 2; AVenueMagic.y = 7;
    BVenueMagic.x = 4; AVenueMagic.y = 1;
    ATomb.x = 2 ; ATomb.y = 1; ATomb.source.clear();
    BTomb.x = 4 ; BTomb.y = 7; BTomb.source.clear();
    AEx.x = 1 ; AEx.y = 7; AEx.source.clear();
    BEx.x = 5 ; BEx.y = 1; BEx.source.clear();

    gameRes = 0; ACards.source.clear(); BCards.source.clear();

    //导入卡牌信息

    Card * p = new Surgical_Striker_HAMP[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sage_of_Strength_Akash[3];
    for (int i = 0 ; i < 3 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sage_of_Wisdom_Himmel[2];
    for (int i = 0 ; i < 2 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Aileron[2];
    for (int i = 0 ; i < 2 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Raye[3];
    for (int i = 0 ; i < 3 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Roze[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Therion_King_Regulus[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new  I_P_Masquerena[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new  Underworld_Goddess_of_the_Closed_World[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Therion_Bull_Ain[2];
    for (int i = 0 ; i < 2 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Zeke;
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Azalea;
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Hayate;
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Kagari[2];
    for (int i = 0 ; i < 2 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Kaina[2];
    for (int i = 0 ; i < 2 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Sky_Striker_Ace_Shizuku[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new I_P_Masquerena[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Decode_Talker[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Topologic_Trisbaena[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Borrelcode_Dragon[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Worldsea_Dragon_Zealantis[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    p = new Borrelsword_Dragon[1];
    for (int i = 0 ; i < 1 ; ++ i) {
        ACards.source.push_back(p+i);
        BCards.source.push_back(p+i);
    }
    //牌堆的效果？
    random_shuffle(ACards.source.begin() , ACards.source.end());
    random_shuffle(BCards.source.begin() , BCards.source.end());

    //分发手牌
    AHandCards.source.insert(AHandCards.source.begin() , ACards.source.begin() , ACards.source.begin() + 5);
    BHandCards.source.insert(BHandCards.source.begin() , BCards.source.begin() , BCards.source.begin() + 5);
    AHandCards.source.erase(AHandCards.source.begin() , AHandCards.source.begin() + 5);
    BHandCards.source.erase(BHandCards.source.begin() , BHandCards.source.begin() + 5);

    state = 1; obj = 0; //即将进入A的准备阶段

}
void FightInterface::clear(){
    //TODO
}
void FightInterface::send2Tomb(Cell * cell){ //必须确保不是能放多张牌的cell
    if (cell->belonger == 0) {
        ATomb.source.push_back(cell->source[0]);
        //墓地卡牌变化
    }
    else {
        BTomb.source.push_back(cell->source[0]);
        //墓地卡牌变化
    }
    cell->source.clear();
    //该地点卡牌变化
    //ui_send2Tomb(cell);
}
void FightInterface::printScores(){

}
int FightInterface::checkWins() // 用于战斗中的判断，看是否某人score <= 0。返回0表示未结束，返回1表示A胜利，返回B表示B胜利（如果胜利就输出相关信息）。
{
    if (scoreA <= 0 || gameRes == 2) {
        printf("B wins!\n");
        return 2;
    }
    if (scoreB <= 0 || gameRes == 1){
        printf("A wins!\n");
        return 1;
    }
    return 0;
}

void FightInterface::performAttack(Cell * _attacker , Cell * _defencer){
    int res; //用于表示战斗结果.1:A win,2:B win;0 : peace
    MonsterCard * attacker = (MonsterCard *)_attacker->source[0];
    MonsterCard * defencer = (MonsterCard *)_defencer->source[0];
    int va , vd; //比较的值。ATK , DEF中的一个
    va = attacker->ATK;
    if (_defencer->state == 1)
        vd = defencer->ATK ;
    else {
        vd = defencer->DEF;
        if (_defencer->state == 2) //盖放情况，把卡牌翻出来
        {
            _defencer->state = 1;
            //TODO 把卡牌翻出来
        }
    }
    if (va > vd) {
        res = 1;
        if (_defencer->state == 1) {
            if (_attacker->belonger == 0) scoreB -= va - vd;
            else scoreA -= va - vd;
            //TODO 显示分数改变
        }
        else {}//守备表示
        send2Tomb(_defencer);
    }
    if (va < vd) {
        res = 2;
        if (_attacker->belonger == 0) scoreA -= vd - va; else scoreB -= vd - va;
        send2Tomb(_attacker);
    }
    if (va == vd) res = 0;
    //TODO 显示分数改变
    //output the result
}

//以下几个阶段 obj均表示谁执行操作。 若obj = 0 , A操作； =1 ， B操作；
void FightInterface::prepare_stage(int obj){

}
void FightInterface::M1_stage(int obj){

}
void FightInterface::BP_stage(int obj){

}
void FightInterface::M2_state(int obj){

}
void FightInterface::EP_stage(int obj){

}
void FightInterface::simu() //主函数体
{

}
