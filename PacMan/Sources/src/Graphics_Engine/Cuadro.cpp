#include "../../../Headers/include/Graphics_Engine/Cuadro.hpp"

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
    //Se cambia el color para pintar en el color Solido del cuadro
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
    //Se cambia el color para pintar en el color Decora del cuadro
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