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
    scoreA = scoreB = 8000;
    //#显示

    gameRes = 0; ACards.source.clear(); BCards.source.clear();
    printf("initialize. Please input card info.\n");
    //TODO 导入卡牌信息
/*
    Card * p = new Surgical_Striker_HAMP[1];

    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Sage_of_Strength_Akash[3];
    ACards.source.insert(ACards.source.end(), p , p + 3);
    BCards.source.insert(ACards.source.end(), p , p + 3);
    p = new Sage_of_Wisdom_Himmel[2];
    ACards.source.insert(ACards.source.end(), p , p + 2);
    BCards.source.insert(ACards.source.end(), p , p + 2);
    p = new Aileron[2];
    ACards.source.insert(ACards.source.end(), p , p + 2);
    BCards.source.insert(ACards.source.end(), p , p + 2);
    p = new Sky_Striker_Ace_Raye[3];
    ACards.source.insert(ACards.source.end(), p , p + 3);
    BCards.source.insert(ACards.source.end(), p , p + 3);
    p = new Sky_Striker_Ace_Roze[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Therion_King_Regulus[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new  I_P_Masquerena[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new  Underworld_Goddess_of_the_Closed_World[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Therion_Bull_Ain[2];
    ACards.source.insert(ACards.source.end(), p , p + 2);
    BCards.source.insert(ACards.source.end(), p , p + 2);
    p = new Sky_Striker_Ace_Zeke;
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Sky_Striker_Ace_Azalea;
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Sky_Striker_Ace_Hayate;
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Sky_Striker_Ace_Kagari[2];
    ACards.source.insert(ACards.source.end(), p , p + 2);
    BCards.source.insert(ACards.source.end(), p , p + 2);
    p = new Sky_Striker_Ace_Kaina[2];
    ACards.source.insert(ACards.source.end(), p , p + 2);
    BCards.source.insert(ACards.source.end(), p , p + 2);
    p = new Sky_Striker_Ace_Shizuku[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new I_P_Masquerena[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Decode_Talker[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Topologic_Trisbaena[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Borrelcode_Dragon[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Worldsea_Dragon_Zealantis[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    p = new Borrelsword_Dragon[1];
    ACards.source.insert(ACards.source.end(), p , p + 1);
    BCards.source.insert(ACards.source.end(), p , p + 1);
    //牌堆的效果？
    random_shuffle(ACards.source.begin() , ACards.source.end());
    random_shuffle(BCards.source.begin() , BCards.source.end());
    //分发手牌
    AHandCards.source.insert(AHandCards.source.begin() , ACards.source.begin() , ACards.source.begin() + 5);
    BHandCards.source.insert(BHandCards.source.begin() , BCards.source.begin() , BCards.source.begin() + 5);
    AHandCards.source.erase(AHandCards.source.begin() , AHandCards.source.begin() + 5);
    BHandCards.source.erase(BHandCards.source.begin() , BHandCards.source.begin() + 5);
    //?手牌的效果
*/
    //QVector<int> v = {1, 2, 3};
    //QVector<int> toInsert = {4, 5, 6};
    //copy(toInsert.begin(), toInsert.end(), v.begin() + 1);
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
void FightInterface::printHandCards(int obj){

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
