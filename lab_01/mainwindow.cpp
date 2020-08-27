#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Лабораторная работа №1");
    this->draw_place = new DrawWidget(this);
    ui->horizontalLayout->addWidget(this->draw_place);
    this->draw_place->setMinimumSize(700, 700);
    this->draw_place->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(actionLoadModelTriggered()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(actionSaveTriggered()));
    connect(ui->pushButtonMoving, SIGNAL(clicked(bool)), this, SLOT(clickedBtnMove()));
    connect(ui->pushButtonRotate, SIGNAL(clicked(bool)), this, SLOT(clickedBtnRot()));
    connect(ui->pushButtonScale, SIGNAL(clicked(bool)), this, SLOT(clickedBtnScale()));
}

MainWindow::~MainWindow()
{
    Repository repository;
    createRepository(repository);

    operation_t operation = EXIT;
    error_t er = processingAction(repository, operation);
    std::string errorMessage;
    errorMessage = processErrors(er);

    delete ui;
}

void MainWindow::actionLoadModelTriggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Open Model", QDir::homePath());
    error_t er = SUCCESS;

    if (filepath.isEmpty())
    {
        er = OPEN_ERR;
    }

    Repository repository;
    createRepository(repository);
    repository.file = filepath.toLocal8Bit().data();

    operation_t operation = OPENNING;

    if (er == SUCCESS)
    {
        er = processingAction(repository, operation);
    }

    process(repository, er);
}

void MainWindow::actionSaveTriggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Save Model", QDir::homePath());

    if (filepath.isEmpty())
        filepath = "res/Result.txt";

    Repository repository;
    createRepository(repository);
    repository.file = filepath.toLocal8Bit().data();

    operation_t operation = SAVING;

    error_t er = processingAction(repository, operation);

    process(repository, er);
}

void MainWindow::clickedBtnScale()
{
    Repository repository;
    createRepository(repository);

    QString kx_str;
    QString ky_str;
    QString kz_str;

    bool kx_double = false;
    bool ky_double = false;
    bool kz_double = false;

    kz_str = ui->lineEditScaleKz->text().simplified();
    kx_str = ui->lineEditScaleKx->text().simplified();
    ky_str = ui->lineEditScaleKy->text().simplified();

    if (kx_str == "" || kz_str == "" || ky_str == "")
    {
        QMessageBox::warning(this, "ERROR", "Пустой ввод");
        return;
    }

    kx_str.toDouble(&kx_double);
    ky_str.toDouble(&ky_double);
    kz_str.toDouble(&kz_double);

    if (kz_double == false || kx_double == false || ky_double == false)
    {
        QMessageBox::warning(this, "ERROR", "Некорректные данные:\nчисла должны быть вещественные");
        return;
    }

    double kx_ = kx_str.toDouble();
    double ky_ = ky_str.toDouble();
    double kz_ = kz_str.toDouble();

    setScale(repository.scaling, kx_, ky_, kz_);

    operation_t operation = SCALE;

    error_t er = processingAction(repository, operation);

    process(repository, er);
}

void MainWindow::clickedBtnRot()
{
    Repository repository;
    createRepository(repository);

    QString ox_str;
    QString oy_str;
    QString oz_str;

    bool ox_double = false;
    bool oy_double = false;
    bool oz_double = false;

    oz_str = ui->lineEditRotOz->text().simplified();
    ox_str = ui->lineEditRotOx->text().simplified();
    oy_str = ui->lineEditRotOy->text().simplified();

    if (ox_str == "" || oz_str == "" || oy_str == "")
    {
        QMessageBox::warning(this, "ERROR", "Пустой ввод");
        return;
    }

    ox_str.toDouble(&ox_double);
    oy_str.toDouble(&oy_double);
    oz_str.toDouble(&oz_double);

    if (oz_double == false || ox_double == false || oy_double == false)
    {
        QMessageBox::warning(this, "ERROR", "Некорректные данные:\nчисла должны быть вещественные");
        return;
    }

    double ox_ = ox_str.toDouble();
    double oy_ = oy_str.toDouble();
    double oz_ = oz_str.toDouble();

    setRotate(repository.rotation, ox_, oy_, oz_);

    operation_t operation = ROTATE;

    error_t er = processingAction(repository, operation);

    process(repository, er);
}

void MainWindow::clickedBtnMove()
{
    Repository repository;
    createRepository(repository);

    QString dx_str;
    QString dy_str;
    QString dz_str;

    bool dx_double = false;
    bool dy_double = false;
    bool dz_double = false;

    dz_str = ui->lineEditMoveDz->text().simplified();
    dx_str = ui->lineEditMoveDx->text().simplified();
    dy_str = ui->lineEditMoveDy->text().simplified();

    if (dx_str == "" || dz_str == "" || dy_str == "")
    {
        QMessageBox::warning(this, "ERROR", "Пустой ввод");
        return;
    }

    dx_str.toDouble(&dx_double);
    dy_str.toDouble(&dy_double);
    dz_str.toDouble(&dz_double);

    if (dz_double == false || dx_double == false || dy_double == false)
    {
        QMessageBox::warning(this, "ERROR", "Некорректные данные:\nчисла должны быть вещественные");
        return;
    }

    double dx_ = dx_str.toDouble();
    double dy_ = dy_str.toDouble();
    double dz_ = dz_str.toDouble();

    setMoving(repository.move, dx_, dy_, dz_);

    operation_t operation = MOVING;

    error_t er = processingAction(repository, operation);

    process(repository, er);
}

void MainWindow::process(Repository &repository, error_t er)
{
    if (er == SUCCESS)
    {
        operation_t operation = TRANSFORM;
        er = processingAction(repository, operation);
        this->draw_place->setPoints(repository.points, repository.numberPoints);
        this->draw_place->setInd(repository.ind, repository.numberInd);

        this->draw_place->setPaintingFlag(true);
        this->draw_place->repaint();
        delete[] repository.points;
        delete[] repository.ind;
    }
    else
    {
        std::string errorMessage;
        errorMessage = processErrors(er);
        QString mes = QString::fromLocal8Bit(errorMessage.c_str());
        QMessageBox::warning(this, "ERROR", mes);

        if (er != MEM_ERR_INDEX)
        {
            delete[] repository.ind;
        }
        if (er != MEM_ERR_POINT)
        {
            delete[] repository.points;
        }
    }
}
