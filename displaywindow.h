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
public:
    explicit DisplayWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void takeTheVariables(MainWindow& w);
    void initializeVectors();
    void showIt();
    void clearScreen();

private:
    QTimer* timer;
    QTimer* trialLength;

    int numberOfCongruentDots = 0;
    int numberOfIncongruentDots = 0;
    double speedOfDotMovement = 0;
    double timePerTrial = 1;

    int width = 1300;
    int height = 700;
    int sizeOfDot = 10;

    bool moveRight = 1;

    std::vector<int>* xValuesCongruent;
    std::vector<int>* yValuesCongruent;

    std::vector<double>* xValuesIncongruent;
    std::vector<double>* yValuesIncongruent;

    std::vector<double>* xChange;
    std::vector<double>* yChange;

signals:

public slots:
    void openNewWindow();
};

#endif // DISPLAYWINDOW_H
