#include "Arbol.h"
#include <time.h>

#define CANT_NUMEROS_ALE 50

using namespace std;

int menu(){
    int userInput;
    cout << "1 Introducir numero\n";
    cout << "2 Intocucir 50 numeros aleatorios\n";
    cout << "3 Mostrar Inorder\n";
    cout << "4 Mostrar Preorder\n";
    cout << "5 Mostrar Postorder\n";
    cout << "6 Salir\n";
    cin >> userInput;
    return userInput;
}

void introNum(Arbol * test){
    int userInput;
    cout << "Intoduce num: ";
    cin >> userInput;
    test->insertar(userInput);
}

void ale50Num(Arbol * test){
    srand (time(NULL));

    while(test->getNumNod() < CANT_NUMEROS_ALE)
        test->insertar(rand());

}

int main()
{
    Arbol test;
    int option;

    while(option = menu()){
        if(option == 1) introNum(&test);
        if(option == 2) ale50Num(&test);
        if(option == 3) test.mostrar(INORDER);
        if(option == 4) test.mostrar(PREORDER);
        if(option == 5) test.mostrar(POSTORDER);
        if(option == 6) break;
    }

    return 0;
}
