#include "cardsetting.h"
#include "ui_cardsetting.h"

cardbank_configuration::cardbank_configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardbank_configuration)
{
    ui->setupUi(this);
}

cardbank_configuration::cardbank_configuration(MainWindow *mainw) :
    QDialog(),
    ui(new Ui::cardbank_configuration)
{
    ui->setupUi(this);
    mw = mainw;
}


cardbank_configuration::~cardbank_configuration()
{
    delete ui;
}
