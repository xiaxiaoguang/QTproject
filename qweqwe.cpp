#include "qweqwe.h"
#include "ui_qweqwe.h"

qweqwe::qweqwe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qweqwe)
{
    ui->setupUi(this);
}

qweqwe::qweqwe(FightInterface *p) :
    QDialog(),
    ui(new Ui::qweqwe)
{
    ui->setupUi(this);
    mw = p;
}

qweqwe::~qweqwe()
{
    delete ui;
}

void qweqwe::on_pushButton_3_clicked()
{
    close();
}


void qweqwe::on_pushButton_2_clicked()
{
    close();
}

