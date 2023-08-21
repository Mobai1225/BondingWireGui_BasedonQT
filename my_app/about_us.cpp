#include "about_us.h"

About_us::About_us(QObject *parent)
    : QObject{parent}
{

}

void About_us::AboutUs()
{
    //qDebug()<<"进入了关于我们";
    QDialog *dialog = new QDialog();
    dialog->resize(600, 400);
    QLabel *label = new QLabel("此软件采用3D视觉对键合引线进行缺陷检测", dialog);
    QLabel *label2 = new QLabel("软件版本：0.1", dialog);
    QLabel *label3 = new QLabel("创建日期：2023/06/13", dialog);
    QLabel *label4 = new QLabel("Designed by Li", dialog);

    QVBoxLayout *layout = new QVBoxLayout(dialog);//
    layout->addWidget(label);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(label4);
    dialog->setLayout(layout);

    dialog->setWindowTitle("关于我们");
    dialog->show();
}

void About_us::soft_update(){
    QDialog *dialog = new QDialog();
    dialog->resize(600, 200);
    QLabel *label = new QLabel("最新软件下载地址：https://github.com/Mobai1225", dialog);

    QVBoxLayout *layout = new QVBoxLayout(dialog);//
    layout->addWidget(label);
    dialog->setLayout(layout);

    dialog->setWindowTitle("软件更新");
    dialog->show();
}
