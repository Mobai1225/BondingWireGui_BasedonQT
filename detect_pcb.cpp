#include "detect_pcb.h"

detect_PCB::detect_PCB(QObject *parent)
    : QObject{parent}
{

}
//QString readTextFileLine(const QString& file_path, int line_number)
//{
//    QFile file(file_path);
//    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        QTextStream in(&file);
//        in.setCodec("UTF-8");  // 指定编码方式为UTF-8
//        QString line;
//        int current_line_number = 0;

//        while (!in.atEnd())
//        {
//            line = in.readLine();
//            current_line_number++;

//            if (current_line_number == line_number)
//                break;
//        }

//        file.close();
//        return line;
//    }

//    return QString();
//}
void detect_PCB::open_file(Ui::MainWindow *ui){
    ui->stackedWidget->setCurrentIndex(2);
    QString filePath = QFileDialog::getOpenFileName(nullptr, "选择文件");

    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* currentWidget = stackedWidget->currentWidget();
    QTextBrowser* pcb_textTS = currentWidget->findChild<QTextBrowser*>("textBrowser_8");
    pcb_textTS->setText("打开文件...\n");

    if (!filePath.isEmpty()) {
        QFileInfo fileInfo(filePath);
        QString fileExtension = fileInfo.suffix();
        if(fileExtension == "pcd"){
            pcb_textTS->setText("打开文件成功！");


            this->selectedFilePath = filePath;
            QProcess process;
            //设置python解释器路径

            QString pythonScriptPath = "C:/Users/legion/Desktop/QT_lession/Python_file/pcb_show.py";  //更换文件

            QString message = filePath;
            // 构建命令行参数列表
            QStringList args;
            args << pythonScriptPath << message;

            // 启动 Python 脚本
            process.start("python", args);
            process.waitForFinished(-1); // 等待脚本执行完成
            //pcb_textTS->append("正在执行.Py文件...\n");
            pcb_textTS->setText("打开文件成功！\n");

            QByteArray output = process.readAllStandardOutput();
            QString result = QString::fromUtf8(output);

            // 打印 Python 脚本的输出
            qDebug() << "Python Script Output:" << result;
            PCB_imgShow(ui);


        }
        else{
            pcb_textTS->setText("请打开以.pcd结尾的文件");
        }
    }
}
void detect_PCB::PCB_imgShow(Ui::MainWindow *ui){
    QString imagePath = "C:/Users/legion/Desktop/QT_lession/BondingWireImage/image_pcb.png";  // 指定图片文件的路径
    QImage image(imagePath);
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    // 设置图片的缩放尺寸
    pixmapItem->setScale(301.0 / pixmapItem->boundingRect().width());


    scene->addItem(pixmapItem);
    //QGraphicsView* gg = new QGraphicsView;

    ui->graphicsView_2->setScene(scene);

}
void detect_PCB::detect_pcb(Ui::MainWindow *ui){
    ui->stackedWidget->setCurrentIndex(2);
    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* currentWidget = stackedWidget->currentWidget();
    QTextBrowser* pcb_text1 = currentWidget->findChild<QTextBrowser*>("textBrowser_1");
    QTextBrowser* pcb_text2 = currentWidget->findChild<QTextBrowser*>("textBrowser_2");
    QTextBrowser* pcb_text3 = currentWidget->findChild<QTextBrowser*>("textBrowser_3");
    QTextBrowser* pcb_text4 = currentWidget->findChild<QTextBrowser*>("textBrowser_4");
    QTextBrowser* pcb_text5 = currentWidget->findChild<QTextBrowser*>("textBrowser_5");
    QTextBrowser* pcb_text6 = currentWidget->findChild<QTextBrowser*>("textBrowser_6");
    QTextBrowser* pcb_text7 = currentWidget->findChild<QTextBrowser*>("textBrowser_7");

    QString pythonScriptPath = "C:/Users/legion/Desktop/QT_lession/Python_file/pcb_detect.py";
    QProcess process;
    QString message = this->selectedFilePath;
    // 构建命令行参数列表
    QStringList args;
    args << pythonScriptPath << message;
    process.start("python", args);
    process.waitForFinished(-1); // 等待脚本执行完成
    QByteArray output = process.readAllStandardOutput();
    QString result = QString::fromUtf8(output);
    result=result.trimmed();

    QString txt_content;
    txt_content=readTextFileLine(result,1);
    qDebug()<<txt_content;
    pcb_text1->setText(txt_content);

    txt_content=readTextFileLine(result,2);
    pcb_text2->setText(txt_content);
    txt_content=readTextFileLine(result,3);
    pcb_text3->setText(txt_content);
    txt_content=readTextFileLine(result,4);
    pcb_text4->setText(txt_content);
    txt_content=readTextFileLine(result,5);
    pcb_text5->setText(txt_content);
    txt_content=readTextFileLine(result,6);
    pcb_text6->setText(txt_content);
    txt_content=readTextFileLine(result,7);
    pcb_text7->setText(txt_content);
}
