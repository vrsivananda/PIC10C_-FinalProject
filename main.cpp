#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Seed the random number generator
    srand (time(NULL));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
