#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include<stdio.h>

const int MAX = 80;
const char EOS = '\0';
const char EOL = '\n';
const char BSP = ' ';
const char TAB = '\t';
typedef char * string;

//Crea un string vacío
void strcrear(string &s);

//Librera la memoria ocupada por el string
void strdestruir(string &s);

//Devuelve el largo de un string
int strlar(string s);

//Copia el segundo string en el primero
void strcop(string &s, string t);

//Lee un string desde teclado
void scan(string &s);

//Concatena el segundo string en el primero
void strcon(string &s, string t);

//Intercambia el contenido de los strings
void strswp(string &s, string &t);

//Despliega un string en pantalla
void print(string s);

//Pasa a minusculas los caracteres del string
void strtolower(string &s);

//Compara alfabèticamente dos string
bool strmen(string s, string t);

//Compara si son iguales
bool streq(string s, string t);


#endif // STRING_H_INCLUDED
