#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fightpre.h"
#include "cardsetting.h"
#include "humanbot.h"
#include "replay.h"
#include<QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    mp = new QMediaPlayer;
//    mp->setMedia(":/sound/summer-walk-152722.mp3");
//    mp->setVolumn(50);
//    mp->play();
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete mp;
}


void MainWindow::on_MBpvp_clicked()//双人对战按钮点击执行
{
    fightpre *a = new fightpre(this);
    hide();
    a->show();
}


void MainWindow::on_MBpve_clicked()//人机对战按钮点击执行
{
    HumanBot *a = new HumanBot (this);
    hide();
    a->show();
}


void MainWindow::on_MBcardsetting_clicked()//卡组配置界面按钮点击执行
{
    cardbank_configuration *a = new cardbank_configuration(this);
    hide();
    a->show();
}


void MainWindow::on_MBreplay_clicked()//回放按钮点击执行
{
    replay *a = new replay(this);
    hide();
    a->show();
}

void MainWindow::on_MBsystemsettings_clicked()//系统设置按钮点击执行
{
    HumanBot *a = new HumanBot (this);
    hide();
    a->show();
}

