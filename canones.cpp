#include "canones.h"
#include <math.h>
#include <iostream>


signed short canones::getCoordenada_x() const
{
    return coordenada_x;
}

signed short canones::getCoordenada_y() const
{
    return coordenada_y;
}

signed short canones::getAngulo() const
{
    return angulo;
}

bool canones::detectarAmenaza(signed short int alcance)
{
    if(alcance>coordenada_x-ancho and alcance<coordenada_x+80){
        return true;
    }
    else{
        return  false;
    }
}

void canones::actualizar()
{
    this->setPos(coordenada_x,coordenada_y);
    std::cout << coordenada_x <<" - "<<coordenada_y<< std::endl;

}

void canones::subir()
{
    angulo=angulo-1;
    this->setRotation(angulo);
}

void canones::bajar()
{
    angulo=angulo+1;
    this->setRotation(angulo);
}


QRectF canones::boundingRect() const
{
    return QRectF(coordenada_x,coordenada_y,ancho,alto);
}

void canones::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

canones::canones(unsigned short _ancho, unsigned short _alto, signed short _x, signed short _y)
{
    ancho=_ancho;
    alto=_alto;
    coordenada_x=_x;
    coordenada_y=_y;
    angulo=0;
}
