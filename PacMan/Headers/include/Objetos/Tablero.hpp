#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Pacman.hpp"

#include "Mapas.hpp"

#include "../Estructuras_de_Datos/Graph/Graph.hpp"

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

#endif  //TABLERO_HPP
