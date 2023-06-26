#include "mainwindow.h"

#include <QApplication>
#include<QProcess>
#include<QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,400);
    w.show();


    return a.exec();
}


