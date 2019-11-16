#ifndef COMIDA_HPP
#define COMIDA_HPP
/**
 * Se utilizara la clase Figura de cual hereda la clase comida
 **/
#include "Figura.hpp"

class Comida : public Figura{
private:
    /* data */
public:
    Comida(/* args */);
    Comida(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Comida();

    void pinta();
};

#endif