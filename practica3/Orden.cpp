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
	med = fin / 2;
	pivote = copia.getValor(med);	//PROVISIONAL

	i = 0;
	j = copia.getN() - 1;
	while (i < j)
	{
		//Recorrer la copia hasta que un elemento este en el lado que no le corresponde
		for (; copia.getValor(i) < pivote; ++i);
        for (; copia.getValor(j) > pivote; --j);
        //"igual" es un contador de elementos iguales que "pivote", se anaden al final
        for (; copia.getValor(i) == pivote || copia.getValor(j) == pivote; ++i, --j)
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
    cout << "flag\n";
    for(int i = 0; i < lista->getN(); i++)
        cout << lista->getValor(i) << " ";
    cout << "\nflag2\n";
	ListaContigua ordenada(QSort(lista,0,lista->getN()));


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
	cout << "fin=" << fin << endl;
	if (fin < 0)
	{
		printf("MAL\n");
	}
	ListaContigua salida(lista);
	// static int cont = 0;	//Indica la posicion de la lista resultado donde se tiene que insertar el valor del caso base ([veces que se ha ejecutado caso base] - 1)
	int len = fin - ini + 1, med = len / 2 + ini, l_ini = 0, r_ini = med, l_fin = med - 1, r_fin = len - 1 + ini;//BIEN
	
	if (fin - ini <= 1)
	{
		salida.setValor(ini, lista.getValor(ini));	//REPLANTEAR CASO BASE Y DIVIDIR
		return salida;
	}

	salida = dividir(lista, l_ini, l_fin);
	salida = dividir(lista, r_ini, r_fin);

	return merge(salida, l_ini, l_fin, r_ini, r_fin);
}

void Orden::MergeSort(ListaContigua *lista, int direccion){
	ListaContigua salida(*lista);
    cout << lista->getN() << endl;
    cout << salida.getN() << endl;

	salida = dividir(*lista, 0, lista->getN() - 1);

	//Copiar "salida" a "lista"
	for (int i = 0; i < salida.getN(); ++i)
		lista->setValor(i, salida.getValor(i));
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





