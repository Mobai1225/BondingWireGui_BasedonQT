#ifndef DETECT_PCB_H
#define DETECT_PCB_H

#include <QObject>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QProcess>
#include"QGraphicsScene.h"
#include <QGraphicsPixmapItem>
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include"detect_single.h"
class detect_PCB : public QObject
{
    Q_OBJECT
public:
    explicit detect_PCB(QObject *parent = nullptr);
    void open_file(Ui::MainWindow *ui);
    void PCB_imgShow(Ui::MainWindow *ui);
    void detect_pcb(Ui::MainWindow *ui);
public:
    QString selectedFilePath;
signals:

};

#endif // DETECT_PCB_H
