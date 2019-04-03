#include "MyStr.h"
#include <iostream>
#include <cstring>

MyStr::MyStr(){
	this->string = NULL;
	N=-1;
}
MyStr::MyStr(const char* original){
	N = (unsigned int)((strlen(original) + 1) * 2);	//Capacidad para el doble de la longitud de la cadena
	(this->string) = (char * ) malloc(N); // alocar la memoria necesaria
	strcpy((this->string),original);//copiar el string
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
			changes++;
		}
	}
	return changes;

}

MyStr::~MyStr(){
	free((this->string));
}