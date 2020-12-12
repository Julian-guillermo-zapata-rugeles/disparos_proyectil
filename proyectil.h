#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include "movimientoparabolico.h"
#include <math.h>

class proyectil: public QGraphicsItem , public movimientoParabolico
{
private:
   signed int ancho;
   signed int alto ;
   int x_position;
   int y_position;

public:
   proyectil(short int angulo_ , signed short int velocidad_, int _x_pos, int _y_pos,int _ancho_, int _alto_);
   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
   void moverProyectil();
   int getY_position() const;
   int getX_position() const;
};

#endif // PROYECTIL_H
