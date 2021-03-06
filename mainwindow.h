#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsItem>
#include "movimientoparabolico.h"
#include <proyectil.h>
#include <canones.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QVector>
#include <QTimer>
#include <QtMultimedia>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool defendiendose=false;
    QMediaPlayer *reproductor = new QMediaPlayer;
    QVector <proyectil*> proyectiles;
    QVector <proyectil*> proyectilesDefensivos;
    canones *canonUno;
    canones *canonDos;
    proyectil *tmpProyectil;
    QTimer *reloj;
    QTimer *deteccion;
    QTimer *atacar;
    QGraphicsScene *escena;
    void keyPressEvent(QKeyEvent *evento);
    ~MainWindow();
    unsigned short int maximoDisparos=1;
    unsigned short int maximoDefensivos=1;
    bool onair=false;
    int angle=0;

public slots:
    void moverObjetos();
    void defensaObjetos();
    void ataqueSeguido();
    void disparar();
private slots:
    void on_btn_1_clicked();

    void on_btn_3_clicked();

    void on_btn_1def_clicked();

    void on_btn_3def_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
