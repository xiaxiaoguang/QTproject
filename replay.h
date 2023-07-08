#ifndef REPLAY_H
#define REPLAY_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class replay;
}

class replay : public QWidget
{
    Q_OBJECT


public:
    explicit replay(QWidget *parent = nullptr);
    explicit replay(MainWindow *main);
    ~replay();

private slots:
    void on_pushButton_9_clicked();

private:
    MainWindow *mw;
    Ui::replay *ui;
};

#endif // REPLAY_H
