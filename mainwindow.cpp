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
    DisplayWindow* dw = new DisplayWindow();
    //show the object
    qDebug() << "Calling takeTheVariables";
    dw->takeTheVariables(*this);

}
