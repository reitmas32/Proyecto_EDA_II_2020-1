#include "../../../../Headers/include/Estructuras_de_Datos/Graph/Vertex.hpp"

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