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

    void initializeVectors();

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

    int numberOfCongruentDots = 100;
    int numberOfIncongruentDots = 100;
    int speedOfDotMovement = 0;
    double timePerTrial = 0;

    std::vector<int> xValuesCongruent;
    std::vector<int> yValuesCongruent;

    std::vector<int> xValuesIncongruent;
    std::vector<int> yValuesIncongruent;




};

#endif // MAINWINDOW_H
