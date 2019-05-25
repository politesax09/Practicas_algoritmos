#include "MyStr.h"


MyStr::MyStr(){
	this->string = NULL;
	N = 0;
}

MyStr::MyStr(const char* original){
	N = (unsigned int)((strlen(original) + 1) * 2);	//Capacidad para el doble de la longitud de la cadena
	(this->string) = (char * ) malloc(N); // alocar la memoria necesaria
	strcpy((this->string), original);//copiar el string
}

/*METODOS AUXILIARES*/
void MyStr::actualizarN(int other_len){
	if (other_len == 0)		//Si no hay segunda cadena other_len = 0, la capacidad se reduce o se mantiene
		while (Length() + 1 <= N / 4)		//Comprueba si hay que reducir la capacidad en funcion de la longitud de la cadena
		{
			N = N / 2;
			string = (char*)realloc(string, N);
		}

	else		//Cuando hay segunda cadena, la capacidad se queda igual o se incrementa
		while ((Length() + 1) + (other_len + 1) >= N)		//Comprueba si hay que aumentar la capacidad en funcion de la logitud de la cadena
		{
			N = N * 2;
			string = (char*)realloc(string, N);
		}
}

char* MyStr::getString() const {
	return string;
}

void MyStr::setString(char *other_string){
	string = (char*)realloc(string, 1);	//Borra la string antigua

	actualizarN(strlen(other_string));

	string = other_string;
}

void MyStr::setStringPos(int pos, char elemento){
	string[pos] = elemento;
}

void MyStr::borrar4(){
	int i;
	for (i = 4; string[i] != '\0'; ++i)
		string[i - 4] = string[i];
	string[i - 4] = '\0';
	actualizarN(DEF);
}

void MyStr::imprimir(){
	puts(string);
}

/*===============================================================================================================================*/

/*METODOS PROPUESTOS*/
unsigned int MyStr::Length() const {
	return (unsigned int)strlen(string);
}

unsigned int MyStr::Capacity()const{
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

int MyStr::Compare(const MyStr &other) const{
	if (strcmp(other.string, string) < 0)
		return -1;
	else if (strcmp(other.string, string) > 0)
		return 1;
	return 0;
}

MyStr MyStr::Right(unsigned int num){
	MyStr salida;
	int pos = Length() - num;	//Situa indice al principio de la subcadena a devolver
	
	for (; string[pos] != '\0'; ++pos)
		salida.string[pos] = string[pos];

	return salida;
}

MyStr MyStr::Left(unsigned int num){
	MyStr salida(string);
	int pos = 0;

	for (int pos = 0; pos <= (int)num; pos++)
		salida.string[pos] = string[pos];
	
	return salida;
}

MyStr MyStr::Substring(unsigned int initialIndex, unsigned int finalIndex){
	MyStr salida(string);
	int pos = 0, i = 0;

	for (i = (int)initialIndex; i <= (int)finalIndex; ++i, pos++)
		salida.string[i] = string[pos];
	salida.setStringPos(i, '\0');

	salida.actualizarN(DEF);

	return salida;
}

int MyStr::Remove(char find){
	int changes = 0;

	for (unsigned int i = 0; string[i] != '\0'; i++)
	{
		if (find == string[i])
		{
			for (unsigned int j = i; j < Length() + 1; j++)	//Condicion en funcion de length en vez de '\0' para poderlo mover tambien
				string[j] = string[j + 1];
			//El \0 se copia a la posicion anterior, el segundo \0 se desprecia
			changes++;
		}
	}
	return changes;
}

int MyStr::TrimRight(){
	int i = 0, changes = 0;		//changes es igual al numero de espacios

	for (; string[i] != ' '; i++)

	changes = Length() - i;
	
	string[i] = '\0';	//Mueve el \0 para recortar los espacios

	actualizarN(DEF);

	return changes;
}

int MyStr::TrimLeft(){
	int i = 0, j = 0, changes = 0;	//changes es el numero de espacios borrados
	MyStr salida(string);

	for (; string[i] == ' '; i++)	//Localiza donde deja de haber espacios

	changes = i;

	for (; string[i] != '\0'; i++, j++)
		string[j] = string[i];

	actualizarN(DEF);

	return changes;
}

int MyStr::Trim(){
	int changes = 0;

	changes = TrimLeft();
	changes = changes + TrimRight();

	actualizarN(DEF);

	return changes;
}

int MyStr::ToUpper(){
	int changes = 0, mayus = 0;

	for (int i = 0; string[i] >= 65 && string[i] <= 90; ++i)
	{
		if (string[i] >= 65 && string[i] <= 90)
			mayus++;
		toupper(string[i]);
	}

	changes = (int)Length() - mayus;

	return changes;
}

int MyStr::ToLower(){
	int changes = 0, minus = 0;

	for (int i = 0; string[i] >= 'a' && string[i] <= 'z'; ++i)
	{
		if (string[i] >= 'a' && string[i] <= 'z')
			minus++;
		tolower(string[i]);
	}

	changes = (int)Length() - minus;

	return changes;
}

bool MyStr::StartsWith(const MyStr &other){
	for (int i = 0; other.string[i] != '\0'; ++i)
		if (other.string[i] != string[i])
			return false;

	return true;
}

bool MyStr::EndsWith(const MyStr &other){
	for (int i = (int)Length(); i >= (int)other.Length(); --i)
		if (other.string[i] != string[i])
			return false;

	return true;
}

MyStr MyStr::Concatenate(const MyStr &other){
	MyStr salida(string);
	
	salida = salida + other;

	return salida;
}

MyStr MyStr::Introduce(const MyStr &other, unsigned int index) {

	MyStr salida(string);

	salida = Substring(0, index) + other;
	salida = salida + Substring(index + 1, other.Length());

	return salida;
}

MyStr::~MyStr(){
	free((this->string));
}

/*===========================================================================================================================================================*/

/*OPERADOR AUXILIAR*/
inline void MyStr::operator = (const MyStr &other){
	strcpy(string, other.getString());
	N = other.Capacity();
}

/*OPERADORES PROPUESTOS*/
inline bool MyStr::operator == (const MyStr &other){
	if (!Compare(other))
		return true;
	return false;
}

inline bool MyStr::operator != (const MyStr &other){
	if (!(*this == other))
		return true;
	return false;
}

inline bool MyStr::operator < (const MyStr &other){
	if (Compare(other) < 0)
		return true;
	return false;
}

inline bool MyStr::operator > (const MyStr &other){
	if (Compare(other) > 0)
		return true;
	return false;
}

inline bool MyStr::operator <= (const MyStr &other){
	if (Compare(other) <= 0)
		return true;
	return false;
}

inline bool MyStr::operator >= (const MyStr &other){
	if (Compare(other) >= 0)
		return true;
	return false;
}

inline char& MyStr::operator [] (int index) const{
	return string[index];
}

inline MyStr MyStr::operator + (const MyStr &other){
	MyStr salida(string);
	int i,j;

	salida.actualizarN(other.Length());
	for (i = salida.Length(), j = 0; other[j] != '\0'; ++i, ++j)
		salida.setStringPos(i, other[j]);
	salida.setStringPos(i, '\0');

	return salida;
}