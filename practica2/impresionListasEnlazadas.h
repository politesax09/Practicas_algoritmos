// #pragma once

// #ifndef IMPRESIONLISTASENLAZADAS_H
// #define IMPRESIONLISTASENLAZADAS_H

#include "ListaEnlazada.h"

// Imprime una lista enlazada por pantalla (su "n" y sus elementos), con un maximo de 20 elementos
// Parámetros:
// - lista: puntero a la lista enlazada que queremos imprimir
// Precondición: lista!=NULL
// Complejidad temporal: O(n^2). Realmente es O(1) porque como maximo imprime 20 elementos
// Complejidad espacial: O(1)
void imprimirListaEnlazada(ListaEnlazada *lista);

// #endif