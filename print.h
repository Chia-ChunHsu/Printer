#ifndef PRINT
#define PRINT
#include "opencv.hpp"
#include <QPrinter>
#include <QPainter>
#endif // PRINT
void PrintOne(QPrinter* printer,cv::Mat mat);
void Print(cv::Mat mat); //Print(the image you want to print);
