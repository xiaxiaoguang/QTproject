#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "dialog.h"

=======
>>>>>>> 970e385 (测试0.0.0)

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

<<<<<<< HEAD

private slots:
    void on_HumanHumanButton_clicked();

    void on_HumanBotButton_clicked();

    void on_Cardsetting_clicked();

    void on_Videosetting_clicked();

    void on_Gamesetting_clicked();

private:
    Ui::MainWindow *ui;
    Dialog* HHFIght;
=======
private slots:
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
>>>>>>> 970e385 (测试0.0.0)
};
#endif // MAINWINDOW_H
