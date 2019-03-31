#include "MyStr.h"
#include <iostream>
#include <cstring>

MyStr::MyStr(){
	this->string = NULL;
}
MyStr::MyStr(const char* original){
	(this->string) = (char * ) malloc( strlen(original) + 1 ); // alocar la memoria necesaria
	strcpy((this->string),original);//copiar el string
}
MyStr::~MyStr(){
	free((this->string));
}
