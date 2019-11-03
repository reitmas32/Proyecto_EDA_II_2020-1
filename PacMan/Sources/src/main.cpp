#include <iostream>
#include "../../Headers/include/miniwin.h"
using namespace miniwin;

#include <iostream>

#include "../../Headers/include/Cuadro.hpp"
#include "../../Headers/include/Tablero.hpp"
#include "../../Headers/include/Pacman.hpp"

int main() {
    vredimensiona(TAM*COLUMNAS + MARGEN* 2,TAM*FILAS + MARGEN* 2);
    Pacman p = Pacman(9,10,Colors::Yellow,Colors::Black);
    Tablero T = Tablero();
    T.creaMundo();
    T.pinta();
    p.pinta_abajo();

    int t = tecla();

    while(t != ESCAPE){

        Pacman copia = p;

        if( t == ARRIBA){
            p.mueve_arriba();
            //borra();
            //p.pinta_arri();
        }
        
        else if( t == ABAJO){
            p.mueve_abajo();
        }
        else if( t == DERECHA){
            p.mueve_derecha();
        }
        else if( t == IZQUIERDA){
            p.mueve_izquierda();
        }
        
        if(T.colision(p)){
            p = copia;
            std::cout<<"Choco"<<std::endl;
        }
        
        if(t != NINGUNA){
            T.repinta();
            if(t == ARRIBA){
                p.pinta_arri();
            }
            else if(t == ABAJO){
                p.pinta_abajo();
            }
            else if(t == DERECHA){
                p.pinta_der();
            }
            else if(t == IZQUIERDA){
                p.pinta_izq();
            }
        }
        espera(10);
        t = tecla();
    }
    vcierra();
    refresca();
   return 0;
}
