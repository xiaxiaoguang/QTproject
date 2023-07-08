#include "systemsettings.h"
#include "ui_systemsettings.h"

systemsettings::systemsettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::systemsettings)
{
    ui->setupUi(this);
}

systemsettings::systemsettings(MainWindow * main) :
    QDialog(),
    ui(new Ui::systemsettings)
{
    ui->setupUi(this);
    mw = main;
}

systemsettings::~systemsettings()
{
    delete ui;
}

void systemsettings::on_pushButton_9_clicked()
{
    close();
    mw->show();
}

