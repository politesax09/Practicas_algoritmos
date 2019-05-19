#include "Arbol.h"

using namespace std;

Arbol::Arbol(){
    this->raiz = nullptr;
    this->numeroDeNodos = 0;
}

Arbol::~Arbol(){
    removeN(this->raiz);
}

void Arbol::removeN(Node* root){
    if(root == nullptr) return;
    removeN(root->derecha);
    removeN(root->izquierda);
    delete root;
}

void Arbol::insertar(int valor){
    Node* hueco;

    // Cuando el arbol esta vacio, crea el nodo raiz
    if(this->raiz == nullptr){
        raiz = (Node *) malloc(sizeof(Node));
        raiz->elemento = valor;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;

    // Si no esta vacio, llama a encuentraHueco()
    }else{
        hueco = this->encuentraHueco(valor, this->raiz);
        if(hueco == nullptr) return;
        
        // Inserta el valor en el hueco
        if(valor < hueco->elemento){
            hueco->izquierda = (Node *) malloc(sizeof(Node));
            hueco->izquierda->elemento = valor;
            hueco->izquierda->derecha = nullptr;
            hueco->izquierda->izquierda = nullptr;
        }else{
            hueco->derecha = (Node *) malloc(sizeof(Node));
            hueco->derecha->elemento = valor;
            hueco->derecha->derecha = nullptr;
            hueco->derecha->izquierda = nullptr;
        }
    }
    this->numeroDeNodos++;
}

Node* Arbol::encuentraHueco(int valor, Node* root){
    if(root->elemento > valor){
        if(root->izquierda == nullptr) return root;
        return encuentraHueco(valor, root->izquierda);
    }else if(root->elemento < valor) {
        if(root->derecha == nullptr) return root;
        return encuentraHueco(valor, root->derecha);
    }
    return nullptr;
}

int Arbol::getNumNod(){
    return this->numeroDeNodos;
}

void Arbol::mostrar(int orden){
    cout << endl;
    this->mostrarR(this->raiz, orden);
    cout << endl << endl;
}

void Arbol::mostrarR(Node* root,int orden){
    if(root == nullptr) return;
    if(orden == INORDER){
        mostrarR(root->izquierda, orden);
        cout << root->elemento << " " ;
        mostrarR(root->derecha, orden);
        }
    if(orden == PREORDER){
        cout << root->elemento << " " ;
        mostrarR(root->izquierda, orden);
        mostrarR(root->derecha, orden);
    }
    if(orden == POSTORDER){
        mostrarR(root->izquierda, orden);
        mostrarR(root->derecha, orden);
        cout << root->elemento << " " ;
    }
}
