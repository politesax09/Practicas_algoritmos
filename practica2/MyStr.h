
// #ifndef MYSTR_H
// #define MYSTR_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

//Definicion de NULL
#define NULL nullptr

//Longitud de cadena por defecto
#define DEF 0

//endl para cout
#define endl '\n'

class MyStr {
	private:
		char * string;			// Array que almacena la cadena de caracteres
		unsigned int N;			// Capacidad
	public:
		// Constructor por defecto
		MyStr();						//BIEN

		// Constructor por valor
		// Parametros:		- original: cadena a guardar en la clase string
		MyStr(const char* original);						//BIEN

		~MyStr();	// ERROR --- munmap_chunk(): invalid pointer

		//Actualiza la capacidad gestionando la memoria necesaria
		//Parametros:	other_len (longitud de la cadena a introducir o concatenar, si no hay es DEF(0))
		void actualizarN(int other_len);				//BIEN

		//Devuelve la cadena
		char* getString() const;						//BIEN

		//Modifica la cadena con la introducida por parametro
		void setString(char *other_string);				

		//Modifica un elemento de la cadena
		//Parametros:	pos (posicion a modificar), elemento (nuevo elemento)
		void setStringPos(int pos, char elemento);				//BIEN

		//Borra los 4 primeros caracteres de la cadena
		void borrar4();					//BIEN

		//Imprimer la cadena por pantalla
		void imprimir();					//BIEN


		unsigned int Length() const;	//Tamano del Array						//BIEN
		unsigned int Capacity()const;	//Capacidad actual de memoria				//BIEN
		int Replace(char find, char replaceBy);	//Busca los caracteres iguales que find, los sustituye por replaceBy y devuelve el numero de intervenciones				//BIEN
		int Compare(const MyStr &other) const;	//Devuelve 0 si son iguales, 1 si es mayor que other y -1 si other es menor				//BIEN
		int Remove(char find);	//Borra los caracteres iguales a find y devuelve el numero de los borrados					//BIEN
		MyStr Right(unsigned int num);	//Devuelve la subcadena de num caracteres desde el final. el \0 no cuenta
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
		MyStr Introduce(const MyStr& other, unsigned int index); //Concatena la cadena introduciendola entre medias, empezando en la posición indicada por index.


		inline void operator=(const MyStr &other);	//Evita errores y simplifica al igualar dos objetos

		inline bool operator==(const MyStr& other); //Usar la función Compare.
		inline bool operator!=(const MyStr& other); //Puede ser el opuesto a ==
		inline bool operator< (const MyStr& other); //Usar la función Compare (del siguiente apartado)
		inline bool operator> (const MyStr& other); //Usar la función Compare (del siguiente apartado)
		inline bool operator<=(const MyStr& other); //Puede ser el opuesto a >
		inline bool operator>=(const MyStr& other); //Puede ser el opuesto a <

		inline char& operator [] (int index) const; //Devuelve el caracter en el elemento “index”
		inline MyStr operator + (const MyStr & other); //Concatena una cadena a otra.

};

// #endif