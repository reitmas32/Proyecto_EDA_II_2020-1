#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
//#include <cstring>
//#include <string.h>
// para declarar y procesar cadenas

//#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)

#include <vector>

//#include <algorithm>

#include "Vertex.hpp"

#include "Administrador.hpp"

//#include <istream>
//#include <iterator>
//#include <sstream>

//----------------------------------------------------------------------
//  Class Graph
//----------------------------------------------------------------------
class Graph
{
private:
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex
	Administrador admon;

public:
	Graph();
//	Graph( std::vector<Vertex> vertices ); 

	bool add_vertex( Vertex v );
	bool add_edge( std::string edge1, std::string edge2 );
	bool add_edge_directed( std::string edge1, std::string edge2 );

	void print();
	Vertex get_Vertex(std::string Vname);
	
	void BSF(std::string nameStart);

	std::map<std::string, Vertex> get_map();

	std::vector<Vertex> dfs_to(std::string nameStart);

	bool add_edge_weighted( std::string edge1, std::string edge2, int weigth);

	void DFS(std::string nameStart);

	void dfs_traverse(std::string nameV, size_t* time);
	
	void dfs_traverse_to(std::string nameV, int* time, std::vector<Vertex>* v);

	void create_Graph();

	void cargar_Plano();

};
