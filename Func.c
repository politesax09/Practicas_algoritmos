#include "MyStr.h"

/*Usada por contatenate() e introduce()*/
/*Amplia/Reduce sobre la str1*/
void actualizarN(MyStr &str1, MyStr &str2){	//Funcion independiente para reducir o incrementarla capacidad
	if (str2.string == '\0')
		while (str1.length() + 1 <= N / 4)		//Comprueba si hay que reducir la capacidad en funcion de la longitud de la cadena
			// if (other.length() + 1 <= N / 4)
			N = N / 2;
	else
		while (str1.length() + str2.length() > str1.getN())
			str1.setN(str1.getN() * 2);

}