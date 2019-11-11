#ifndef GHOST_HPP
#define GHOST_HPP

#include <sstream>

#include "Cuadro.hpp"

#include "Figura.hpp"

#include "Mapas.hpp"

#include "Estructuras_de_Datos/Graph/Graph.hpp"

std::string inToString(int num){
    std::stringstream sout;
    sout << num;
    return sout.str();
} 

std::string connectNums(int num1, int num2){
    std::string ret = inToString(num1) + "," + inToString(num2);
    return ret;
}

class Fantasma : public Figura{
private:
    Graph* mapa;
public:
    Fantasma(/* args */);
    Fantasma(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Fantasma();

    int creaMapa();
    void pinta();
};

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

int Fantasma::creaMapa(){
    this->mapa = new Graph();
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            if(MAPAS::LevelOne[j][i] == 0){
                this->mapa->add_vertex(Vertex(connectNums(i,j)));
            }
            
        }
    }
    
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            if(MAPAS::LevelOne[j][i] == 0){
                if(MAPAS::LevelOne[j - 1][i] == 0){
                    this->mapa->add_edge(connectNums(i,j),connectNums(i,j - 1));
                }
                if(MAPAS::LevelOne[j + 1][i] == 0){
                    this->mapa->add_edge(connectNums(i,j),connectNums(i,j + 1));
                }
                if(MAPAS::LevelOne[j][i - 1] == 0){
                    this->mapa->add_edge(connectNums(i,j),connectNums(i - 1,j));
                }
                if(MAPAS::LevelOne[j][i + 1] == 0){
                    this->mapa->add_edge(connectNums(i,j),connectNums(i + 1,j));
                }
            }
        }
    }    
    
    return 0;
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

#endif  //GHOST_HPP
