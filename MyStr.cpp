#include "MyStr.h"
#include <iostream>
#include <cstring>

MyStr::MyStr(){
	this->string = NULL;
	N = -1;
}
MyStr::MyStr(const char* original){
	N = (unsigned int)((strlen(original) + 1) * 2);	//Capacidad para el doble de la longitud de la cadena
	(this->string) = (char * ) malloc(N); // alocar la memoria necesaria
	strcpy((this->string),original);//copiar el string
}

unsigned int MyStr::getN(){
	return N;
}

void MyStr::setN(unsigned int nuevaN){
	N = nuevaN;
}

unsigned int MyStr::Length(){
	return (unsigned int)strlen(string);
}

unsigned int MyStr::Capacity(){
	return N;
}

int MyStr::Replace(char find, char replaceBy){
	int changes = 0;

	for (unsigned int i = 0; i < Length(); ++i)
	{
		if (find == string[i])
		{
			string[i] = replaceBy;
			changes++;
		}
	}

	return changes;
}

int MyStr::Compare(MyStr &other){
	return strcmp(string, other->string);
}

MyStr MyStr::Right(unsigned int num){
	MyStr salida;
	int pos = length() - num;	//Situa indice al principio del tamano de la cadena a devolver
	
	for (; string[pos] != '\0'; ++pos)
		salida.string[pos] = string[pos];

	return salida;
}

MyStr MyStr::Left(unsigned int num){
	MyStr salida;
	int pos = 0;

	for (int pos = 0; pos <= num; pos++)
		salida.string[pos] = string[pos];
	
	return salida;
}

MyStr MyStr::Substring(unsigned int initialIndex, unsigned int finalIndex){
	MyStr salida;

	for (int i = initialIndex; i <= finalIndex; ++i)
		salida.string[pos] = string[pos];

	return salida;
}

int MyStr::Remove(char find){
	int changes = 0;

	for (unsigned int i = 0; string[i] != '\0'; i++)
	{
		if (find == string[i])
		{
			for (unsigned int j = i; j < Length(); j++)	//length en vez de '\0' para poder moverlo tambien
			{
				string[j] = string[j + 1];
			}
			//El \0 se copia a la posicion anterior, el segundo \0 se desprecia
			changes++;
		}
	}
	return changes;
}

int MyStr::TrimRight(){
	int i;
	MyStr salida;
	for (i = 0; string[i] != '\0'; ++i)
	i++;	//Para coreegir la ultima pasada del bucle

	for (; string[i] == ' '; --i)
	i++;	//Para corregir la ultima pasada del bucle
	
	for (int j = 0; j < i; j++)
		salida.string[j] = string[j];
	salida.string[i] = '\0';	//Mueve el \0 para recortar los espacios

	reducirN(salida);

	// N = i;
	// for (int i = 0; i <= N; ++i)
	// {
	// 	salida.string[i] = string[i];
	// }
}

MyStr::~MyStr(){
	free((this->string));
}