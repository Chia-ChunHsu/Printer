#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T23:15:15
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = printer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        print.cpp

HEADERS  += mainwindow.h \
        print.h

FORMS    += mainwindow.ui
INCLUDEPATH += $$quote(D:\opencv 2.4.9.1\include)\
               $$quote(D:\opencv 2.4.9.1\include\opencv2)

OPENCVLIB += $$quote(D:\opencv 2.4.9.1\x64\vc12\lib)

CONFIG(debug, debug|release){
LIBS+= $$OPENCVLIB/opencv_core249d.lib\
       $$OPENCVLIB/opencv_highgui249d.lib\
       $$OPENCVLIB/opencv_features2d249d.lib\
       $$OPENCVLIB/opencv_flann249d.lib\
       $$OPENCVLIB/opencv_nonfree249d.lib\
       $$OPENCVLIB/opencv_imgproc249d.lib\
       $$OPENCVLIB/opencv_ocl249d.lib\
       $$OPENCVLIB/opencv_stitching249d.lib\
       $$OPENCVLIB/opencv_ml249d.lib

}

CONFIG(release, debug|release){
LIBS+= $$OPENCVLIB/opencv_core249.lib\
       $$OPENCVLIB/opencv_highgui249.lib\
       $$OPENCVLIB/opencv_features2d249.lib\
       $$OPENCVLIB/opencv_flann249.lib\
       $$OPENCVLIB/opencv_nonfree249.lib\
       $$OPENCVLIB/opencv_imgproc249.lib\
       $$OPENCVLIB/opencv_ocl249.lib\
       $$OPENCVLIB/opencv_stitching249.lib\
       $$OPENCVLIB/opencv_ml249.lib\

}

DEFINES += HAVE_OPENCV
