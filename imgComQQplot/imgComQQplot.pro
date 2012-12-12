#-------------------------------------------------
#
# Project created by QtCreator 2012-12-02T13:24:47
#
#-------------------------------------------------

QT       += core gui

TARGET = imgComQQplot
TEMPLATE = app


SOURCES += main.cpp\
        imgcomqqplot.cpp \
        qcustomplot.cpp

HEADERS  += imgcomqqplot.h \
    qcustomplot.h

FORMS    += imgcomqqplot.ui

INCLUDEPATH +=  /usr/include/opencv-2.3.1
LIBS += -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_contrib -lopencv_legacy -lopencv_flann -lopencv_ml -lopencv_video -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_imgproc -lopencv_highgui

