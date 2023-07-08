#ifndef QWEQWE_H
#define QWEQWE_H

#include <QDialog>
#include "fightinterface.h"

namespace Ui {
class qweqwe;
}

class qweqwe : public QDialog
{
    Q_OBJECT

public:
    explicit qweqwe(QWidget *parent = nullptr);
    explicit qweqwe(FightInterface *);
    ~qweqwe();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::qweqwe *ui;
    FightInterface *mw;
};

#endif // QWEQWE_H
