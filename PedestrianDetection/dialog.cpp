#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    hogDescriptor_.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    timer_ = new QTimer(this);
    timer_->setInterval(1);

    connect(timer_,SIGNAL(timeout()),this,SLOT(timerTimeout()));
}

Dialog::~Dialog()
{
    delete ui;
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
    pedestrian_.clear();
    pedestrianFilter_.clear();


    exTime_.start();
    hogDescriptor_.detectMultiScale(img_,pedestrian_, 0, Size(8,8), Size(32,32), 1.05, 2);
    runtime_ = exTime_.elapsed();

    ui->exTime->setText(QString::number(runtime_)+ "    ms");
    size_t i, j;
    for( i = 0; i < pedestrian_.size(); i++ )
    {
        Rect r = pedestrian_[i];
        for( j = 0; j < pedestrian_.size(); j++ )
            if( j != i && (r & pedestrian_[j]) == r)
                break;
        if( j == pedestrian_.size() )
            pedestrianFilter_.push_back(r);
    }
    for( i = 0; i < pedestrianFilter_.size(); i++ )
    {
        Rect r = pedestrianFilter_[i];

        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
        rectangle(img_,r.tl(), r.br(), cv::Scalar(0,255,0), 3);
    }
    imshow("Image", img_);
}

void Dialog::on_btnVideo_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    video_ = cvCaptureFromFile(filePath.toUtf8().constData());
    if (!video_)
    {
        msg_.setText("Error loading video");
        msg_.exec();
    }
    else
        timer_->start();
}
void Dialog::timerTimeout()
{
    imgVideo_ = (Mat) cvQueryFrame(video_);

    int i;

    pedestrian_.clear();
    pedestrianFilter_.clear();

    exTime_.start();
    hogDescriptor_.detectMultiScale(imgVideo_,pedestrian_, 0, Size(8,8), Size(32,32), 1.05, 2);
    runtime_ = exTime_.elapsed();
    ui->exTime->setText(QString::number(runtime_)+ "    ms");

    for( i = 0; i < pedestrian_.size(); i++ )
    {
        Rect r = pedestrian_[i];

        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
        rectangle(imgVideo_,r.tl(), r.br(), cv::Scalar(0,255,0), 3);
    }


    imshow("Camera",imgVideo_);
}
