#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED

#include <stdio.h>
#include "lib/listaABB.h"
#include "Conjunto.h"

typedef struct{
    ListaABB conjuntos;
    int tope;
}Conjuntos;

void ConjuntosCreate(Conjuntos &c);

void ConjuntosAdd(Conjuntos &c, Conjunto conjunto);

bool ConjuntosHasId(Conjuntos c, int id);

void ConjuntosAddValueToConj(Conjuntos &c, int id, int valor, Conjunto &conjunto);

void ConjuntosGetById(Conjuntos &c, int id, Conjunto &conjunto);

int ConjuntosGetNextId(Conjuntos c);

void ConjuntosShow(Conjuntos c);

void ConjuntoIntersection(Conjunto c1, Conjunto c2, Conjunto &inter);

#endif
