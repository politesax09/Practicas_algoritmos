#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

//Definicion de NULL
#define NULL nullptr

//Longitud de cadena por defecto
#define DEF 0


class MyStr {
	private:
		char * string;
		unsigned int N;
	public:
		MyStr();
		MyStr(const char* original);

		unsigned int getN();
		void setN(unsigned int nuevaN);
		char* getString();
		void setStringPos(int pos, char elemento);

		void actualizarN(int other_len);

		unsigned int Length();	//Tamano del array
		unsigned int Capacity();	//Capacidad actual de memoria
		int Replace(char find, char replaceBy);	//Busca los caracteres find, los sustituye por replaceBy y devuelve el numero de intervenciones
		int Compare(MyStr &other);	//Devuelve 0 si son iguales, 1 si es mayor que other y -1 si other es mayor
		int Remove(char find);	//Borra los caracteres iguales a find y devuelve el numero de los borrados
		MyStr Right(unsigned int num);	//Devuelve la subcadena de num caracteres desde el final
		MyStr Left(unsigned int num);	//Devuelve la subcadena de num caracteres desde el inicio
		MyStr Substring(unsigned int initialIndex, unsigned int finalIndex);	//Devuelve la subacadena de initialIndex a finalIndex

		int TrimRight(); //Elimina los espacios en blanco que haya por la derecha del texto. Devuelve el número de espacios eliminados. *Atender al decremento de la capacidad*
		int TrimLeft(); //Elimina los espacios en blanco que haya por la izquierda del texto. Devuelve el número de espacios eliminados. *Atender al decremento de la capacidad*
		int Trim(); //Elimina los espacios en blanco en ambos lados del texto. Devuelve el número de espacios eliminados. *Atender al decremento de la capacidad*
		int ToUpper(); //Convierte todos los caracteres en letras mayúsculas. Devuelve el número de caracteres que han sido cambiados a mayúsculas. Se permite usar toupper de C.
		int ToLower(); //Convierte todos los caracteres en letras minúsculas. Devuelve el número de caracteres que han sido cambiados a minúsculas. Se permite usar tolower de C.
		bool StartsWith(const MyStr& other); //Devuelve true si la cadena empieza con “other”.
		bool EndsWith(const MyStr& other); //Devuelve true si la cadena termina con “other”.
		MyStr Concatenate(const MyStr& other); //Concatena la cadena añadiendo “other” de manera consecutiva. *Atender al incremento de la capacidad de la primera cadena*

		~MyStr();

};