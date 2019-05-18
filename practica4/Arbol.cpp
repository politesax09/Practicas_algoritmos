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
    if(this->raiz == nullptr){
        raiz = (Node *) malloc(sizeof(Node));
        raiz->elemento = valor;
        raiz->derecha = nullptr;
        raiz->izquierda = nullptr;
    }else{
        hueco = this->encuentraHueco(valor,this->raiz);
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
}

Node* Arbol::encuentraHueco(int valor, Node* root){
    if(root->elemento > valor){
        if(root->izquierda == nullptr) return root;
        return encuentraHueco(valor,root->izquierda);
    }else{
        if(root->derecha == nullptr) return root;
        return encuentraHueco(valor,root->derecha);
    }

}

void Arbol::mostrarOrden(){
    this->mostrarOrdenR(this->raiz);
}

void Arbol::mostrarOrdenR(Node* root){
    if(root == nullptr) return;
    mostrarOrdenR(root->izquierda);
    cout << root->elemento << " " ;
    mostrarOrdenR(root->derecha);
}
