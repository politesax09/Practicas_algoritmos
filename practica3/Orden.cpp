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