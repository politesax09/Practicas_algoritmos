#include "ListaContigua.h"

#define ASC 0	// de menor a mayor
#define DESC 1	// de mayor a menor

class Orden
{
public:
	Orden();

	bool esOrdenada(ListaContigua *lista, int direccion);

	ListaContigua QSort(ListaContigua *lista, int ini, int fin);
	ListaContigua merge(ListaContigua &lista, int l_ini, int l_fin, int r_ini, int r_fin);
	ListaContigua dividir(ListaContigua &lista, int ini, int fin);

	//Metodos de ordenacion
	void Insercion(ListaContigua *lista, int direccion);
	void Seleccion(ListaContigua *lista, int direccion);
	void Burbuja(ListaContigua *lista, int direccion);
	void QuickSort(ListaContigua *lista, int direccion);
	void MergeSort(ListaContigua *lista, int direccion);
	void Rango(ListaContigua *lista, int direccion);

};
