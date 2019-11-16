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

#endif	//VERTEX_HPP