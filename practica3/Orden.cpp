#include "Orden.h"
#include "cstdlib"

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

void Orden::Seleccion(ListaContigua *lista, int direccion){
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

void Orden::Burbuja(ListaContigua *lista, int direccion){
	int temp = 0;

	for (int i = 2; i <= lista->getN(); ++i)
	{
		for (int j = 0; j < lista->getN() - i; ++j)
		{
			if (lista->getValor(j) > lista->getValor(j + 1))
			{
				temp = lista->getValor(j);
				lista->setValor(j, lista->getValor(j + 1));
				lista->setValor(j + 1, temp);
			}
		}
	}
}

ListaContigua Orden::QSort(ListaContigua *lista, int ini, int fin){
	int med = 0, pivote = 0, temp = 0, igual = 0, i, j;
	ListaContigua copia(*lista);

	//Localizar la mitad de la lista y asignar el pivote
	med = copia.getN() / 2;
	pivote = copia.getValor(med);	//PROVISIONAL

	i = 0;
	j = copia.getN();
	while (i < j)
	{
		//Recorrer la copia hasta que un elemento este en el lado que no le corresponde
		for (; copia.getValor(i) < pivote; ++i)
		for (; copia.getValor(j) > pivote; --j)
		//"igual" es un contador de elementos iguales que "pivote", se anaden al final
		for (; copia.getValor(i) == pivote || copia.getValor(i) == pivote; ++i, --j)
			igual++;

		//Los que no estan en el lado correcto, se intercambian si los indices no se han cruzado
		if (i < j)
		{
			temp = copia.getValor(j);
			copia.setValor(j, copia.getValor(i));
			copia.setValor(i, temp);
		}
	}

	//Llamadas recursivas a las semicopias
	if (fin - ini != 1)		//Condicion de parada: cuando quede solo 1 elemento
	{
		QSort(&copia, ini, med);
		QSort(&copia, med + 1, fin);
	}

	return copia;
}

void Orden::QuickSort(ListaContigua *lista, int direccion){
    ListaContigua temp(*lista);
	ListaContigua ordenada(QSort(&temp, 0, temp.getN()));

	//Copiar la lista ordenada a la lista pasada por parametro
	for (int i = 0; i < ordenada.getN(); ++i)
		lista->setValor(i, ordenada.getValor(i));
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
	ListaContigua salida(lista);

	salida = dividir(lista, 0, lista->getN() - 1);
	//COPIAR SALIDA A LISTA
}
