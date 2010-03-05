#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdio.h>
#include "string.h"

//imprime una nueva linea
void nl();

//imprime un caracter una cantidad de veces dada
void repeatChar(char c, int cant);

//imprime un tab
void tab();

//imprime una cantidad de tabs
void tabs(int cant);

//imprime una linea de tamaño dado
void line(int tam);

void printInt(int i);

void printFloat(float f);

#endif // UTILS_H_INCLUDED
