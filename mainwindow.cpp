#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionPrint_triggered()
{
    if(!image.empty())
    {
        QPrinter printer(QPrinter::HighResolution);
        //printer.setOutputFileName("print.ps");
        printer.setOutputFormat(QPrinter::NativeFormat);
        QPrintPreviewDialog preview(&printer, this);
        preview.setWindowFlags(Qt::Window);
        connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));
        if(preview.exec() != QDialog::Accepted)
            return;
    }
}

void MainWindow::printPreview(QPrinter *printer)
{
    QPainter *painter = new QPainter(printer);
    QImage pImg = QImage(image.data, image.size().width, image.size().height, image.step, QImage::Format_RGB888).rgbSwapped();
    pImg = pImg.scaled(printer->pageRect().width(),printer->pageRect().height(), Qt::KeepAspectRatio);
    painter->drawImage(0, 0, pImg);
    painter->end();
}

void MainWindow::on_actionLoad_triggered()
{
    cv::Mat temp;
    QString name = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                "/home",
                                                tr("Images (*.jpg)"));
    temp = cv::imread(name.toStdString().c_str(),cv::IMREAD_COLOR);
    if(temp.empty())
        return;
    image = temp.clone();
}

void MainWindow::on_pushButton_clicked()
{
    Print(image);
}
