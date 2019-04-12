#pragma once
#include "MyStr.h"
// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
	Nodo *ateriorNodo;
	int elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};

