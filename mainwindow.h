#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;

    int numberOfCongruentDots = 0;
    int numberofIncongruentDots = 0;
    int speedOfDotMovement = 0;
    double timePerTrial = 0;

};

#endif // MAINWINDOW_H
