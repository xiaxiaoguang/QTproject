#ifndef HUMANBOT_H
#define HUMANBOT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class HumanBot;
}

class HumanBot : public QDialog
{
    Q_OBJECT

public:
    explicit HumanBot(QWidget *parent = nullptr);
    explicit HumanBot(MainWindow *qwq);
    ~HumanBot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HumanBot *ui;
    MainWindow *mw;
};

#endif // HUMANBOT_H
