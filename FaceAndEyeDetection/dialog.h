#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>


#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    vector<Rect> faceDetect(Mat img,CascadeClassifier &faceClassifier);
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_btnClassifier_clicked();

    void on_btnImage_clicked();

    void on_btnDetect_clicked();

    void on_chkFaceDetectEnable_clicked();

    void on_chkEyeDetectEnable_clicked();

    void on_btnCamera_clicked();

    void timerTimeout();


private:
    Ui::Dialog *ui;
    Mat img_;
    Mat imgCam_;
    CvCapture *cam_;

    CascadeClassifier faceClassifier_;
    CascadeClassifier eyeClassifier_;

    vector<Rect> face_;
    vector<Rect> eye_;

    bool faceDetectEnable_;
    bool eyeDetectEnable_;

    QMessageBox msg_;

    QTimer* timer_;
};

#endif // DIALOG_H
