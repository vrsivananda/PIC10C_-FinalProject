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

private slots:

    //Connect Slider to Spinbox
    void on_horizontalSlider_1_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_horizontalSlider_4_valueChanged(int value);
    void on_horizontalSlider_5_valueChanged(int value);
    void on_horizontalSlider_6_valueChanged(int value);
    void on_horizontalSlider_7_valueChanged(int value);
    void on_horizontalSlider_8_valueChanged(int value);

    //Connect Spinbox to Slider
    void on_spinBox_1_valueChanged(int arg);
    void on_spinBox_2_valueChanged(int arg);
    void on_spinBox_3_valueChanged(int arg);
    void on_spinBox_4_valueChanged(int arg);
    void on_spinBox_5_valueChanged(int arg);
    void on_spinBox_6_valueChanged(int arg);
    void on_spinBox_7_valueChanged(int arg);
    void on_spinBox_8_valueChanged(int arg);

    //checkbox for fullscreen
    void on_checkBox_1_toggled(bool checked);

    //push button to start the trials
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;

    //declare and initialize the public variables
    int numberOfCongruentDots = 0;
    int numberOfIncongruentDots = 0;
    double speedOfDotMovement = 0;
    double timePerTrial = 0;

    int sizeOfDot = 1;
    int numberOfTrials = 1;
    int width = 1300;
    int height = 700;
    bool fullscreen = false;

};

#endif // MAINWINDOW_H
