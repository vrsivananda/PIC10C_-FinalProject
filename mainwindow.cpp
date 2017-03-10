#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Connect slider to spinbox
void MainWindow::on_horizontalSlider_1_valueChanged(int value){
    ui->spinBox_1->setValue(value);
    numberOfCongruentDots = value;
}
void MainWindow::on_horizontalSlider_2_valueChanged(int value){
    ui->spinBox_2->setValue(value);
    numberofIncongruentDots = value;
}
void MainWindow::on_horizontalSlider_3_valueChanged(int value){
    ui->spinBox_3->setValue(value);
    speedOfDotMovement = value;
}
void MainWindow::on_horizontalSlider_4_valueChanged(int value){
    ui->spinBox_4->setValue(value);
    timePerTrial = value;
}

//Connect Spinbox to Slider
void MainWindow::on_spinBox_1_valueChanged(int arg){
    ui->horizontalSlider_1->setValue(arg);
    numberOfCongruentDots = arg;
}
void MainWindow::on_spinBox_2_valueChanged(int arg){
    ui->horizontalSlider_2->setValue(arg);
    numberofIncongruentDots = arg;
}
void MainWindow::on_spinBox_3_valueChanged(int arg){
    ui->horizontalSlider_3->setValue(arg);
    speedOfDotMovement = arg;
}
void MainWindow::on_spinBox_4_valueChanged(int arg){
    ui->horizontalSlider_4->setValue(arg);
    timePerTrial = arg;
}




