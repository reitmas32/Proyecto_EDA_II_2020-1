
#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
#include <cstring>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)

#include <vector>

//#include <algorithm>

#include "Grafo.hpp"

Graph::Graph()
{
	// nada (por el momento)
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
		//printf("Siiiii\n");
		v1->second.add_neighbor( v2->second );
		v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}

bool Graph::add_edge_directed( std::string edge1, std::string edge2 ){
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

bool Graph::add_edge_weighted( std::string edge1, std::string edge2, int weigth = 1){
	
	bool res = false;

	if( add_edge_directed(edge1, edge2)){

		auto v1 = this->vertices.find( edge1 );

		v1->second.set_weigth(weigth);

		return true;
	}

	return res;
}


Vertex Graph::get_Vertex(std::string Vname){
	return 	this->vertices.find(Vname)->second;
}

std::map<std::string, Vertex> Graph::get_map(){
	return this->vertices;
}

#if 0
void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}
#else
void Graph::print()
{
	for( auto v : this->vertices ){ v.second.print(); }
}
#endif

void print_list(std::list<Vertex> list){
	for(auto v: list){ std::cout<<v.get_name(); }
}

void Graph::BSF(std::string nameStart){

	for(auto &v: this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor("Nil");
	}
	
	auto &start = this->vertices.find(nameStart)->second;
	start.set_color(Vertex::Colors::GRAY);
	
	#if 1

	std::list<Vertex> q;
	q.push_front(start);

	while(!q.empty()){

		Vertex v = q.front();
		q.pop_front();
		
		for(auto &w: this->vertices.find(v.get_name())->second.get_neighbors()){

			if(this->vertices.find(w.get_name())->second.get_color() == Vertex::Colors::BLACK){
				this->vertices.find(w.get_name())->second.set_color(Vertex::Colors::GRAY);
				
				int dist = this->vertices.find(v.get_name())->second.get_distance();
				this->vertices.find(w.get_name())->second.set_distance(dist+1);
				this->vertices.find(w.get_name())->second.set_predecesor(v.get_name());
				q.push_back(w);
			}
		}
		this->vertices.find(v.get_name())->second.set_color(Vertex::Colors::WHITE);
	}

	#endif
}

void Graph::dfs_traverse(std::string nameV, size_t* time){
	
	++*time;

	this->vertices.find(nameV)->second.set_discovery_time(*time);
	this->vertices.find(nameV)->second.set_color(Vertex::Colors::GRAY);

	for( auto &u: this->vertices.find(nameV)->second.get_neighbors()){
		if(this->vertices.find(u.get_name())->second.get_color() == Vertex::Colors::BLACK){
			this->vertices.find(u.get_name())->second.set_predecesor(nameV);
			dfs_traverse(u.get_name(), time);
		}
	}

	this->vertices.find(nameV)->second.set_color(Vertex::Colors::WHITE);

	++*time;

	this->vertices.find(nameV)->second.set_finish_time(*time);
}

void Graph::DFS(std::string nameStart){

	size_t time = 0;

	for(auto &v: this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor("Nil");
		v.second.set_discovery_time(0);
		v.second.set_finish_time(0);
	}

	dfs_traverse(nameStart, &time);
	
}

void Graph::dfs_traverse_to(std::string nameV, int* time, std::vector<Vertex>* lista){

	++*time;
	
	this->vertices.find(nameV)->second.set_discovery_time(*time);
	this->vertices.find(nameV)->second.set_color(Vertex::Colors::GRAY);

	for( auto &u: this->vertices.find(nameV)->second.get_neighbors()){
		if(this->vertices.find(u.get_name())->second.get_color() == Vertex::Colors::BLACK){
			this->vertices.find(u.get_name())->second.set_predecesor(nameV);
			dfs_traverse_to(u.get_name(), time, lista);
		}
	}

	this->vertices.find(nameV)->second.set_color(Vertex::Colors::WHITE);

	++*time;

	this->vertices.find(nameV)->second.set_finish_time(*time);

	lista->push_back(this->vertices.find(nameV)->second);
}


std::vector<Vertex> Graph::dfs_to(std::string nameStart){
	static int time = 0;

	for(auto &v: this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_predecesor("Nil");
		v.second.set_discovery_time(0);
		v.second.set_finish_time(0);
	}	

	std::vector<Vertex> lista;

	dfs_traverse_to(nameStart, &time, &lista);

	std::sort (lista.begin(), lista.end(),
		[](Vertex& lhs, Vertex& rhs)->bool{
			return lhs.get_finish_time() > rhs.get_finish_time();
		} );

	return lista;

}

void Graph::create_Graph(){
	//
}


void Graph::cargar_Plano(){
	
	std::vector< std::string > datos;

	for( auto s : this->admon.getNodos() ){
		char *cstr = new char [s.size()+1];
		std::strcpy( cstr, s.c_str() );
		char *token = strtok( cstr, ":" );
		//while( token != NULL ){
		for( int i = 0; i < 3; ++i ){
			datos.push_back( token );
			token = strtok( NULL, ":" );
		}
		this->add_vertex( Vertex( datos[0], datos[1], datos[2] ) );
		datos.clear();
		delete[] cstr;
	}

	datos.clear();

	for( auto s : this->admon.getEdges() ){
		char *cstr = new char [ s.size() ];
		std::strcpy( cstr, s.c_str() );
		char *token = strtok( cstr, ":" );
		//while( token != NULL ){
		for( int i = 0; i < 2; ++i ){
			datos.push_back( token );
			token = strtok( NULL, ":" );
		}
		this->add_edge( datos[0], datos[1] );
		datos.clear();
		delete[] cstr;
	}
}

int main()
{	

	Graph g;

	g.cargar_Plano();
	//g.add_edge("1", "2");

	//std::cout<<"BSF: "<<"\n";
	g.BSF("1");
	g.print();

	//std::cout<<"\n";

}
