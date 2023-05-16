#include "mainwindow.h"
#include "dialog.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this,"aqwq","b");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::about(this,"cqaq","d");
}


void MainWindow::on_pushButton_2_clicked()
{
    Dialog sec;
    sec.setModal(true);
    sec.exec();

}

