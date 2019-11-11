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

Graph::Graph()
{
	// nada (por el momento)
}

Graph::~Graph()
{
	this->vertices.~map();
}

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos
	
	return ret.second;
}

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );
		v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}

bool Graph::add_edge_directed( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );

		return true;
	}

	return res;
}

void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}

std::map<std::string, Vertex> Graph::get_map(){
	return this->vertices;
}
/*
void Graph::BFS(Vertex start){
	for(auto& v : this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor("");
	}
	start.set_color(Vertex::Colors::GRAY);
	std::list<Vertex> q = std::list<Vertex>();
	q.push_back(start);

	while (!q.empty())
	{
		Vertex v = q.front();
		q.pop_front();

		for (auto& w : v.get_neighbors())
		{
			if (w.get_color() == Vertex::Colors::BLACK)
			{
				w.set_color(Vertex::Colors::GRAY);
				w.set_distance(v.get_distance()+1);
				w.set_predecesor(v.get_name());
				q.push_back(w);
			}
		}
		v.set_color(Vertex::Colors::WHITE);
	}
	for(auto& v : this->vertices){
		v.second.print();
	}
	
}
*/

void Graph::BFS(std::string start){
	for(auto& v : this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor(" ");
	}

	this->vertices.find(start)->second.set_color(Vertex::Colors::GRAY);
	std::list<Vertex> q;
	q.push_back(this->vertices.find(start)->second);

	while (not q.empty())
	{
		Vertex v = q.front();
		q.pop_front();

		for (auto& w : this->vertices.find(v.get_name())->second.get_neighbors())
		{
			if (this->vertices.find(w.get_name())->second.get_color() == Vertex::Colors::BLACK)
			{
				this->vertices.find(w.get_name())->second.set_color(Vertex::Colors::GRAY);
				this->vertices.find(w.get_name())->second.set_distance(v.get_distance() + 1);
				this->vertices.find(w.get_name())->second.set_predecesor(v.get_name());
				q.push_back(this->vertices.find(w.get_name())->second);
			}
		}
		this->vertices.find(v.get_name())->second.set_color(Vertex::Colors::WHITE);
	}
	for(auto& v : this->vertices){
		v.second.print();
	}
	
}

std::list<std::string> Graph::goTo(std::string start, std::string end){
	this->BFS(start);
	std::list<std::string> pila;
	pila.push_back(this->vertices.find(end)->second.get_name());
	std::string s = this->vertices.find(end)->second.get_predecesor();
	while(s != start){
		pila.push_back(s);
		s = this->vertices.find(s)->second.get_predecesor();
	}
	pila.push_back(s);
	return pila;
}

bool Graph::allVisit(){
	for(auto& v : this->vertices){
		if(v.second.get_color() != Vertex::Colors::WHITE){
			return false;
		}
	}
	return true;
}

void Graph::DIJSKTRA(std::string start){
	for(auto& v : this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor(" ");
	}
	for(auto& w : this->vertices){
		std::list<Vertex> l = w.second.get_neighbors();
		if(w.second.isNeighbors(start)){
			this->vertices.find(w.second.get_name())->second.set_distance(this->vertices.find(start)->second.get_distance() + 1);
		}
 
	}
	this->vertices.find(start)->second.set_distance(0);
	this->vertices.find(start)->second.set_color(Vertex::Colors::WHITE);

	while (not this->allVisit())
	{
		Vertex v = Vertex("");
		for(auto& w : this->vertices){
			if(w.second.get_color() != Vertex::Colors::WHITE){
				v = this->vertices.find(w.second.get_name())->second;
				break;
			}
		}
		this->vertices.find(v.get_name())->second.set_color(Vertex::Colors::WHITE);

		for (auto& w : this->vertices)
		{
			if( w.second.get_distance() < v.get_distance() + 1 && w.second.get_color() != Vertex::Colors::WHITE){
				this->vertices.find(w.second.get_name())->second.set_distance(v.get_distance() + 1);
				this->vertices.find(w.second.get_name())->second.set_predecesor(v.get_name());
			}
		}
		
	}
	for(auto& v : this->vertices){
		v.second.print();
	}
	
}

#endif	//GRAPH_HPP