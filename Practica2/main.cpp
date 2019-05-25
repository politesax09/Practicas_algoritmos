#include <iostream>
#include "impresionListasEnlazadas.h"

// using namespace std;

void pruebas_simple(){
	MyStr cad1 = "Kha\'zix", cad2 = "son las", cad3 = "Thresh", resultado;
	MyStr cadena(cad2.getString()), temp1 = "ola q Ashe", temp2 = "Ketchup";
	int resul_comp;

	cadena.imprimir();
	// resultado.imprimir();	//violacion de segmento (creo q porq string apunta a NULL)
	// resultado.actualizarN(cadena.Length() + temp1.Length());

	cadena = cadena.Concatenate(temp1);
	cadena.imprimir();
//===============================================================================================

	cadena = cadena.Substring(11, cadena.Length() + 1);
	cadena.imprimir();

	cadena = cadena.Substring(0, cadena.Length() - 7);
	cadena.imprimir();

	cadena.Concatenate(temp2);
	cadena.imprimir();

	cadena.ToUpper();
	cadena.imprimir();

	cad1.imprimir();
	cad1.ToLower();
	cad1.imprimir();

	cad1.Concatenate(cad2);
	cad1.Concatenate(cad3);
	cad1.imprimir();

	resul_comp = cad1.Compare(cadena);
	if (resul_comp == 0)
		printf("Cadenas iguales.\n");
	else if (resul_comp < 0)
		printf("Segunda cadena mayor que la Primera: %s > %s\n", cad1, cadena);
	else printf("Primera cadena mayor que la Segunda: %s > %s\n", cadena, cad1);
}

void pruebas_enlazada(){
	ListaEnlazada l1;
	MyStr cad1 = "  DOWN  DOWN  END_ ", cad2 = " RULETA    MOLA  MAZO EHHH  ", cad3 = " NOOO  CONFUNDAS  ESTATAREA", cad4 = " PEPE  PAPAPIPIPOPO PUPU", cad5 = "       UP__  UP__ UP__";
    MyStr fin = "END";

	imprimirListaEnlazada(&l1);
	l1.insertar(0, cad1);
	l1.insertar(1, cad2);
    l1.insertar(2, cad3);
	l1.insertar(3, cad4);
    l1.insertar(4, cad5);
    l1.insertar(5, fin);
	imprimirListaEnlazada(&l1);

	for (int i = 0; (l1.getValor(i).Substring(0, 3)) != fin;)		//Mientras los cuatro primeros caracteres sean distintos de END
	{
		int flag;

		l1.getValor(0).Trim();

		if (l1.getValor(i).Substring(0, 1) == "UP")
			flag = 1;
		else if (l1.getValor(i).Substring(0, 3) == "DOWN")
			flag = 0;

		l1.getValor(i).borrar4();
		l1.getValor(i).imprimir();

		if (flag == 1)
			i--;
		else
			i++;
	}
}


int main(){
	//pruebas_simple();

	pruebas_enlazada();

	return 0;
}
