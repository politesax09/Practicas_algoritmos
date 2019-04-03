
//Definicion de NULL
#define NULL nullptr


class MyStr {
	private:
		char * string;
		unsigned int N;
	public:
		MyStr();
		MyStr(const char* original);

		unsigned int Length();	//Tamano del array
		unsigned int Capacity();	//Capacidad actual de memoria
		int Replace(char find, char replaceBy);	//Busca los caracteres find, los sustituye por replaceBy y devuelve el numero de intervenciones
		int Compare(MyStr &other);	//Devuelve 0 si son iguales, 1 si es mayor que other y -1 si other es mayor
		int Remove(char find);	//Borra los caracteres iguales a find y devuelve el numero de los borrados
		MyStr Right(unsigned int num);	//Devuelve la subcadena de num caracteres desde el final
		MyStr Left(unsigned int num);	//Devuelve la subcadena de num caracteres desde el inicio
		MyStr Substring(unsigned int initialIndex, unsigned int finalIndex);	//Devuelve la subacadena de initialIndex a finalIndex

		~MyStr();

};