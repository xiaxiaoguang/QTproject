#include "mainwindow.h"
#include "dialog.h"
#include "./ui_mainwindow.h"

#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setStyleSheet(
            "QPushButton{background-color:grey;color:black}\
             QPushButton::hover{color:black}");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_toolButton_triggered(QAction *arg1)
{

}


void MainWindow::on_HumanHumanButton_clicked()
{

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

}

