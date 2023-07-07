#include "humanbot.h"
#include "ui_humanbot.h"

HumanBot::HumanBot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HumanBot)
{
    ui->setupUi(this);
}

HumanBot::HumanBot(MainWindow *m) :
    QDialog(),
    ui(new Ui::HumanBot)
{
    ui->setupUi(this);
    mw = m;
}


HumanBot::~HumanBot()
{
    delete ui;
}

void HumanBot::on_pushButton_clicked()
{
    close();
    mw->show();
}

