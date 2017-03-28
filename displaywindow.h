#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QImage>

class MainWindow;

class DisplayWindow : public QWidget
{
    Q_OBJECT
//Declare the public functions
public:
    explicit DisplayWindow(int& width, int& height, bool fullscreen, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void takeTheVariables(MainWindow& w);
    void initializeVectors();
    void anotherTrial();
    void clearScreen();
    void closeEvent(QCloseEvent*);

private:
    //Declare the timers used
    QTimer* timer;
    QTimer* trialLength;
    QTimer* rerunTrial;

    // Declare and set the default values of the private variables
    int numberOfCongruentDots = 0;
    int numberOfIncongruentDots = 0;
    double speedOfDotMovement = 0;
    double timePerTrial = 1;

    int width = 1300;
    int height = 700;
    int sizeOfDot = 1;
    int numberOfTrials = 1;
    bool fullscreen = false;

    bool moveRight = 1;
    bool clearTheScreen = false;

    int originalNumberOfCongruentDots = 0;
    int originalNumberOfIncongruentDots = 0;
    int trialCounter = 0;

    //Declare all the private vectors
    std::vector<int>* xValuesCongruent;
    std::vector<int>* yValuesCongruent;

    std::vector<double>* xValuesIncongruent;
    std::vector<double>* yValuesIncongruent;

    std::vector<double>* xChange;
    std::vector<double>* yChange;

signals:

public slots:
};

#endif // DISPLAYWINDOW_H
