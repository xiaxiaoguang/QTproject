#ifndef FIGHTPRE_H
#define FIGHTPRE_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class fightpre;
}

class fightpre : public QDialog
{
    Q_OBJECT

public:
    inline void connectButtons();
    explicit fightpre(QWidget *parent = nullptr);
    explicit fightpre(MainWindow *main);
    ~fightpre();

private slots:
    void on_pushButton_4_clicked();
    void backToMain();
    void onPlayer1ButtonClicked();
    void onPlayer2ButtonClicked();
    void onpreviewButtonClicked();
    void on_startFightButton_clicked();

private:
    MainWindow *mw;
    Ui::fightpre *ui;
};

#endif // FIGHTPRE_H
