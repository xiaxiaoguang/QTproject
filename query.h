#ifndef QUERY_H
#define QUERY_H

#include <QDialog>
#include "fightinterface.h"

namespace Ui {
class Query;
}

class Query : public QDialog
{
    Q_OBJECT

public:
    explicit Query(QWidget *parent = nullptr);
    Query(FightInterface * mw);
    ~Query();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Query *ui;
    FightInterface * mw;
};

#endif // QUERY_H
