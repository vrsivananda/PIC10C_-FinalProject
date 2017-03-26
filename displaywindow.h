#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QImage>

class MainWindow;

class DisplayWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void drawIt(MainWindow& w);

private:
    QTimer* timer;

signals:

public slots:
    void openNewWindow();
};

#endif // DISPLAYWINDOW_H
