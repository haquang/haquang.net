#ifndef IMGCOMQQPLOT_H
#define IMGCOMQQPLOT_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv/highgui.h"
#include "opencv/highgui.h"
#include "qcustomplot.h"
#include <math.h>

#define A 15

namespace Ui {
class imgComQQplot;
}

class imgComQQplot : public QDialog
{
    Q_OBJECT
    
public:
    explicit imgComQQplot(QWidget *parent = 0);
    ~imgComQQplot();
    

private slots:
    void on_pushButtonLoad_clicked();

    void on_pushButtonHist_clicked();

    void on_pushButtonQqPlot_clicked();

    void on_chkCor_clicked();

    void on_chkPval_clicked();


private:
    Ui::imgComQQplot *ui;
    QMessageBox msg;

    IplImage* imgTempl;
    IplImage* imgTemplsHist;
    CvHistogram * histTempl;
    IplImage * grayTempl;
    double* dProLevelTempl;
    double* disTemp;
    double* qTemp;
    double* lTemp;

    IplImage* imgSample;
    IplImage* imgSampleHist;
    CvHistogram * histSample;
    IplImage * graySample;
    double* dProLevelSample;
    double* disSample;
    double* qSample;
    double* lSample;

    double similarValue;
    int Lmax;
    double step;
    int numSteps;
    bool start;


    bool pValMethod;

};

#endif // IMGCOMQQPLOT_H
