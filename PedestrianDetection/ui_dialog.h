/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Dec 19 18:35:29 2012
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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QPushButton *btnImage;
    QPushButton *btnVideo;
    QPushButton *btnDetect;
    QLabel *label_4;
    QLabel *exTime;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(307, 104);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 288, 85));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 4);

        btnImage = new QPushButton(layoutWidget);
        btnImage->setObjectName(QString::fromUtf8("btnImage"));

        gridLayout->addWidget(btnImage, 1, 0, 1, 1);

        btnVideo = new QPushButton(layoutWidget);
        btnVideo->setObjectName(QString::fromUtf8("btnVideo"));

        gridLayout->addWidget(btnVideo, 1, 1, 1, 2);

        btnDetect = new QPushButton(layoutWidget);
        btnDetect->setObjectName(QString::fromUtf8("btnDetect"));

        gridLayout->addWidget(btnDetect, 1, 3, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 2);

        exTime = new QLabel(layoutWidget);
        exTime->setObjectName(QString::fromUtf8("exTime"));
        exTime->setFont(font);
        exTime->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(exTime, 2, 2, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Pedestrian Detection", 0, QApplication::UnicodeUTF8));
        btnImage->setText(QApplication::translate("Dialog", "Load Image", 0, QApplication::UnicodeUTF8));
        btnVideo->setText(QApplication::translate("Dialog", "Load Video", 0, QApplication::UnicodeUTF8));
        btnDetect->setText(QApplication::translate("Dialog", "Detect", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Time Execution", 0, QApplication::UnicodeUTF8));
        exTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
