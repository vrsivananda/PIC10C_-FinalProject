#include "displaywindow.h"
#include "mainwindow.h"


DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
    setGeometry(50,100,1300,700);
    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start();
}
void DisplayWindow::drawIt(MainWindow& w){


    numberOfCongruentDots = w.numberOfCongruentDots;
    numberOfIncongruentDots = w.numberOfIncongruentDots;
    speedOfDotMovement = w.speedOfDotMovement;
    timePerTrial = w.timePerTrial;

    xValuesCongruent = w.xValuesCongruent;
    yValuesCongruent = w.yValuesCongruent;

    xValuesIncongruent = w.xValuesIncongruent;
    yValuesIncongruent = w.yValuesIncongruent;

    width = w.width;
    height = w.height;
    sizeOfDot = w.sizeOfDot;


    this->show();
}

void DisplayWindow::paintEvent(QPaintEvent*){
    QImage background(size(),QImage::Format_ARGB32_Premultiplied);

    for(size_t i = 0; i< yValuesCongruent->size(); ++i ){

        QRgb pixelColor = qRgb(0,0,0);
        int xMidValue = (*xValuesCongruent)[i];
        int yMidValue = (*yValuesCongruent)[i];

        for (size_t j = 0; j<1000; ++j){
            int xValue = xMidValue+((rand()%sizeOfDot));
            int yValue = yMidValue+((rand()%sizeOfDot));
            double distanceFromCenter = sqrt(((xValue-xMidValue)^2) + ((yValue-yMidValue)^2));
            if ( distanceFromCenter <= sizeOfDot/2){
                background.setPixel(xValue,yValue, pixelColor);
            }
        }

    }

    /*
     QImage background(size(),QImage::Format_ARGB32_Premultiplied);
        for (int i = 0; i<width(); ++i){
            for (int z = 0; z<height(); ++z){
                QRgb rgb = qRgb(rand()%255, rand()%255, rand()%255);
                background.setPixel(i,z,rgb);
            }
        }
        */
    QPainter paint(this);
    paint.drawImage(0,0,background);

}

void DisplayWindow::openNewWindow(){


}

