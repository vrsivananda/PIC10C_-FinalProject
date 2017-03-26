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
    void drawIt(MainWindow& w);

private:
    QTimer* timer;
    int numberOfCongruentDots = 100;
    int numberOfIncongruentDots = 100;
    int speedOfDotMovement = 0;
    double timePerTrial = 0;

    int width = 1300;
    int height = 700;
    int sizeOfDot = 10;

    std::vector<int>* xValuesCongruent = new std::vector<int>(numberOfCongruentDots);
    std::vector<int>* yValuesCongruent = new std::vector<int>(numberOfCongruentDots);

    std::vector<int>* xValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);
    std::vector<int>* yValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);

signals:

public slots:
    void openNewWindow();
};

#endif // DISPLAYWINDOW_H
