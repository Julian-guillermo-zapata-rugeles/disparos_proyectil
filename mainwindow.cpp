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
    balaCanon= new proyectil(10,50,50,400,20,20);
    //canonUno = new canones(40,20,10,400);
    //escena->addItem(canonUno);
    escena = new QGraphicsScene(0,0,1000,500);
    ui->visorGrafico->setScene(escena);
    escena->addItem(balaCanon);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
        //---------------  espacio   ---------------
        if(evento->key()==Qt::Key_Space){
            balaCanon->moverProyectil();
        }
        if(evento->key()==Qt::Key_W){
            //balaCanon->move
        }
        if(evento->key()==Qt::Key_S){
            balaCanon->moverProyectil();
        }
}
