#include "print.h"
//=======================================
void Print(cv::Mat mat)//You Just Need To call This Function;
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setPaperSize(QPrinter::A4);
    PrintOne(&printer,mat);
}

void PrintOne(QPrinter* printer,cv::Mat mat)
{
    if(!mat.empty())
    {
        QPainter *painter = new QPainter(printer);
        QImage pImg = QImage(mat.data, mat.size().width, mat.size().height, mat.step, QImage::Format_RGB888).rgbSwapped();
        pImg = pImg.scaled(printer->pageRect().width(),printer->pageRect().height(), Qt::KeepAspectRatio);
        painter->begin(printer);
        painter->drawImage(0, 0, pImg);
        painter->end();
    }
}

//================
