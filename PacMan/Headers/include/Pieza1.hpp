#ifndef PIEZA_HPP_INCLUDED
#define PIEZA_HPP_INCLUDED

#include <cstdlib>

#include "miniwin.h"

//const int TAM = 25;

const int FILAS = 20;

const int COLUMNAS = 10;

typedef struct Coord{
    int x, y;
}Coord;

typedef struct Pieza{
    Coord orig;         //Bloque central
    Coord peri[3];      //Bloques Perifericos
    int color;

    Coord posicion(int n) const; // n es el numero de bloque el 0 es el centro y de 1 a 3 son los perfericos


}Pieza;

Coord Pieza::posicion(int n) const {

    Coord ret = { orig.x, orig.y };

    if(n != 0){
        ret.x += peri[n-1].x;
        ret.y += peri[n-1].y;
    }
    return ret;
}

void cuadrado(int x, int y){
    rectangulo_lleno(21 + x * TAM,
                     21 + y * TAM,
                     20 + x * TAM + TAM,
                     20 + y * TAM + TAM);

}

void pinta_pieza(const Pieza& P){
    color(P.color);

    for(int i = 0; i < 4; i++){
        Coord c = P.posicion(i);
        cuadrado( c.x , c.y );
    }
}

Coord rota_derecha(const Coord& c){
    Coord ret = { -c.y, c.x };
    return ret;
}

void rota_derecha(Pieza& P){
    for( int i = 0; i < 3; i++){
        P.peri[i] = rota_derecha(P.peri[i]);
    }
}

Coord rota_izquierda(const Coord& c){
    Coord ret = { c.y, -c.x };
    return ret;
}

void rota_izquierda(Pieza& P){
    for( int i = 0; i < 3; i++){
        P.peri[i] = rota_izquierda(P.peri[i]);
    }
}

const Coord perifs[7][3]  ={
    { {1,0}, {0,1}, {1,1}},     //cuadrado
    { {1,0}, {-1,1}, {0,1}},    //S
    { {0,1}, {1,1}, {-1,0}},    //2
    { {0,-1}, {0,1}, {1,1}},    //L
    { {0,-1}, {0,1}, {-1,1}},   //J
    { {0,-1}, {0,1}, {0,2}},    //I
    { {-1,0}, {1,0}, {0,1}},    //T
};

void pieza_nueva(Pieza& P){
    P.orig.x = 5;
    P.orig.y = 3;

    int pieza = rand() % 7;

    for( int i = 0; i < 3; i++){
        P.peri[i] = perifs[pieza][i];
    }
    int color = rand() % 6;
    P.color = color;
}

#endif // PIEZA_HPP_INCLUDED
