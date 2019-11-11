#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Cuadro.hpp"

#include "Pacman.hpp"

#include "Figura.hpp"

#include "Mapas.hpp"

#include "Estructuras_de_Datos/Graph/Graph.hpp"

class Tablero
{
public:
    Cuadro tablero[COLUMNAS][FILAS];
    Graph* LevelOneGraph = new Graph();
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
    
    LevelOneGraph->add_vertex(Vertex("2,2"));
    LevelOneGraph->add_vertex(Vertex("2,3"));
    LevelOneGraph->add_vertex(Vertex("2,4"));
    LevelOneGraph->add_vertex(Vertex("2,5"));
    LevelOneGraph->add_vertex(Vertex("2,6"));
    LevelOneGraph->add_vertex(Vertex("2,11"));
    LevelOneGraph->add_vertex(Vertex("2,16"));
    LevelOneGraph->add_vertex(Vertex("2,17"));
    LevelOneGraph->add_vertex(Vertex("2,18"));
    LevelOneGraph->add_vertex(Vertex("2,20"));
    LevelOneGraph->add_vertex(Vertex("2,21"));
    LevelOneGraph->add_vertex(Vertex("2,22"));
    LevelOneGraph->add_vertex(Vertex("3,2"));
    LevelOneGraph->add_vertex(Vertex("3,4"));
    LevelOneGraph->add_vertex(Vertex("3,6"));
    LevelOneGraph->add_vertex(Vertex("3,11"));
    LevelOneGraph->add_vertex(Vertex("3,16"));
    LevelOneGraph->add_vertex(Vertex("3,18"));
    LevelOneGraph->add_vertex(Vertex("3,19"));
    LevelOneGraph->add_vertex(Vertex("3,20"));
    LevelOneGraph->add_vertex(Vertex("3,22"));
    LevelOneGraph->add_vertex(Vertex("4,2"));
    LevelOneGraph->add_vertex(Vertex("4,4"));
    LevelOneGraph->add_vertex(Vertex("4,6"));
    LevelOneGraph->add_vertex(Vertex("4,11"));
    LevelOneGraph->add_vertex(Vertex("4,16"));
    LevelOneGraph->add_vertex(Vertex("4,18"));
    LevelOneGraph->add_vertex(Vertex("4,19"));
    LevelOneGraph->add_vertex(Vertex("4,20"));
    LevelOneGraph->add_vertex(Vertex("4,22"));
    LevelOneGraph->add_vertex(Vertex("5,2"));
    LevelOneGraph->add_vertex(Vertex("5,3"));
    LevelOneGraph->add_vertex(Vertex("5,4"));
    LevelOneGraph->add_vertex(Vertex("5,5"));
    LevelOneGraph->add_vertex(Vertex("5,6"));
    LevelOneGraph->add_vertex(Vertex("5,7"));
    LevelOneGraph->add_vertex(Vertex("5,8"));
    LevelOneGraph->add_vertex(Vertex("5,9"));
    LevelOneGraph->add_vertex(Vertex("5,10"));
    LevelOneGraph->add_vertex(Vertex("5,11"));
    LevelOneGraph->add_vertex(Vertex("5,12"));
    LevelOneGraph->add_vertex(Vertex("5,13"));
    LevelOneGraph->add_vertex(Vertex("5,14"));
    LevelOneGraph->add_vertex(Vertex("5,15"));
    LevelOneGraph->add_vertex(Vertex("5,16"));
    LevelOneGraph->add_vertex(Vertex("5,20"));
    LevelOneGraph->add_vertex(Vertex("5,22"));
    LevelOneGraph->add_vertex(Vertex("6,2"));
    LevelOneGraph->add_vertex(Vertex("6,4"));
    LevelOneGraph->add_vertex(Vertex("6,10"));
    LevelOneGraph->add_vertex(Vertex("6,11"));
    LevelOneGraph->add_vertex(Vertex("6,16"));
    LevelOneGraph->add_vertex(Vertex("6,17"));
    LevelOneGraph->add_vertex(Vertex("6,18"));
    LevelOneGraph->add_vertex(Vertex("6,19"));
    LevelOneGraph->add_vertex(Vertex("6,20"));
    LevelOneGraph->add_vertex(Vertex("6,22"));
    LevelOneGraph->add_vertex(Vertex("7,2"));
    LevelOneGraph->add_vertex(Vertex("7,4"));
    LevelOneGraph->add_vertex(Vertex("7,5"));
    LevelOneGraph->add_vertex(Vertex("7,6"));
    LevelOneGraph->add_vertex(Vertex("7,8"));
    LevelOneGraph->add_vertex(Vertex("7,9"));
    LevelOneGraph->add_vertex(Vertex("7,10"));
    LevelOneGraph->add_vertex(Vertex("7,11"));
    LevelOneGraph->add_vertex(Vertex("7,12"));
    LevelOneGraph->add_vertex(Vertex("7,13"));
    LevelOneGraph->add_vertex(Vertex("7,14"));
    LevelOneGraph->add_vertex(Vertex("7,15"));
    LevelOneGraph->add_vertex(Vertex("7,16"));
    LevelOneGraph->add_vertex(Vertex("7,18"));
    LevelOneGraph->add_vertex(Vertex("7,20"));
    LevelOneGraph->add_vertex(Vertex("7,21"));
    LevelOneGraph->add_vertex(Vertex("7,22"));
    LevelOneGraph->add_vertex(Vertex("8,2"));
    LevelOneGraph->add_vertex(Vertex("8,3"));
    LevelOneGraph->add_vertex(Vertex("8,4"));
    LevelOneGraph->add_vertex(Vertex("8,6"));
    LevelOneGraph->add_vertex(Vertex("8,7"));
    LevelOneGraph->add_vertex(Vertex("8,8"));
    LevelOneGraph->add_vertex(Vertex("8,12"));
    LevelOneGraph->add_vertex(Vertex("8,14"));
    LevelOneGraph->add_vertex(Vertex("8,15"));
    LevelOneGraph->add_vertex(Vertex("8,16"));
    LevelOneGraph->add_vertex(Vertex("8,18"));
    LevelOneGraph->add_vertex(Vertex("8,20"));
    LevelOneGraph->add_vertex(Vertex("8,21"));
    LevelOneGraph->add_vertex(Vertex("8,22"));
    LevelOneGraph->add_vertex(Vertex("9,4"));
    LevelOneGraph->add_vertex(Vertex("9,7"));
    LevelOneGraph->add_vertex(Vertex("9,8"));
    LevelOneGraph->add_vertex(Vertex("9,9"));
    LevelOneGraph->add_vertex(Vertex("9,10"));
    LevelOneGraph->add_vertex(Vertex("9,12"));
    LevelOneGraph->add_vertex(Vertex("9,15"));
    LevelOneGraph->add_vertex(Vertex("9,16"));
    LevelOneGraph->add_vertex(Vertex("9,17"));
    LevelOneGraph->add_vertex(Vertex("9,18"));
    LevelOneGraph->add_vertex(Vertex("9,22"));
    LevelOneGraph->add_vertex(Vertex("10,2"));
    LevelOneGraph->add_vertex(Vertex("10,3"));
    LevelOneGraph->add_vertex(Vertex("10,4"));
    LevelOneGraph->add_vertex(Vertex("10,6"));
    LevelOneGraph->add_vertex(Vertex("10,7"));
    LevelOneGraph->add_vertex(Vertex("10,8"));
    LevelOneGraph->add_vertex(Vertex("10,12"));
    LevelOneGraph->add_vertex(Vertex("10,14"));
    LevelOneGraph->add_vertex(Vertex("10,15"));
    LevelOneGraph->add_vertex(Vertex("10,16"));
    LevelOneGraph->add_vertex(Vertex("10,18"));
    LevelOneGraph->add_vertex(Vertex("10,20"));
    LevelOneGraph->add_vertex(Vertex("10,21"));
    LevelOneGraph->add_vertex(Vertex("10,22"));
    LevelOneGraph->add_vertex(Vertex("11,2"));
    LevelOneGraph->add_vertex(Vertex("11,4"));
    LevelOneGraph->add_vertex(Vertex("11,5"));
    LevelOneGraph->add_vertex(Vertex("11,6"));
    LevelOneGraph->add_vertex(Vertex("11,8"));
    LevelOneGraph->add_vertex(Vertex("11,9"));
    LevelOneGraph->add_vertex(Vertex("11,10"));
    LevelOneGraph->add_vertex(Vertex("11,11"));
    LevelOneGraph->add_vertex(Vertex("11,12"));
    LevelOneGraph->add_vertex(Vertex("11,13"));
    LevelOneGraph->add_vertex(Vertex("11,14"));
    LevelOneGraph->add_vertex(Vertex("11,15"));
    LevelOneGraph->add_vertex(Vertex("11,16"));
    LevelOneGraph->add_vertex(Vertex("11,18"));
    LevelOneGraph->add_vertex(Vertex("11,20"));
    LevelOneGraph->add_vertex(Vertex("11,21"));
    LevelOneGraph->add_vertex(Vertex("11,22"));
    LevelOneGraph->add_vertex(Vertex("12,2"));
    LevelOneGraph->add_vertex(Vertex("12,4"));
    LevelOneGraph->add_vertex(Vertex("12,10"));
    LevelOneGraph->add_vertex(Vertex("12,11"));
    LevelOneGraph->add_vertex(Vertex("12,16"));
    LevelOneGraph->add_vertex(Vertex("12,17"));
    LevelOneGraph->add_vertex(Vertex("12,18"));
    LevelOneGraph->add_vertex(Vertex("12,19"));
    LevelOneGraph->add_vertex(Vertex("12,20"));
    LevelOneGraph->add_vertex(Vertex("12,22"));
    LevelOneGraph->add_vertex(Vertex("13,2"));
    LevelOneGraph->add_vertex(Vertex("13,3"));
    LevelOneGraph->add_vertex(Vertex("13,4"));
    LevelOneGraph->add_vertex(Vertex("13,5"));
    LevelOneGraph->add_vertex(Vertex("13,6"));
    LevelOneGraph->add_vertex(Vertex("13,7"));
    LevelOneGraph->add_vertex(Vertex("13,8"));
    LevelOneGraph->add_vertex(Vertex("13,9"));
    LevelOneGraph->add_vertex(Vertex("13,10"));
    LevelOneGraph->add_vertex(Vertex("13,11"));
    LevelOneGraph->add_vertex(Vertex("13,12"));
    LevelOneGraph->add_vertex(Vertex("13,13"));
    LevelOneGraph->add_vertex(Vertex("13,14"));
    LevelOneGraph->add_vertex(Vertex("13,15"));
    LevelOneGraph->add_vertex(Vertex("13,16"));
    LevelOneGraph->add_vertex(Vertex("13,20"));
    LevelOneGraph->add_vertex(Vertex("13,22"));
    LevelOneGraph->add_vertex(Vertex("14,2"));
    LevelOneGraph->add_vertex(Vertex("14,4"));
    LevelOneGraph->add_vertex(Vertex("14,6"));
    LevelOneGraph->add_vertex(Vertex("14,11"));
    LevelOneGraph->add_vertex(Vertex("14,16"));
    LevelOneGraph->add_vertex(Vertex("14,18"));
    LevelOneGraph->add_vertex(Vertex("14,19"));
    LevelOneGraph->add_vertex(Vertex("14,20"));
    LevelOneGraph->add_vertex(Vertex("14,22"));
    LevelOneGraph->add_vertex(Vertex("15,2"));
    LevelOneGraph->add_vertex(Vertex("15,4"));
    LevelOneGraph->add_vertex(Vertex("15,6"));
    LevelOneGraph->add_vertex(Vertex("15,11"));
    LevelOneGraph->add_vertex(Vertex("15,16"));
    LevelOneGraph->add_vertex(Vertex("15,18"));
    LevelOneGraph->add_vertex(Vertex("15,19"));
    LevelOneGraph->add_vertex(Vertex("15,20"));
    LevelOneGraph->add_vertex(Vertex("15,22"));
    LevelOneGraph->add_vertex(Vertex("16,2"));
    LevelOneGraph->add_vertex(Vertex("16,3"));
    LevelOneGraph->add_vertex(Vertex("16,4"));
    LevelOneGraph->add_vertex(Vertex("16,5"));
    LevelOneGraph->add_vertex(Vertex("16,6"));
    LevelOneGraph->add_vertex(Vertex("16,11"));
    LevelOneGraph->add_vertex(Vertex("16,16"));
    LevelOneGraph->add_vertex(Vertex("16,17"));
    LevelOneGraph->add_vertex(Vertex("16,18"));
    LevelOneGraph->add_vertex(Vertex("16,20"));
    LevelOneGraph->add_vertex(Vertex("16,21"));
    LevelOneGraph->add_vertex(Vertex("16,22"));
}

Tablero::~Tablero()
{
    this->LevelOneGraph->~Graph();
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
