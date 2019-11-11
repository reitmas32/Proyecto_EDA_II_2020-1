#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Cuadro.hpp"

#include "Pacman.hpp"

#include "Figura.hpp"

#include "Mapas.hpp"

class Tablero
{
public:
    Cuadro tablero[COLUMNAS][FILAS];
public:
    Tablero();
    ~Tablero();

    void creaMundo();

    void pinta();

    bool colision(Figura figura);

    void repinta();
};

Tablero::Tablero(/* args */)
{
}

Tablero::~Tablero()
{
}

void Tablero::creaMundo(){

    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            switch (MAPAS::LevelOne[j][i])
            {
            case 0:
                this->tablero[i][j].setPosicion(i,j);
                this->tablero[i][j].setColorSolido(Colors::Black);
                this->tablero[i][j].setColorDecora(Colors::Black);
            break;
            case 1:
                this->tablero[i][j].setPosicion(i,j);
                this->tablero[i][j].setColorSolido(Colors::Gray);
                this->tablero[i][j].setColorDecora(Colors::Gray);
            break;
            case 2:
                this->tablero[i][j].setPosicion(i,j);
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
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            this->tablero[i][j].pinta();
        }
    }
}

bool Tablero::colision(Figura figura){

        if(figura.getPosicion().x < 0 || figura.getPosicion().x >= COLUMNAS){
            return true;
        }
        if(figura.getPosicion().y < 0 || figura.getPosicion().y >= FILAS){
            return true;
        }
        if(this->tablero[figura.getPosicion().x][figura.getPosicion().y].getColorSolido() != Colors::Black){
            return true;
        }
        return false;
}

void Tablero::repinta(){
    borra();
    this->pinta();
    refresca();
}

#endif  //TABLERO_HPP
