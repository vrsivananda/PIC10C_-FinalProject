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

private:
    QTimer* timer;
    int numberOfCongruentDots = 0;
    int numberOfIncongruentDots = 0;
    int speedOfDotMovement = 1;
    double timePerTrial = 1;

    int width = 1300;
    int height = 700;
    int sizeOfDot = 10;

    bool moveRight = 1;

    std::vector<int>* xValuesCongruent;
    std::vector<int>* yValuesCongruent;

    std::vector<int>* xValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);
    std::vector<int>* yValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);

signals:

public slots:
    void openNewWindow();
};

#endif // DISPLAYWINDOW_H
