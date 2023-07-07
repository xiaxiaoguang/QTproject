#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtMultimedia>

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
    void on_MBsystemsettings_clicked();

private slots:
    void on_MBreplay_clicked();

private slots:
    void on_MBcardsetting_clicked();

private slots:
    void on_MBpve_clicked();

private slots:
    void on_MBpvp_clicked();


private:
    Ui::MainWindow *ui;
//    QMediaPlayer *mp;

};
#endif // MAINWINDOW_H
