#ifndef CANONES_H
#define CANONES_H
#include <QPainter>
#include <QGraphicsItem>
#include "proyectil.h"

class canones:public QGraphicsItem
{
private:
    signed short int angulo;
    unsigned short int ancho , alto ;
    signed short int coordenada_x , coordenada_y ;
public:
    void disparar();
    void actualizar();
    void subir();
    void bajar();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    canones(unsigned short int ancho,unsigned short int alto,signed short int x,signed short int y);
};

#endif // CANONES_H
