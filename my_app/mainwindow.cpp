#include "mainwindow.h"

void my_print(){
    qDebug()<<"HELLO";
}
void MainWindow::main_imgShow(Ui::MainWindow *ui){
    QString imagePath = "C:\\Users\\legion\\Desktop\\QT_lession\\Python_file\\main_img\\main_img.png";  // 指定图片文件的路径
    QImage image(imagePath);
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    // 设置图片的缩放尺寸
    pixmapItem->setScale(471.0 / pixmapItem->boundingRect().width());


    scene->addItem(pixmapItem);

    ui->graphicsView_main->setScene(scene);
    qDebug()<<"main_imgshow";
}

MainWindow::MainWindow(QWidget *parent)    : QMainWindow(parent)    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //主页面显示ui
    this->main_imgShow(ui);

    //关于版本信息的连接/关于软件更新的连接
    connect(ui->version1,&QAction::triggered,abs1,&About_us::AboutUs);
    connect(ui->version_softupdate,&QAction::triggered,abs1,&About_us::soft_update);

    //退出按钮的使用、
    connect(ui->pb_close,&QPushButton::clicked,[=](){
        this->close();
    });

    //关于界面管理
    ui->stackedWidget->addWidget(ui->page0);
    ui->stackedWidget->addWidget(ui->page1);
    ui->stackedWidget->addWidget(ui->page2);
    ui->stackedWidget->addWidget(ui->page3);
    ui->stackedWidget->addWidget(ui->page4);

    //ui->stackedWidget_single->addWidget(ui->page_single_0);
    ui->stackedWidget_single->addWidget(ui->page_single_1);
    ui->stackedWidget_single->addWidget(ui->page_single_2);
    connect(ui->pb_main,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_single->setCurrentIndex(0);
        this->main_imgShow(ui);
    });
    connect(ui->pb_detectSingle,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_single->setCurrentIndex(1);

    });
    connect(ui->pb_PCB,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget_single->setCurrentIndex(2);
    });
    connect(ui->pb_IP,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->pb_help,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(4);
    });


    //关于single页面按钮的使用
    connect(ui->pb_single_file,&QPushButton::clicked,[=](){//打开文件页面
        d_s->openFile(ui);
    });
    connect(ui->pb_single_start,&QPushButton::clicked,[=](){//开始缺陷检测
        d_s->detect(ui);
    });

    //关于pcb页面按钮的使用
    connect(ui->pb_pcb_file,&QPushButton::clicked,[=](){
        d_p->open_file(ui);
    });
    connect(ui->pb_pcb_start,&QPushButton::clicked,[=](){
        d_p->detect_pcb(ui);
    });

    //关于客户端使用
    tp_c->TcpClientInit(this,ui);
    connect(ui->Client_setlisten,&QPushButton::clicked,[=](){
        tp_c->on_setlisten_clicked(ui);
    });
    connect(ui->Client_send_Button,&QPushButton::clicked,[=](){
        tp_c->on_Button_send_clicked(ui);
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}
Ui::MainWindow *MainWindow::getUi() const
{
    return ui;
}

