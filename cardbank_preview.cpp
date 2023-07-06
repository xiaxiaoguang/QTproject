#include "cardbank_preview.h"
#include "ui_cardbank_preview.h"

cardbank_preview::cardbank_preview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardbank_preview)
{
    ui->setupUi(this);
}

cardbank_preview::~cardbank_preview()
{
    delete ui;
}

void cardbank_preview::on_pushButton_clicked()
{
    close();
}

