#ifndef CONJUNTOS_H_INCLUDED
#define CONJUNTOS_H_INCLUDED

#include <stdio.h>
#include "lib/listaABB.h"
#include "Params.h"
#include "Conjunto.h"
#include "common.h"

typedef struct{
    ListaABB conjuntos;
    int tope;
}Conjuntos;

void ConjuntosCreate(Conjuntos &c);

void ConjuntosAdd(Conjuntos &c, Conjunto conjunto);

bool ConjuntosHasId(Conjuntos c, int id);

void ConjuntosAddValueToConj(Conjuntos &c, int id, Params params, Conjunto &conjunto);

void ConjuntosGetById(Conjuntos &c, int id, Conjunto &conjunto);

int ConjuntosGetNextId(Conjuntos c);

void ConjuntosShow(Conjuntos c);

void ConjuntosAddAndShow(Conjuntos &conjuntos, Conjunto conjunto);

int ConjuntosCount(Conjuntos c);

void ConjuntosRemoveValueFromConj(Conjuntos &c, int id, Params params, Conjunto &c);

#endif
