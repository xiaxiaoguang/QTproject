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


void FightInterface::on_pushButton_57_clicked()
{
    scoreDemonstrate(0,0);
}


using std::to_string;
using std::string;


void FightInterface::scoreDemonstrate(int a,int b){
    string be = "<div align=\"center\"><font color=\"red\">";
    string ed = "</font></div>";

    ui->label->setText((be + to_string(a) + ed).data());
    ui->label_2->setText((be + to_string(b)+ ed).data());
}


