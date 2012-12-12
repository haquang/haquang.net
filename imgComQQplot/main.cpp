#include <QtGui/QApplication>
#include "imgcomqqplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    imgComQQplot w;
    w.show();
    
    return a.exec();
}
