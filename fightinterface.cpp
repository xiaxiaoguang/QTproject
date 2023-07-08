#include "fightinterface.h"
#include "ui_fightinterface.h"
#include "monster_origin.h"
#include "cell.h"
#include "query.h"
#include <iostream>
#include <algorithm>
#include <QString>
#include <vector>
#include <random>
using namespace std;

FightInterface::FightInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightInterface)
{
    ui->setupUi(this);
}

FightInterface::FightInterface(MainWindow * main) :
    QWidget(),
    ui(new Ui::FightInterface)
{
    ui->setupUi(this);
    mw = main;
    pos[0]=ui->pB_0;
    pos[1]=ui->pB_1;
    pos[2]=ui->pB_2;
    pos[3]=ui->pB_3;
    pos[4]=ui->pB_4;
    pos[5]=ui->pB_5;
    pos[6]=ui->pB_6;
    pos[7]=ui->pB_7;
    pos[8]=ui->pB_8;
    pos[9]=ui->pB_9;
    pos[10]=ui->pB_10;
    pos[11]=ui->pB_11;
    pos[12]=ui->pB_12;
    pos[13]=ui->pB_13;
    pos[14]=ui->pB_14;
    pos[15]=ui->pB_15;
    pos[16]=ui->pB_16;
    pos[17]=ui->pB_17;
    pos[18]=ui->pB_18;
    pos[19]=ui->pB_19;
    pos[20]=ui->pB_20;
    pos[21]=ui->pB_21;
    pos[22]=ui->pB_22;
    pos[23]=ui->pB_23;
    pos[24]=ui->pB_24;
    pos[25]=ui->pB_25;
    pos[26]=ui->pB_26;
    pos[27]=ui->pB_27;
    pos[28]=ui->pB_28;
    pos[29]=ui->pB_29;
    pos[30]=ui->pB_30;
    pos[31]=ui->pB_31;
    pos[32]=ui->pB_32;
    pos[33]=ui->pB_33;
    pos[35]=ui->pB_35;
    pos[36]=ui->pB_36;
    pos[37]=ui->pB_37;
    pos[38]=ui->pB_38;
    pos[39]=ui->pB_39;
    pos[40]=ui->pB_40;
    pos[42]=ui->pB_42;
    pos[43]=ui->pB_43;
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

using std::vector;
using std::to_string;
using std::string;

void FightInterface::scoreDemonstrate(int a,int b){
    string be = "<div align=\"center\"><font color=\"red\">";
    string ed = "</font></div>";

    ui->BloodA->setText((be + to_string(a) + ed).data());
    ui->BloodB->setText((be + to_string(b)+ ed).data());
}

void FightInterface::ui_send2Tomb(Cell *a){
    string tmp = "border-image: url(";
    tmp += (*((a->source).rbegin()))->imagename;
    tmp += ") 0 0 0 0 stretch stretch;";
    if(a->belonger){
        ui->pB_7->setStyleSheet(tmp.data());
    }else {
        ui->pB_20->setStyleSheet(tmp.data());
    }
}


void FightInterface::on_pushButton_clicked()
    {
        state = (state + 1) % 5;
        if (state == 0) {
            obj ^= 1;
            if (obj == 0) {
                for (int i = 0 ; i < 6 ; ++ i) {
                    if (AHand[i].source.size() == 0) {
                        if (ACards.source.size() != 0) {
                            AHand[i].source.push_back(*ACards.source.begin());
                            ACards.source.erase(ACards.source.begin() , ACards.source.begin() + 1);
                            updateCell(AHand + i);
                        }
                        break;
                    }
                }
            }
            else {
                for (int i = 0 ; i < 6 ; ++ i) {
                    if (BHand[i].source.size() == 0) {
                        if (BCards.source.size() != 0) {
                            BHand[i].source.push_back(*BCards.source.begin());
                            BCards.source.erase(BCards.source.begin() , BCards.source.begin() + 1);
                            updateCell(BHand + i);
                        }
                        break;
                    }
                }
            }
        }
        QString str;
        if (obj == 0) str += "A:"; else str += "B:";
        if (state == 0) str += "准备阶段";
        if (state == 1) {str += "M1阶段";
            pickTime = 0;
        }
        if (state == 2) str += "BP阶段";
        if (state == 3) str += "M2阶段";
        if (state == 4) str += "结束阶段";
        ui->pushButton->setText(str);
        ui->pushButton->setFont(QFont("Arial", 10));
        ui->pushButton->setStyleSheet("QPushButton {text-align:center;}");
    }




void FightInterface::updateCell(Cell *a){
//    printf("%d %d\n",a->x,a->y);
    int rc = (a->x * 7 + a->y);
    if((a->source).empty()){
        pos[rc]->setStyleSheet("background-color: orange;");
        return ;
    }
//    printf("%d %d %d %d\n",a->x,a->y,(a->source).size(),(*((a->source).rbegin()))->getatk());
//    printf("%d %d\n %d\n",a->x,a->y ,(a->source).size());
    string tmp = "border-image: url(";
    tmp+=(*((a->source).rbegin()))->imagename;
    tmp+=") 0 0 0 0 stretch stretch;";
//    cout<<tmp<<endl;
    pos[rc]->setText("");
    pos[rc]->setStyleSheet(tmp.data());
}


void FightInterface::initialize()
{
    //初始化Cell的坐标。
    scoreA = scoreB = 8000;  gameRes = 0;
    scoreDemonstrate(8000,8000);
    for (int i = 0 ; i < 5 ; ++ i)
    {
        AMonsters[i].source.clear() ; AMonsters[i].source.clear() ; AMagic[i].source.clear() ; BMagic[i].source.clear();
        AMonsters[i].x = 1; AMonsters[i].y = i + 1; AMagic[i].x = 0; AMagic[i].y = i + 1;
        BMonsters[i].x = 2; BMonsters[i].y = i + 1; BMagic[i].x = 3; BMagic[i].y = i + 1;
    }
    for(int i = 0;i < 6;++ i) {
        AHand[i].x = 5;
        AHand[i].y = i;
        AHand[i].source.clear();
        BHand[i].x = 4;
        BHand[i].y = i;
        BHand[i].source.clear();
    }
    additional_1.x = additional_2.x = 6; additional_1.source.clear();
    additional_1.y = 0; additional_2.y = 1; additional_2.source.clear();
    AVenueMagic.x = 1; AVenueMagic.y = 6;
    BVenueMagic.x = 2; AVenueMagic.y = 0;
    ATomb.x = 1 ; ATomb.y = 0; ATomb.source.clear();
    BTomb.x = 2 ; BTomb.y = 6; BTomb.source.clear();
    AEx.x = 0 ; AEx.y = 6; AEx.source.clear();
    BEx.x = 3 ; BEx.y = 0; BEx.source.clear();
    ACards.x = 0; ACards.y = 0; ACards.source.clear();
    BCards.x = 3; BCards.y = 6; BCards.source.clear();

    Card * p;
    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Surgical_Striker_HAMP;
        ACards.source.push_back(p);
        p = new Surgical_Striker_HAMP;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 3 ; ++ i) {
        p = new Sage_of_Strength_Akash;
        ACards.source.push_back(p);
        p = new Sage_of_Strength_Akash;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 2 ; ++ i) {
        p = new Sage_of_Wisdom_Himmel;
        ACards.source.push_back(p);
        p = new Sage_of_Wisdom_Himmel;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 2 ; ++ i) {
        p = new Aileron;
        ACards.source.push_back(p);
        p = new Aileron;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 3 ; ++ i) {
        p = new Sky_Striker_Ace_Raye;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Raye;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Sky_Striker_Ace_Roze;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Roze;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Therion_King_Regulus;
        ACards.source.push_back(p);
        p = new Therion_King_Regulus;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new  I_P_Masquerena;
        ACards.source.push_back(p);
        p = new  I_P_Masquerena;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new  Underworld_Goddess_of_the_Closed_World;
        ACards.source.push_back(p);
        p = new  Underworld_Goddess_of_the_Closed_World;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 2 ; ++ i) {
        p = new Therion_Bull_Ain;
        ACards.source.push_back(p);
        p = new Therion_Bull_Ain;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Sky_Striker_Ace_Zeke;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Zeke;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Sky_Striker_Ace_Azalea;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Azalea;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Sky_Striker_Ace_Hayate;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Hayate;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 2 ; ++ i) {
        p = new Sky_Striker_Ace_Kagari;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Kagari;
        BCards.source.push_back(p);
    }


    for (int i = 0 ; i < 2 ; ++ i) {
        p = new Sky_Striker_Ace_Kaina;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Kaina;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Sky_Striker_Ace_Shizuku;
        ACards.source.push_back(p);
        p = new Sky_Striker_Ace_Shizuku;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new I_P_Masquerena;
        ACards.source.push_back(p);
        p = new I_P_Masquerena;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Decode_Talker;
        ACards.source.push_back(p);
        p = new Decode_Talker;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Topologic_Trisbaena;
        ACards.source.push_back(p);
        p = new Topologic_Trisbaena;
        BCards.source.push_back(p);
    }

    for (int i = 0 ; i < 1 ; ++ i) {
        p = new Borrelcode_Dragon;
        ACards.source.push_back(p);
        p = new Borrelcode_Dragon;
        BCards.source.push_back(p);
    }
//    printf("%d %d\n",BHand[0].x,BHand[0].y);
    //洗牌
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(ACards.source.begin() , ACards.source.end(),std::default_random_engine(seed));
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(BCards.source.begin() , BCards.source.end(),std::default_random_engine(seed));

    //分发手牌
    for (int i = 0 ; i < 5 ; ++ i) {
        AHand[i].source.push_back(ACards.source[i]);
        BHand[i].source.push_back(BCards.source[i]);

    }
    ACards.source.erase(ACards.source.begin() , ACards.source.begin() + 5);
    BCards.source.erase(BCards.source.begin() , BCards.source.begin() + 5);

    //显示cell
    for (int i = 0 ; i < 5 ; ++ i) {
        updateCell(AHand + i);
        updateCell(BHand + i);
        updateCell(AMonsters + i);
        updateCell(BMonsters + i);
        updateCell(AMagic + i);
        updateCell(BMagic + i);
    }
    updateCell(&ATomb);
    updateCell(&AEx);
    updateCell(&AVenueMagic);
    updateCell(&ACards);
    updateCell(&BTomb);
    updateCell(&BEx);
    updateCell(&BVenueMagic);
    updateCell(&BCards);
    updateCell(&additional_1);
    updateCell(&additional_2);

    state = 0; obj = 0; //即将进入A的准备阶段
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
    ui_send2Tomb(cell);
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

void FightInterface::detail(Card * a){
    if(a->imagename=="")return ;
    string tmp = "border-image: url(";
    tmp+=a->imagename;
    tmp+=") 0 0 0 0 stretch stretch;";
    ui->MainPic->setStyleSheet(tmp.data());
}

void FightInterface::on_pB_28_clicked()
{
    if((BHand[0].source).empty())return ;
    detail(*((BHand[0].source).rbegin()));
    if(obj==1 && (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();
        printf("%d %d %d %d !!\n",obj,state,pickTime,tmp);
            tmpCell.source.clear();
            tmpCell.source.push_back(*(BHand[0].source.rbegin()));
            rctmp[0]=&BHand[0];
    }
}

void FightInterface::on_pB_29_clicked()
{
    if((BHand[1].source).empty())return ;
    detail(*((BHand[1].source).rbegin()));
    if(obj==1 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();
            tmpCell.source.clear();
            tmpCell.source.push_back(*(BHand[1].source.rbegin()));
            rctmp[0]=&BHand[1];

    }
}

void FightInterface::on_pB_30_clicked()
{
    if((BHand[2].source).empty())return ;
    detail(*((BHand[2].source).rbegin()));
    if(obj==1 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();
            tmpCell.source.clear();
            tmpCell.source.push_back(*(BHand[2].source.rbegin()));
            rctmp[0]=&BHand[2];

    }
}

void FightInterface::on_pB_31_clicked()
{
    if((BHand[3].source).empty())return ;
    detail(*((BHand[3].source).rbegin()));
    if(obj==1 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();
            tmpCell.source.clear();
            tmpCell.source.push_back(*(BHand[3].source.rbegin()));
            rctmp[0]=&BHand[3];

    }
}

void FightInterface::on_pB_32_clicked()
{
    if((BHand[4].source).empty())return ;
    detail(*((BHand[4].source).rbegin()));
    if(obj==1 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();
            tmpCell.source.clear();
            tmpCell.source.push_back(*(BHand[4].source.rbegin()));
            rctmp[0]=&BHand[4];

    }
}

void FightInterface::on_pB_33_clicked()
{
    if((BHand[5].source).empty())return ;
    detail(*((BHand[5].source).rbegin()));
    if(obj==1 && (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();
            tmpCell.source.clear();
            tmpCell.source.push_back(*(BHand[5].source.rbegin()));
            rctmp[0]=&BHand[5];

    }
}


void FightInterface::commonspell(Cell * a,Cell * b){ //攻击表示的召唤
    b->source.push_back(*a->source.begin());
    a->source.clear();
    pickTime = 1;
    b->state = 1;
}

void FightInterface::on_pB_15_clicked()
{
    if(tmp!=0 && obj==1){
        if(tmp==1){
            commonspell(rctmp[0],&BMonsters[0]);
            updateCell(rctmp[0]);
            printf("%d %d %d\n",BMonsters[0].x,BMonsters[0].y,BMonsters[0].source.size());
            updateCell(&BMonsters[0]);
            tmp=0;
            return ;
        }
        else return ;
    }
    else {
        if(!BMonsters[0].source.empty())
            detail(*(BMonsters[0].source.rbegin()));
    }
}

void FightInterface::on_pB_16_clicked()
{
    if(tmp!=0 && obj==1){
        if(tmp==1){
            commonspell(rctmp[0],&BMonsters[1]);
            updateCell(rctmp[0]);
            updateCell(&BMonsters[1]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!BMonsters[1].source.empty())
            detail(*(BMonsters[1].source.rbegin()));
    }
}

void FightInterface::on_pB_17_clicked()
{
    if(tmp!=0 && obj==1){
        if(tmp==1){
            commonspell(rctmp[0],&BMonsters[2]);
            updateCell(rctmp[0]);
            updateCell(&BMonsters[2]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!BMonsters[2].source.empty())
            detail(*(BMonsters[2].source.rbegin()));
    }
}

void FightInterface::on_pB_18_clicked()
{
    if(tmp!=0 && obj==1){
        if(tmp==1){
            commonspell(rctmp[0],&BMonsters[3]);
            updateCell(rctmp[0]);
            updateCell(&BMonsters[3]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!BMonsters[3].source.empty())
            detail(*(BMonsters[3].source.rbegin()));
    }
}

void FightInterface::on_pB_19_clicked()
{
    if(tmp!=0 && obj==1){
        if(tmp==1){
            commonspell(rctmp[0],&BMonsters[4]);
            updateCell(rctmp[0]);
            updateCell(&BMonsters[4]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!BMonsters[4].source.empty())
            detail(*(BMonsters[4].source.rbegin()));
    }
}


void FightInterface::on_pB_35_clicked()
{
    if((AHand[0].source).empty())return ;
    detail(*((AHand[0].source).rbegin()));
    if(obj==0 && (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();

        tmpCell.source.clear();
        tmpCell.source.push_back(*(AHand[0].source.rbegin()));
        rctmp[0]=&AHand[0];
    }
}

void FightInterface::on_pB_36_clicked()
{
    if((AHand[1].source).empty())return ;
    detail(*((AHand[1].source).rbegin()));
    if(obj==0 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();

        tmpCell.source.clear();
        tmpCell.source.push_back(*(AHand[1].source.rbegin()));
        rctmp[0]=&AHand[1];
    }
}

void FightInterface::on_pB_37_clicked()
{
    if((AHand[2].source).empty())return ;
    detail(*((AHand[2].source).rbegin()));
    if(obj==0 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();

        tmpCell.source.clear();
        tmpCell.source.push_back(*(AHand[2].source.rbegin()));
        rctmp[0]=&AHand[2];

    }
}

void FightInterface::on_pB_38_clicked()
{
    if((AHand[3].source).empty())return ;
    detail(*((AHand[3].source).rbegin()));
    if(obj==0 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();

        tmpCell.source.clear();
        tmpCell.source.push_back(*(AHand[3].source.rbegin()));
        rctmp[0]=&AHand[3];

    }
}

void FightInterface::on_pB_39_clicked()
{
    if((AHand[4].source).empty())return ;
    detail(*((AHand[4].source).rbegin()));
    if(obj==0 &&  (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();

        tmpCell.source.clear();
        tmpCell.source.push_back(*(AHand[4].source.rbegin()));
        rctmp[0]=&AHand[4];

    }
}

void FightInterface::on_pB_40_clicked()
{
    if((AHand[5].source).empty())return ;
    detail(*((AHand[5].source).rbegin()));
    if(obj==0 && (state==1 || state == 3) && pickTime==0){
        Query * a = new Query(this);
        a->show();

        tmpCell.source.clear();
        tmpCell.source.push_back(*(AHand[5].source.rbegin()));
        rctmp[0]=&AHand[5];

    }
}


void FightInterface::on_pB_8_clicked()
{
    if(tmp!=0 && obj==0){
        if(tmp==1){
            commonspell(rctmp[0],&AMonsters[0]);
            updateCell(rctmp[0]);
            updateCell(&AMonsters[0]);
            tmp=0;
            return ;
        }
        else return ;
    }
    else {
        if(!AMonsters[0].source.empty())
            detail(*(AMonsters[0].source.rbegin()));
    }
}

void FightInterface::on_pB_9_clicked()
{
    if(tmp!=0 && obj== 0){
        if(tmp==1){
            commonspell(rctmp[0],&AMonsters[1]);
            updateCell(rctmp[0]);
            updateCell(&AMonsters[1]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!AMonsters[1].source.empty())
            detail(*(AMonsters[1].source.rbegin()));
    }
}

void FightInterface::on_pB_10_clicked()
{
    if(tmp!=0 && obj== 0){
        if(tmp==1){
            commonspell(rctmp[0],&AMonsters[2]);
            updateCell(rctmp[0]);
            updateCell(&AMonsters[2]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!AMonsters[2].source.empty())
            detail(*(AMonsters[2].source.rbegin()));
    }
}

void FightInterface::on_pB_11_clicked()
{
    if(tmp!=0 && obj== 0){
        if(tmp==1){
            commonspell(rctmp[0],&AMonsters[3]);
            updateCell(rctmp[0]);
            updateCell(&AMonsters[3]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!AMonsters[3].source.empty())
            detail(*(AMonsters[3].source.rbegin()));
    }
}

void FightInterface::on_pB_12_clicked()
{
    if(tmp!=0 && obj== 0){
        if(tmp==1){
            commonspell(rctmp[0],&AMonsters[4]);
            updateCell(rctmp[0]);
            updateCell(&AMonsters[4]);
            tmp=0;
        }
        else return ;
    }
    else {
        if(!AMonsters[4].source.empty())
            detail(*(AMonsters[4].source.rbegin()));
    }
}

