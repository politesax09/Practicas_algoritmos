#include <iostream>
#include "MyStr.h"

int main(){
	MyStr cad1 = "Kha\'zix", cad2 = "son las", cad3 = "Thresh";
	MyStr cadena(cad2.getString()), temp1 = "ola q Ashe", temp2 = "Ketchup"
	int resul_comp;

	cadena.imprimir();
	
	cadena.Concatenate(temp1);
	cadena.imprimir();

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
		cout << "Cadenas iguales." << endl;
	else if (resul_comp < 0)
		cout << "Segunda cadena mayor que la Primera: " << cad1 << ">" << cadena << endl;
	else cout << "Primera cadena mayor que la Segunda: " << cadena << ">" << cad1 << endl;

	return 0;
}
