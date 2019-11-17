#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)


//----------------------------------------------------------------------
//  Class Vertex
//----------------------------------------------------------------------
class Vertex
{
public:
	enum class Colors { BLACK, GRAY, WHITE };

private:
	std::string name; ///< campo de texto. Se utilizará como key

	// aquí van más campos relacionados con la naturaleza de la información del
	// nodo. P. ej., Estudiante: promedio, semestre. Persona: dirección, edad;
	// etc.

	std::list<Vertex> neighbors; ///< lista de vértices adyacentes

	int distance{ 0 };

	Colors color{ Colors::BLACK };

	std::string predecesor = "";

public:
	Vertex( std::string name );

	std::string get_name() const;

	void add_neighbor( Vertex v );

	void print_neighbors();

    void set_distance(int distance);

    int get_distance();

    void set_color( Colors color);

    Colors get_color();

    void set_predecesor(std::string predecesor);

    std::string get_predecesor();

    void print();

	std::list<Vertex> get_neighbors();

	bool isNeighbors(std::string neighbors);
};

Vertex::Vertex( std::string _name ) : name{ _name }
{
	// nada (por el momento)
}

void Vertex::add_neighbor( Vertex v )
{
	this->neighbors.push_back( v );
}


std::string Vertex::get_name() const
{
	return this->name;
}

void Vertex::print_neighbors()
{
	for( auto v : this->neighbors ) 
		std::cout << v.get_name() << "-> ";
	std::cout << "Nil";
}


void Vertex::set_distance(int distance){
	if(distance > 0){
		this->distance = distance;
	}
}

int Vertex::get_distance(){
    return this->distance;
}

void Vertex::set_color( Vertex::Colors color){
    this->color = color;
}

Vertex::Colors Vertex::get_color(){
    return this->color;
}

void Vertex::set_predecesor(std::string predecesor){
    this->predecesor = predecesor;
}

std::string Vertex::get_predecesor(){
    return this->predecesor;
}

std::list<Vertex> Vertex::get_neighbors(){
	return this->neighbors;
}


bool Vertex::isNeighbors(std::string neighbor){
	for(auto& n : this->neighbors){
		if(n.get_name() == neighbor){
			return true;
		}
	}
	return false;
}

#if 1
void Vertex::print(){

	std::string color;

	switch (this->get_color())
	{
	case Vertex::Colors::BLACK:
		color = "BLACK";
		break;
	case Vertex::Colors::GRAY:
		color = "GRAY";
		break;
	case Vertex::Colors::WHITE:
		color = "WHITE";
		break;
	
	default:
		break;
	}

    std::cout<<"Name: "<<this->get_name()<<", Distance: "<<this->get_distance()
             <<", Color: "<<color<<", Predecesor: "<<get_predecesor()<<std::endl;
}
#endif

#endif	//VERTEX_HPP