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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QVector <proyectil*> proyectiles;
    canones *canonUno;
    QGraphicsScene *escena;
    void keyPressEvent(QKeyEvent *evento);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
