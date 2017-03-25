#include "displaywindow.h"


DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
    setGeometry(50,100,1300,700);
}

void DisplayWindow::paintEvent(QPaintEvent*){
    QImage background(size(),QImage::Format_ARGB32_Premultiplied);
        for (int i = 0; i<width(); ++i){
            for (int z = 0; z<height(); ++z){
                QRgb rgb = qRgb(rand()%255, rand()%255, rand()%255);
                background.setPixel(i,z,rgb);
            }
        }
    QPainter paint(this);
    paint.drawImage(0,0,background);

}

void DisplayWindow::openNewWindow(){


}

