#ifndef CUADRO_HPP
#define CUADRO_HPP

/**
 * Se usara la biblioteca estandar de I/O de C++
 **/
#include <iostream>

/**
 * Se utilizara la estructura vector
 **/
#include <vector>

/**
 * API sobre la que se basa el pseudomotorgrafico
 **/ 
#include "miniwin.h"

/**
 * BIblioteca que almacena los valores de los colores para el pseudomotorgrafico
 **/
#include "Colors.hpp"

using namespace miniwin;

/**
 * Es el margen del Diplay
 **/
const int MARGEN = 20;

/**
 * Es el tamaño que tendra cada cuadro
 **/
const int TAM = 15;

/**
 * Estructura que almacena las coordenadas de cada cuadro respecto a todo el Display
 **/
typedef struct Coord{
    int x, y;
    void rota_derecha();
}Coord;

/**
 * Metodo que rota cada cuador 90° ala derecha
 **/
void Coord::rota_derecha(){
    int tmp = this->x;
    this->x = -this->y;
    this->y = tmp;
}

//! Definicion de la Clase Cuadro de esta clase heredan todos los elementos del pseudomotorgrafico
class Cuadro
{
private:
    Coord posicion;
    int id;
    std::vector<int> colorSolido;
    std::vector<int> colorDecora;
public:
    Cuadro(/* args */);
    Cuadro(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Cuadro();

    Coord getPosicion(){return this->posicion;}
    std::vector<int> getColorSolido(){return this->colorSolido;}
    std::vector<int> getColorDecora(){return this->colorDecora;}
    int getId(){return this->id;}

    void setPosicion(int x, int y){posicion.x = x; posicion.y = y;}

    void setColorSolido(std::vector<int> colorSolido){
        for (int i : colorSolido)   this->colorSolido.push_back(i);
    }
    void setColorDecora(std::vector<int> colorDecora){
        for (int i : colorDecora)   this->colorDecora.push_back(i);
    }
    void setId(int id){this->id = id;}

    void pinta();
};


#endif  //CUADRO_HPP