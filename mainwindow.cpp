#include "mainwindow.h"
#include "./ui_mainwindow.h"
<<<<<<< HEAD

#include<QMessageBox>


=======
#include "fightpre.h"
>>>>>>> 970e385 (测试0.0.0)
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
<<<<<<< HEAD
    setStyleSheet(
            "QPushButton{background-color:grey;color:black}\
             QPushButton::hover{color:black}");
=======
>>>>>>> 970e385 (测试0.0.0)
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


<<<<<<< HEAD
void MainWindow::on_HumanHumanButton_clicked()
{
    HHFIght = new Dialog();
    this->hide();
    HHFIght->show();
}


void MainWindow::on_HumanBotButton_clicked()
{

}


void MainWindow::on_Cardsetting_clicked()
{

}


void MainWindow::on_Videosetting_clicked()
{

}


void MainWindow::on_Gamesetting_clicked()
{

=======
void MainWindow::on_pushButton_5_clicked()
{
    fightpre *a = new fightpre;
    hide();
    a->show();
>>>>>>> 970e385 (测试0.0.0)
}

