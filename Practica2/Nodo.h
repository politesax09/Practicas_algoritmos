#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "MyStr.h"

// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
	Nodo *ateriorNodo;
	MyStr elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};


#endif // NODO_H_INCLUDED
