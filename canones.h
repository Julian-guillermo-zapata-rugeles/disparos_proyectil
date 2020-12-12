#ifndef CANONES_H
#define CANONES_H
#include <QPainter>
#include <QGraphicsItem>

class canones:public QGraphicsItem
{
private:
    signed short int angulo;
    unsigned short int ancho , alto ;
    signed short int coordenada_x , coordenada_y ;
public:
    void actualizar();
    void subir();
    void bajar();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    canones(unsigned short int ancho,unsigned short int alto,signed short int x,signed short int y);
    signed short getCoordenada_x() const;
    signed short getCoordenada_y() const;
    signed short getAngulo() const;
};

#endif // CANONES_H
