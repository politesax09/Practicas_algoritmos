#include "ListaContigua.h"

#define ASC 0	// de menor a mayor
#define DESC 1	// de mayor a menor

class Orden
{
private:
    void QSortASC(ListaContigua *copia, int ini, int fin);
	void QSortDESC(ListaContigua *copia, int ini, int fin);
public:
	Orden();

	bool esOrdenada(ListaContigua *lista, int direccion);


	void mergeASC(ListaContigua *lista, int l, int m, int r);
	void mergeDESC(ListaContigua *lista, int l, int m, int r);
	void dividir(ListaContigua *lista, int ini, int fin, bool descendente);

	//Metodos de ordenacion
	void Insercion(ListaContigua *lista, int direccion);
	void Seleccion(ListaContigua *lista, int direccion);
	void Burbuja(ListaContigua *lista, int direccion);
	void QuickSort(ListaContigua *lista, int direccion);
	void MergeSort(ListaContigua *lista, int direccion);
	void Rango(ListaContigua *lista, int direccion);

};
