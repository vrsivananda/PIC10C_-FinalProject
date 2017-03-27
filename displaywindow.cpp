#include "displaywindow.h"
#include "mainwindow.h"
#include <QDebug>

DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
    setGeometry(50,100,1300,700);

}
void DisplayWindow::takeTheVariables(MainWindow& w){

    qDebug() << "Inside takeTheVariables";


    numberOfCongruentDots = w.numberOfCongruentDots;
    numberOfIncongruentDots = w.numberOfIncongruentDots;
    speedOfDotMovement = w.speedOfDotMovement;
    timePerTrial = w.timePerTrial;

    qDebug() << "Number of Congruent dots is " << numberOfCongruentDots;
    qDebug() << "Number of Incongruent dots is " << numberOfIncongruentDots;
    qDebug() << "Speed of dot movement is " << speedOfDotMovement;
    qDebug() << "Time per trial is " << timePerTrial;

    //xValuesCongruent = w.xValuesCongruent;
    //yValuesCongruent = w.yValuesCongruent;

    //xValuesIncongruent = w.xValuesIncongruent;
    //yValuesIncongruent = w.yValuesIncongruent;

    width = w.width;
    height = w.height;
    sizeOfDot = w.sizeOfDot;

    this->initializeVectors();

    this->showIt();

    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(1000);

}

void DisplayWindow::showIt(){
    this->show();
}

//Counter for counting how many times repaint is called
int repaintCounter = 0;

void DisplayWindow::paintEvent(QPaintEvent*){
    QImage background(size(),QImage::Format_ARGB32_Premultiplied);

    if(moveRight){
        for(int i = 0; i< numberOfCongruentDots; ++i ){
            (*xValuesCongruent)[i] += speedOfDotMovement;
            qDebug() << "Inside moveRight: (*xValuesCongruent)["<< i << "] is " << (*xValuesCongruent)[i];
            qDebug() << "Inside moveRight: (*yValuesCongruent)["<< i << "] is " << (*yValuesCongruent)[i];
        }
    }
    else{
        for(int i = 0; i< numberOfCongruentDots; ++i ){
            (*xValuesCongruent)[i] -= speedOfDotMovement;
        }
    }

    for(int i = 0; i< numberOfCongruentDots; ++i ){

        QRgb pixelColor = qRgb(0,0,0);
        int xMidValue = (*xValuesCongruent)[i];
        int yMidValue = (*yValuesCongruent)[i];

        for (int j = 0; j < sizeOfDot; ++j){
            int xValue = xMidValue +j;
            for (int k = 0; k <sizeOfDot; ++k){
                int yValue = yMidValue +k;
                background.setPixel(xValue,yValue, pixelColor);
            }
        }
    }

    QPainter paint(this);
    paint.drawImage(0,0,background);
    ++repaintCounter;
    qDebug() << "Repaint called." << repaintCounter;
    qDebug() << "(*xValuesCongruent)[0] is " << (*xValuesCongruent)[0];

}

//Initialize Vectors
void DisplayWindow::initializeVectors(){
    qDebug() << "Inside initializeVectors";

    xValuesCongruent = new std::vector<int>(numberOfCongruentDots);
    yValuesCongruent = new std::vector<int>(numberOfCongruentDots);
    for (int i = 0; i<numberOfCongruentDots; ++i){
        (*xValuesCongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesCongruent)[i] = ((rand()%(height-200))+100);
        qDebug() << "(*xValuesCongruent)["<<i<<"] is " << (*xValuesCongruent)[i];
        qDebug() << "(*yValuesCongruent)["<<i<<"] is " << (*yValuesCongruent)[i];
    }
    qDebug() << "Finished initializing congruent dots";

    xValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);
    yValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);
    for (int i = 0; i<numberOfIncongruentDots; ++i){
        (*xValuesIncongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesIncongruent)[i] = ((rand()%(height-200))+100);
        qDebug() << "(*xValuesIncongruent)["<<i<<"] is " << (*xValuesIncongruent)[i];
        qDebug() << "(*yValuesIncongruent)["<<i<<"] is " << (*yValuesIncongruent)[i];
    }
    qDebug() << "vectors successfully intialized";
}

void DisplayWindow::openNewWindow(){


}

