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
        for(auto& it:proyectiles){
            if(defensa->getX_position()-it->getX_position()<50){
                if(defensa->getY_position()-it->getY_position()<50){
                    std::cout << "colisión OK" << std::endl;
                }
            }
        }
    }
    for(auto& iterador:proyectiles){
        iterador->moverProyectil();
        bool detection=canonDos->detectarAmenaza(iterador->getX_position(),iterador->getY_position());
        if(detection==true and defendiendose==false){
             srand(time(0));
            for(unsigned short int a =0 ; a<3;a++){
                short int aleatorio = 120+ rand() % 150;
                tmpProyectil =new proyectil(90-canonUno->getAngulo(),50,canonDos->getCoordenada_x()+30,canonDos->getCoordenada_y(),20,20);
                tmpProyectil->setAngulo(90);
                proyectilesDefensivos.push_back(tmpProyectil);
                //delete tmpProyectil;
            }
            for(auto& it:proyectilesDefensivos){
                escena->addItem(it);
            }
            defendiendose=true;
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
