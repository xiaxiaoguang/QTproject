#include "fightpre.h"
#include "ui_fightpre.h"
#include<QMessageBox>
#include "fightinterface.h"
#include "cardbank_preview.h"
inline void fightpre::connectButtons()
{
    for (int i = 1; i <= 5; ++i) {
        QString player1ButtonName = "Fpplayer1Deck" + QString::number(i);
        QString player2ButtonName = "Fpplayer2Deck" + QString::number(i);
        QString previewButtonName = "FppreviewDeck" + QString::number(i);

        QPushButton *player1Button = findChild<QPushButton *>(player1ButtonName);
        QPushButton *player2Button = findChild<QPushButton *>(player2ButtonName);
        QPushButton *previewButton = findChild<QPushButton *>(previewButtonName);

        if (player1Button && player2Button) {
            connect(player1Button, &QPushButton::clicked, this, &fightpre::onPlayer1ButtonClicked);
            connect(player2Button, &QPushButton::clicked, this, &fightpre::onPlayer2ButtonClicked);
            connect(previewButton, &QPushButton::clicked, this, &fightpre::onpreviewButtonClicked);
        }
    }
}

fightpre::fightpre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightpre)
{
    ui->setupUi(this);
    connectButtons();
}

fightpre::fightpre(MainWindow *main)
    : QDialog(),
    ui(new Ui::fightpre)
{
    ui->setupUi(this);
    mw = main;
    connectButtons();
}


fightpre::~fightpre()
{
    delete ui;
}

void fightpre::onPlayer1ButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        // 处理 player1 的按钮点击事件
        // 可以根据 button 的具体信息进行相应的操作
    }
}

void fightpre::onPlayer2ButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        // 处理 player2 的按钮点击事件
        // 可以根据 button 的具体信息进行相应的操作
    }
}

void fightpre::onpreviewButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        // 处理 preview 的按钮点击事件
        // 可以根据 button 的具体信息进行相应的操作
    }
}

void fightpre::on_startFightButton_clicked()
{
    FightInterface * a = new FightInterface(mw);
    close();
    a->show();
}


void fightpre::on_backToMain_clicked()
{
    close();
    mw->show();
}


void fightpre::on_FppreviewDeck1_clicked()
{
    cardbank_preview * a = new cardbank_preview();
    a->show();
}

