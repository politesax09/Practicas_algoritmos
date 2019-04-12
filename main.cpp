#include <iostream>
#include "MyStr.h"

int main(){
	MyStr cad1 = "Kha\'zix", cad2 = "son las", cad3 = "Thresh";
	MyStr cadena(cad2.getString()), temp = "ola q Ashe";
	cadena.imprimir();
	
	cadena.Concatenate(temp);
	cadena.imprimir();

	cadena = cadena.Substring(11, cadena.Length() + 1);
	cadena.imprimir();

	cadena = cadena.Substring(0, cadena.Length() - 7);
	cadena.imprimir();


	// resultado.Concatenate()


	return 0;
}
