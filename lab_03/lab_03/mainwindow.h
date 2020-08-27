#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elevator.h"
#include <iostream>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Elevator elevator;

signals:
    void addRequest(int);

private slots:
    void clickCallFrom1();
    void clickCallFrom2();
    void clickCallFrom3();
    void clickCallFrom4();
    void clickFloor1();
    void clickFloor2();
    void clickFloor3();
    void clickFloor4();
    void setInfo(QString info);
    void close();
    void open();
    void startClosing();
    void startOpening();
    void stop();
    void moving();
};

#endif // MAINWINDOW_H
