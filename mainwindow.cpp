#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time.h"
#include <QDebug>
#include"displaywindow.h"
#include <time.h>
#include <stdlib.h>


//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSlider_1->setRange(0,100);
    ui->horizontalSlider_2->setRange(0,100);
    ui->horizontalSlider_3->setRange(0,100);
    ui->horizontalSlider_4->setRange(0,1000);
    ui->horizontalSlider_5->setRange(1,15);
    ui->horizontalSlider_6->setRange(1,100);
    ui->horizontalSlider_7->setRange(1500,2000);
    ui->horizontalSlider_8->setRange(800,1500);

    ui->spinBox_1->setRange(0,100);
    ui->spinBox_2->setRange(0,100);
    ui->spinBox_3->setRange(0,100);
    ui->spinBox_4->setRange(0,1000);
    ui->spinBox_5->setRange(1,15);
    ui->spinBox_6->setRange(1,100);
    ui->spinBox_7->setRange(1500,2000);
    ui->spinBox_8->setRange(800,1500);

}

//Destructor
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
    numberOfIncongruentDots = value;
}
void MainWindow::on_horizontalSlider_3_valueChanged(int value){
    ui->spinBox_3->setValue(value);
    speedOfDotMovement = value;
}
void MainWindow::on_horizontalSlider_4_valueChanged(int value){
    ui->spinBox_4->setValue(value);
    timePerTrial = value;
}
void MainWindow::on_horizontalSlider_5_valueChanged(int value){
    ui->spinBox_5->setValue(value);
    sizeOfDot = value;
}
void MainWindow::on_horizontalSlider_6_valueChanged(int value){
    ui->spinBox_6->setValue(value);
    numberOfTrials = value;
}
void MainWindow::on_horizontalSlider_7_valueChanged(int value){
    ui->spinBox_7->setValue(value);
    width = value;
}
void MainWindow::on_horizontalSlider_8_valueChanged(int value){
    ui->spinBox_8->setValue(value);
    height = value;
}

//Connect Spinbox to Slider
void MainWindow::on_spinBox_1_valueChanged(int arg){
    ui->horizontalSlider_1->setValue(arg);
    numberOfCongruentDots = arg;
}
void MainWindow::on_spinBox_2_valueChanged(int arg){
    ui->horizontalSlider_2->setValue(arg);
    numberOfIncongruentDots = arg;
}
void MainWindow::on_spinBox_3_valueChanged(int arg){
    ui->horizontalSlider_3->setValue(arg);
    speedOfDotMovement = arg;
}
void MainWindow::on_spinBox_4_valueChanged(int arg){
    ui->horizontalSlider_4->setValue(arg);
    timePerTrial = arg;
}
void MainWindow::on_spinBox_5_valueChanged(int arg){
    ui->horizontalSlider_5->setValue(arg);
    sizeOfDot = arg;
}
void MainWindow::on_spinBox_6_valueChanged(int arg){
    ui->horizontalSlider_6->setValue(arg);
    numberOfTrials = arg;
}
void MainWindow::on_spinBox_7_valueChanged(int arg){
    ui->horizontalSlider_7->setValue(arg);
    width = arg;
}
void MainWindow::on_spinBox_8_valueChanged(int arg){
    ui->horizontalSlider_8->setValue(arg);
    height = arg;
}

//See if the user wants fullscreen
void MainWindow::on_checkBox_1_toggled(bool checked)
{
    //If yes, then set the fullscreen boolean to be true
    //And disable all the settings for the screen dimensions
    if (checked){
        fullscreen = true;
        ui->horizontalSlider_7->setEnabled(false);
        ui->horizontalSlider_8->setEnabled(false);
        ui->spinBox_7->setEnabled(false);
        ui->spinBox_8->setEnabled(false);

    }
    //If no, set the fullscreen boolean to be false
    //And enable all the settings for the screen dimensions
    else if (!checked){
        fullscreen = false;
        ui->horizontalSlider_7->setEnabled(true);
        ui->horizontalSlider_8->setEnabled(true);
        ui->spinBox_7->setEnabled(true);
        ui->spinBox_8->setEnabled(true);
    }
}

//start another window when clicked
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "inside on_pushButton_click()";

    // construct the displaywindow and pass in some parameters
    DisplayWindow* dw = new DisplayWindow(this->width,this->height, this->fullscreen);

    //call the function to take the variables from this object and proceed with the other functionality
    dw->takeTheVariables(*this);

}

