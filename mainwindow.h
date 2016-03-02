#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include "opencv.hpp"
#include <QPrintPreviewDialog>
#include "print.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    private slots:
        void on_actionQuit_triggered();

        void on_actionPrint_triggered();
        void printPreview(QPrinter* printer);

        void on_actionLoad_triggered();

        void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    cv::Mat image;
};

#endif // MAINWINDOW_H
