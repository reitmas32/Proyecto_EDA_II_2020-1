#PacMan
Sour = Sources/src
Head = Headers/include
Obj  = obj/Debug
GE_headers = $(Head)/Graphics_Engine
GE_sources = $(Sour)/Graphics_Engine
GE_obj	   = $(Obj)/Graphics_Engine

Obj_headers = $(Head)/Objetos
Obj_sources = $(Sour)/Objetos
Obj_obj	   = $(Obj)/Objetos

ED_headers = $(Head)/Estructuras_de_Datos
ED_sources = $(Sour)/Estructuras_de_Datos
ED_obj = $(Obj)/Estructuras_de_Datos

#-----------------Graphics Engine----------------#
miniwin.o:$(GE_headers)/miniwin.h $(GE_sources)/miniwin.cpp
	g++ -Wall -g -DDEBUG  -c "$(GE_sources)/miniwin.cpp" -o "$(GE_obj)/miniwin.o"

Cuadro.o:$(GE_headers)/Cuadro.hpp $(GE_sources)/Cuadro.cpp miniwin.o
	g++ -Wall -g -DDEBUG  -c "$(GE_sources)/Cuadro.cpp" -o "$(GE_obj)/Cuadro.o"

#-------------------Main-------------------------#
main.o:$(Sour)/main.o miniwin.o
	g++ -Wall -g -DDEBUG  -c "$(Sour)/main.cpp" -o "$(Obj)/main.o"

Pacman:main.o miniwin.o
	g++  -o "bin/Debug/PacMan" "obj/Debug/main.o" "obj/Debug/Graphics_Engine/miniwin.o"  -pthread  -lX11
