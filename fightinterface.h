#ifndef FIGHTINTERFACE_H
#define FIGHTINTERFACE_H

#include <QWidget>
#include <algorithm>
#include <QPushButton>

#include "mainwindow.h"
#include "cell.h"


namespace Ui {
class FightInterface;
}

class FightInterface : public QWidget
{
    Q_OBJECT

public:
    explicit FightInterface(QWidget *parent = nullptr);
    explicit FightInterface(MainWindow *);
    ~FightInterface();

    void scoreDemonstrate(int a,int b);
    void ui_send2Tomb(Cell *qwq);

    int tmp;
    Cell tmpCell;
    Cell* rctmp[2];

    int gameRes; //游戏胜利情况。 0：未结束。 1：A胜利 ， 2：B胜利
    int scoreA , scoreB , cardNumA , cardNumB;
    vector <Card *> cardSummon; //所有场上卡的备份，用于析构函数删除
    Cell AMonsters[5] , BMonsters[5] , AMagic[5] , BMagic[5];
    Cell AVenueMagic , BVenueMagic; //场地魔法
    Cell ATomb , BTomb ,AHandCards , BHandCards; //墓地和手卡
    Cell AHand[6],BHand[6];
    Cell AEx , BEx; //额外卡组
    Cell additional_1 , additional_2; //额外怪兽区
    Cell ACards , BCards; //卡组
    int state;
    int obj;
    int pickTime;
    //TODO 额外卡组

    void initialize();
    void clear();
    void send2Tomb(Cell *);
    void detail(Card *);
    void printScores();
    void updateCell(Cell *);
    int checkWins();
    void commonspell(Cell *,Cell *);
    // 用于战斗中的判断，看是否某人score <= 0。返回0表示未结束，返回1表示A胜利，返回B表示B胜利（如果胜利就输出相关信息）。
    void performAttack(Cell * attacker , Cell * defencer);
    //以下几个阶段 obj均表示谁执行操作。 若obj = 0 , A操作； =1 ， B操作
    void prepare_stage(int obj);
    void M1_stage(int obj);
    void BP_stage(int obj);
    void M2_state(int obj);
    void EP_stage(int obj);
    void simu(); //主函数体

private slots:
    void on_backToMainButton_clicked();

    void on_pB_28_clicked();
    void on_pB_29_clicked();
    void on_pB_30_clicked();
    void on_pB_31_clicked();
    void on_pB_32_clicked();
    void on_pB_33_clicked();

    void on_pB_15_clicked();
    void on_pB_16_clicked();
    void on_pB_17_clicked();
    void on_pB_18_clicked();
    void on_pB_19_clicked();

    void on_pB_8_clicked();
    void on_pB_9_clicked();
    void on_pB_10_clicked();
    void on_pB_11_clicked();
    void on_pB_12_clicked();

    void on_pB_35_clicked();
    void on_pB_36_clicked();
    void on_pB_37_clicked();
    void on_pB_38_clicked();
    void on_pB_39_clicked();
    void on_pB_40_clicked();

    void on_pushButton_clicked();

private:
    Ui::FightInterface *ui;
    MainWindow *mw;
    QPushButton *pos[100];
};

#endif // FIGHTINTERFACE_H
