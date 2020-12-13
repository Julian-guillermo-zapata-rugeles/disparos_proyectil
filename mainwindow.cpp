#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <iostream>
#include <random>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);
    reloj = new QTimer();
    deteccion = new QTimer();
    connect(reloj,SIGNAL(timeout()),this,SLOT(moverObjetos()));
    connect(deteccion,SIGNAL(timeout()),this,SLOT(defensaObjetos()));
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

    for(auto& iterador:proyectiles){
        iterador->moverProyectil();
        }
    for(auto& iterador:proyectiles){
        //std::cout << iterador->getY_position() << std::endl;
        if(iterador->getY_position()<0){
            //std::cout << " eliminado " << std::endl;
        }
    }

    //escena->advance();
}

void MainWindow::defensaObjetos()
{

   for(auto& iterador:proyectiles){
   bool detection=canonDos->detectarAmenaza(iterador->alcance_maximo);
   if(detection==true and defendiendose==false){
         //short int aleatorio = 120+ rand() % 150;
        tmpProyectil =new proyectil(90-canonUno->getAngulo(),100,canonDos->getCoordenada_x()+30,canonDos->getCoordenada_y(),20,20);
        proyectilesDefensivos.push_back(tmpProyectil);
        delete tmpProyectil;
        reproductor->setMedia(QUrl("qrc:/sonidos/detect.mp3"));
        reproductor->play();

        }
   }
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
        //---------------  espacio   ---------------
        if(evento->key()==Qt::Key_Space){
            tmpProyectil =new proyectil(-canonUno->getAngulo(),100,canonUno->getCoordenada_x()+30,canonUno->getCoordenada_y(),20,20);
            escena->addItem(tmpProyectil);
            proyectiles.push_back(tmpProyectil);
            reproductor->setMedia(QUrl("qrc:/sonidos/disparar.mp3"));
            reproductor->play();
            deteccion->start(2000);
        }
        if(evento->key()==Qt::Key_W){
            //balaCanon->move
            canonUno->subir();
        }
        if(evento->key()==Qt::Key_S){
            canonUno->bajar();
        }
}
