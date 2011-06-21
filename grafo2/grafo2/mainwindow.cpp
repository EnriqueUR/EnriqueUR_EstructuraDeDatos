#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->AreaRender = new RenderArea();
    this->AreaRender->setGrafo(C->L);
     this->C = new conectar(5,730,470);

    this->ui->gridLayout->addWidget(this->AreaRender,0,0,1,1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
