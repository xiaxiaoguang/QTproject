#ifndef FIGHTINTERFACE_H
#define FIGHTINTERFACE_H

#include <QWidget>
#include "mainwindow.h"
#include <QVector>
#include "cell.h"
#include "monster.h"
#include <vector>
using namespace  std;



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
    int gameRes; //游戏胜利情况。 0：未结束。 1：A胜利 ， 2：B胜利
    int scoreA , scoreB , cardNumA , cardNumB;
    vector <Card *> cardSummon; //所有场上卡的备份，用于析构函数删除
    Cell AMonsters[5] , BMonsters[5] , AMagic[5] , BMagic[5];
    Cell AVenueMagic , BVenueMagic; //场地魔法
    Cell ATomb , BTomb ,AHandCards , BHandCards; //墓地和手卡
    Cell AOut , BOut; //除外区
    Cell additional_1 , additional_2; //额外怪兽区
    Cell ACards , BCards; //卡组

    int state; int obj;
    //TODO 额外卡组

    void initialize();
    void clear();
    void send2Tomb(Cell *);
    void printScores();
    int checkWins(); // 用于战斗中的判断，看是否某人score <= 0。返回0表示未结束，返回1表示A胜利，返回B表示B胜利（如果胜利就输出相关信息）。
    void printHandCards(int obj);
    void performAttack(Cell * attacker , Cell * defencer);
    //以下几个阶段 obj均表示谁执行操作。 若obj = 0 , A操作； =1 ， B操作；
    void prepare_stage(int obj);
    void M1_stage(int obj);
    void BP_stage(int obj);
    void M2_state(int obj);
    void EP_stage(int obj);
    //

    void simu(); //主函数体
private slots:
    void on_backToMainButton_clicked();

private:
    Ui::FightInterface *ui;
    MainWindow *mw;
};

#endif // FIGHTINTERFACE_H
