#include "fightpre.h"
#include "ui_fightpre.h"
#include<QMessageBox>
fightpre::fightpre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightpre)
{
    ui->setupUi(this);
}

fightpre::~fightpre()
{
    delete ui;
}

void fightpre::on_pushButton_4_clicked()
{
    QMessageBox::about(this,"Hint","Waiting for updating");
}

