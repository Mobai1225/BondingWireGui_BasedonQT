#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>
#include <QTcpServer>   // TCP服务器类
#include <QTcpSocket>   // TCP套接字类
#include <QHostAddress> // 主机地址类
#include <QTcpSocket>
#include<QLabel>
#include "ui_mainwindow.h"
class TCP_client : public QObject
{
    Q_OBJECT
public:
    explicit TCP_client(QObject *parent = nullptr);
    void TcpClientInit(QMainWindow *MainWindow ,Ui::MainWindow *ui);
public slots:

    void on_setlisten_clicked(Ui::MainWindow *ui);
    void on_Button_send_clicked(Ui::MainWindow *ui);

signals:
public:
    QTcpServer *m_s;
    QTcpSocket *m_tcp;
};

#endif // TCP_CLIENT_H
