#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <QObject>
#include <QDialog>
#include<QLabel>
#include<QVBoxLayout>
#include<QDebug>
class About_us : public QObject
{
    Q_OBJECT
public:
    explicit About_us(QObject *parent = nullptr);
    void AboutUs();
    void soft_update();
signals:

};

#endif // ABOUT_US_H
