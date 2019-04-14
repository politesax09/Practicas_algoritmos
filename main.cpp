#include <iostream>
#include "impresionListasEnlazadas.h"

// using namespace std;

int main(){
	/*PRUEBAS SIMPLES*/
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

	/*PRUEBAS LISTA DOBLEMENTE ENLAZADA*/
	ListaEnlazada l1;

	// l1.insertar(0, "  DOWN  DOWN  END_ ");
	// l1.insertar(1, " RULETA    MOLA  MAZO EHHH  ");
	// l1.insertar(2, " NOOO  CONFUNDAS  ESTATAREA");
	// l1.insertar(3, " PEPE  PAPAPIPIPOPO PUPU");
	// l1.insertar(4, "       UP__  UP__ UP__")

	return 0;
}
