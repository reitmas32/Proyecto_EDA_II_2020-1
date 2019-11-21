
#include <stdio.h>
// para las operaciones con archivos 

#include <string>
// para memset()

#include <stdlib.h>
// para exit()

#include <list>


class Administrador{

private:
	std::string RUTA_DATOS = "./datos/";
	std::string NOMBRE_ARCHIVO_NODOS = "Nodos.txt";
	std::string NOMBRE_ARCHIVO_EDGES = "Edges.txt";

public:

	Administrador();

	std::list< std::string > getNodos();

	std::list< std::string > getEdges();

};
