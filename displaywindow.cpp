#include "displaywindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <algorithm>

// Constructor
DisplayWindow::DisplayWindow(int& otherWidth, int& otherHeight, bool otherFullscreen, QWidget *parent) : QWidget(parent)
{
    //Set the fullscreen variable from the mainWindow object
    fullscreen = otherFullscreen;

    //Create a desktop widget to access screen dimensions
    QDesktopWidget wid;

    //Initialize the screen width and height
    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();

    //If it is fullscree, then use the dimensions of the screen
    //And set the private variables to be also to the dimensions of the screen
    if (fullscreen){
        setGeometry(2,28,screenWidth,screenHeight);
        width = screenWidth;
        height = screenHeight;
    }
    //If it is not fullscreen,
    //check if the width set is smaller than the screen width,
    //or if the height set is smaller than the screen height
    else{
        //If yes, then set our variables accordingly since the dimensions fit
        if (screenWidth >= otherWidth || screenHeight >= otherHeight){
            width = otherWidth;
            height = otherHeight;
            setGeometry((screenWidth-width)/2,(screenHeight-height)/2,width,height);
        }
        //If no, then set dimensions to full screen specifications
        else{
            fullscreen = true;
            width = screenWidth;
            height = screenHeight;
            setGeometry(2,28,screenWidth,screenHeight);
        }

    }


}

//Function to take the variables from the main window settings
void DisplayWindow::takeTheVariables(MainWindow& w){

    qDebug() << "Inside takeTheVariables";


    //Take the variables
    numberOfCongruentDots = w.numberOfCongruentDots;
    numberOfIncongruentDots = w.numberOfIncongruentDots;
    originalNumberOfCongruentDots = w.numberOfCongruentDots;
    originalNumberOfIncongruentDots = w.numberOfIncongruentDots;
    speedOfDotMovement = w.speedOfDotMovement;
    timePerTrial = w.timePerTrial;

    qDebug() << "Number of Congruent dots is " << numberOfCongruentDots;
    qDebug() << "Number of Incongruent dots is " << numberOfIncongruentDots;
    qDebug() << "Speed of dot movement is " << speedOfDotMovement;
    qDebug() << "Time per trial is " << timePerTrial;

    //If it is not fullscreen, then take the variables set
    if (!fullscreen){
        width = w.width;
        height = w.height;
    }
    sizeOfDot = w.sizeOfDot;
    numberOfTrials = w.numberOfTrials;

    //Once all variables are taken, call to start the trial
    this->anotherTrial();
}

//Function that starts a trial
void DisplayWindow::anotherTrial(){
    //Reset the number of dots to the original in a new trial
    numberOfCongruentDots = originalNumberOfCongruentDots;
    numberOfIncongruentDots = originalNumberOfIncongruentDots;

    //Randomize if dots move left or right
    moveRight = rand()%2;

    //Initialize the vectors to have new values per trial
    this->initializeVectors();

    //Display the window
    this->show();

    //Set timer to repaint the dots to simulate movement
    timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start();

    //Set timer to stop the repainting above when the length of a trial has been reached
    trialLength = new QTimer(this);
    connect(trialLength, SIGNAL(timeout()), timer, SLOT(stop()));
    trialLength->start(timePerTrial);
    trialLength->setSingleShot(true);
    connect(trialLength, &QTimer::timeout, this, &DisplayWindow::clearScreen);

    //Set timer to start a new trial when trial is over
    rerunTrial = new QTimer(this);
    rerunTrial->start(timePerTrial + 500);
    rerunTrial->setSingleShot(true);
    connect(rerunTrial, &QTimer::timeout, this, &DisplayWindow::anotherTrial);

    //Increment the trial counter and stop new trials when number has been reached
    ++trialCounter;
    if (trialCounter == numberOfTrials){
        rerunTrial->stop();
    }

}

//Counter for counting how many times repaint is called
int repaintCounter = 0;

//Function that updates the window that shows the dots
void DisplayWindow::paintEvent(QPaintEvent*){
    QImage background(size(),QImage::Format_ARGB32_Premultiplied);

    //If not clear the screen, perform the computation and update the screen
    if (clearTheScreen == false){

        //If there is only 1 dot left, then stop the timer.
        if (numberOfCongruentDots <= 1 && numberOfIncongruentDots <= 1){
            timer->stop();
        }

        //---------Congruent Dots---------
        //Change the values in the congruent dots vector for movement
        if(moveRight){
            for(int i = 0; i< numberOfCongruentDots; ++i ){
                (*xValuesCongruent)[i] += speedOfDotMovement;
            }
        }
        else{
            for(int i = 0; i< numberOfCongruentDots; ++i ){
                (*xValuesCongruent)[i] -= speedOfDotMovement;
            }
        }

        //Paint in the squares for the Congruent Dots
        for(int i = 0; i< numberOfCongruentDots; ++i ){

            //Set the pixel color and the starting point
            QRgb pixelColor = qRgb(0,0,0);
            int xMidValue = (*xValuesCongruent)[i];
            int yMidValue = (*yValuesCongruent)[i];

            //Color in the square
            for (int j = 0; j < sizeOfDot; ++j){
                int xValue = xMidValue +j;
                for (int k = 0; k <sizeOfDot; ++k){
                    int yValue = yMidValue +k;
                    background.setPixel(xValue,yValue, pixelColor);
                }
            }
        }

        //---------Incongruent Dots---------
        //Change values in incongruent dots vector for movement
        for (int i = 0; i< numberOfIncongruentDots; ++i){
            (*xValuesIncongruent)[i] += (*xChange)[i];
            (*yValuesIncongruent)[i] += (*yChange)[i];
        }

        //Fill in incongruent dots
        for(int i = 0; i< numberOfIncongruentDots; ++i ){

            //Set the pixel color and the starting point
            QRgb pixelColor = qRgb(0,0,0);
            int xMidValue = (*xValuesIncongruent)[i];
            int yMidValue = (*yValuesIncongruent)[i];

            //Color in the square
            for (int j = 0; j < sizeOfDot; ++j){
                int xValue = xMidValue +j;
                for (int k = 0; k <sizeOfDot; ++k){
                    int yValue = yMidValue +k;
                    background.setPixel(xValue,yValue, pixelColor);
                }
            }
        }

        //--------------------
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
                (*xChange).erase((*xChange).begin() + i);
                (*yChange).erase((*yChange).begin() + i);
                numberOfIncongruentDots -= 1;
                qDebug() << "Incongruent index " << i << "deleted.";
            }
        }

    }
    //If we want to clear the screen, then create a blank background and reset the clear screen boolean
    else{
        QImage background(size(),QImage::Format_ARGB32_Premultiplied);
        clearTheScreen = false;
    }

    //Paint in the background
    QPainter paint(this);
    paint.drawImage(0,0,background);

    ++repaintCounter;
    qDebug() << "Repaint called." << repaintCounter;
}

//Initialize Vectors
void DisplayWindow::initializeVectors(){
    qDebug() << "Inside initializeVectors";

    //---------------Congruent Dots-----------------
    //Preallocate the memory
    xValuesCongruent = new std::vector<int>(numberOfCongruentDots);
    yValuesCongruent = new std::vector<int>(numberOfCongruentDots);

    //Insert random values that are 100 pixels within the bounds of the screen
    for (int i = 0; i<numberOfCongruentDots; ++i){
        (*xValuesCongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesCongruent)[i] = ((rand()%(height-200))+100);
        qDebug() << "(*xValuesCongruent)["<<i<<"] is " << (*xValuesCongruent)[i];
        qDebug() << "(*yValuesCongruent)["<<i<<"] is " << (*yValuesCongruent)[i];
    }
    qDebug() << "Finished initializing congruent dots";

    //---------------Incongruent Dots-----------------
    //Preallocate the memory
    xValuesIncongruent = new std::vector<double>(numberOfIncongruentDots);
    yValuesIncongruent = new std::vector<double>(numberOfIncongruentDots);

    //Insert random values that are 100 pixels within the bounds of the screen
    for (int i = 0; i<numberOfIncongruentDots; ++i){
        (*xValuesIncongruent)[i] = ((rand()%(width-200))+100);
        (*yValuesIncongruent)[i] = ((rand()%(height-200))+100);
        qDebug() << "(*xValuesIncongruent)["<<i<<"] is " << (*xValuesIncongruent)[i];
        qDebug() << "(*yValuesIncongruent)["<<i<<"] is " << (*yValuesIncongruent)[i];
    }

    //Preallocate the memory for change values
    xChange = new std::vector<double>(numberOfIncongruentDots);
    yChange = new std::vector<double>(numberOfIncongruentDots);

    //Insert random values for all directions
    //Scale the change in values to the speed of the movement
    for (int i = 0; i<numberOfIncongruentDots; ++i){
        (*xChange)[i] = (((double)rand()/RAND_MAX)*(speedOfDotMovement))-(speedOfDotMovement/2);
        (*yChange)[i] = (((double)rand()/RAND_MAX)*(speedOfDotMovement))-(speedOfDotMovement/2);
        qDebug() << "(*xChange)["<<i<<"] is " << (*xChange)[i];
        qDebug() << "(*yChange)["<<i<<"] is " << (*yChange)[i];
    }

    qDebug() << "vectors successfully intialized";
}

//Function to set the clear screen boolean and call repaint to clear the screen
void DisplayWindow::clearScreen(){
    qDebug() << "clearScreen called.";
    clearTheScreen = true;
    repaint();

}

void DisplayWindow::closeEvent(QCloseEvent*){
    rerunTrial->stop();
    //event->accept();
}
