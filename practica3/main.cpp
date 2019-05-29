#include "Orden.h"
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	int tam;
    Orden oblig;

	srand(time(NULL));
	cout << "Introduce el tamano de la lista (numero mayor o igual que 1): ";
	cin >> tam;

	ListaContigua listaInsercion;
	for (int i = 0; i < tam; i++)
	{
        int numeroAInsertar = rand() % 100; // Numero aleatorio para insertar en las listas
        listaInsercion.insertarAlFinal(numeroAInsertar);
    }
    //Utilizar el constructor de copia a partir de la primera lista inicializada
    ListaContigua listaSeleccion(listaInsercion), listaBurbuja(listaInsercion), listaQSort(listaInsercion), listaMSort(listaInsercion), listaRango(listaInsercion);

    printf("ESCRIBIDO\n");
    if (oblig.esOrdenada(listaInsercion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n\n");
    printf("ATIENDE SUBLIME Q TE DESTRUYO. KPIN KPAN.\n");

    // Medicion del algoritmo de ordenacion por Insercion
    unsigned long int clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Insercion: " << clicksInicio << endl;
	oblig.Insercion(&listaInsercion, ASC);
    unsigned long int clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Insercion:    " << clicksFin << endl;

    float tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (caso general)\n", tiempo);

    if (oblig.esOrdenada(listaInsercion, ASC) == false) printf(">>>> EL ALGORITMO NO HA FUNCIONADO CORRECTAMENTE!!! <<<<\n\n");

    //Mejor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Insercion: " << clicksInicio << endl;
	oblig.Insercion(&listaInsercion, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Insercion:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (mejor caso)\n", tiempo);

    //Peor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Insercion: " << clicksInicio << endl;
	oblig.Insercion(&listaInsercion, DESC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Insercion:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (peor caso)\n", tiempo);
//=======================================================================================================================

    // Medicion del algoritmo de ordenacion por Seleccion
    //Caso general
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Seleccion: " << clicksInicio << endl;
	oblig.Seleccion(&listaSeleccion, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Seleccion:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Seleccion ha tardado: %f segundos (caso general)\n", tiempo);

    //Mejor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Seleccion: " << clicksInicio << endl;
	oblig.Seleccion(&listaSeleccion, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Seleccion:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Seleccion ha tardado: %f segundos (mejor caso)\n", tiempo);

    //Peor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Seleccion: " << clicksInicio << endl;
	oblig.Seleccion(&listaSeleccion, DESC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Seleccion:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Seleccion ha tardado: %f segundos (peor caso)\n", tiempo);
//====================================================================================================================

    // Medicion del algoritmo de ordenacion Burbuja
    //Caso general
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Burbuja: " << clicksInicio << endl;
	oblig.Burbuja(&listaBurbuja, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Burbuja:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Burbuja ha tardado: %f segundos (caso general)\n", tiempo);

    //Mejor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Burbuja: " << clicksInicio << endl;
	oblig.Burbuja(&listaBurbuja, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Burbuja:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (mejor caso)\n", tiempo);

    //Peor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Burbuja: " << clicksInicio << endl;
	oblig.Burbuja(&listaBurbuja, DESC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Burbuja:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (peor caso)\n", tiempo);
   //====================================================================================================================

    // Medicion del algoritmo de ordenacion QuickSort
    //Caso general
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por QuickSort: " << clicksInicio << endl;
	oblig.QuickSort(&listaQSort, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Quicksort:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("QuickSort ha tardado: %f segundos (caso general)\n", tiempo);

    //Mejor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por QuickSort: " << clicksInicio << endl;
	oblig.QuickSort(&listaQSort, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por QuickSort:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (mejor caso)\n", tiempo);

    //Peor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por QuickSort: " << clicksInicio << endl;
	oblig.QuickSort(&listaQSort, DESC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por QuickSort:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (peor caso)\n", tiempo);
//====================================================================================================================

    // Medicion del algoritmo de ordenacion MergeSort
    //Caso general
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por MergeSort: " << clicksInicio << endl;
	oblig.MergeSort(&listaMSort, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por MergeSort:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("MergeSort ha tardado: %f segundos (caso general)\n", tiempo);

    //Mejor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por MergeSort: " << clicksInicio << endl;
	oblig.MergeSort(&listaMSort, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por MergeSort:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (mejor caso)\n", tiempo);

    //Peor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por MergeSort: " << clicksInicio << endl;
	oblig.MergeSort(&listaMSort, DESC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por MergeSort:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (peor caso)\n", tiempo);
//====================================================================================================================

    // Medicion del algoritmo de ordenacion por Rango
    //Caso general
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Rango: " << clicksInicio << endl;
	oblig.Rango(&listaRango, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Rango:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Rango ha tardado: %f segundos (caso general)\n", tiempo);

    //Mejor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Rango: " << clicksInicio << endl;
	oblig.Rango(&listaRango, ASC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Rango:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (mejor caso)\n", tiempo);

    //Peor caso
    clicksInicio = clock();
    cout << "Clocks de inicio con ordenacion por Rango: " << clicksInicio << endl;
	oblig.Rango(&listaRango, DESC);
    clicksFin = clock();
    cout << "Clocks de fin con ordenacion por Rango:    " << clicksFin << endl;

    tiempo = ((float)clicksFin - clicksInicio) / CLOCKS_PER_SEC;
    printf("Insercion ha tardado: %f segundos (peor caso)\n", tiempo);

	// ListaContigua lista;
	// // Orden ordenar;

	// lista.insertarAlFinal(1);
	// lista.insertarAlFinal(5);
	// lista.insertarAlFinal(3);
	// lista.insertarAlFinal(8);

	// for (int i = 0; i < lista.getN(); i++)
	// {
	// 	printf("%d ", lista.getValor(i));
	// }
	// printf("\n");

	// // insercion(&lista, ASC);

	// for (int i = 0; i < lista.getN(); i++)
	// {
	// 	printf("%d ", lista.getValor(i));
	// }
	// printf("\n");

	return 0;
}
