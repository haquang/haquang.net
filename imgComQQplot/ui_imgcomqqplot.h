/********************************************************************************
** Form generated from reading UI file 'imgcomqqplot.ui'
**
** Created: Sun Dec 9 17:42:10 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGCOMQQPLOT_H
#define UI_IMGCOMQQPLOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_imgComQQplot
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonHist;
    QPushButton *pushButtonQqPlot;
    QLabel *lblTempl;
    QLabel *lblSample;
    QTableWidget *tblTplImg;
    QTableWidget *tblDefImg;
    QCheckBox *chkCor;
    QCheckBox *chkPval;
    QLabel *label_2;
    QLineEdit *lineEditStep;
    QLabel *label;
    QLineEdit *lineEditSimilarValue;
    QCustomPlot *customPlot;

    void setupUi(QDialog *imgComQQplot)
    {
        if (imgComQQplot->objectName().isEmpty())
            imgComQQplot->setObjectName(QString::fromUtf8("imgComQQplot"));
        imgComQQplot->resize(1009, 569);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(imgComQQplot->sizePolicy().hasHeightForWidth());
        imgComQQplot->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(imgComQQplot);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 10, 991, 344));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonLoad = new QPushButton(layoutWidget);
        pushButtonLoad->setObjectName(QString::fromUtf8("pushButtonLoad"));

        gridLayout->addWidget(pushButtonLoad, 0, 0, 1, 1);

        pushButtonHist = new QPushButton(layoutWidget);
        pushButtonHist->setObjectName(QString::fromUtf8("pushButtonHist"));

        gridLayout->addWidget(pushButtonHist, 0, 1, 1, 2);

        pushButtonQqPlot = new QPushButton(layoutWidget);
        pushButtonQqPlot->setObjectName(QString::fromUtf8("pushButtonQqPlot"));

        gridLayout->addWidget(pushButtonQqPlot, 0, 3, 1, 1);

        lblTempl = new QLabel(layoutWidget);
        lblTempl->setObjectName(QString::fromUtf8("lblTempl"));
        lblTempl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblTempl, 1, 0, 1, 2);

        lblSample = new QLabel(layoutWidget);
        lblSample->setObjectName(QString::fromUtf8("lblSample"));
        lblSample->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblSample, 1, 2, 1, 2);

        tblTplImg = new QTableWidget(layoutWidget);
        tblTplImg->setObjectName(QString::fromUtf8("tblTplImg"));

        gridLayout->addWidget(tblTplImg, 2, 0, 1, 2);

        tblDefImg = new QTableWidget(layoutWidget);
        tblDefImg->setObjectName(QString::fromUtf8("tblDefImg"));

        gridLayout->addWidget(tblDefImg, 2, 2, 1, 2);

        chkCor = new QCheckBox(layoutWidget);
        chkCor->setObjectName(QString::fromUtf8("chkCor"));

        gridLayout->addWidget(chkCor, 3, 0, 1, 2);

        chkPval = new QCheckBox(layoutWidget);
        chkPval->setObjectName(QString::fromUtf8("chkPval"));

        gridLayout->addWidget(chkPval, 3, 2, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        lineEditStep = new QLineEdit(layoutWidget);
        lineEditStep->setObjectName(QString::fromUtf8("lineEditStep"));

        gridLayout->addWidget(lineEditStep, 4, 1, 1, 3);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 0, 1, 1);

        lineEditSimilarValue = new QLineEdit(layoutWidget);
        lineEditSimilarValue->setObjectName(QString::fromUtf8("lineEditSimilarValue"));

        gridLayout->addWidget(lineEditSimilarValue, 5, 1, 1, 3);

        customPlot = new QCustomPlot(imgComQQplot);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(270, 360, 521, 191));

        retranslateUi(imgComQQplot);

        QMetaObject::connectSlotsByName(imgComQQplot);
    } // setupUi

    void retranslateUi(QDialog *imgComQQplot)
    {
        imgComQQplot->setWindowTitle(QApplication::translate("imgComQQplot", "imgComQQplot", 0, QApplication::UnicodeUTF8));
        pushButtonLoad->setText(QApplication::translate("imgComQQplot", "Load", 0, QApplication::UnicodeUTF8));
        pushButtonHist->setText(QApplication::translate("imgComQQplot", "Histogram", 0, QApplication::UnicodeUTF8));
        pushButtonQqPlot->setText(QApplication::translate("imgComQQplot", "QQ Plot", 0, QApplication::UnicodeUTF8));
        lblTempl->setText(QApplication::translate("imgComQQplot", "Template Image", 0, QApplication::UnicodeUTF8));
        lblSample->setText(QApplication::translate("imgComQQplot", "Sample Image", 0, QApplication::UnicodeUTF8));
        chkCor->setText(QApplication::translate("imgComQQplot", "Correlation", 0, QApplication::UnicodeUTF8));
        chkPval->setText(QApplication::translate("imgComQQplot", "P-Value", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("imgComQQplot", "Percentage step", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("imgComQQplot", "Similarity Value", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imgComQQplot: public Ui_imgComQQplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGCOMQQPLOT_H
