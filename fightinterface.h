#ifndef FIGHTINTERFACE_H
#define FIGHTINTERFACE_H

#include <QWidget>
#include "mainwindow.h"

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

private slots:
    void on_backToMainButton_clicked();

    void on_pushButton_57_clicked();

private:
    Ui::FightInterface *ui;
    MainWindow *mw;
};

#endif // FIGHTINTERFACE_H
