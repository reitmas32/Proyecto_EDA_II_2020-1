#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "Figura.hpp"

//#include "Tablero.hpp"

const int RADIO = TAM / 2; 

class Pacman : public Figura
{
private:
public:
    Pacman(/* args */);
    Pacman(int x, int y, std::vector<int> colorSolido, std::vector<int> colorDecora);
    ~Pacman();
    void pinta_der();
    void pinta_izq();
    void pinta_arri();
    void pinta_abajo();
};

#endif  //PACMAN_HPP