#-------------------------------------------------
#
# Project created by QtCreator 2012-12-18T15:04:11
#
#-------------------------------------------------

QT       += core gui

TARGET = PedestrianDetection
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui
INCLUDEPATH +=  /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_video -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann

