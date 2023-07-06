#include "fightinterface.h"
#include "ui_fightinterface.h"
#include <iostream>
#include "fightinterface.h"
#include "cardclass.h"
#include "cell.h"
#include "monster.h"
#include <iostream>

using namespace std;

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
    gameRes = 0;
    printf("initialize. Please input card info.\n");
    //TODO 导入卡牌信息

}
void FightInterface::clear(){
    //TODO
}
void FightInterface::send2Tomb(Cell * cell){ //必须确保不是能放多张牌的cell
    if (cell->belonger == 0) {
        ATomb.source.push_back(cell->source[0]);
    }
    else {
        BTomb.source.push_back(cell->source[0]);
    }
    cell->source.clear();
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
