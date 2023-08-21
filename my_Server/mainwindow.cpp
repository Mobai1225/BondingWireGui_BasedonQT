#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->port->setText("8899");
    ui->IP->setText("127.0.0.1");
    setWindowTitle("客户端");
    ui->disconnect->setDisabled(true);

    //创建监听的服务器对象
    m_tcp=new QTcpSocket(this);

    connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
            {
                QByteArray data=m_tcp->readAll();
                ui->record->append("服务器："+data);
            });

    connect(m_tcp,&QTcpSocket::disconnected,this,[=]()
            {
                m_tcp->close();
                m_status->setText("未连接");
                ui->record->append("已经成功断开了服务器..........");
                ui->connect->setDisabled(false);
                ui->disconnect->setDisabled(true);
            });

    connect(m_tcp,&QTcpSocket::connected,this,[=]()
            {
                m_status->setText("已连接");
                ui->record->append("已经成功连接到服务器..........");
                ui->connect->setDisabled(true);
                ui->disconnect->setDisabled(false);
            });

    //状态栏
    m_status=new QLabel(this);
    m_status->setText("未连接");
    ui->statusbar->addWidget(m_status);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//发送信息
void MainWindow::on_Button_send_clicked()
{
    QString msg=ui->send->toPlainText();
    m_tcp->write(msg.toUtf8());
    ui->record->append("客户端："+msg);
}

//连接服务器
void MainWindow::on_connect_clicked()
{
    QString ip=ui->IP->text();
    unsigned short port=ui->port->text().toUShort();
    m_tcp->connectToHost(QHostAddress(ip),port);
}


void MainWindow::on_disconnect_clicked()
{
    m_tcp->close();
    ui->connect->setDisabled(false);
    ui->disconnect->setDisabled(true);
}

