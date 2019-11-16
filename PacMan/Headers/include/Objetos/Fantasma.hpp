#ifndef GHOST_HPP
#define GHOST_HPP

#include <sstream>

#include "Cuadro.hpp"

#include "Figura.hpp"

#include "../Mapas.hpp"

#include "../Estructuras_de_Datos/Graph/Graph.hpp"

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
public:
    Fantasma(/* args */);
    Fantasma(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Fantasma();

    void pinta();
};


#endif  //GHOST_HPP
