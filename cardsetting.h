#ifndef CARDBANK_CONFIGURATION_H
#define CARDBANK_CONFIGURATION_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class cardbank_configuration;
}

class cardbank_configuration : public QDialog
{
    Q_OBJECT

public:
    explicit cardbank_configuration(QWidget *parent = nullptr);
    cardbank_configuration(MainWindow *main);
    ~cardbank_configuration();

private:
    Ui::cardbank_configuration *ui;
    MainWindow *mw;
};

#endif // CARDBANK_CONFIGURATION_H
