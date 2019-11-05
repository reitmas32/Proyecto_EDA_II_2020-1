#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Cuadro.hpp"

#include "Pacman.hpp"

#include "Figura.hpp"

const int FILAS = 25;

const int COLUMNAS = 19;

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
#if 1
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            this->tablero[i][j].setPosicion(i,j);
            this->tablero[i][j].setColorSolido(Colors::Black);
            this->tablero[i][j].setColorDecora(Colors::Black);
        }
    }

    for (size_t i = 0; i < COLUMNAS; i++)
    {
        this->tablero[i][0].setPosicion(i,0);
        this->tablero[i][0].colorSolido = Colors::Brown;
        this->tablero[i][0].colorDecora = Colors::Brown;

        this->tablero[i][FILAS-1].setPosicion(i,FILAS-1);
        this->tablero[i][FILAS-1].colorSolido = Colors::Brown;
        this->tablero[i][FILAS-1].colorDecora = Colors::Brown;
    }

    for (size_t j = 0; j < FILAS; j++)
    {
        this->tablero[0][j].setPosicion(0,j);
        this->tablero[0][j].colorSolido = Colors::Brown;
        this->tablero[0][j].colorDecora = Colors::Brown;      

        this->tablero[COLUMNAS-1][j].setPosicion(COLUMNAS-1,j);
        this->tablero[COLUMNAS-1][j].colorSolido = Colors::Brown;
        this->tablero[COLUMNAS-1][j].colorDecora = Colors::Brown;
    }

    for(size_t i = 1; i < COLUMNAS - 1; i++){
        this->tablero[i][1].setPosicion(i,1);
        this->tablero[i][1].colorSolido = Colors::Gray;
        this->tablero[i][1].colorDecora = Colors::Gray;  

        this->tablero[i][FILAS-2].setPosicion(i,FILAS-2);
        this->tablero[i][FILAS-2].colorSolido = Colors::Gray;
        this->tablero[i][FILAS-2].colorDecora = Colors::Gray; 
    }

    for(size_t j = 2; j < 8; j++){
        this->tablero[1][j].setPosicion(1,j);
        this->tablero[1][j].colorSolido = Colors::Gray;
        this->tablero[1][j].colorDecora = Colors::Gray; 

        this->tablero[17][j].setPosicion(17,j);
        this->tablero[17][j].colorSolido = Colors::Gray;
        this->tablero[17][j].colorDecora = Colors::Gray;   

        this->tablero[1][j+15].setPosicion(1,j+15);
        this->tablero[1][j+15].colorSolido = Colors::Gray;
        this->tablero[1][j+15].colorDecora = Colors::Gray; 

        this->tablero[17][j+15].setPosicion(17,j+15);
        this->tablero[17][j+15].colorSolido = Colors::Gray;
        this->tablero[17][j+15].colorDecora = Colors::Gray;   
    }

    for(size_t i = 0; i < 2; i++){
        this->tablero[i+3][3].setPosicion(i+3,3);
        this->tablero[i+3][3].colorSolido = Colors::Gray;
        this->tablero[i+3][3].colorDecora = Colors::Gray; 

        this->tablero[i+3][5].setPosicion(i+3,5);
        this->tablero[i+3][5].colorSolido = Colors::Gray;
        this->tablero[i+3][5].colorDecora = Colors::Gray;  

        this->tablero[i+6][3].setPosicion(i+6,3);
        this->tablero[i+6][3].colorSolido = Colors::Gray;
        this->tablero[i+6][3].colorDecora = Colors::Gray; 

        this->tablero[i+11][3].setPosicion(i+11,3);
        this->tablero[i+11][3].colorSolido = Colors::Gray;
        this->tablero[i+11][3].colorDecora = Colors::Gray; 

        this->tablero[i+14][3].setPosicion(i+14,3);
        this->tablero[i+14][3].colorSolido = Colors::Gray;
        this->tablero[i+14][3].colorDecora = Colors::Gray; 

        this->tablero[i+14][5].setPosicion(i+14,5);
        this->tablero[i+14][5].colorSolido = Colors::Gray;
        this->tablero[i+14][5].colorDecora = Colors::Gray;  

        this->tablero[i+7][17].setPosicion(i+7,17);
        this->tablero[i+7][17].colorSolido = Colors::Gray;
        this->tablero[i+7][17].colorDecora = Colors::Gray;

        this->tablero[i+10][17].setPosicion(i+10,17);
        this->tablero[i+10][17].colorSolido = Colors::Gray;
        this->tablero[i+10][17].colorDecora = Colors::Gray;
    }

    for(size_t i = 0; i < 4; i++){
        this->tablero[i+1][7].setPosicion(i+1,7);
        this->tablero[i+1][7].colorSolido = Colors::Gray;
        this->tablero[i+1][7].colorDecora = Colors::Gray;

        this->tablero[i+1][10].setPosicion(i+1,10);
        this->tablero[i+1][10].colorSolido = Colors::Gray;
        this->tablero[i+1][10].colorDecora = Colors::Gray;

        this->tablero[i+14][7].setPosicion(i+14,7);
        this->tablero[i+14][7].colorSolido = Colors::Gray;
        this->tablero[i+14][7].colorDecora = Colors::Gray;

        this->tablero[i+14][10].setPosicion(i+14,10);
        this->tablero[i+14][10].colorSolido = Colors::Gray;
        this->tablero[i+14][10].colorDecora = Colors::Gray;

        this->tablero[i+1][12].setPosicion(i+1,12);
        this->tablero[i+1][12].colorSolido = Colors::Gray;
        this->tablero[i+1][12].colorDecora = Colors::Gray;

        this->tablero[i+1][15].setPosicion(i+1,15);
        this->tablero[i+1][15].colorSolido = Colors::Gray;
        this->tablero[i+1][15].colorDecora = Colors::Gray;

        this->tablero[i+14][12].setPosicion(i+14,12);
        this->tablero[i+14][12].colorSolido = Colors::Gray;
        this->tablero[i+14][12].colorDecora = Colors::Gray;

        this->tablero[i+14][15].setPosicion(i+14,15);
        this->tablero[i+14][15].colorSolido = Colors::Gray;
        this->tablero[i+14][15].colorDecora = Colors::Gray;

        this->tablero[i+3][21].setPosicion(i+3,21);
        this->tablero[i+3][21].colorSolido = Colors::Gray;
        this->tablero[i+3][21].colorDecora = Colors::Gray;

        this->tablero[i+12][21].setPosicion(i+12,21);
        this->tablero[i+12][21].colorSolido = Colors::Gray;
        this->tablero[i+12][21].colorDecora = Colors::Gray;

    }

    for(size_t j = 0; j < 2; j++){
        this->tablero[9][j+2].setPosicion(9,j+2);
        this->tablero[9][j+2].colorSolido = Colors::Gray;
        this->tablero[9][j+2].colorDecora = Colors::Gray;

        this->tablero[4][j+8].setPosicion(4,j+8);
        this->tablero[4][j+8].colorSolido = Colors::Gray;
        this->tablero[4][j+8].colorDecora = Colors::Gray;

        this->tablero[14][j+8].setPosicion(14,j+8);
        this->tablero[14][j+8].colorSolido = Colors::Gray;
        this->tablero[14][j+8].colorDecora = Colors::Gray;

        this->tablero[4][j+13].setPosicion(4,j+13);
        this->tablero[4][j+13].colorSolido = Colors::Gray;
        this->tablero[4][j+13].colorDecora = Colors::Gray;

        this->tablero[14][j+13].setPosicion(14,j+13);
        this->tablero[14][j+13].colorSolido = Colors::Gray;
        this->tablero[14][j+13].colorDecora = Colors::Gray;

        this->tablero[8][j+9].setPosicion(8,j+9);
        this->tablero[8][j+9].colorSolido = Colors::Gray;
        this->tablero[8][j+9].colorDecora = Colors::Gray;

        this->tablero[10][j+9].setPosicion(10,j+9);
        this->tablero[10][j+9].colorSolido = Colors::Gray;
        this->tablero[10][j+9].colorDecora = Colors::Gray;

        this->tablero[5][j+18].setPosicion(5,j+18);
        this->tablero[5][j+18].colorSolido = Colors::Gray;
        this->tablero[5][j+18].colorDecora = Colors::Gray;

        this->tablero[13][j+18].setPosicion(13,j+18);
        this->tablero[13][j+18].colorSolido = Colors::Gray;
        this->tablero[13][j+18].colorDecora = Colors::Gray;

        this->tablero[9][j+20].setPosicion(9,j+20);
        this->tablero[9][j+20].colorSolido = Colors::Gray;
        this->tablero[9][j+20].colorDecora = Colors::Gray;
    }

    for(size_t i = 0; i < 3; i++){
        this->tablero[i+8][5].setPosicion(i+8,5);
        this->tablero[i+8][5].colorSolido = Colors::Gray;
        this->tablero[i+8][5].colorDecora = Colors::Gray;

        this->tablero[i+8][13].setPosicion(i+8,13);
        this->tablero[i+8][13].colorSolido = Colors::Gray;
        this->tablero[i+8][13].colorDecora = Colors::Gray;

        this->tablero[i+3][17].setPosicion(i+3,17);
        this->tablero[i+3][17].colorSolido = Colors::Gray;
        this->tablero[i+3][17].colorDecora = Colors::Gray;

        this->tablero[i+13][17].setPosicion(i+13,17);
        this->tablero[i+13][17].colorSolido = Colors::Gray;
        this->tablero[i+13][17].colorDecora = Colors::Gray;

        this->tablero[i+8][11].setPosicion(i+8,11);
        this->tablero[i+8][11].colorSolido = Colors::Gray;
        this->tablero[i+8][11].colorDecora = Colors::Gray;
    }

    for(size_t i = 0; i < 5; i++){
        this->tablero[i+7][19].setPosicion(i+7,19);
        this->tablero[i+7][19].colorSolido = Colors::Gray;
        this->tablero[i+7][19].colorDecora = Colors::Gray;

    }

    for(size_t j = 0; j < 5; j++){
        this->tablero[6][j+5].setPosicion(6,j+5);
        this->tablero[6][j+5].colorSolido = Colors::Gray;
        this->tablero[6][j+5].colorDecora = Colors::Gray;

        this->tablero[12][j+5].setPosicion(12,j+5);
        this->tablero[12][j+5].colorSolido = Colors::Gray;
        this->tablero[12][j+5].colorDecora = Colors::Gray;
    }

    for(size_t j = 0; j < 4; j++){
        this->tablero[6][j+12].setPosicion(6,j+12);
        this->tablero[6][j+12].colorSolido = Colors::Gray;
        this->tablero[6][j+12].colorDecora = Colors::Gray;

        this->tablero[12][j+12].setPosicion(12,j+12);
        this->tablero[12][j+12].colorSolido = Colors::Gray;
        this->tablero[12][j+12].colorDecora = Colors::Gray;
    }

    this->tablero[9][6].setPosicion(9,6);
    this->tablero[9][6].colorSolido = Colors::Gray;
    this->tablero[9][6].colorDecora = Colors::Gray;

    this->tablero[7][7].setPosicion(7,7);
    this->tablero[7][7].colorSolido = Colors::Gray;
    this->tablero[7][7].colorDecora = Colors::Gray;

    this->tablero[11][7].setPosicion(11,7);
    this->tablero[11][7].colorSolido = Colors::Gray;
    this->tablero[11][7].colorDecora = Colors::Gray;

    this->tablero[9][14].setPosicion(9,14);
    this->tablero[9][14].colorSolido = Colors::Gray;
    this->tablero[9][14].colorDecora = Colors::Gray;

    this->tablero[2][19].setPosicion(2,19);
    this->tablero[2][19].colorSolido = Colors::Gray;
    this->tablero[2][19].colorDecora = Colors::Gray;

    this->tablero[16][19].setPosicion(16,19);
    this->tablero[16][19].colorSolido = Colors::Gray;
    this->tablero[16][19].colorDecora = Colors::Gray;
#endif
#if 0
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            this->tablero[i][j].setPosicion(i,j);
            this->tablero[i][j].setColorSolido(Colors::Black);
            this->tablero[i][j].setColorDecora(Colors::Black);
        }
    }

    for (size_t i = 0; i < COLUMNAS; i++)
    {
        this->tablero[i][0].setPosicion(i,0);
        this->tablero[i][0].colorSolido = Colors::Brown;
        this->tablero[i][0].colorDecora = Colors::Black;

        this->tablero[i][FILAS-1].setPosicion(i,FILAS-1);
        this->tablero[i][FILAS-1].colorSolido = Colors::Brown;
        this->tablero[i][FILAS-1].colorDecora = Colors::Black;
    }

    for (size_t j = 0; j < FILAS; j++)
    {
        this->tablero[0][j].setPosicion(0,j);
        this->tablero[0][j].colorSolido = Colors::Brown;
        this->tablero[0][j].colorDecora = Colors::Black;      

        this->tablero[COLUMNAS-1][j].setPosicion(COLUMNAS-1,j);
        this->tablero[COLUMNAS-1][j].colorSolido = Colors::Brown;
        this->tablero[COLUMNAS-1][j].colorDecora = Colors::Black;
    }

    for(size_t i = 1; i < COLUMNAS - 1; i++){
        this->tablero[i][1].setPosicion(i,1);
        this->tablero[i][1].colorSolido = Colors::Gray;
        this->tablero[i][1].colorDecora = Colors::Black;  

        this->tablero[i][FILAS-2].setPosicion(i,FILAS-2);
        this->tablero[i][FILAS-2].colorSolido = Colors::Gray;
        this->tablero[i][FILAS-2].colorDecora = Colors::Black; 
    }

    for(size_t j = 2; j < 8; j++){
        this->tablero[1][j].setPosicion(1,j);
        this->tablero[1][j].colorSolido = Colors::Gray;
        this->tablero[1][j].colorDecora = Colors::Black; 

        this->tablero[17][j].setPosicion(17,j);
        this->tablero[17][j].colorSolido = Colors::Gray;
        this->tablero[17][j].colorDecora = Colors::Black;   

        this->tablero[1][j+15].setPosicion(1,j+15);
        this->tablero[1][j+15].colorSolido = Colors::Gray;
        this->tablero[1][j+15].colorDecora = Colors::Black; 

        this->tablero[17][j+15].setPosicion(17,j+15);
        this->tablero[17][j+15].colorSolido = Colors::Gray;
        this->tablero[17][j+15].colorDecora = Colors::Black;   
    }

    for(size_t i = 0; i < 2; i++){
        this->tablero[i+3][3].setPosicion(i+3,3);
        this->tablero[i+3][3].colorSolido = Colors::Gray;
        this->tablero[i+3][3].colorDecora = Colors::Black; 

        this->tablero[i+3][5].setPosicion(i+3,5);
        this->tablero[i+3][5].colorSolido = Colors::Gray;
        this->tablero[i+3][5].colorDecora = Colors::Black;  

        this->tablero[i+6][3].setPosicion(i+6,3);
        this->tablero[i+6][3].colorSolido = Colors::Gray;
        this->tablero[i+6][3].colorDecora = Colors::Black; 

        this->tablero[i+11][3].setPosicion(i+11,3);
        this->tablero[i+11][3].colorSolido = Colors::Gray;
        this->tablero[i+11][3].colorDecora = Colors::Black; 

        this->tablero[i+14][3].setPosicion(i+14,3);
        this->tablero[i+14][3].colorSolido = Colors::Gray;
        this->tablero[i+14][3].colorDecora = Colors::Black; 

        this->tablero[i+14][5].setPosicion(i+14,5);
        this->tablero[i+14][5].colorSolido = Colors::Gray;
        this->tablero[i+14][5].colorDecora = Colors::Black;  

        this->tablero[i+7][17].setPosicion(i+7,17);
        this->tablero[i+7][17].colorSolido = Colors::Gray;
        this->tablero[i+7][17].colorDecora = Colors::Black;

        this->tablero[i+10][17].setPosicion(i+10,17);
        this->tablero[i+10][17].colorSolido = Colors::Gray;
        this->tablero[i+10][17].colorDecora = Colors::Black;
    }

    for(size_t i = 0; i < 4; i++){
        this->tablero[i+1][7].setPosicion(i+1,7);
        this->tablero[i+1][7].colorSolido = Colors::Gray;
        this->tablero[i+1][7].colorDecora = Colors::Black;

        this->tablero[i+1][10].setPosicion(i+1,10);
        this->tablero[i+1][10].colorSolido = Colors::Gray;
        this->tablero[i+1][10].colorDecora = Colors::Black;

        this->tablero[i+14][7].setPosicion(i+14,7);
        this->tablero[i+14][7].colorSolido = Colors::Gray;
        this->tablero[i+14][7].colorDecora = Colors::Black;

        this->tablero[i+14][10].setPosicion(i+14,10);
        this->tablero[i+14][10].colorSolido = Colors::Gray;
        this->tablero[i+14][10].colorDecora = Colors::Black;

        this->tablero[i+1][12].setPosicion(i+1,12);
        this->tablero[i+1][12].colorSolido = Colors::Gray;
        this->tablero[i+1][12].colorDecora = Colors::Black;

        this->tablero[i+1][15].setPosicion(i+1,15);
        this->tablero[i+1][15].colorSolido = Colors::Gray;
        this->tablero[i+1][15].colorDecora = Colors::Black;

        this->tablero[i+14][12].setPosicion(i+14,12);
        this->tablero[i+14][12].colorSolido = Colors::Gray;
        this->tablero[i+14][12].colorDecora = Colors::Black;

        this->tablero[i+14][15].setPosicion(i+14,15);
        this->tablero[i+14][15].colorSolido = Colors::Gray;
        this->tablero[i+14][15].colorDecora = Colors::Black;

        this->tablero[i+3][21].setPosicion(i+3,21);
        this->tablero[i+3][21].colorSolido = Colors::Gray;
        this->tablero[i+3][21].colorDecora = Colors::Black;

        this->tablero[i+12][21].setPosicion(i+12,21);
        this->tablero[i+12][21].colorSolido = Colors::Gray;
        this->tablero[i+12][21].colorDecora = Colors::Black;

    }

    for(size_t j = 0; j < 2; j++){
        this->tablero[9][j+2].setPosicion(9,j+2);
        this->tablero[9][j+2].colorSolido = Colors::Gray;
        this->tablero[9][j+2].colorDecora = Colors::Black;

        this->tablero[4][j+8].setPosicion(4,j+8);
        this->tablero[4][j+8].colorSolido = Colors::Gray;
        this->tablero[4][j+8].colorDecora = Colors::Black;

        this->tablero[14][j+8].setPosicion(14,j+8);
        this->tablero[14][j+8].colorSolido = Colors::Gray;
        this->tablero[14][j+8].colorDecora = Colors::Black;

        this->tablero[4][j+13].setPosicion(4,j+13);
        this->tablero[4][j+13].colorSolido = Colors::Gray;
        this->tablero[4][j+13].colorDecora = Colors::Black;

        this->tablero[14][j+13].setPosicion(14,j+13);
        this->tablero[14][j+13].colorSolido = Colors::Gray;
        this->tablero[14][j+13].colorDecora = Colors::Black;

        this->tablero[8][j+9].setPosicion(8,j+9);
        this->tablero[8][j+9].colorSolido = Colors::Gray;
        this->tablero[8][j+9].colorDecora = Colors::Black;

        this->tablero[10][j+9].setPosicion(10,j+9);
        this->tablero[10][j+9].colorSolido = Colors::Gray;
        this->tablero[10][j+9].colorDecora = Colors::Black;

        this->tablero[5][j+18].setPosicion(5,j+18);
        this->tablero[5][j+18].colorSolido = Colors::Gray;
        this->tablero[5][j+18].colorDecora = Colors::Black;

        this->tablero[13][j+18].setPosicion(13,j+18);
        this->tablero[13][j+18].colorSolido = Colors::Gray;
        this->tablero[13][j+18].colorDecora = Colors::Black;

        this->tablero[9][j+20].setPosicion(9,j+20);
        this->tablero[9][j+20].colorSolido = Colors::Gray;
        this->tablero[9][j+20].colorDecora = Colors::Black;
    }

    for(size_t i = 0; i < 3; i++){
        this->tablero[i+8][5].setPosicion(i+8,5);
        this->tablero[i+8][5].colorSolido = Colors::Gray;
        this->tablero[i+8][5].colorDecora = Colors::Black;

        this->tablero[i+8][13].setPosicion(i+8,13);
        this->tablero[i+8][13].colorSolido = Colors::Gray;
        this->tablero[i+8][13].colorDecora = Colors::Black;

        this->tablero[i+3][17].setPosicion(i+3,17);
        this->tablero[i+3][17].colorSolido = Colors::Gray;
        this->tablero[i+3][17].colorDecora = Colors::Black;

        this->tablero[i+13][17].setPosicion(i+13,17);
        this->tablero[i+13][17].colorSolido = Colors::Gray;
        this->tablero[i+13][17].colorDecora = Colors::Black;

        this->tablero[i+8][11].setPosicion(i+8,11);
        this->tablero[i+8][11].colorSolido = Colors::Gray;
        this->tablero[i+8][11].colorDecora = Colors::Black;
    }

    for(size_t i = 0; i < 5; i++){
        this->tablero[i+7][19].setPosicion(i+7,19);
        this->tablero[i+7][19].colorSolido = Colors::Gray;
        this->tablero[i+7][19].colorDecora = Colors::Black;

    }

    for(size_t j = 0; j < 5; j++){
        this->tablero[6][j+5].setPosicion(6,j+5);
        this->tablero[6][j+5].colorSolido = Colors::Gray;
        this->tablero[6][j+5].colorDecora = Colors::Black;

        this->tablero[12][j+5].setPosicion(12,j+5);
        this->tablero[12][j+5].colorSolido = Colors::Gray;
        this->tablero[12][j+5].colorDecora = Colors::Black;
    }

    for(size_t j = 0; j < 4; j++){
        this->tablero[6][j+12].setPosicion(6,j+12);
        this->tablero[6][j+12].colorSolido = Colors::Gray;
        this->tablero[6][j+12].colorDecora = Colors::Black;

        this->tablero[12][j+12].setPosicion(12,j+12);
        this->tablero[12][j+12].colorSolido = Colors::Gray;
        this->tablero[12][j+12].colorDecora = Colors::Black;
    }

    this->tablero[9][6].setPosicion(9,6);
    this->tablero[9][6].colorSolido = Colors::Gray;
    this->tablero[9][6].colorDecora = Colors::Black;

    this->tablero[7][7].setPosicion(7,7);
    this->tablero[7][7].colorSolido = Colors::Gray;
    this->tablero[7][7].colorDecora = Colors::Black;

    this->tablero[11][7].setPosicion(11,7);
    this->tablero[11][7].colorSolido = Colors::Gray;
    this->tablero[11][7].colorDecora = Colors::Black;

    this->tablero[9][14].setPosicion(9,14);
    this->tablero[9][14].colorSolido = Colors::Gray;
    this->tablero[9][14].colorDecora = Colors::Black;

    this->tablero[2][19].setPosicion(2,19);
    this->tablero[2][19].colorSolido = Colors::Gray;
    this->tablero[2][19].colorDecora = Colors::Black;

    this->tablero[16][19].setPosicion(16,19);
    this->tablero[16][19].colorSolido = Colors::Gray;
    this->tablero[16][19].colorDecora = Colors::Black;
#endif
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
