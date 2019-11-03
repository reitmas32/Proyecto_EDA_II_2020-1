#ifndef CUADRO_HPP
#define CUADRO_HPP

#include <iostream>

#include "miniwin.h"

#include "Colors.hpp"

#include <vector>

using namespace miniwin;

const int MARGEN = 20;

const int TAM = 15;

typedef struct Coord{
    int x, y;
    void rota_derecha();
}Coord;

void Coord::rota_derecha(){
    int tmp = this->x;
    this->x = -this->y;
    this->y = tmp;
}

class Cuadro
{
public:
    Coord posicion;
    std::vector<int> colorSolido;
    std::vector<int> colorDecora;
public:
    Cuadro(/* args */);
    Cuadro(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Cuadro();

    Coord getPosicion(){return this->posicion;}
    std::vector<int> getColorSolido(){return this->colorSolido;}
    std::vector<int> getColorDecora(){return this->colorDecora;}

    void setPosicion(int x, int y){posicion.x = x; posicion.y = y;}
    void setColorSolido(std::vector<int> colorSolido){
    
        for (size_t i = 0; i < 3; i++)
        {
            this->colorSolido.push_back(colorSolido[i]);
            //this->colorSolido[i] = colorSolido[i];
        }
    }
    void setColorDecora(std::vector<int> colorDecora){
        for (size_t i = 0; i < 3; i++)
        {
            this->colorDecora.push_back(colorDecora[i]);
        }
    }

    void pinta();
};

Cuadro::Cuadro(/* args */)
{
}

Cuadro::Cuadro(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora)
{
    
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

void Cuadro::pinta(){
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
    
    color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );
    rectangulo( MARGEN + 3 + this->getPosicion().x * TAM,
                MARGEN + 3 + this->getPosicion().y * TAM,
                MARGEN + this->getPosicion().x * TAM + TAM - 3,
                MARGEN + this->getPosicion().y * TAM + TAM - 3);
}

Cuadro::~Cuadro()
{
}


#endif  //CUADRO_HPP