#include "proyectil.h"

int proyectil::getY_position() const
{
    return posicion_y;
}

int proyectil::getX_position() const
{
    return posicion_x;
}

void proyectil::setAngulo(signed short angle)
{
    setAnguloDisparo(angle);
}



proyectil::proyectil(short int angulo , signed short int velocidad ,int x, int y , int ancho_, int alto_ ):
    movimientoParabolico(angulo,velocidad , x , y)
{
    ancho=ancho_;
    alto=alto_;
    x_position=x;
    y_position=y;
}

QRectF proyectil::boundingRect() const
{
    return QRectF(x_position,y_position,ancho,alto);
}

void proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());

}

void proyectil::moverProyectil()
{
    this->avanzarProyectil();
    this->setPos(posicion_x,-posicion_y);
}
