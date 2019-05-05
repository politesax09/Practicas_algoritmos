#include "ListaContigua.h"

#define ASC 0	// de menor a mayor
#define DESC 1	// de mayor a menor

class Orden
{
public:
	Orden();

	bool esOrdenada(ListaContigua *lista, int direccion);

	ListaContigua QSort(ListaContigua *lista, int ini, int fin);

	//Metodos de ordenacion
	void insercion(ListaContigua *lista, int direccion);
	void seleccion(ListaContigua *lista, int direccion);
	void burbuja(ListaContigua *lista, int direccion);
	void QuickSort(ListaContigua *lista, int direccion);
	void MSort(ListaContigua *lista, int direccion);
	void rango(ListaContigua *lista, int direccion);

	~Orden();
	
};