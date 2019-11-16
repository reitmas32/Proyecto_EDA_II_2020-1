#include "../../../Headers/include/Objetos/Fantasma.hpp"
Fantasma::Fantasma(/* args */)
{
}

Fantasma::Fantasma(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora)
{
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

Fantasma::~Fantasma()
{
}

void Fantasma::pinta(){
    /*
    color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );
    
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
                        */
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 3,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM - 3,
                        MARGEN + this->getPosicion().y * TAM + TAM);

    color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 4,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 4,
                        MARGEN + 1 + this->getPosicion().x * TAM + 5,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 1);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 7,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 4,
                        MARGEN + 1 + this->getPosicion().x * TAM + 8,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 1);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 10,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 4,
                        MARGEN + 1 + this->getPosicion().x * TAM + 11,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 1);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 5,
                        MARGEN + 1 + this->getPosicion().y * TAM + 2,
                        MARGEN + 1 + this->getPosicion().x * TAM + 7,
                        MARGEN + 1 + this->getPosicion().y * TAM + 4);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 8,
                        MARGEN + 1 + this->getPosicion().y * TAM + 2,
                        MARGEN + 1 + this->getPosicion().x * TAM + 10,
                        MARGEN + 1 + this->getPosicion().y * TAM + 4);

}