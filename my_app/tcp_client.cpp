#include "tcp_client.h"

TCP_client::TCP_client(QObject *parent)
    : QObject{parent}
{

}

void TCP_client::TcpClientInit(QMainWindow *MainWindow,Ui::MainWindow *ui){

    m_s=new QTcpServer(MainWindow);
    ui->port->setText("8899");
    connect(m_s,&QTcpServer::newConnection,this,[=]()
            {
                m_tcp=m_s->nextPendingConnection();

                //检查是否可以接收数据
                connect(m_tcp,&QTcpSocket::readyRead,this,[=]()
                        {
                            QByteArray data=m_tcp->readAll();
                            ui->Client_record->append("客户端："+data);
                        });

                //断开连接
                connect(m_tcp,&QTcpSocket::disconnected,this,[=]()
                        {
                            m_tcp->close();
                            m_tcp->deleteLater();
                        });

            });
}

//启动监听
void TCP_client::on_setlisten_clicked(Ui::MainWindow *ui)
{
    unsigned short port =ui->port->text().toUShort();
    m_s->listen(QHostAddress::Any,port);
    ui->Client_setlisten->setDisabled(true);
}

//发送信息
void TCP_client::on_Button_send_clicked(Ui::MainWindow *ui)
{
    QString msg=ui->Client_send->toPlainText();
    m_tcp->write(msg.toUtf8());
    ui->Client_record->append("客户端："+msg);
}

