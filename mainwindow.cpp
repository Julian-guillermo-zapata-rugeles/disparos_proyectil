#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <iostream>
#include <random>
#include<QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);
    reloj = new QTimer();
    deteccion = new QTimer();
    atacar=new QTimer();

    connect(reloj,SIGNAL(timeout()),this,SLOT(moverObjetos()));
    connect(deteccion,SIGNAL(timeout()),this,SLOT(defensaObjetos()));
    connect(atacar,SIGNAL(timeout()),this,SLOT(ataqueSeguido()));
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
    for(auto& it:proyectiles){
       it->moverProyectil();
       if(it->getY_position()<0){
           escena->removeItem(it);
           proyectiles.erase(std::remove(proyectiles.begin(),proyectiles.end(),it),proyectiles.end());
       }
    }
    for(auto&it:proyectilesDefensivos){
        it->moverProyectil();
        if(it->getY_position()<0){
        escena->removeItem(it);
        proyectilesDefensivos.erase(std::remove(proyectilesDefensivos.begin(),proyectilesDefensivos.end(),it),proyectilesDefensivos.end());
        }
    }
    if(proyectiles.size()==0){
        onair=false;
        deteccion->stop();
        atacar->stop();
    }
    for(auto& ti:proyectiles){
        for(auto& is:proyectilesDefensivos){
            if(ti->collidesWithItem(is)){
                escena->removeItem(ti);
                proyectilesDefensivos.erase(std::remove(proyectilesDefensivos.begin(),proyectilesDefensivos.end(),ti),proyectilesDefensivos.end());
                escena->removeItem(is);
                proyectilesDefensivos.erase(std::remove(proyectilesDefensivos.begin(),proyectilesDefensivos.end(),is),proyectilesDefensivos.end());
                reproductor->setMedia(QUrl("qrc:/sonidos/det.mp3"));
                reproductor->play();

                }

            }
        }
    }


void MainWindow::defensaObjetos()
{
    if(defendiendose==true){
         atacar->start(300);
         reproductor->setMedia(QUrl("qrc:/sonidos/detect.mp3"));
         reproductor->play();
    }
}

void MainWindow::ataqueSeguido()
{
    for(auto& iterador:proyectiles){
    defendiendose=canonDos->detectarAmenaza(iterador->alcance_maximo);
    if(defendiendose==true){
        if(onair==false){
            for(unsigned short int a=0;a<maximoDefensivos;a++){
                if(-1*canonUno->getAngulo()<45){
                    angle=  90-canonUno->getAngulo()+15+rand()%18;
                }
                else{
                    angle = 90-canonUno->getAngulo()-15+rand()%18;
                }
                tmpProyectil =new proyectil(angle,180,canonDos->getCoordenada_x()+30,canonDos->getCoordenada_y(),20,20);
                proyectilesDefensivos.push_back(tmpProyectil);
                escena->addItem(tmpProyectil);
                onair=true;
            }
        }
         //short int aleatorio = 90+ rand() % 120;


         }
    }

}

void MainWindow::disparar()
{
    for(unsigned short int a =0;a<maximoDisparos;a++){
        tmpProyectil =new proyectil(-canonUno->getAngulo() +1+rand()% 10,100,canonUno->getCoordenada_x()+30,canonUno->getCoordenada_y(),20,20);
        escena->addItem(tmpProyectil);
        proyectiles.push_back(tmpProyectil);
            }
             reproductor->setMedia(QUrl("qrc:/sonidos/disparar.mp3"));
             reproductor->play();
             deteccion->stop();
             deteccion->start(3000);
             defendiendose=true;

}


void MainWindow::keyPressEvent(QKeyEvent *evento)
{
        //---------------  espacio   ---------------
        if(evento->key()==Qt::Key_Space){
            disparar();
        }
        if(evento->key()==Qt::Key_W){
            //balaCanon->move
            canonUno->subir();
            ui->labelAngulo->setText(QString::number(canonUno->getAngulo()));
            ui->labelAngulo->setStyleSheet(" font-weight:600");
        }
        if(evento->key()==Qt::Key_S){
            canonUno->bajar();
            ui->labelAngulo->setText(QString::number(canonUno->getAngulo()));
            ui->labelAngulo->setStyleSheet(" font-weight:600");
        }
}

void MainWindow::on_btn_1_clicked()
{
    maximoDisparos=1;
    disparar();
}

void MainWindow::on_btn_3_clicked()
{
    maximoDisparos=3;
    disparar();
}

void MainWindow::on_btn_1def_clicked()
{
    maximoDefensivos=1;
}

void MainWindow::on_btn_3def_clicked()
{
    maximoDefensivos=3;
}
