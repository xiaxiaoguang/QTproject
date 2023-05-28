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
    explicit fightpre(QWidget *parent = nullptr);
    explicit fightpre(MainWindow *main);
    ~fightpre();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_startFightButton_clicked();

private:
    MainWindow *mw;
    Ui::fightpre *ui;
};

#endif // FIGHTPRE_H
