#ifndef FIGURA_HPP
#define FIGURA_HPP

#include "Cuadro.hpp"

class Figura : public Cuadro{
private:
    /* data */
public:
    Figura();
    ~Figura();
    void mueve_arriba();
    void mueve_abajo();
    void mueve_derecha();
    void mueve_izquierda();
};

Figura::Figura(/* args */)
{
}

Figura::~Figura()
{
}

void Figura::mueve_arriba(){

    this->posicion.y = this->posicion.y - 1;

}

void Figura::mueve_abajo(){

    this->posicion.y++;

}

void Figura::mueve_derecha(){

    this->posicion.x++;

}

void Figura::mueve_izquierda(){

    this->posicion.x--;

}

#endif  //FIGURA_HPP