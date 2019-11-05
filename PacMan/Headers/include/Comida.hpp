#ifndef COMIDA_HPP
#define COMIDA_HPP

#include "Figura.hpp"

class Comida : public Figura{
private:
    /* data */
public:
    Comida(/* args */);
    Comida(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Comida();

    void pinta();
};

Comida::Comida(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora)
{
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

Comida::Comida(/* args */)
{
}

Comida::~Comida()
{
}

void Comida::pinta(){
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 6,
                        MARGEN + 1 + this->getPosicion().y * TAM + 6,
                        MARGEN + 1 + this->getPosicion().x * TAM + 8,
                        MARGEN + 1 + this->getPosicion().y * TAM + 8);
}
#endif