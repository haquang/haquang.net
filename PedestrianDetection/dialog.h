#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>
#include <QTime>


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_btnImage_clicked();

    void on_btnDetect_clicked();


    void on_btnVideo_clicked();

    void timerTimeout();


private:
    Ui::Dialog *ui;
    QMessageBox msg_;

    Mat img_;
    Mat imgVideo_;
    CvCapture *video_;


    QTime exTime_;
    int runtime_;

    HOGDescriptor hogDescriptor_;
    vector<Rect> pedestrian_;
    vector<Rect> pedestrianFilter_;

    QTimer* timer_;
};

#endif // DIALOG_H
