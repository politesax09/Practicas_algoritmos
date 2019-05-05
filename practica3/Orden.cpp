#include "Orden.h"

bool Orden::esOrdenada(ListaContigua *lista, int direccion){
	int i = 0;

	if (direccion == ASC)
	{
		while (lista->getValor(i - 1) < lista->getValor(i) && i < lista->getN())
		if (i == lista->getN() - 1)
			return true;
		return false;
	}
	else
	{
		while (lista->getValor(i - 1) > lista->getValor(i) && i < lista->getN())
		if (i == lista->getN() - 1)
			return true;
		return false;				
	}
}

void Orden::insercion(ListaContigua *lista, int direccion){
	int temp = 0, i, j, k;

	for (i = 0; i < lista->getN(); ++i)
	{
		temp = lista->getValor(i);

		for (j = i - 1, k = i - 1; j >= 0; --j)
		{
			if (lista->getValor(i) < lista->getValor(j))
			{
				for (; k - 1 > j; --k)
					lista->setValor(k, lista->getValor(k - 1));
				lista->setValor(j, temp);	
			}
		}
	}
}

void Orden::seleccion(ListaContigua *lista, int direccion){
	int i, j, menor, posMenor;
	for (i = 0; i < lista->getN(); ++i)
	{
		menor = lista->getValor(i);
		posMenor = 0;

		//Buscar el menor elemento de la semi-lista y guaradarlo junto a su posicion
		for (j = i; j < lista->getN(); ++j)
		{
			if (lista->getValor(j) < menor)
			{
				menor = lista->getValor(j);
				posMenor = j;
			}
		}
		
		//Intercambiar el elemento "i" con el "j"
		//Si posMenor == 0, significa que el "i" es el menor elemento en ese momento
		if (posMenor != 0)
		{
			lista->setValor(posMenor, lista->getValor(i));
			lista->setValor(i, menor);		
		}

	}
}