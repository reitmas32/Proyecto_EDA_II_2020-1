/**
 * Se usara la biblioteca estandar de I/O de C++
 **/
#include <iostream>
#include <fstream>
#include <omp.h>

#include "../../Headers/include/Graphics_Engine/miniwin.h"
/*
#include "../../Headers/include/Objetos/Fantasma.hpp"
#include "../../Headers/include/Objetos/Comida.hpp"
#include "../../Headers/include/Objetos/Pacman.hpp"
#include "../../Headers/include/Objetos/Tablero.hpp"
*/
using namespace miniwin; 

int main(int argc, char const *argv[])
{
    vredimensiona(200,200);
    return 0;
}


#if 1


pthread_t waka;
pthread_t mainLoop;



void* playSound(void* data){
    char* sound = (char *)data;
    while(1){
        printf("%s\n", sound);
        system(sound);        
    }
}

void moveFantasma(Fantasma* f,Tablero T,Pacman* p){
    Fantasma f_copia = *f;
    if(f->getTime() > 15){
        f->setTime(0);
        switch (f->getDir())
        {
        case 1:
            f->mueve_arriba();
            break;
        case 2:
            f->mueve_abajo();
            break;
        case 3:
            f->mueve_derecha();
            break;
        case 4:
            f->mueve_izquierda();
            break;
        default:
            break;
        }
        if(T.colision(*f)){
            *f = f_copia;
        }
        f->setDir((rand() % 4) + 1);
    }
}

void movePacman(Tablero* T, Pacman* p, int* time, int* dir, int tecla){
    Pacman copia = *p;

        if(tecla != ARRIBA || tecla != ABAJO || tecla != DERECHA || tecla != IZQUIERDA || dir != 0){
            if(*time > 15){
                *time = 0;
                switch (*dir)
                {
                case 1:
                    tecla = ARRIBA;
                    break;
                case 2:
                    tecla = ABAJO;
                    break;
                case 3:
                    tecla = DERECHA;
                    break;
                case 4:
                    tecla  =IZQUIERDA;
                    break;
                default:
                    break;
                }
            }
        }

    if( tecla == ARRIBA){
        p->mueve_arriba();
        *dir = 1;
    }
    
    else if( tecla == ABAJO){
        p->mueve_abajo();
        *dir = 2;
    }
    else if( tecla == DERECHA){
        p->mueve_derecha();
        *dir = 3;
    }
    else if( tecla == IZQUIERDA){
        p->mueve_izquierda();
        *dir = 4;
    }

    if(T->colision(*p)){
        *p = copia;
    }
}


void* MainLoop(void* data){
vredimensiona(300,350);

    color(BLANCO);

    texto(85,100,"<====PACMAN====>");

    texto(75,150,"Oprime Espacio para iniciar");

    refresca();

    //Es el detector de la tecla que se presiono
    int t = tecla();
/*
    while ( t != ESPACIO )
    {
        if(t == ESCAPE){
            //break;

            refresca();
            vcierra();
            
        }else{
            t = tecla();
        }
        
    }
    t = tecla();
*/
    //para el raind de el Fantasma
    srand(time(NULL));

    //Tablero
    Tablero T = Tablero(MAPAS::LEVEL_ONE, Colors::Blue700, Colors::Black);
    T.creaMundo();
    T.pinta();

    //Pacman
    Pacman p = Pacman(2,2,Colors::Yellow,Colors::Black);
    //p.pinta_der();

    //Fantasma Rojo
    Fantasma f_rojo = Fantasma(5,8,Colors::Red, Colors::Gray);
    f_rojo.pinta();

    //Fantasma Verde
    Fantasma f_verde = Fantasma(9,17,Colors::Green, Colors::Gray);
    f_verde.pinta();

    //Fantasma Naranja
    Fantasma f_naranja = Fantasma(5,12,Colors::Orange, Colors::Gray);
    f_naranja.pinta();

    //Tabla que guarda la posicion de la comida
    Comida posComida[COLUMNAS][FILAS];
    
    refresca();
    //Cuenta un tiempo si es que pacaman no se mueve 
    int time = 0;

    //Almacena la ultima direccion que tomo pacman
    int dir = 0;


    //Lista de fantasmas
    std::vector<Fantasma*> listaFantasmas;

    listaFantasmas.push_back(&f_rojo);
    listaFantasmas.push_back(&f_verde);
    listaFantasmas.push_back(&f_naranja);

    //PacMan origen
    Pacman p_origen = p;

    for(size_t i = 0; i < T.vidas ; i++){
        Pacman p_v = Pacman(23,2+i*2,Colors::Yellow,Colors::Black);
        p_v.pinta_der();
    }

    while(t != ESCAPE){


        Pacman copia = p;

        for (Fantasma* f : listaFantasmas)
        {
            moveFantasma(f,T,&p);
            f->setTime(f->getTime() + 1);
        }
        
        //movePacman(&T, &p, &time, &dir, t);

        if(t != ARRIBA || t != ABAJO || t != DERECHA || t != IZQUIERDA || dir != 0){
            if(time > 40){
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
        }

        if(t != NINGUNA){
            T.repinta();           
            for(size_t i = 0; i < T.Columnas; i++){
                for(size_t j = 0; j < T.Filas; j++){
                    if(T.tablero[j][i].getColorDecora()== T.ColorCamino){
                        posComida[i][j] = Comida(i,j,Colors::Yellow, T.ColorCamino);
                        if(T.mapa[j][i] == 3){
                            posComida[i][j].pintaGrande();
                        }else{
                            posComida[i][j].pinta();
                        }
                        
                    }
                    else
                    {
                        posComida[i][j] = Comida(i,j,T.ColorCamino, T.ColorCamino);
                    }
                    
                }
            }

            for(Fantasma* f : listaFantasmas){
                f->pinta();
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
            if( t == ARRIBA || t == ABAJO || t == DERECHA || t == IZQUIERDA){
                if(T.tablero[p.getPosicion().y][p.getPosicion().x].getColorDecora() == T.ColorCamino){
                    T.tablero[p.getPosicion().y][p.getPosicion().x].setColorDecora(T.ColorCamino);
                    T.puntos++;
                }
            }
        }

        for(Fantasma* f : listaFantasmas){
            if(p.getPosicion().x == f->getPosicion().x &&
            p.getPosicion().y == f->getPosicion().y){
                if(T.vidas == 0){
                    vcierra();               
                }
                else{
                    p = p_origen;
                    T.vidas--; 
                    espera(500);
                }
            }           
        }



        //moveFantasma(&f_rojo,T,&p,&time_f, &dir_f);
        
        espera(10);
        time++;
        t = tecla();
        
    }
    pthread_cancel(waka);
    vcierra();
    
    refresca();
    return data;
}

int main() {

    pthread_create(&waka, NULL, &playSound, (void*)"paplay ../../Resources/sounds/pacman-waka-waka.wav");
    
    pthread_create(&mainLoop, NULL, &MainLoop, NULL);
    pthread_join(waka,NULL);
    pthread_join(mainLoop,NULL);
    //pthread_create(&waka, NULL, &playSound, (void*)"paplay ../../Resources/sounds/pacman-waka.wav");
#if 0
    vredimensiona(300,350);

    color(BLANCO);

    texto(85,100,"<====PACMAN====>");

    texto(75,150,"Oprime Espacio para iniciar");

    refresca();

    //Es el detector de la tecla que se presiono
    int t = tecla();
/*
    while ( t != ESPACIO )
    {
        if(t == ESCAPE){
            //break;

            refresca();
            vcierra();
            
        }else{
            t = tecla();
        }
        
    }
    t = tecla();
*/
    //para el raind de el Fantasma
    srand(time(NULL));

    //Tablero
    Tablero T = Tablero(MAPAS::LEVEL_ONE, Colors::Blue700, Colors::Black);
    T.creaMundo();
    T.pinta();

    //Pacman
    Pacman p = Pacman(2,2,Colors::Yellow,Colors::Black);
    //p.pinta_der();

    //Fantasma Rojo
    Fantasma f_rojo = Fantasma(5,8,Colors::Red, Colors::Gray);
    f_rojo.pinta();

    //Fantasma Verde
    Fantasma f_verde = Fantasma(9,17,Colors::Green, Colors::Gray);
    f_verde.pinta();

    //Fantasma Naranja
    Fantasma f_naranja = Fantasma(5,12,Colors::Orange, Colors::Gray);
    f_naranja.pinta();

    //Tabla que guarda la posicion de la comida
    Comida posComida[COLUMNAS][FILAS];
    
    refresca();
    //Cuenta un tiempo si es que pacaman no se mueve 
    int time = 0;

    //Almacena la ultima direccion que tomo pacman
    int dir = 0;


    //Lista de fantasmas
    std::vector<Fantasma*> listaFantasmas;

    listaFantasmas.push_back(&f_rojo);
    listaFantasmas.push_back(&f_verde);
    listaFantasmas.push_back(&f_naranja);

    //PacMan origen
    Pacman p_origen = p;

    for(size_t i = 0; i < T.vidas ; i++){
        Pacman p_v = Pacman(23,2+i*2,Colors::Yellow,Colors::Black);
        p_v.pinta_der();
    }

    while(t != ESCAPE){


        Pacman copia = p;

        for (Fantasma* f : listaFantasmas)
        {
            moveFantasma(f,T,&p);
            f->setTime(f->getTime() + 1);
        }
        
        //movePacman(&T, &p, &time, &dir, t);

        if(t != ARRIBA || t != ABAJO || t != DERECHA || t != IZQUIERDA || dir != 0){
            if(time > 40){
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
        }

        if(t != NINGUNA){
            T.repinta();           
            for(size_t i = 0; i < T.Columnas; i++){
                for(size_t j = 0; j < T.Filas; j++){
                    if(T.tablero[j][i].getColorDecora()== T.ColorCamino){
                        posComida[i][j] = Comida(i,j,Colors::Yellow, T.ColorCamino);
                        if(T.mapa[j][i] == 3){
                            posComida[i][j].pintaGrande();
                        }else{
                            posComida[i][j].pinta();
                        }
                        
                    }
                    else
                    {
                        posComida[i][j] = Comida(i,j,T.ColorCamino, T.ColorCamino);
                    }
                    
                }
            }

            for(Fantasma* f : listaFantasmas){
                f->pinta();
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
            if( t == ARRIBA || t == ABAJO || t == DERECHA || t == IZQUIERDA){
                if(T.tablero[p.getPosicion().y][p.getPosicion().x].getColorDecora() == T.ColorCamino){
                    T.tablero[p.getPosicion().y][p.getPosicion().x].setColorDecora(T.ColorCamino);
                    T.puntos++;
                }
            }
        }

        for(Fantasma* f : listaFantasmas){
            if(p.getPosicion().x == f->getPosicion().x &&
            p.getPosicion().y == f->getPosicion().y){
                if(T.vidas == 0){
                    vcierra();               
                }
                else{
                    p = p_origen;
                    T.vidas--; 
                    espera(500);
                }
            }           
        }



        //moveFantasma(&f_rojo,T,&p,&time_f, &dir_f);
        
        espera(10);
        time++;
        t = tecla();
        
    }
    pthread_cancel(waka);
    vcierra();
    
    refresca();
#endif
   return 0;
}
#endif