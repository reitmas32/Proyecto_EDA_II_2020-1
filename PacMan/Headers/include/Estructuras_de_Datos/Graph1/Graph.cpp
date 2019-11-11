#include "Graph.hpp"

size_t Graph::hash_string(string key, size_t max){
	const char *newKey = key.c_str();
	int length = strlen(newKey);

	int i,sum;

	for(sum =0, i=0; i< length; i++){
		sum += newKey[i];
	}

	return sum %max;
}
size_t Graph::coll_res( size_t index, size_t max ){
	 size_t new_index = (index + 1) % max;
	 return new_index;
}

void Graph::printNeighbors(string name, Vertex vertex){

	cout << "\n" << vertex.getName() << ": ";
	vertex.print_neighbors();
	cout <<endl;		
}

void Graph::printVertex(string name, Vertex vertex){
	vertex.print();
	cout << endl;
}

//===========================================================

Graph::Graph(size_t capacity){
	Vertex null;
	this -> vertices = new Map<string,Vertex>(capacity,"",hash_string,coll_res);
}

Graph::~Graph(){
	delete this -> vertices;
}

bool Graph::contains(string name){
	Vertex tmp;

	return this ->vertices -> Retrieve(name,&tmp);
}

bool Graph::addVertex(Vertex v){

	return (this -> vertices -> Insert(v.getName(),v));
}

bool Graph::addEdge(string b1, string b2){

	Vertex v1(b1);
	Vertex v2(b2);

	if(this -> vertices -> Retrieve(b1,&v1) && this -> vertices -> Retrieve(b2,&v2)){
		if(v1.addNeighbors(v2) && v2.addNeighbors(v1)){
			this -> vertices -> Remove(b1);
			this -> vertices -> Remove(b2);
			this -> addVertex(v1);
			this -> addVertex(v2);
			return true;	
		}
	}

	return false;
}


bool Graph::addEdgeDirected(string b1, string b2){

	Vertex v1(b1);
	Vertex v2(b2);

	if(this -> vertices -> Retrieve(b1,&v1) && this -> vertices -> Retrieve(b2,&v2)){
		if(v1.addNeighbors(v2)){
			this -> vertices -> Remove(b1);
			this -> addVertex(v1);
			return true;	
		}
	}

	return false;

}

Vertex Graph::getVertex(string v){
	Vertex vertex(v);

	this -> vertices -> Retrieve(v,&vertex);

	return vertex;
}

Map<string,Vertex>  *Graph::getMap(){
	return this -> vertices;
}

void Graph::print(size_t modo){
	cout << endl;
	switch(modo){
		case 0:
			this -> vertices -> Iterator(printNeighbors);
			break;
		case 1:
			this -> vertices ->Iterator(printVertex);
			break;
	}

}

void Graph::dijkstra(string start){
		cout<<"v";
		
	Vertex v = Vertex("");
	Couple<string,Vertex>* _start = new Couple<string,Vertex>("", v);	

	//Obtengo el couple 
	this->vertices->Remove(start, _start);	

	//Modifico el couple
	v = _start->getTwo();
		
	DLL<Vertex>* W = v.getNeighbors();
	Vertex w = Vertex("");
	W->RemoveFront(&w);
	for(size_t i = 0; i < 0; i++){

		if( w.getColor() == Vertex::Colors::BLACK || _start->getTwo().getDistance() + 1 < w.getDistance()){
			w.setDistance(_start->getTwo().getDistance() + 1);
			w.setPredecesor(_start->getTwo().getName());
			w.setColor(Vertex::Colors::GRAY);
		}
		W->InsertBack(w);
		
	}
	//v.neighbors->~DLL();
	
	v.neighbors = W;
	v.setColor(Vertex::Colors::WHITE);
	//Regreso el vertex a _start
	_start->setTwo(v);
	v.neighbors->CursorFirst();
	Vertex U[v.getNeighbors()->Len()];
	v.neighbors->CursorFirst();
	for(size_t i = 0; i < v.neighbors->Len(); i++){
		v.neighbors->Peek(&U[i]);
		v.neighbors->CursorNext();
	}
	for(size_t i = 0; i < v.neighbors->Len(); i++){
		U[i].print();
	}
	/*
	for(size_t i = 0; i < v.getNeighbors()->Len(); i++){
		
		Vertex* u = new Vertex("");
		cout<<v.neighbors->Len();
		if(not v.neighbors->IsEmpty()){
			v.neighbors->Peek(u);
			this->dijkstra(u->getName());
			
		}
		//v.neighbors->CursorNext();
	}
	*/
}

#if 1
void Graph::DIJKSTRA(string start){
	
	for( size_t i = 0; i < this->vertices->Size(); i++){
		Vertex tmp = this->vertices->table[i].getTwo();
		tmp.setDistance(0);
		tmp.setPredecesor("");
		tmp.setColor(Vertex::Colors::BLACK);
		this->vertices->table[i].setTwo(tmp);
	}
	//variables auxiliares
	Vertex v = Vertex("");
	Couple<string,Vertex>* _start = new Couple<string,Vertex>("", v);

	//Obtengo el couple 
	this->vertices->Remove(start, _start);

	//Modifico el couple
	v = _start->getTwo();
	v.setColor(Vertex::Colors::WHITE);

	//Regreso el Vertex modificado
	_start->setTwo(v);

	//Regreso el Couple modificado
	this->vertices->Insert(_start->getOne(), _start->getTwo());
	v.print_neighbors();
	this->dijkstra(start);
}
#endif

void Graph::BFS(string start){
	cout<<"jj";
	
	for( size_t i = 0; i < this->vertices->Size(); i++){
		Vertex tmp = this->vertices->table[i].getTwo();
		tmp.setDistance(0);
		tmp.setPredecesor("");
		tmp.setColor(Vertex::Colors::BLACK);
		this->vertices->table[i].setTwo(tmp);
	}
	
	this->vertices->find(start)->last.setColor(Vertex::Colors::GRAY);
	this->vertices->find(start)->last.print();
	DLL<Vertex>* q = new DLL<Vertex>();
	
	q->InsertBack(this->vertices->find(start)->last);
	while(not q->IsEmpty()){
		Vertex v = Vertex("");
		q->RemoveFront(&v);
		
		DLL<Vertex>* neighbors = this->vertices->find(v.getName())->last.getNeighbors();
		neighbors->CursorFirst();
		for(size_t i = 0; i < neighbors->Len(); i++){
			Vertex* w;
			neighbors->RemoveFront(w);
			if(w->getColor() == Vertex::Colors::BLACK){
				w->setColor(Vertex::Colors::GRAY);
				w->setDistance(v.getDistance() + 1);
				w->setPredecesor(v.getName());
				q->InsertBack(this->vertices->find(w->getName())->last);
			
			}
			neighbors->InsertBack(*w);
		}
		this->vertices->find(v.getName())->last.setColor(Vertex::Colors::WHITE);
		
	}
	
}
