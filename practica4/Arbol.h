#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <iostream>
#include <stdlib.h>

typedef struct nodo{
    int elemento;
    struct nodo * derecha;
    struct nodo * izquierda;
} Node;

class Arbol{
    private:
        Node* raiz;
        int numeroDeNodos;

        void removeN(Node* root);
        Node* encuentraHueco(int valor, Node* root);
        void mostrarOrdenR(Node* root);

    public:
        void mostrarOrden();
        void insertar(int valor);
        Arbol();
        ~Arbol();
};

#endif // ARBOL_H_INCLUDED
