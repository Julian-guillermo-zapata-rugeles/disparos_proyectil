#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reloj = new QTimer();
    connect(reloj,SIGNAL(timeout()),this,SLOT(moverObjetos()));
    reloj->start(50);
    canonUno = new canones(100,20,20,470);
    canonDos = new canones(100,20,900,470);
    canonUno->setTransformOriginPoint(canonUno->boundingRect().center());
    canonDos->setTransformOriginPoint(canonDos->boundingRect().center());
    escena = new QGraphicsScene(0,0,1100,500);
    ui->visorGrafico->setScene(escena);

    escena->addItem(canonUno);
    escena->addItem(canonDos);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moverObjetos()
{
    for(auto& defensa:proyectilesDefensivos){
        defensa->moverProyectil();
    }
    for(auto& iterador:proyectiles){
        iterador->moverProyectil();
        bool detection=canonDos->detectarAmenaza(iterador->getX_position(),iterador->getY_position());
        if(detection==true){
            tmpProyectil =new proyectil(- canonDos->getAngulo(),100,canonDos->getCoordenada_x()+30,canonDos->getCoordenada_y(),20,20);
            tmpProyectil->setAngulo(90);
            escena->addItem(tmpProyectil);
            proyectilesDefensivos.push_back(tmpProyectil);
        }
    }
    for(auto& iterador:proyectiles){
        //std::cout << iterador->getY_position() << std::endl;
        if(iterador->getY_position()<0){
            //std::cout << " eliminado " << std::endl;
        }
    }

    //escena->advance();
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
        //---------------  espacio   ---------------
        if(evento->key()==Qt::Key_Space){
            tmpProyectil =new proyectil(-canonUno->getAngulo(),100,canonUno->getCoordenada_x()+30,canonUno->getCoordenada_y(),20,20);
            escena->addItem(tmpProyectil);
            proyectiles.push_back(tmpProyectil);
        }
        if(evento->key()==Qt::Key_W){
            //balaCanon->move
            canonUno->subir();
        }
        if(evento->key()==Qt::Key_S){
            canonUno->bajar();
        }
}
