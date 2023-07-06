#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fightpre.h"
#include "cardsetting.h"
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 将按钮的clicked信号与对应的槽函数连接
    connect(ui->MBpvp, &QPushButton::clicked, this, &MainWindow::on_MBpvp_clicked);
    connect(ui->MBpve, &QPushButton::clicked, this, &MainWindow::on_MBpve_clicked);
    connect(ui->MBcardsetting, &QPushButton::clicked, this, &MainWindow::on_MBcardsetting_clicked);
    connect(ui->MBreplay, &QPushButton::clicked, this, &MainWindow::on_MBreplay_clicked);
    connect(ui->MBsystemsettings, &QPushButton::clicked, this, &MainWindow::on_MBsystemsettings_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MBpvp_clicked()//双人对战按钮点击执行
{
    fightpre *a = new fightpre(this);
    hide();
    a->show();
}


void MainWindow::on_MBpve_clicked()//人机对战按钮点击执行
{

}


void MainWindow::on_MBcardsetting_clicked()//卡组配置界面按钮点击执行
{
    cardbank_configuration *a = new cardbank_configuration(this);
    hide();
    a->show();
}


void MainWindow::on_MBreplay_clicked()//回放按钮点击执行
{

}


void MainWindow::on_MBsystemsettings_clicked()//系统设置按钮点击执行
{

}

