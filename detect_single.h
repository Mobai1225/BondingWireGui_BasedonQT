#ifndef DETECT_SINGLE_H
#define DETECT_SINGLE_H

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
QString readTextFileLine(const QString& file_path, int line_number);
class detect_single : public QObject
{
    Q_OBJECT
public:
    explicit detect_single(QObject *parent = nullptr);
    void openFile(Ui::MainWindow *ui);
    void imshow_image(Ui::MainWindow *ui);
    void detect(Ui::MainWindow *ui);

public:
    QString selectedFilePath;
private:



signals:

};

#endif // DETECT_SINGLE_H
