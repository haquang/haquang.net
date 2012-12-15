/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Sat Dec 15 15:22:25 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnCamera;
    QLabel *label;
    QPushButton *btnImage;
    QCheckBox *chkFaceDetectEnable;
    QCheckBox *chkEyeDetectEnable;
    QPushButton *btnClassifier;
    QPushButton *btnDetect;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(422, 134);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 402, 113));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnCamera = new QPushButton(widget);
        btnCamera->setObjectName(QString::fromUtf8("btnCamera"));

        gridLayout->addWidget(btnCamera, 1, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        btnImage = new QPushButton(widget);
        btnImage->setObjectName(QString::fromUtf8("btnImage"));

        gridLayout->addWidget(btnImage, 1, 1, 1, 1);

        chkFaceDetectEnable = new QCheckBox(widget);
        chkFaceDetectEnable->setObjectName(QString::fromUtf8("chkFaceDetectEnable"));

        gridLayout->addWidget(chkFaceDetectEnable, 2, 0, 1, 2);

        chkEyeDetectEnable = new QCheckBox(widget);
        chkEyeDetectEnable->setObjectName(QString::fromUtf8("chkEyeDetectEnable"));

        gridLayout->addWidget(chkEyeDetectEnable, 2, 2, 1, 2);

        btnClassifier = new QPushButton(widget);
        btnClassifier->setObjectName(QString::fromUtf8("btnClassifier"));

        gridLayout->addWidget(btnClassifier, 1, 0, 1, 1);

        btnDetect = new QPushButton(widget);
        btnDetect->setObjectName(QString::fromUtf8("btnDetect"));

        gridLayout->addWidget(btnDetect, 1, 3, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        btnCamera->setText(QApplication::translate("Dialog", "Camera", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Face And Eye Detection", 0, QApplication::UnicodeUTF8));
        btnImage->setText(QApplication::translate("Dialog", "Load Image", 0, QApplication::UnicodeUTF8));
        chkFaceDetectEnable->setText(QApplication::translate("Dialog", "Face Detect", 0, QApplication::UnicodeUTF8));
        chkEyeDetectEnable->setText(QApplication::translate("Dialog", "Eye Detect", 0, QApplication::UnicodeUTF8));
        btnClassifier->setText(QApplication::translate("Dialog", "Load Classifier", 0, QApplication::UnicodeUTF8));
        btnDetect->setText(QApplication::translate("Dialog", "Detect", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
