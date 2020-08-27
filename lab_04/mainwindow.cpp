#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setUpCanvas();
    connect(ui->actionOpen, SIGNAL(clicked(bool)), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(clicked(bool)), this, SLOT(save()));
    connect(ui->pushButtonMove, SIGNAL(clicked(bool)), this, SLOT(move()));
    connect(ui->pushButtonRotate, SIGNAL(clicked(bool)), this, SLOT(rotate()));
    connect(ui->pushButtonScale, SIGNAL(clicked(bool)), this, SLOT(scale()));
}

void MainWindow::open()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Открыть модель", "", \
                                                    "Wavefront (*.txt)");
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Не выбран файл");
        return;
    }

    OpenCommand cmd(filePath.toStdString());
    controller.process(cmd);
    this->updateScene();
}

void MainWindow::save()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Сохранить модель", "", \
                                                    "Wavefront (*.txt)");
    if (filePath.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Не выбран файл");
        return;
    }
    SaveCommand cmd(filePath.toStdString());
    controller.process(cmd);
}

void MainWindow::move()
{
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

    MoveCommand cmd(dx_, dy_, dz_);
    controller.process(cmd);
    this->updateScene();
}

void MainWindow::scale()
{
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

    ScaleCommand cmd(kx_, ky_, kz_);
    controller.process(cmd);
    this->updateScene();
}

void MainWindow::rotate()
{
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

    RotateCommand cmd(ox_, oy_, oz_);
    controller.process(cmd);
    this->updateScene();
}

void MainWindow::setUpCanvas()
{
    this->scene = new QGraphicsScene;
    ui->canvas->installEventFilter(this);
    ui->canvas->setScene(scene);
}

void MainWindow::updateScene()
{
    this->scene->clear();

    Drawer drawer(this->scene);
    DrawCommand cmd(drawer);
    controller.process(cmd);
}

MainWindow::~MainWindow()
{
    delete ui;
}
