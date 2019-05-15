#include "Orden.h"
#include "cstdlib"

#define RANGO 200
#include <iostream>

using namespace std;
Orden::Orden(){}
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

void Orden::Insercion(ListaContigua *lista, int direccion){
	int temp = 0, i, j, k,temp2;

	if(direccion == ASC)
        for (i = 0; i < lista->getN(); ++i)
        {
            temp = lista->getValor(i);
            for (j = i - 1, k = 0; j >= 0 && temp < lista->getValor(j) ; --j, ++k)
            {
                temp2 = lista->getValor(i - k);
                lista->setValor(i - k,lista->getValor(j));
                lista->setValor(j,temp2);
            }
        }
    else
        for (i = 0; i < lista->getN(); ++i)
        {
            temp = lista->getValor(i);
            for (j = i - 1, k = 0; j >= 0 && temp > lista->getValor(j) ; --j, ++k)
            {
                temp2 = lista->getValor(i - k);
                lista->setValor(i - k,lista->getValor(j));
                lista->setValor(j,temp2);
            }
        }
}

void Orden::Seleccion(ListaContigua *lista, int direccion){
	int i, j, interes, posInteres;

    if(direccion == ASC){
        for (i = 0; i < lista->getN(); ++i)
        {
            interes = lista->getValor(i);
            posInteres = 0;

            //Buscar el menor elemento de la semi-lista y guaradarlo junto a su posicion
            for (j = i; j < lista->getN(); ++j)
            {
                if (lista->getValor(j) < interes)
                {
                    interes = lista->getValor(j);
                    posInteres = j;
                }
            }

            //Intercambiar el elemento "i" con el "j"
            //Si posMenor == 0, significa que el "i" es el menor elemento en ese momento
            if (posInteres != 0)
            {
                lista->setValor(posInteres, lista->getValor(i));
                lista->setValor(i, interes);
            }

        }
	}
	else{
              for (i = 0; i < lista->getN(); ++i)
        {
            interes = lista->getValor(i);
            posInteres = 0;

            //Buscar el mallor elemento de la semi-lista y guaradarlo junto a su posicion
            for (j = i; j < lista->getN(); ++j)
            {
                if (lista->getValor(j) > interes)
                {
                    interes = lista->getValor(j);
                    posInteres = j;
                }
            }

            //Intercambiar el elemento "i" con el "j"
            //Si posInteres == 0, significa que el "i" es el mallor elemento en ese momento
            if (posInteres != 0)
            {
                lista->setValor(posInteres, lista->getValor(i));
                lista->setValor(i, interes);
            }

        }
	}

}

void Orden::Burbuja(ListaContigua *lista, int direccion){
	int temp = 0, i, j;

    for(i = 0; i < lista->getN();i++)
        cout << lista->getValor(i) << " ";
    cout << endl;
    if(direccion == ASC)
        for ( i = 1; i <= lista->getN(); ++i)
        {
            for ( j = 0; j < lista->getN() - i; ++j)
            {
                if (lista->getValor(j) > lista->getValor(j + 1))
                {
                    temp = lista->getValor(j);
                    lista->setValor(j, lista->getValor(j + 1));
                    lista->setValor(j + 1, temp);
                }
            }
        }
	else
        for ( i = 1; i <= lista->getN(); ++i)
        {
            for ( j = 0; j < lista->getN() - i; ++j)
            {
                if (lista->getValor(j) < lista->getValor(j + 1))
                {
                    temp = lista->getValor(j);
                    lista->setValor(j, lista->getValor(j + 1));
                    lista->setValor(j + 1, temp);
                }
            }
        }

    for(i = 0; i < lista->getN();i++)
        cout << lista->getValor(i) << " ";
    cout << endl;

}

void Orden::QSortASC(ListaContigua *copia, int ini, int fin){
  int i = ini, j = fin;
  int tmp;
  int pivot = copia->getValor((ini + fin) / 2);

  /* partition */
  while (i <= j) {
        while (copia->getValor(i) < pivot)
              i++;
        while (copia->getValor(j) > pivot)
              j--;
        if (i <= j) {
              tmp = copia->getValor(i);
              copia->setValor(i,copia->getValor(j));
              copia->setValor(j,tmp);
              i++;
              j--;
        }
    }
    /* recursion */
    if (ini < j)
        QSortASC(copia, ini, j);
    if (i < fin)
        QSortASC(copia, i, fin);
}

void Orden::QSortDESC(ListaContigua *copia, int ini, int fin){
  int i = ini, j = fin;
  int tmp;
  int pivot = copia->getValor((ini + fin) / 2);

  /* partition */
  while (i <= j) {
        while (copia->getValor(i) > pivot)
              i++;
        while (copia->getValor(j) < pivot)
              j--;
        if (i <= j) {
              tmp = copia->getValor(i);
              copia->setValor(i,copia->getValor(j));
              copia->setValor(j,tmp);
              i++;
              j--;
        }
    }
    /* recursion */
    if (ini < j)
        QSortDESC(copia, ini, j);
    if (i < fin)
        QSortDESC(copia, i, fin);
}

void Orden::QuickSort(ListaContigua *lista, int direccion){
    if (direccion == DESC)
        QSortDESC(lista,0,lista->getN() - 1);
    else
        QSortASC(lista,0,lista->getN() - 1);
}

// void merge(int *left, int l_len, int *right, int r_len, int *out)
// {
// 	int i, j, k;
// 	for (i = j = k = 0; i < l_len && j < r_len; )
// 		out[k++] = left[i] < right[j] ? left[i++] : right[j++];

// 	while (i < l_len) out[k++] = left[i++];
// 	while (j < r_len) out[k++] = right[j++];
// }

// void recur(int *buf, int *tmp, int len)
// {
// 	int l = len / 2;
// 	if (len <= 1) return;

// 	recur(tmp, buf, l);
// 	recur(tmp + l, buf + l, len - l);

// 	merge(tmp, l, tmp + l, len - l, buf);
// }

// void merge_sort(int *buf, int len)
// {
// 	//BUF ES EL RESULTADO
// 	int *tmp = malloc(sizeof(int) * len);
// 	memcpy(tmp, buf, sizeof(int) * len);

// 	recur(buf, tmp, len);

// 	free(tmp);
// }

ListaContigua Orden::merge(ListaContigua &lista, int l_ini, int l_fin, int r_ini, int r_fin){
	int i, j, k;
	ListaContigua salida(lista);
	for (i = l_ini, j = r_ini, k = 0; i <= l_fin && j <= r_fin; ++i)
	{
		if (lista.getValor(i) < lista.getValor(j))
			salida.setValor(k++, lista.getValor(i++));
		else salida.setValor(k++, lista.getValor(j++));
	}

	while (i <= l_fin) salida.setValor(k++, lista.getValor(i++));
	while (j <= r_fin) salida.setValor(k++, lista.getValor(j++));

	return salida;
}

ListaContigua Orden::dividir(ListaContigua &lista, int ini, int fin){
	int len = fin - ini, med = len / 2 - 1, l_ini = 0, r_ini = med + 1, l_fin = med, r_fin = len - 1;
	ListaContigua salida(lista);
	if (fin - ini <= 1)
	{
		salida.setValor(ini, lista.getValor(ini));	//REPLANTEAR CASO BASE Y DIVIDIR
		return salida;
	}

	dividir(lista, l_ini, l_fin);
	dividir(lista, r_ini, r_fin);

	return merge(lista, l_ini, l_fin, r_ini, r_fin);
}

void Orden::MergeSort(ListaContigua *lista, int direccion){
	ListaContigua salida(*lista);

	salida = dividir(*lista, 0, lista->getN() - 1);
	//COPIAR SALIDA A LISTA
}

void Orden::Rango(ListaContigua* lista, int direccion){
    int i,j,k; // contadores
    //Generar una lista de rango inicializada a 0
    ListaContigua temp;
    for(i = 0; i < RANGO; i++)
        temp.insertar(i,0);

    if(direccion == ASC){//Ordenacion ascendente

        for(i = 0; i < lista->getN(); i++)
            temp.setValor(lista->getValor(i),temp.getValor(lista->getValor(i)) + 1);
        for(i = 0,j = 0;i < RANGO && j < lista->getN(); i++)
            for(k = 0; k < temp.getValor(i) && j < lista->getN();k++)
                lista->setValor(j++,i);

    }else if(direccion == DESC){//Ordenacion descendente

        for(i = 0; i < lista->getN(); i++)
            temp.setValor(lista->getValor(i),temp.getValor(lista->getValor(i)) + 1); // generar el array de rangos
        for(i = RANGO - 1,j = 0;i >= 0 && j < lista->getN(); i--)// Modificar la lista entorno al array de rangos
            for(k = 0; k < temp.getValor(i) && j < lista->getN();k++)
                lista->setValor(j++,i);

    }
}





