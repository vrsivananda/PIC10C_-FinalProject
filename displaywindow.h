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
    int numberOfCongruentDots;
    int numberOfIncongruentDots;
    int speedOfDotMovement;
    double timePerTrial;

    int width = 1300;
    int height = 700;
    int sizeOfDot = 10;

    bool moveRight = 1;

    std::vector<int>* xValuesCongruent = new std::vector<int>(numberOfCongruentDots);
    std::vector<int>* yValuesCongruent = new std::vector<int>(numberOfCongruentDots);

    std::vector<int>* xValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);
    std::vector<int>* yValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);

signals:

public slots:
    void openNewWindow();
};

#endif // DISPLAYWINDOW_H
