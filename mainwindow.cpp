#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time.h"
#include <QDebug>
#include"displaywindow.h"
#include <time.h>
#include <stdlib.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->horizontalSlider_1->setRange(0,100);
    ui->horizontalSlider_2->setRange(0,100);
    ui->horizontalSlider_3->setRange(0,100);
    ui->horizontalSlider_4->setRange(0,1000);
    ui->horizontalSlider_5->setRange(0,15);
    ui->horizontalSlider_6->setRange(0,100);
    ui->horizontalSlider_7->setRange(1500,2000);
    ui->horizontalSlider_8->setRange(800,1500);

    ui->spinBox_1->setRange(0,100);
    ui->spinBox_2->setRange(0,100);
    ui->spinBox_3->setRange(0,100);
    ui->spinBox_4->setRange(0,1000);
    ui->spinBox_5->setRange(0,15);
    ui->spinBox_6->setRange(0,100);
    ui->spinBox_7->setRange(1500,2000);
    ui->spinBox_8->setRange(800,1500);

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

void MainWindow::on_checkBox_1_toggled(bool checked)
{
    if (checked){
        fullscreen = true;
        qDebug() << "fullscreen is true.";
        ui->horizontalSlider_7->setEnabled(false);
        ui->horizontalSlider_8->setEnabled(false);
        ui->spinBox_7->setEnabled(false);
        ui->spinBox_8->setEnabled(false);

    }
    else if (!checked){
        fullscreen = false;
        qDebug() << "fullscreen is false.";
        ui->horizontalSlider_7->setEnabled(true);
        ui->horizontalSlider_8->setEnabled(true);
        ui->spinBox_7->setEnabled(true);
        ui->spinBox_8->setEnabled(true);
    }
}

/*
//Initialize Vectors
void MainWindow::initializeVectors(){

    for (int i = 0; i<numberOfCongruentDots; ++i){
        xValuesCongruent->push_back((rand()%(width-200))+100);
        yValuesCongruent->push_back((rand()%(height-200))+100);
    }
    for (int i = 0; i<numberOfCongruentDots; ++i){
        xValuesIncongruent->push_back((rand()%(width-200))+100);
        yValuesIncongruent->push_back((rand()%(height-200))+100);
    }
}
*/


//start another window when clicked
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "inside on_pushButton_click()";
    //initializeVectors();
    //the display window object is created
    DisplayWindow* dw = new DisplayWindow(this->width,this->height, this->fullscreen);
    //show the object
    qDebug() << "Calling takeTheVariables";
    dw->takeTheVariables(*this);

}

