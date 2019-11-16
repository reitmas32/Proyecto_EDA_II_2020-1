#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Vertex.hpp"

void printQ(std::list<Vertex> _this){
	for (auto& q : _this){
		std::cout<<q.get_name()<<std::endl;
	}
	
}

//----------------------------------------------------------------------
//  Class Graph
//----------------------------------------------------------------------
class Graph
{
private:
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex

public:
	Graph();
	~Graph();
//	Graph( std::vector<Vertex> vertices ); 

	bool add_vertex( Vertex v );
	bool add_edge( std::string edge1, std::string edge2 );
	bool add_edge_directed( std::string edge1, std::string edge2 );
	std::map<std::string, Vertex> get_map();

	bool allVisit();

	void print();

	void BFS(std::string start);
	void DIJSKTRA(std::string start);

	std::list<std::string> goTo(std::string start, std::string end);
};

#endif	//GRAPH_HPP