#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class systemsettings;
}

class systemsettings : public QDialog
{
    Q_OBJECT

public:
    explicit systemsettings(QWidget *parent = nullptr);
    explicit systemsettings(MainWindow *main);
    ~systemsettings();

private slots:
    void on_pushButton_9_clicked();

private:
    MainWindow *mw;
    Ui::systemsettings *ui;
};

#endif // SYSTEMSETTINGS_H
