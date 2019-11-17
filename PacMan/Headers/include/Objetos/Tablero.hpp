#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Pacman.hpp"

#include "../Mapas.hpp"

#include "../Estructuras_de_Datos/Graph.hpp"

std::string intToString(int num){
    std::stringstream sout;
    sout << num;
    return sout.str();
} 

bool searchInList(std::list<std::string> lista, std::string key){
    for(std::string item : lista){
        if(item == key){
            return true;
        }
    }
    return false;
}


class Tablero
{
public:
    Cuadro tablero[COLUMNAS][FILAS];
    Graph LevelOneGraph;
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
    this->LevelOneGraph = Graph();
    std::list<std::string> lista;
    for(size_t i = 0; i < FILAS; i++){
        for (size_t j = 0; j < COLUMNAS; j++)
        {
            if(MAPAS::LevelOne[i][j] == 0){
                std::string name = intToString((i*COLUMNAS)+j);
                lista.push_back(name);
            }
        }
        
    }
    for(std::string name : lista){
        this->LevelOneGraph.add_vertex(Vertex(name));
    }

    for(std::string item : lista){
        if(searchInList(lista, intToString(atoi(item.c_str()) + 1 ) ) ){
            std::cout<<item<<", "<<intToString(atoi(item.c_str()) + 1 )<<std::endl;
            this->LevelOneGraph.add_edge(item,intToString(atoi(item.c_str()) + 1 ));
        }
        if(searchInList(lista, intToString(atoi(item.c_str()) + COLUMNAS ) ) ){
            std::cout<<item<<", "<<intToString(atoi(item.c_str()) + COLUMNAS )<<std::endl;
            this->LevelOneGraph.add_edge(item,intToString(atoi(item.c_str()) + COLUMNAS ));
        }
    }

    lista = LevelOneGraph.goTo("40","222");
    for(std::string g : lista){
        std::cout<<g<<", ";
    }
}

Tablero::~Tablero()
{
    //this->LevelOneGraph.~Graph();
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
