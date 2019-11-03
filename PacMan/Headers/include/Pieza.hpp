#ifndef PIEZA_HPP
#define PIEZA_HPP

#include <cstdlib>
#include "Cuadro.hpp"
#include "miniwin.h"

using namespace miniwin;

const Coord perifs[7][3]  = {
    { {1,0}, {0,1}, {1,1}},     //cuadrado
    { {1,0}, {-1,1}, {0,1}},    //S
    { {0,1}, {1,1}, {-1,0}},    //2
    { {0,-1}, {0,1}, {1,1}},    //L
    { {0,-1}, {0,1}, {-1,1}},   //J
    { {0,-1}, {0,1}, {0,2}},    //I
    { {-1,0}, {1,0}, {0,1}},    //T
};


class Pieza
{
private:
    Coord orig;         //Bloque central
    Coord peri[3];      //Bloques Perifericos
    std::vector<int> colorSolido;
    std::vector<int> colorDecora;
public:
    Pieza();
    ~Pieza();

    Coord getOrig(){return orig;}

    void setOrig(Coord orig){this->orig = orig;}

    std::vector<int> getColorSolido(){return this->colorSolido;}
    std::vector<int> getColorDecora(){return this->colorDecora;}
    
    Coord posicion(int n) const;
    void rota_derecha();
    void pinta() const;
};

Pieza::Pieza(/* args */)
{
    this->orig.x = 5;
    this->orig.y = 3;

    int pieza = rand() % 7;

    for (size_t i = 0; i < 3; i++)
    {
        this->peri[i] = perifs[pieza][i];
    }
    switch (pieza)
    {
        case 0:
            this->colorSolido = Colors::Blue;
            this->colorDecora = Colors::Blue;
        break;
        case 1:
            this->colorSolido = Colors::Red;
            this->colorDecora = Colors::Red;
        break;
        case 2:
            this->colorSolido = Colors::Cyan;
            this->colorDecora = Colors::Cyan;
        break;
        case 3:
            this->colorSolido = Colors::Green;
            this->colorDecora = Colors::Green;
        break;
        case 4:
            this->colorSolido = Colors::Yellow;
            this->colorDecora = Colors::Yellow;
        break;
        case 5:
            this->colorSolido = Colors::Magenta;
            this->colorDecora = Colors::Magenta;
        break;
        case 6:
            this->colorSolido = Colors::Red100;
            this->colorDecora = Colors::Red100;
        break;

    };
}

Coord Pieza::posicion(int n) const{
    Coord ret = {this->orig.x, this->orig.y};

    if( n!= 0){
        ret.x += peri[n-1].x;
        ret.y += peri[n-1].y;
    }
    return ret;
}

Pieza::~Pieza()
{
}

void Pieza::pinta() const{
    for(int i = 0; i < 4; i++){
        Coord c = this->posicion(i);
        Cuadro cua = Cuadro(c.x, c.y, this->colorSolido, this->colorDecora);
        cua.pinta();
    }
}

void Pieza::rota_derecha(){
    for (size_t i = 0; i < 3; i++){
        this->peri[i].rota_derecha();
    }
    
}

#endif // PIEZA_HPP