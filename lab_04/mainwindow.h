#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QGraphicsScene>

#include "managers/controller.h"
#include "commands/command.h"
#include "drawer/drawer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateScene();
    void setUpCanvas();

public slots:
    void open();
    void save();
    void scale();
    void move();
    void rotate();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Controller controller;
};

#endif // MAINWINDOW_H
