#include "movimientoparabolico.h"
#include <math.h>
#include <iostream>

signed short movimientoParabolico::getAnguloDisparo() const
{
    return anguloDisparo;
}

void movimientoParabolico::setAnguloDisparo(signed short value)
{
    anguloDisparo = value;
}


movimientoParabolico::movimientoParabolico(ssi _angulo_ , ssi velocidad_int ,signed int _x_ , signed int _y_)
{
    // inicializamos los valores del constructor
    anguloDisparo=_angulo_;
    posicion_x=_x_;
    posicion_y=_y_;
    velocidadInstantanea=velocidad_int;
    tiempo=0;
    //
    velocidad_inicial_x = velocidadInstantanea * cos((anguloDisparo*3.1416)/180);
    velocidad_inicial_y = velocidadInstantanea * sin((anguloDisparo*3.1416)/180);
    velocidad_horizontal = 0 ;
    altura_alcanzada=0;
    tiempo=0;
    altura_maxima= ((sin((anguloDisparo*3.1416)/180)*(sin((anguloDisparo*3.1416)/180)))*(velocidadInstantanea*velocidadInstantanea))/(9.8*2) ;
    alcance_maximo=abs((pow(velocidadInstantanea,2)*sin(2*((anguloDisparo*3.1416)/180)))/10);
    std::cout << "velocidad  " << velocidadInstantanea <<std::endl;
    std::cout << "angulo " << anguloDisparo <<std::endl;
    std::cout << "alcance maximo horizontal " << alcance_maximo <<std::endl;
}

void movimientoParabolico::avanzarProyectil()
{
    tiempo=tiempo+0.1;
    posicion_x = float(velocidad_inicial_x*tiempo);
    posicion_y=float(0+velocidad_inicial_y*tiempo+(0.5*(-9.8*tiempo*tiempo)));
    //std::cout << "Avance Metros en  X -> "<< posicion_x << std::endl;
    //std::cout << "Avance Metros en  Y -> "<< posicion_y << std::endl;
    velocidad_horizontal=posicion_x/tiempo;
}
