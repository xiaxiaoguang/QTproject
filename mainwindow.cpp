#include "mainwindow.h"
#include "dialog.h"
#include "./ui_mainwindow.h"

#include<QMessageBox>
#include<QTimer>

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

void MainWindow::on_HumanHumanButton_clicked()
{
//    QMessageBox* msgBox = new QMessageBox();
//    msgBox->setText("敬请期待");
//    msgBox->show();
//    QTimer::singleShot(3000, msgBox, &QMessageBox::close);
    Dialog *a = new Dialog;
    this->hide();
    a->show();
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

