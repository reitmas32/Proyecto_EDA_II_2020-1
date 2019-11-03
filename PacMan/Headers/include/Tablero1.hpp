#ifndef TABLERO_HPP_INCLUDED
#define TABLERO_HPP_INCLUDED

#include "Pieza1.hpp"

typedef int Tablero[COLUMNAS][FILAS];

void tablero_vacia(Tablero& T){

    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            T[i][j] = NEGRO;
        }
    }

}

void tablero_pinta(const Tablero& T){
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            color(T[i][j]);
            cuadrado(i,j);
        }
    }
}

bool tablero_fila_llena(const Tablero& t, int fila){
    for(int i = 0; i < COLUMNAS; i++){
        if(t[i][fila] == NEGRO){
            return false;
        }
    }
    return true;
}

void tablero_incrusta_pieza(Tablero& T,const Pieza& P){
    for( int i = 0; i < 4; i++){
        Coord c = P.posicion(i);
        T[c.x][c.y] = P.color;
    }
}

bool tablero_colision(const Tablero& T, const Pieza& P ){

    for(int i = 0; i < 4; i++){
        Coord c = P.posicion(i);
        //Comprobar limites
        if(c.x < 0 || c.x >= COLUMNAS){
            return true;
        }
        if(c.y < 0 || c.y >= FILAS){
            return true;
        }
        //mirar basurilla
        if(T[c.x][c.y] != NEGRO){
            return true;
        }
    }
    return false;
}

void tablero_colapsa(Tablero& T, const int fila){
    for(int j = fila; j > 0; j--){
        for(int i = 0; i < COLUMNAS; i++){
            T[i][j] = T[i][j-1];
        }
    }
    for(int i = 0; i < COLUMNAS; i++){
        T[i][0] = NEGRO;
    }
}

void tablero_cuenta_lineas(Tablero& T){

    int fila = FILAS-1;
    while(fila >= 0){
        if(tablero_fila_llena(T,fila)){
            tablero_colapsa(T,fila);
        }else{
            fila--;
        }

    }
}

void repinta(const Tablero& T, const Pieza& P){
    borra();
    tablero_pinta(T);
    color_rgb(228, 25, 238 );
    linea(20,20,20,20 + TAM * FILAS);
    linea(20,20+TAM * FILAS,20+TAM * COLUMNAS,20+TAM * FILAS);
    linea(20+TAM * COLUMNAS,20+TAM * FILAS,20+TAM * COLUMNAS,0);
    pinta_pieza(P);
    refresca();
}

#endif // TABLERO_HPP_INCLUDED
