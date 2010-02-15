#ifndef ARBOLINT_H_INCLUDED
#define ARBOLINT_H_INCLUDED

#include <stdio.h>

typedef struct NArbolInt{
        int info;
        NArbolInt * hizq;
        NArbolInt * hder;
    }NodoArbolInt;

typedef NodoArbolInt * ArbolInt;

void ArbolIntCreate(ArbolInt &a);

ArbolInt ArbolIntCons(int info, ArbolInt hizq, ArbolInt hder);

void ArbolIntPreorden (ArbolInt a);

void ArbolIntOrden (ArbolInt a);

void ArbolIntPosorden (ArbolInt a);

int ArbolIntCount (ArbolInt a);

bool ArbolIntPertenece (ArbolInt a, int valor);

void ArbolIntDelete (ArbolInt a);

void ArbolIntCopy(ArbolInt &a, ArbolInt b);

#endif // ARBOLINT_H_INCLUDED
