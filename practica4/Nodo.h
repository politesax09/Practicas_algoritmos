#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

/*Estructura basica del arbol binario*/
typedef struct nodo{
    int elemento;		// Valor guardado por el nodo
    struct nodo* derecha;		// Puntero al nodo hijo derecho
    struct nodo* izquierda;		// Puntero al nodo hijo izquierdo
} Node;

#endif	// NODO_H_INCLUDED