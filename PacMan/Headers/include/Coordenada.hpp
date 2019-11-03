#ifndef COORDENADA_HPP
#define COORDENADA_HPP

#include <stdlib.h>

class Coordenada
{
private:
    int x;
    int y;
public:
    Coordenada(/* args */){}
    Coordenada(int x, int y){
        this->setX(x);
        this->setY(y);
    }
    ~Coordenada(){free(this);}

    int     getX(){     return this->x;}
    int     getY(){     return this->y;}
    void    setX(int x){this->x = x;}
    void    setY(int y){this->y = y;}
};


#endif  //COORDENADA_HPP