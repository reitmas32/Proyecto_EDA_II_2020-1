#ifndef FIGURA_HPP
#define FIGURA_HPP

/**
 * Biblioteca de la clase Cuadro
 **/
#include "Graphics_Engine/Cuadro.hpp"

/**
 * Clase Figura es una clase intermedia entre Cuadro y Pacman o Fantasma
 **/
class Figura : public Cuadro{
private:
    
public:
    Figura();
    ~Figura();
    void mueve_arriba();
    void mueve_abajo();
    void mueve_derecha();
    void mueve_izquierda();
};

#endif  //FIGURA_HPP