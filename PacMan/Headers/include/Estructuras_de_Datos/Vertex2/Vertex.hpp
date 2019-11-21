
#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)

#include <vector>

#include <algorithm>

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

	int weigth{ 0 };

	size_t discovery_time{ 0 };

	size_t finish_time{ 0 };

	int x { 0 };

	int y { 0 };

public:
	Vertex( std::string name );
	
	Vertex( std::string name, std::string x, std::string y );

	std::string get_name() const;

	void add_neighbor( Vertex v );

	void print_neighbors();

	void print();

	void set_distance( int d );

	int get_distance();

	void set_color( Colors c );

	Vertex::Colors get_color();

	void set_predecesor( std::string p );

	std::string get_predecesor();

	std::list<Vertex> get_neighbors();

	int get_weigth();
	
	void set_weigth( int w);

	int get_finish_time();

	void set_finish_time(size_t ft);

	int get_discovery_time();

	void set_discovery_time(size_t ft);

	void set_X( int _x );
	
	void set_Y( int _y );

	int get_X();

	int get_Y();

};
