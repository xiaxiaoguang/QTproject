#include "cardsetting.h"
#include "ui_cardsetting.h"

cardbank_configuration::cardbank_configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardbank_configuration)
{
    ui->setupUi(this);
}

cardbank_configuration::~cardbank_configuration()
{
    delete ui;
}
