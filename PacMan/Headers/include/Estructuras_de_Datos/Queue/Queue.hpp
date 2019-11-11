/**
 * @file    Queue.hpp
 * @version 1.0
 * @date    13/07/2019.
 * @author  Zamora Ramírez Oswaldo Rafael
 * @brief   Es la API de una Queue plantilla
 * @code
 
    #include <iostream>

    #include "Queue.hpp"
    #include "Queue.cpp"

    using namespace std;

    int main() {
        Queue<int> miQueue(5);
        miQueue.Enqueue(3);
        int tmp;
        miQueue.Dequeue(&tmp);
        cout<<tmp<<endl;
        return 0;
    }
 * @endcode 
 */

#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

//Biblioteca para el uso de size_t
#include <cstdio>
//Biblioteca para el uso de memoria dinamica
#include <stdlib.h>

//Clase plantilla en de la Queue
template <class Item>
class Queue {
private:
    //Atributos
    Item* queue;      
    size_t front{};    
    size_t back{};     
    size_t len{};      
    size_t capacity{}; 

    //Getters
    Item* getQueue()     const{ return queue;}
    size_t getFront()    const{ return  front;}
    size_t getBack()     const{ return back;}
    size_t getLen()      const{ return len;}
    size_t getCapacity() const{ return capacity;}

    //Setters
    void setQueue(Item* _queue){ queue = _queue;}
    void setFront(size_t _front){ front = _front;}
    void setBack(size_t _back){ back = _back;}
    void setLen(size_t _len){ len = _len;}
    void setCapacity(size_t _capacity){ capacity = _capacity;}

public:

    //Constructoe
    Queue(size_t _capacity);

    //Destructor
    ~Queue();

    //Metodos
    bool Enqueue(Item _data);
    bool Dequeue(Item* _data_back);
    bool Peek(Item* _data_back);
    bool IsEmpty();
    bool IsFull();
    size_t Len();
    size_t Capacity();
    void MakeEmpty();
};

//Constructoe
template<class Item>
Queue<Item>::Queue(size_t _capacity){
    setQueue((Item*)calloc(_capacity, sizeof(Item)));
    setCapacity(_capacity);
    setLen(0);
    setFront(0);
    setBack(0);
}

//Destructor
template<class Item>
Queue<Item>::~Queue(){
    free(getQueue());
    free(this);
}

//Metodos
template<class Item>
bool Queue<Item>::Enqueue(Item _data){
    bool done = false;
    if(getFront()<getCapacity()){
        done = true;
        getQueue()[getBack()] = _data;
        setBack(getBack()+1);
        setLen(getLen()+1);
    }
    return done;
}

template<class Item>
bool Queue<Item>::Dequeue(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getQueue()[getFront()];
        setFront(getFront()+1);
        setLen(getLen()+1);
    }
    return done;
}

template<class Item>
bool Queue<Item>::Peek(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getQueue()[getFront()];
    }
    return done;
}

template<class Item>
bool Queue<Item>::IsEmpty(){
    return getLen() == 0;
}

template<class Item>
bool Queue<Item>::IsFull(){
    return getLen() + 1 == getCapacity();
}

template<class Item>
size_t Queue<Item>::Len(){
    return getLen();
}

template<class Item>
size_t Queue<Item>::Capacity(){
    return getCapacity();
}

template<class Item>
void Queue<Item>::MakeEmpty(){
    setLen(0);
    setCapacity(0);
    setBack(0);
}



#endif //QUEUE_QUEUE_HPP
