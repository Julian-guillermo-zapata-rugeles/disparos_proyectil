#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QGraphicsItem>
#include <QPainter>

class proyectil:public QGraphicsItem
{
private:
   signed int ancho;
   signed int alto ;
   int x_position;
   int y_position;
public:
   proyectil(int , int , int x, int y);
   void mostrar_pared();
   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
};

#endif // PROYECTIL_H
