#include "fightpre.h"
#include "ui_fightpre.h"
#include<QMessageBox>
#include "fightinterface.h"

fightpre::fightpre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightpre)
{
    ui->setupUi(this);
}

fightpre::fightpre(MainWindow *main)
    :QDialog(),
    ui(new Ui::fightpre)
{
    ui->setupUi(this);
    mw = main;
}

fightpre::~fightpre()
{
    delete ui;
}

void fightpre::on_pushButton_4_clicked()
{
    QMessageBox::about(this,"Hint","Waiting for updating");
}


void fightpre::on_pushButton_6_clicked()
{
    close();
    mw->show();
}


void fightpre::on_startFightButton_clicked()
{
    FightInterface * a = new FightInterface(mw);
    close();
    a->show();
}

