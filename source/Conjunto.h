#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "lib/string.h"
#include "lib/arbolint.h"

typedef ArbolInt Conjunto;

void ConjuntoCreate(Conjunto &c);

void ConjuntoAddValue(Conjunto &c, int valor);

void ConjuntoShow(Conjunto c);

void ConjuntoOrdenBuffer(Conjunto c, string &buffer, string &result);

bool ConjuntoPertenece(Conjunto c, int valor);

int ConjuntoCount(Conjunto c);

void ConjuntoRemoveValue(Conjunto &c, int valor);

void ConjuntoUnion(Conjunto c1, Conjunto &c2);

void ConjuntoUnion(Conjunto c1, Conjunto c2, Conjunto &c3);

void ConjuntoDifference(Conjunto c1, Conjunto c2, Conjunto &diff);

void ConjuntoCopy(Conjunto &c1, Conjunto c2);

#endif