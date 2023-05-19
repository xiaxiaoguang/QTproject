#ifndef FIGHTPRE_H
#define FIGHTPRE_H

#include <QDialog>

namespace Ui {
class fightpre;
}

class fightpre : public QDialog
{
    Q_OBJECT

public:
    explicit fightpre(QWidget *parent = nullptr);
    ~fightpre();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::fightpre *ui;
};

#endif // FIGHTPRE_H
