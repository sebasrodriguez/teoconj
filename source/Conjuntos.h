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

void ConjuntosAdd(Conjuntos &c, ArbolInt conjunto);

bool ConjuntosHasId(Conjuntos c, int id);

void ConjuntosGetById(Conjuntos &c, int id, ArbolInt &conjunto);

int ConjuntosGetNextId(Conjuntos c);

void ConjuntosShow(Conjuntos c);

#endif
