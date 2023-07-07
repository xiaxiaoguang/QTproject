#ifndef FIGHTINTERFACE_H
#define FIGHTINTERFACE_H

#include <QWidget>
#include "mainwindow.h"
#include "cell.h"

namespace Ui {
class FightInterface;
}

class FightInterface : public QWidget
{
    Q_OBJECT

public:
    explicit FightInterface(QWidget *parent = nullptr);
    explicit FightInterface(MainWindow *);
    ~FightInterface();

    void scoreDemonstrate(int a,int b);

    void ui_send2Tomb(Cell *qwq);

private slots:
    void on_backToMainButton_clicked();

    void on_pushButton_57_clicked();

private:
    Ui::FightInterface *ui;
    MainWindow *mw;
};

#endif // FIGHTINTERFACE_H
