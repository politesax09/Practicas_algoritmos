#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define INORDER 0
#define PREORDER 1
#define POSTORDER 2

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
        void mostrarR(Node* root,int orden);

    public:
        void mostrar(int orden);
        int getNumNod();
        void insertar(int valor);
        Arbol();
        ~Arbol();
};

#endif // ARBOL_H_INCLUDED
