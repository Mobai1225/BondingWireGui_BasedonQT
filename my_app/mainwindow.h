#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include"about_us.h"
#include<QPushButton>
#include<QDebug>
#include <QStackedWidget>
#include "detect_single.h"
#include"detect_pcb.h"
#include"tcp_client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *getUi() const;
    void main_imgShow(Ui::MainWindow *ui);
private:
    Ui::MainWindow *ui;
    About_us * abs1 = new About_us;

    detect_single* d_s = new detect_single;

    detect_PCB* d_p = new detect_PCB;

    TCP_client* tp_c = new TCP_client;
};
#endif // MAINWINDOW_H
