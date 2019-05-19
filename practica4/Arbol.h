#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Nodo.h"

/* Clase que define un arbol de ordenacion binaria compuesto por nodos */
/* Los elementos menores se situan a la izquierda y los mayores a la derecha */
class Arbol{
    private:

        // Puntero a la raiz principal del arbol
        Node* raiz;

        // Numero de nodos existentes
        int numeroDeNodos;

        // Metodo auxiliar 
        void removeN(Node* root);

        // Metodo auxiliar utilizado por insertar()
        // Busca un hueco libre para insertar un valor mantenierdo el arbol ordenado
        // Parametros:   - valor: numero a introducir
        //               - root: puntero a la raiz
        // Retorno: el hueco donde se puede introducir (*Node)
        Node* encuentraHueco(int valor, Node* root);

        // Metodo auxiliar utilizado por mostrar()
        // Imprimer la informacion segun el orden indicado por parametro
        // Parametros:  -root: puntero a la raiz
        //              - orden: forma de imprimir (Inorder, Preorder o Postorder)
        void mostrarR(Node* root, int orden);

    public:

        // Imprime la informacion por pantalla
        // Utiliza el metodo auxiliar mostrarR()
        // Parametros:  - orden: forma de imprimir (Inorder, Preorder o Postorder)
        void mostrar(int orden);

        // Metodo que devuelve el numero de nodos (numeroDeNodos)
        int getNumNod();

        // Inserta un valor pasado por parametro de tal forma que el arbol se mantiene ordenado
        // Parametros:  -valor: numero a introducir
        void insertar(int valor);

        // Constructor por defecto
        Arbol();

        // Destructor recursivo
        // Utiliza el metodo auxiliar removeN()
        ~Arbol();
};

#endif // ARBOL_H_INCLUDED
