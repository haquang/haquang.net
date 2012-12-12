#include "imgcomqqplot.h"
#include "ui_imgcomqqplot.h"

imgComQQplot::imgComQQplot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::imgComQQplot)
{
    ui->setupUi(this);
    ui->tblTplImg->setRowCount(256);
    ui->tblTplImg->setColumnCount(5);
    ui->tblTplImg->setHorizontalHeaderItem(0,new QTableWidgetItem("Histogram"));
    ui->tblTplImg->setHorizontalHeaderItem(1,new QTableWidgetItem("Probability"));
    ui->tblTplImg->setHorizontalHeaderItem(2,new QTableWidgetItem("Distribution"));
    ui->tblTplImg->setHorizontalHeaderItem(3,new QTableWidgetItem("q"));
    ui->tblTplImg->setHorizontalHeaderItem(4,new QTableWidgetItem("l"));

    ui->tblDefImg->setRowCount(256);
    ui->tblDefImg->setColumnCount(5);
    ui->tblDefImg->setHorizontalHeaderItem(0,new QTableWidgetItem("Histogram"));
    ui->tblDefImg->setHorizontalHeaderItem(1,new QTableWidgetItem("Probability"));
    ui->tblDefImg->setHorizontalHeaderItem(2,new QTableWidgetItem("Distribution"));
    ui->tblDefImg->setHorizontalHeaderItem(3,new QTableWidgetItem("q"));
    ui->tblDefImg->setHorizontalHeaderItem(4,new QTableWidgetItem("l"));
    Lmax = 256;
    dProLevelTempl = new double[Lmax];
    disTemp = new double[Lmax];

    dProLevelSample = new double[Lmax];
    disSample = new double[Lmax];

    start = false;
    pValMethod = true;
    ui->chkPval->setChecked(true);
    ui->chkCor->setChecked(false);
}

imgComQQplot::~imgComQQplot()
{
    delete ui;
}

void imgComQQplot::on_pushButtonLoad_clicked()
{
    // load template image
    msg.setText("Please load template image");
    msg.exec();
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!filePath.isEmpty())
    {
        imgTempl = cvLoadImage(filePath.toUtf8().constData());
        cvNamedWindow("Template Image",CV_WINDOW_AUTOSIZE);
        cvShowImage("Template Image",imgTempl);
    }

    // load sample image
    msg.setText("Please load sample image");
    msg.exec();
    filePath = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!filePath.isEmpty())
    {
        imgSample = cvLoadImage(filePath.toUtf8().constData());
        cvNamedWindow("Sample Image",CV_WINDOW_AUTOSIZE);
        cvShowImage("Sample Image",imgSample);
    }
}
int find_max(CvHistogram ** hist,int bins)
{
    int i_max=0;
    float value=0;
    for( int i=0;i<bins;i++)
    {
        value=cvQueryHistValue_1D(*hist,i);
        if(value>cvQueryHistValue_1D(*hist,i_max))
            i_max=i;
    }
    return (i_max);
}
void imgComQQplot::on_pushButtonHist_clicked()
{
    int height,width;
    int bins=256;
    int h_size[]={bins};                // Stores the no of bins for each dimenssion
    float xranges[]={0,256};            // Stores the bin ranges for each histogram dimension
    float* ranges[]={xranges};          // Stores the bin ranges for all histogram dimensions
    float value;
    float value_max;

    // template image
    height=imgTempl->height;
    width = imgTempl->width;

    grayTempl = cvCreateImage(cvGetSize(imgTempl),IPL_DEPTH_8U,1);

    imgTemplsHist = cvCreateImage(cvSize(bins,height/2),IPL_DEPTH_8U,1);

    histTempl = cvCreateHist(1,h_size,CV_HIST_ARRAY,ranges,1);

    cvRectangle(imgTemplsHist, cvPoint(0,0), cvPoint(255,(height-1)/2), CV_RGB(255,255,255),-1);

    cvCvtColor(imgTempl,grayTempl,CV_BGR2GRAY);
    cvCalcHist( &grayTempl, histTempl, 0, NULL);
    value_max = cvQueryHistValue_1D(histTempl,find_max(&histTempl,bins));

    for(int i=0;i<256;i++)
    {
        value=cvQueryHistValue_1D(histTempl,i);
        dProLevelTempl[i] = value/(imgTempl->height*imgTempl->width);
        cvLine(imgTemplsHist,cvPoint(i,(height-1)/2),cvPoint(i,(height-(value*height)/(value_max))/2),CV_RGB(0,0,0));

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(QString::number(value));
        ui->tblTplImg->setItem(i,0,item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(dProLevelTempl[i]));
        ui->tblTplImg->setItem(i,1,item2);
    }

    // Display Image
    cvNamedWindow("Template Image Histogram",CV_WINDOW_AUTOSIZE);
    cvShowImage("Template Image Histogram",imgTemplsHist);

    // sample image
    height=imgSample->height;
    width = imgSample->width;

    graySample = cvCreateImage(cvGetSize(imgSample),IPL_DEPTH_8U,1);

    imgSampleHist = cvCreateImage(cvSize(bins,height/2),IPL_DEPTH_8U,1);

    histSample = cvCreateHist(1,h_size,CV_HIST_ARRAY,ranges,1);

    cvRectangle(imgSampleHist, cvPoint(0,0), cvPoint(255,(height-1)/2), CV_RGB(255,255,255),-1);

    cvCvtColor(imgSample,graySample,CV_BGR2GRAY);
    cvCalcHist( &graySample, histSample, 0, NULL);
    value_max = cvQueryHistValue_1D(histSample,find_max(&histSample,bins));

    for(int i=0;i<256;i++)
    {
        value=cvQueryHistValue_1D(histSample,i);
        dProLevelSample[i] = value/(imgTempl->height*imgTempl->width);
        cvLine(imgSampleHist,cvPoint(i,(height-1)/2),cvPoint(i,(height-(value*height)/(value_max))/2),CV_RGB(0,0,0));

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(QString::number(value));
        ui->tblDefImg->setItem(i,0,item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(dProLevelSample[i]));
        ui->tblDefImg->setItem(i,1,item2);
    }
    // Update Table
    for (int i=0;i<256;i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::number(cvQueryHistValue_1D(histSample,i)));
        ui->tblDefImg->setItem(i,0,item);
    }
    // Display Image
    cvNamedWindow("Sample Image Histogram",CV_WINDOW_AUTOSIZE);
    cvShowImage("Sample Image Histogram",imgSampleHist);
}

double qquantile(double* F,int size,double q)
{
    int i;
    double F1,F2;
    double l;
    F1 = 0;
    F2 = 0;
    while (F2<q)
    {
        F1 = F2;
        i++;
        F2 = F[i];
    }

    if ((F2 - q)<(q-F1))
       return i;
    else
       return i-1;
}

double mean(double* l,int size)
{
    double m;
    m = 0;
    for (int i=0;i<size;i++)
    {
        m += l[i]/size;
    }
    return m;
}

double corcoeffun(double* lk,double* li,int size)
{
    double rq;
    double lk_mean,li_mean;

    lk_mean = mean(lk,size);
    li_mean = mean(li,size);

    double num,den1,den2;

    num = 0;
    den1 = 0;
    den2 = 0;
    for (int i=0;i<size;i++)
    {
        num += (lk[i]-lk_mean)*(li[i]-li_mean);
        den1+= pow(lk[i]-lk_mean,2);
        den2+= pow(li[i]-li_mean,2);
    }
    rq = num/sqrt(den1*den2);
    return rq;

}

double gamma(double N)
{
    const long double SQRT2PI = 2.5066282746310005024157652848110452530069867406099383;

    long double Z = (long double)N;
    long double Sc = powl((Z + A), (Z + 0.5));
    Sc *= expl(-1.0 * (Z + A));
    Sc /= Z;

    long double F = 1.0;
    long double Ck;
    long double Sum = SQRT2PI;


    for(int K = 1; K < A; K++)
    {
        Z++;
    Ck = powl(A - K, K - 0.5);
    Ck *= expl(A - K);
    Ck /= F;

    Sum += (Ck / Z);

    F *= (-1.0 * K);
    }

    return (double)(Sum * Sc);
}

static double igf(double S, double Z)
{
    if(Z < 0.0)
    {
        return 0.0;
    }
    double Sc = (1.0 / S);
    Sc *= pow(Z, S);
    Sc *= exp(-Z);

    double Sum = 1.0;
    double Nom = 1.0;
    double Denom = 1.0;

    for(int I = 0; I < 200; I++)
    {
    Nom *= Z;
    S++;
    Denom *= S;
    Sum += (Nom / Denom);
    }

    return Sum * Sc;
}

double chisqr(int Dof, double Cv)
{
    if(Cv < 0 || Dof < 1)
    {
        return 0.0;
    }
    double K = ((double)Dof) * 0.5;
    double X = Cv * 0.5;
    if(Dof == 2)
    {
    return exp(-1.0 * X);
    }

    double PValue = igf(K, X);
 //   if(isnan(PValue) || isinf(PValue) || PValue <= 1e-8)
 //   {
 //       return 1e-14;
 //   }

    PValue /= gamma(K);
    //PValue /= tgamma(K);

    return (1.0 - PValue);
}

double chiValue(double* lk,double* li,int size)
{
    double m;
    double XSqr;
    m = 0;
    for (int i=1;i<size;i++)
    {
        XSqr = li[i] - lk[i];
        m += (XSqr * XSqr)/lk[i];
    }
    return m;
}

void imgComQQplot::on_pushButtonQqPlot_clicked()
{

    int i,j;

    // Distribution function
    for (i=0;i<Lmax;i++)
    {
        disTemp[i] = 0.0;
        disSample[i] = 0.0;
        for(j=0;j<=i;j++)
            {
                disTemp[i] += dProLevelTempl[j];
                disSample[i] += dProLevelSample[j];
            }

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(QString::number(disTemp[i]));
        ui->tblTplImg->setItem(i,2,item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(disSample[i]));
        ui->tblDefImg->setItem(i,2,item2);
    }

    //Quantile
    step = ui->lineEditStep->text().toDouble();
    numSteps = int(1/step);

    qTemp = new double[numSteps];
    qSample = new double[numSteps];
    lTemp = new double[numSteps];
    lSample = new double[numSteps];

    QVector<double> x(Lmax), y(Lmax);
    double Xlimit,Ylimit;
    for (i=0;i<numSteps;i++)
    {
        qTemp[i] = i*step;
        qSample[i] = i*step;

        lTemp[i] = qquantile(disTemp,Lmax,qTemp[i]);
        lSample[i] = qquantile(disSample,Lmax,qSample[i]);

        x[i] = lSample[i];
        y[i] = lTemp[i];
        if (x[i]>Xlimit) Xlimit = x[i];
        if (y[i]>Ylimit) Ylimit = y[i];

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(QString::number(qTemp[i]));
        ui->tblTplImg->setItem(i,3,item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(QString::number(qSample[i]));
        ui->tblDefImg->setItem(i,3,item2);

        QTableWidgetItem* item3 = new QTableWidgetItem();
        item3->setText(QString::number(lTemp[i]));
        ui->tblTplImg->setItem(i,4,item3);

        QTableWidgetItem* item4 = new QTableWidgetItem();
        item4->setText(QString::number(lSample[i]));
        ui->tblDefImg->setItem(i,4,item4);

    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0,Xlimit);
    ui->customPlot->yAxis->setRange(0,Ylimit);

    ui->customPlot->replot();

    //Similar value
    double corcoef;
    corcoef = corcoeffun(lTemp,lSample,numSteps);

    double pValue;
    double chi;


    chi = chiValue(lTemp,lSample,numSteps);
    pValue = chisqr(numSteps-1, chi);


    if (!pValMethod)
        ui->lineEditSimilarValue->setText(QString::number(corcoef));
    else
        ui->lineEditSimilarValue->setText(QString::number(pValue));

}

void imgComQQplot::on_chkCor_clicked()
{
    pValMethod = false;
    ui->chkPval->setChecked(false);
    ui->chkCor->setChecked(true);
}

void imgComQQplot::on_chkPval_clicked()
{
    pValMethod = true;
    ui->chkPval->setChecked(true);
    ui->chkCor->setChecked(false);
}

