#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED

#include <stdio.h>
#include "string.h"
typedef struct NListaString{
        string info;
        NListaString * sig;
}NodoListaString;

typedef NodoListaString * ListaString;

void ListaStringCreate(ListaString &lista);

bool ListaStringEmpty(ListaString lista);

void ListaStringInsFront(ListaString &lista, string valor);

int ListaStringCount(ListaString lista);

void ListaStringFirst(ListaString lista, string first);

void ListaStringResto(ListaString &lista);

void ListaStringShow(ListaString lista);

void ListaStringDelete(ListaString &lista);

#endif
