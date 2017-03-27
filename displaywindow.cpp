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

    moveRight = rand()%2;

    this->initializeVectors();

    this->showIt();

    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start();

    trialLength = new QTimer(this);
    connect(trialLength, SIGNAL(timeout()), timer, SLOT(stop()));
    trialLength->start(timePerTrial);

}

void DisplayWindow::showIt(){
    this->show();
}

//Counter for counting how many times repaint is called
int repaintCounter = 0;

void DisplayWindow::paintEvent(QPaintEvent*){
    QImage background(size(),QImage::Format_ARGB32_Premultiplied);

    //If there is only 1 dot left, then stop the timer.
    if (numberOfCongruentDots <= 1 || numberOfIncongruentDots <= 1){
        timer->stop();
    }

    //Change the values in the congruent dots vector for movement
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

    //Paint in the squares for the Congruent Dots
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

    //Change values in incongruent dots vector for movement
    for (int i = 0; i< numberOfIncongruentDots; ++i){
        (*xValuesIncongruent)[i] += (*xChange)[i];
        (*yValuesIncongruent)[i] += (*yChange)[i];
    }

    //Fill in incongruent dots
    for(int i = 0; i< numberOfIncongruentDots; ++i ){

        QRgb pixelColor = qRgb(0,0,0);
        int xMidValue = (*xValuesIncongruent)[i];
        int yMidValue = (*yValuesIncongruent)[i];

        for (int j = 0; j < sizeOfDot; ++j){
            int xValue = xMidValue +j;
            for (int k = 0; k <sizeOfDot; ++k){
                int yValue = yMidValue +k;
                background.setPixel(xValue,yValue, pixelColor);
            }
        }
    }

    //Check if dots have gone out of bounds. Delete those that do.
    //Congruent
    for (int i = 0; i<numberOfCongruentDots; ++i){
        if ((*xValuesCongruent)[i] < 0 || (*xValuesCongruent)[i] > (width-sizeOfDot) || (*yValuesCongruent)[i] < 0 || (*yValuesCongruent)[i] > height){
            (*xValuesCongruent).erase((*xValuesCongruent).begin() + i);
            (*yValuesCongruent).erase((*yValuesCongruent).begin() + i);
            numberOfCongruentDots -= 1;
            qDebug() << "Congruent index " << i << "deleted.";
        }
    }

    //Incongruent
    for (int i = 0; i<numberOfIncongruentDots; ++i){
        if ((*xValuesIncongruent)[i] < 0 || (*xValuesIncongruent)[i] > (width-sizeOfDot) || (*yValuesIncongruent)[i] < 0 || (*yValuesIncongruent)[i] > height){
            (*xValuesIncongruent).erase((*xValuesIncongruent).begin() + i);
            (*yValuesIncongruent).erase((*yValuesIncongruent).begin() + i);
            numberOfIncongruentDots -= 1;
            qDebug() << "Incongruent index " << i << "deleted.";
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

    xValuesIncongruent = new std::vector<double>(numberOfIncongruentDots);
    yValuesIncongruent = new std::vector<double>(numberOfIncongruentDots);
    for (int i = 0; i<numberOfIncongruentDots; ++i){
        (*xValuesIncongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesIncongruent)[i] = ((rand()%(height-200))+100);
        qDebug() << "(*xValuesIncongruent)["<<i<<"] is " << (*xValuesIncongruent)[i];
        qDebug() << "(*yValuesIncongruent)["<<i<<"] is " << (*yValuesIncongruent)[i];
    }

    xChange = new std::vector<double>(numberOfIncongruentDots);
    yChange = new std::vector<double>(numberOfIncongruentDots);
    for (int i = 0; i<numberOfIncongruentDots; ++i){
        (*xChange)[i] = (((double)rand()/RAND_MAX)*(speedOfDotMovement))-(speedOfDotMovement/2);
        (*yChange)[i] = (((double)rand()/RAND_MAX)*(speedOfDotMovement))-(speedOfDotMovement/2);
        qDebug() << "(*xChange)["<<i<<"] is " << (*xChange)[i];
        qDebug() << "(*yChange)["<<i<<"] is " << (*yChange)[i];
    }



    qDebug() << "vectors successfully intialized";
}

void DisplayWindow::openNewWindow(){


}

