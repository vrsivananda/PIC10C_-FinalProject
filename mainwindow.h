#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class DisplayWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class DisplayWindow;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //void initializeVectors();

private slots:

    //Connect Slider to Spinbox
    void on_horizontalSlider_1_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_horizontalSlider_4_valueChanged(int value);

    //Connect Spinbox to Slider
    void on_spinBox_1_valueChanged(int arg);
    void on_spinBox_2_valueChanged(int arg);
    void on_spinBox_3_valueChanged(int arg);
    void on_spinBox_4_valueChanged(int arg);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    int numberOfCongruentDots = 0;
    int numberOfIncongruentDots = 0;
    double speedOfDotMovement = 0;
    double timePerTrial = 0;

    int width = 1300;
    int height = 700;
    int sizeOfDot = 10;

    //std::vector<int>* xValuesCongruent = new std::vector<int>(numberOfCongruentDots);
    //std::vector<int>* yValuesCongruent = new std::vector<int>(numberOfCongruentDots);

    //std::vector<int>* xValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);
    //std::vector<int>* yValuesIncongruent = new std::vector<int>(numberOfIncongruentDots);






};

#endif // MAINWINDOW_H
