/**
 * Se usara la biblioteca estandar de I/O de C++
 **/
#include <iostream>

#include "../../Headers/include/Graphics_Engine/miniwin.h"
#include "../../Headers/include/Objetos/Fantasma.hpp"
#include "../../Headers/include/Objetos/Comida.hpp"
#include "../../Headers/include/Objetos/Pacman.hpp"
#include "../../Headers/include/Objetos/Tablero.hpp"
using namespace miniwin;
int main() {
    vredimensiona(COLUMNAS*TAM+MARGEN*2,FILAS*TAM+MARGEN*2);
    Tablero t = Tablero();
    t.creaMundo();
    t.pinta();
    refresca();
   return 0;
}
