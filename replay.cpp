#include "replay.h"
#include "ui_replay.h"

replay::replay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replay)
{
    ui->setupUi(this);
}

replay::replay(MainWindow * main) :
    QWidget(),
    ui(new Ui::replay)
{
    ui->setupUi(this);
    mw = main;
}

replay::~replay()
{
    delete ui;
}

void replay::on_pushButton_9_clicked()
{
    close();
    mw->show();
}

