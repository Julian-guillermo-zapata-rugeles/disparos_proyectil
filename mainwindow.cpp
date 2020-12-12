#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    balaCanon= new proyectil(10,30,50,50,20,20);
    escena = new QGraphicsScene(0,0,1000,500);
    ui->visorGrafico->setScene(escena);
    escena->addItem(balaCanon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

