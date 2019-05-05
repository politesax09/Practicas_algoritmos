#include "Orden.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	ListaContigua lista;
	// Orden ordenar;

	lista.insertarAlFinal(1);
	lista.insertarAlFinal(5);
	lista.insertarAlFinal(3);
	lista.insertarAlFinal(8);

	for (int i = 0; i < lista.getN(); i++)
	{
		printf("%d ", lista.getValor(i));
	}
	printf("\n");

	// insercion(&lista, ASC);

	for (int i = 0; i < lista.getN(); i++)
	{
		printf("%d ", lista.getValor(i));
	}
	printf("\n");

	return 0;
}