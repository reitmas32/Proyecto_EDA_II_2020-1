#include <iostream>
#include "../../Headers/include/miniwin.h"
using namespace miniwin;

#include <iostream>

#include "../../Headers/include/Cuadro.hpp"
#include "../../Headers/include/Tablero.hpp"
#include "../../Headers/include/Pacman.hpp"
#include "../../Headers/include/Fantasma.hpp"
#include "../../Headers/include/Comida.hpp"

int main() {
    vredimensiona(TAM*COLUMNAS + MARGEN* 2,TAM*FILAS + MARGEN* 2);
#if 1
    Pacman p = Pacman(9,10,Colors::Yellow,Colors::Black);
    Tablero T = Tablero();
    T.creaMundo();
    T.pinta();
    Comida posComida[COLUMNAS][FILAS];
    p.pinta_abajo();

    int time = 0;
    int dir = 0;

    int t = tecla();

    while(t != ESCAPE){

        Pacman copia = p;

        if(t != ARRIBA || t != ABAJO || t != DERECHA || t != IZQUIERDA || dir != 0){
            if(time > 30){
                time = 0;
                switch (dir)
                {
                case 1:
                    t = ARRIBA;
                    break;
                case 2:
                    t = ABAJO;
                    break;
                case 3:
                    t = DERECHA;
                    break;
                case 4:
                    t  =IZQUIERDA;
                    break;
                default:
                    break;
                }
            }
        }
        if( t == ARRIBA){
            p.mueve_arriba();
            dir = 1;
            //borra();
            //p.pinta_arri();
        }
        
        else if( t == ABAJO){
            p.mueve_abajo();
            dir = 2;
        }
        else if( t == DERECHA){
            p.mueve_derecha();
            dir = 3;
        }
        else if( t == IZQUIERDA){
            p.mueve_izquierda();
            dir = 4;
        }
        
        if(T.colision(p)){
            p = copia;
            std::cout<<"Choco"<<std::endl;
        }
        
        if(t != NINGUNA){
            T.repinta();
            for(int i = 0; i < COLUMNAS; i++){
                for(int j = 0; j < FILAS; j++){
                    if(T.tablero[i][j].getColorSolido()==Colors::Black){
                        posComida[i][j] = Comida(i,j,Colors::Yellow, Colors::Black);
                        posComida[i][j].pinta();
                    }
                    else
                    {
                        posComida[i][j] = Comida(i,j,Colors::Black, Colors::Black);
                    }
                    
                }
            }
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
        espera(8);
        time++;
        t = tecla();
    }
    vcierra();

    refresca();
#endif
#if 0
    Fantasma f = Fantasma(9,10,Colors::Blue,Colors::Gray);
    Tablero T = Tablero();
    T.creaMundo();
    T.pinta();
    f.pinta();

    int time = 0;
    int dir = 0;

    int t = tecla();

    while(t != ESCAPE){

        Fantasma copia = f;

        if(t != ARRIBA || t != ABAJO || t != DERECHA || t != IZQUIERDA || dir != 0){
            if(time > 30){
                time = 0;
                switch (dir)
                {
                case 1:
                    t = ARRIBA;
                    break;
                case 2:
                    t = ABAJO;
                    break;
                case 3:
                    t = DERECHA;
                    break;
                case 4:
                    t  =IZQUIERDA;
                    break;
                default:
                    break;
                }
            }
        }
        if( t == ARRIBA){
            f.mueve_arriba();
            dir = 1;
            //borra();
            //p.pinta_arri();
        }
        
        else if( t == ABAJO){
            f.mueve_abajo();
            dir = 2;
        }
        else if( t == DERECHA){
            f.mueve_derecha();
            dir = 3;
        }
        else if( t == IZQUIERDA){
            f.mueve_izquierda();
            dir = 4;
        }
        
        if(T.colision(f)){
            f = copia;
            std::cout<<"Choco"<<std::endl;
        }
        
        if(t != NINGUNA){
            T.repinta();
            if(t == ARRIBA){
                f.pinta();
            }
            else if(t == ABAJO){
                f.pinta();
            }
            else if(t == DERECHA){
                f.pinta();
            }
            else if(t == IZQUIERDA){
                f.pinta();
            }
        }
        espera(8);
        time++;
        t = tecla();
    }
    vcierra();

    refresca();
#endif
#if 0
    Tablero T = Tablero();
    T.creaMundo();
    T.pinta();
    Comida posComida[COLUMNAS][FILAS];
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            if(T.tablero[i][j].getColorSolido()==Colors::Black){
                posComida[i][j] = Comida(i,j,Colors::Yellow, Colors::Black);
                posComida[i][j].pinta();
            }
            else
            {
                posComida[i][j] = Comida(i,j,Colors::Black, Colors::Black);
            }
            
        }
    }
    refresca();


#endif

   return 0;
}
