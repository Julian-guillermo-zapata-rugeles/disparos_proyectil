#ifndef MOVIMIENTOPARABOLICO_H
#define MOVIMIENTOPARABOLICO_H
#define ssi signed short int


class movimientoParabolico
{
protected:
    // serán hereado por los objetos de tipo bala que describirán trayectorias
    // parabólicas
    double tiempo;
    signed short int anguloDisparo;
    signed short int velocidadInstantanea;
    signed int posicion_x;
    signed int posicion_y;
    signed int velocidad_inicial_x;
    signed int velocidad_inicial_y;
    double altura_maxima;
    double velocidad_horizontal;
    double altura_alcanzada;
public:
    movimientoParabolico(ssi _angulo , ssi _velocidad ,signed int  x_pos , signed int y_pos);
    void avanzarProyectil();
    signed short getAnguloDisparo() const;
    void setAnguloDisparo(signed short value);
};

#endif // MOVIMIENTOPARABOLICO_H
