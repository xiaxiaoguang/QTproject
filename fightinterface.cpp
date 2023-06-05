#include "fightinterface.h"
#include "ui_fightinterface.h"

FightInterface::FightInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightInterface)
{
    ui->setupUi(this);

}

FightInterface::FightInterface(MainWindow * main) :
    QWidget(),
    ui(new Ui::FightInterface)
{
    ui->setupUi(this);
    mw = main;
}

FightInterface::~FightInterface()
{
    delete ui;
}


void FightInterface::on_backToMainButton_clicked()
{
    close();
    mw->show();
}

