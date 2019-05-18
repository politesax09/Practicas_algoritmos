#include "Arbol.h"

int main()
{
    Arbol test;
    test.insertar(10);
    test.insertar(5);
    test.insertar(1);
    test.insertar(11);

    test.mostrarOrden();

    return 0;
}
