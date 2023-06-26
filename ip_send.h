#ifndef IP_SEND_H
#define IP_SEND_H

#include <QObject>

class IP_send : public QObject
{
    Q_OBJECT
public:
    explicit IP_send(QObject *parent = nullptr);

signals:

};

#endif // IP_SEND_H
