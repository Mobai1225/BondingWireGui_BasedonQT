
#include "detect_single.h"

detect_single::detect_single(QObject *parent)
    : QObject{parent}
{

}
// 返回文本文件中第 N 行的数据
QString readTextFileLine(const QString& file_path, int line_number)
{
    QFile file(file_path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        in.setCodec("UTF-8");  // 指定编码方式为UTF-8
        QString line;
        int current_line_number = 0;

        while (!in.atEnd())
        {
            line = in.readLine();
            current_line_number++;

            if (current_line_number == line_number)
                break;
        }

        file.close();
        return line;
    }
    return QString();
}

void detect_single::openFile(Ui::MainWindow *ui)
{

    ui->stackedWidget->setCurrentIndex(1);
    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* currentWidget = stackedWidget->currentWidget();
    QTextBrowser* single_text2 = currentWidget->findChild<QTextBrowser*>("single_text2");
     single_text2->setText("打开文件...\n");
    // 打开文件选择对话框
    QString filePath = QFileDialog::getOpenFileName(nullptr, "选择文件");
    // 判断是否成功选择了文件
    if (!filePath.isEmpty()) {
        QFileInfo fileInfo(filePath);
        QString fileExtension = fileInfo.suffix();
        if(fileExtension == "pcd"){
            // 打印文件路径

            qDebug() << "选择的文件路径：" << filePath;
            this->selectedFilePath = filePath;


            QProcess process;
            //设置python解释器路径

            QString pythonScriptPath = "C:/Users/legion/Desktop/QT_lession/Python_file/single_show.py";

            QString message = filePath;
            // 构建命令行参数列表
            QStringList args;
            args << pythonScriptPath << message;

            // 启动 Python 脚本
            process.start("python", args);
            process.waitForFinished(-1); // 等待脚本执行完成
           single_text2->append("正在执行.Py文件...\n");
            single_text2->append("打开文件成功！\n");

            QByteArray output = process.readAllStandardOutput();
            QString result = QString::fromUtf8(output);

            // 打印 Python 脚本的输出
            qDebug() << "Python Script Output:" << result;

            imshow_image(ui);
        }
        else{
            single_text2->append("请打开正确的文件...");
            ui->graphicsView->scene()->clear();
        }
    }
}

void detect_single::imshow_image(Ui::MainWindow *ui){
    QString imagePath = "C:/Users/legion/Desktop/QT_lession/BondingWireImage/image.png";  // 指定图片文件的路径
    QImage image(imagePath);
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    // 设置图片的缩放尺寸
    pixmapItem->setScale(270.0 / pixmapItem->boundingRect().width());


    scene->addItem(pixmapItem);
    //QGraphicsView* gg = new QGraphicsView;

    ui->graphicsView->setScene(scene);

}
void detect_single::detect(Ui::MainWindow *ui){
    ui->stackedWidget->setCurrentIndex(1);
    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* currentWidget = stackedWidget->currentWidget();
    QTextBrowser* single_text1 = currentWidget->findChild<QTextBrowser*>("single_text1");
    QTextBrowser* single_text3 = currentWidget->findChild<QTextBrowser*>("single_text3");

    QString pythonScriptPath = "C:/Users/legion/Desktop/QT_lession/Python_file/single_detect.py";
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
    qDebug() << "Python Script Output:" << result;

    QString txt_content;

    txt_content=readTextFileLine(result,1);
    single_text1->setText(txt_content);

    txt_content=readTextFileLine(result,2);
    single_text3->setText(txt_content);
    txt_content=readTextFileLine(result,3);
    single_text3->append(txt_content);
}
