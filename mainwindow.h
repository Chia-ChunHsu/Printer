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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void PrintOne(cv::Mat mat);


    private slots:
        void on_actionQuit_triggered();

        void on_actionPrint_triggered();
        void printPreview(QPrinter* printer);

        void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
    cv::Mat image;
};

#endif // MAINWINDOW_H
