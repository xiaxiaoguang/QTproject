#include "fightinterface.h"
#include "ui_fightinterface.h"
#include "monster_origin.h"
#include "cell.h"

#include<QString>

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

using std::vector;
using std::to_string;
using std::string;


void FightInterface::on_pushButton_57_clicked()
{
    scoreDemonstrate(0,0);
    Cell *a = new Cell();
    Borrelsword_Dragon b = Borrelsword_Dragon();
    a->source.push_back(&b);
    ui_send2Tomb(a);
}


void FightInterface::scoreDemonstrate(int a,int b){
    string be = "<div align=\"center\"><font color=\"red\">";
    string ed = "</font></div>";

    ui->BloodA->setText((be + to_string(a) + ed).data());
    ui->BloodB->setText((be + to_string(b)+ ed).data());
}

void FightInterface::ui_send2Tomb(Cell *a){
    string tmp = "border-image: url(";
    tmp += (*((a->source).rbegin()))->imagename;
    tmp += ") 0 0 0 0 stretch stretch;";
    cout<<tmp<<endl;
    if(a->belonger){
        ui->TombA->setStyleSheet(tmp.data());
    }else {
        ui->TombB->setStyleSheet(tmp.data());
    }
}


