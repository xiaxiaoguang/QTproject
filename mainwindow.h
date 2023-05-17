#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_HumanHumanButton_clicked();

    void on_HumanBotButton_clicked();

    void on_Cardsetting_clicked();

    void on_Videosetting_clicked();

    void on_Gamesetting_clicked();

private:
    Ui::MainWindow *ui;
    Dialog* HHFIght;
};
#endif // MAINWINDOW_H
