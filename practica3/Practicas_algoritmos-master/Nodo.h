// #pragma once

// #ifndef NODO_H
// #define NODO_H
#include "MyStr.h"

// Estructura que representa un nodo de una lista enlazada
struct Nodo
{
	Nodo *ateriorNodo;
	MyStr elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};

// #endif