#include "query.h"
#include "ui_query.h"
#include "fightinterface.h"

Query::Query(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Query)
{
    ui->setupUi(this);
}

Query::Query(FightInterface *qwq) :
    QDialog(),
    ui(new Ui::Query)
{
    ui->setupUi(this);
    mw = qwq;
}

Query::~Query()
{
    delete ui;
}

void Query::on_pushButton_3_clicked()
{
    mw->tmp=0;
    close();

}


void Query::on_pushButton_clicked()
{
    mw->tmp=1;
    close();
}


void Query::on_pushButton_2_clicked()
{
    mw->tmp=2;
    close();
}

