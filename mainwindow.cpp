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

    canonUno = new canones(70,20,20,470);
    canonUno->setTransformOriginPoint(canonUno->boundingRect().center());
    escena = new QGraphicsScene(0,0,1000,500);
    ui->visorGrafico->setScene(escena);
    escena->addItem(canonUno);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
        //---------------  espacio   ---------------
        if(evento->key()==Qt::Key_Space){
            proyectiles.push_back(new proyectil(10,50,50,400,20,20));
        }
        if(evento->key()==Qt::Key_W){
            //balaCanon->move
            canonUno->subir();
        }
        if(evento->key()==Qt::Key_S){
            canonUno->bajar();
        }
}
