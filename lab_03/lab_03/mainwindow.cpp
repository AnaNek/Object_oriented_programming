#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Лабораторная работа №3:Лифт, Неклепаева");

    connect(elevator.getDoors(), SIGNAL(newInfo(QString)), this, SLOT(setInfo(QString)));
    connect(&elevator, SIGNAL(newInfo(QString)), this, SLOT(setInfo(QString)));

    connect(this, SIGNAL(addRequest(int)), elevator.getControlBox(), SLOT(addTarget(int)));

    connect(ui->floor1, SIGNAL(clicked(bool)), this, SLOT(clickFloor1()));
    connect(ui->floor2, SIGNAL(clicked(bool)), this, SLOT(clickFloor2()));
    connect(ui->floor3, SIGNAL(clicked(bool)), this, SLOT(clickFloor3()));
    connect(ui->floor4, SIGNAL(clicked(bool)), this, SLOT(clickFloor4()));
    connect(ui->callFrom1, SIGNAL(clicked(bool)), this, SLOT(clickCallFrom1()));
    connect(ui->callFrom2, SIGNAL(clicked(bool)), this, SLOT(clickCallFrom2()));
    connect(ui->callFrom3, SIGNAL(clicked(bool)), this, SLOT(clickCallFrom3()));
    connect(ui->callFrom4, SIGNAL(clicked(bool)), this, SLOT(clickCallFrom4()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::stop()
{
    QString info = "Лифт стоит на " + QString::number(elevator.getCurFloor()) + " этаже";
    ui->textBrowser->append(info);
}

void MainWindow::moving()
{
    QString info = "Лифт на " + QString::number(elevator.getCurFloor()) + " этаже";
    ui->textBrowser->append(info);
}

void MainWindow::close()
{
    QString info = "Двери открыты";
    ui->textBrowser->append(info);
}

void MainWindow::open()
{
    QString info = "Двери открыты";
    ui->textBrowser->append(info);
}

void MainWindow::startClosing()
{
    QString info = "Двери закрываются";
    ui->textBrowser->append(info);
}

void MainWindow::startOpening()
{
    QString info = "Двери открываются";
    ui->textBrowser->append(info);
}

void MainWindow::setInfo(QString info)
{
    ui->textBrowser->append(info);
}

void MainWindow::clickCallFrom1()
{
    ui->textBrowser->append("Вызов лифта на 1 этаже");
    emit addRequest(1);
}

void MainWindow::clickCallFrom2()
{
    ui->textBrowser->append("Вызов лифта на 2 этаже");
    emit addRequest(2);
}

void MainWindow::clickCallFrom3()
{
    ui->textBrowser->append("Вызов лифта на 3 этаже");
    emit addRequest(3);
}

void MainWindow::clickCallFrom4()
{
    ui->textBrowser->append("Вызов лифта на 4 этаже");
    emit addRequest(4);
}

void MainWindow::clickFloor1()
{
    ui->textBrowser->append("В кабине лифта нажата кнопка 1 этажа");
    emit addRequest(1);
}

void MainWindow::clickFloor2()
{
    ui->textBrowser->append("В кабине лифта нажата кнопка 2 этажа");
    emit addRequest(2);
}

void MainWindow::clickFloor3()
{
    ui->textBrowser->append("В кабине лифта нажата кнопка 3 этажа");
    emit addRequest(3);
}

void MainWindow::clickFloor4()
{
    ui->textBrowser->append("В кабине лифта нажата кнопка 4 этажа");
    emit addRequest(4);
}

