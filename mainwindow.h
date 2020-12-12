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
    QGraphicsScene *escena;
    void keyPressEvent(QKeyEvent *evento);
    ~MainWindow();

public slots:
    void moverObjetos();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
