#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    faceDetectEnable_ = false;
    eyeDetectEnable_ = false;

    timer_ = new QTimer(this);
    timer_->setInterval(100);
    connect(timer_,SIGNAL(timeout()),this,SLOT(timerTimeout()));

    cam_ = cvCreateCameraCapture(1);

    if (!cam_)
    {
        msg_.setText("Camera not initilized");
        msg_.exec();
    }
}

vector<Rect> Dialog::faceDetect(Mat img,CascadeClassifier &faceClassifier)
{
    vector<Rect> faces;
    Mat frame_gray;

    cvtColor(img, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    faceClassifier.detectMultiScale(frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    return faces;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::timerTimeout()
{
    imgCam_ = (Mat)cvQueryFrame(cam_);

    Mat frame_gray;
    if (faceDetectEnable_)
    {
        face_ = faceDetect(imgCam_,faceClassifier_);

        Point* pImg = new Point(face_.size());

        for( int i = 0; i < face_.size(); i++ )
        {
            pImg[i].x = face_[i].x + face_[i].width*0.5;
            pImg[i].y = face_[i].y + face_[i].height*0.5;

            ellipse(imgCam_,pImg[i],Size(face_[i].width*0.5,face_[i].height*0.5),0,0,360,Scalar(255, 0, 255 ), 4, 8, 0);

        }

        cvtColor( imgCam_, frame_gray, CV_BGR2GRAY );
        equalizeHist( frame_gray, frame_gray );

        if (eyeDetectEnable_)
        {
           for( int i = 0; i < face_.size(); i++ )
           {
               std::vector<Rect> eyes;
               Mat faceROI;
               faceROI = frame_gray(face_[i]);
               eyeClassifier_.detectMultiScale(faceROI,eyes,1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30));
               for( int j = 0; j < eyes.size(); j++ )
                {
                  Point center( face_[i].x + eyes[j].x + eyes[j].width*0.5, face_[i].y + eyes[j].y + eyes[j].height*0.5 );
                  int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                  circle( imgCam_, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
                }
           }
        }
    }
    imshow("Camera",imgCam_);
}

void Dialog::on_btnClassifier_clicked()
{
    msg_.setText("Open Haar face classifier");
    msg_.exec();
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!filePath.isEmpty())
    {
        if (!faceClassifier_.load(filePath.toUtf8().constData()))
        {
            msg_.setText("ERROR: Could not load classifier cascade\n");
            msg_.exec();
        }
    }
    msg_.setText("Open Haar eye classifier");
    msg_.exec();
    filePath = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!filePath.isEmpty())
    {
        if (!eyeClassifier_.load(filePath.toUtf8().constData()))
        {
            msg_.setText("ERROR: Could not load classifier cascade\n");
            msg_.exec();
        }
    }
}

void Dialog::on_btnImage_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!filePath.isEmpty())
    {
        img_ =imread(filePath.toUtf8().constData(),CV_LOAD_IMAGE_COLOR);
        cvNamedWindow("Image",CV_WINDOW_AUTOSIZE);
        imshow("Image",img_);
    }
}

void Dialog::on_btnDetect_clicked()
{
    Mat frame_gray;
    if (faceDetectEnable_)
    {
        face_ = faceDetect(img_,faceClassifier_);

        Point* pImg = new Point(face_.size());

        for( int i = 0; i < face_.size(); i++ )
        {
            pImg[i].x = face_[i].x + face_[i].width*0.5;
            pImg[i].y = face_[i].y + face_[i].height*0.5;

            ellipse(img_,pImg[i],Size(face_[i].width*0.5,face_[i].height*0.5),0,0,360,Scalar(255, 0, 255 ), 4, 8, 0);

        }

        cvtColor( img_, frame_gray, CV_BGR2GRAY );
        equalizeHist( frame_gray, frame_gray );

        if (eyeDetectEnable_)
        {
           for( int i = 0; i < face_.size(); i++ )
           {
               std::vector<Rect> eyes;
               Mat faceROI;
               faceROI = frame_gray(face_[i]);
               eyeClassifier_.detectMultiScale(faceROI,eyes,1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30));
               for( int j = 0; j < eyes.size(); j++ )
                {
                  Point center( face_[i].x + eyes[j].x + eyes[j].width*0.5, face_[i].y + eyes[j].y + eyes[j].height*0.5 );
                  int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                  circle( img_, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
                }
           }
        }
    }
    imshow("Image",img_);
}

void Dialog::on_chkFaceDetectEnable_clicked()
{
     faceDetectEnable_ =!faceDetectEnable_;
}

void Dialog::on_chkEyeDetectEnable_clicked()
{
    eyeDetectEnable_ = !eyeDetectEnable_;
}

void Dialog::on_btnCamera_clicked()
{
    cvNamedWindow("Camera",CV_WINDOW_AUTOSIZE);
    timer_->start();
}


