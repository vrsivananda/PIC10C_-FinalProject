#include "displaywindow.h"
#include "mainwindow.h"
#include <QDebug>

DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
    setGeometry(50,100,1300,700);
    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start();
}
void DisplayWindow::takeTheVariables(MainWindow& w){

    qDebug() << "Inside takeTheVariables";


    numberOfCongruentDots = w.numberOfCongruentDots;
    numberOfIncongruentDots = w.numberOfIncongruentDots;
    speedOfDotMovement = w.speedOfDotMovement;
    timePerTrial = w.timePerTrial;

    //xValuesCongruent = w.xValuesCongruent;
    //yValuesCongruent = w.yValuesCongruent;

    //xValuesIncongruent = w.xValuesIncongruent;
    //yValuesIncongruent = w.yValuesIncongruent;

    width = w.width;
    height = w.height;
    sizeOfDot = w.sizeOfDot;

    this->initializeVectors();

    this->showIt();

}

void DisplayWindow::showIt(){
    this->show();
}

//Counter for counting how many times repaint is called
int repaintCounter = 0;

void DisplayWindow::paintEvent(QPaintEvent*){
    QImage background(size(),QImage::Format_ARGB32_Premultiplied);

    if(moveRight){
        for(size_t i = 0; i< yValuesCongruent->size(); ++i ){
            (*xValuesCongruent)[i] += speedOfDotMovement;
            qDebug() << "Inside moveRight: (*xValuesCongruent)["<< i << "] is " << (*xValuesCongruent)[i];
        }
    }
    else{
        for(size_t i = 0; i< yValuesCongruent->size(); ++i ){
            (*xValuesCongruent)[i] -= speedOfDotMovement;
        }
    }

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
    ++repaintCounter;
    qDebug() << "Repaint called." << repaintCounter;
    qDebug() << "(*xValuesCongruent)[0] is " << (*xValuesCongruent)[0];

}

//Initialize Vectors
void DisplayWindow::initializeVectors(){

    for (int i = 0; i<numberOfCongruentDots; ++i){
        (*xValuesCongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesCongruent)[i] = ((rand()%(height-200))+100);
    }
    for (int i = 0; i<numberOfCongruentDots; ++i){
        (*xValuesCongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesCongruent)[i] = ((rand()%(height-200))+100);
    }
}

void DisplayWindow::openNewWindow(){


}

