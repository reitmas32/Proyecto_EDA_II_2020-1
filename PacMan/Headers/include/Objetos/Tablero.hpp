#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Pacman.hpp"

#include "../Mapas.hpp"

#include "../Estructuras_de_Datos/Graph.hpp"

#include <fstream>
std::string intToString(int num){
    std::stringstream sout;
    sout << num;
    return sout.str();
}
class Tablero
{
public:
    
    int posPacman;
    int posFantasma;

    size_t Columnas;
    size_t Filas;
    uint8_t** mapa;
    Cuadro** tablero;
    size_t vidas;
    std::vector<int> ColorPared;
    std::vector<int> ColorCamino;
    size_t puntos;
public:
    Tablero();
    Tablero(int mapa, std::vector<int> ColorPared, std::vector<int> ColorCamino);
    ~Tablero();

    void creaMundo();

    void creaGrafo();

    void pinta();

    bool colision(Figura figura);

    void repinta();

    bool deadPacman(Pacman p, Fantasma* f);
};

Tablero::Tablero(/* args */)
{

}

Tablero::Tablero(int mapa, std::vector<int> ColorPared, std::vector<int> ColorCamino){
    
    this->ColorPared = ColorPared;
    this->ColorCamino = ColorCamino;
    switch (mapa)
    {
    case MAPAS::LEVEL_ONE:
        this->Columnas = MAPAS::COLUMNAS_LevelOne;
        this->Filas = MAPAS::FILAS_LevelOne;
        this->mapa = (uint8_t**)calloc(this->Filas, sizeof(uint8_t*));
        for( size_t i = 0; i < this->Filas; i++){
            this->mapa[i] = (uint8_t*)calloc(this->Columnas, sizeof(uint8_t));
        }
        for(size_t i = 0; i < this->Filas; i++){
            for( size_t j = 0; j < this->Columnas; j++){
                this->mapa[i][j] = MAPAS::LevelOne[i][j];
            }
        }
        this->tablero = (Cuadro**)calloc(this->Filas, sizeof(Cuadro*));
        for( size_t i = 0; i < this->Filas; i++){
            this->tablero[i] = (Cuadro*)calloc(this->Columnas, sizeof(Cuadro));
        }
        break;
    
    default:
        break;
    }
    this->vidas = 3;
    this->puntos = 0;
}

Tablero::~Tablero()
{
    //this->LevelOneGraph.~Graph();
}

void Tablero::creaMundo(){

    for(size_t i = 0; i < this->Filas; i++){
        for(size_t j = 0; j < this->Columnas; j++){
            switch (this->mapa[i][j])
            {
            case 0:
            case 3:
                this->tablero[i][j].setPosicion(j,i);
                this->tablero[i][j].setColorSolido(this->ColorCamino);
                this->tablero[i][j].setColorDecora(this->ColorCamino);
            break;
            case 1:
                this->tablero[i][j].setPosicion(j,i);
                this->tablero[i][j].setColorSolido(this->ColorPared);
                this->tablero[i][j].setColorDecora(this->ColorPared);
            break;
            case 2:
                this->tablero[i][j].setPosicion(j,i);
                this->tablero[i][j].setColorSolido(Colors::Brown);
                this->tablero[i][j].setColorDecora(Colors::Brown);
            break;
            default:
                break;
            }
        }
    }
}

void Tablero::pinta(){
    vredimensiona(this->Columnas * TAM + MARGEN * 2 + TAM*6, this->Filas * TAM + MARGEN * 2);
    for(size_t i = 0; i < this->Filas; i++){
        for(size_t j = 0; j < this->Columnas; j++){
            this->tablero[i][j].pinta();
        }
    }
}

bool Tablero::colision(Figura figura){

        if(figura.getPosicion().x < 0 || figura.getPosicion().x >= (int)this->Columnas){
            return true;
        }
        if(figura.getPosicion().y < 0 || figura.getPosicion().y >= (int)this->Filas){
            return true;
        }
        if(this->tablero[figura.getPosicion().y][figura.getPosicion().x].getColorSolido() != this->ColorCamino){
            return true;
        }
        return false;
}

void Tablero::repinta(){
    borra();
    this->pinta();

    for(size_t i = 0; i < this->vidas ; i++){
        Pacman p_v = Pacman(23,2+i*2,Colors::Yellow,Colors::Black);
        p_v.pinta_der();
    }
    color(BLANCO);
    texto(23*TAM, 10*TAM, "Puntos:");
    texto(23*TAM,11*TAM, intToString(this->puntos));
    refresca();
}


#endif  //TABLERO_HPP
