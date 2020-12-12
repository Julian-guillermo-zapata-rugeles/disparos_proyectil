#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QGraphicsItem>
#include <QPainter>
#include "movimientoparabolico.h"

class proyectil:public QGraphicsItem , private movimientoParabolico
{
private:
   signed int ancho;
   signed int alto ;
   int x_position;
   int y_position;
public:
   proyectil(short int angulo_ , signed short int velocidad_, int _x_pos, int _y_pos,int _ancho_, int _alto_);
   void mostrar_pared();
   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
};

#endif // PROYECTIL_H
