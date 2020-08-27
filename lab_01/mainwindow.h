#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "drawwidget.h"
#include "repository.h"
#include "processaction.h"
#include "processerrors.h"

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
    DrawWidget *draw_place;

private slots:
    void actionLoadModelTriggered();
    void actionSaveTriggered();
    void clickedBtnRot();
    void clickedBtnScale();
    void clickedBtnMove();
    void process(Repository &repository, error_t er);
};

#endif // MAINWINDOW_H
