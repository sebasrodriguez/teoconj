#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "lib/arbolint.h"
#include "lib/file.h"

typedef ArbolInt Conjunto;

void ConjuntoCreate(Conjunto &c);

void ConjuntoAddValue(Conjunto &c, int valor);

void ConjuntoShow(Conjunto c);

void ConjuntoOrdenBuffer(Conjunto c, string &buffer, string &result);

bool ConjuntoPertenece(Conjunto c, int valor);

int ConjuntoCount(Conjunto c);

void ConjuntoRemoveValue(Conjunto &c, int valor);

void ConjuntoUnion(Conjunto c1, Conjunto c2, Conjunto &uni);

void ConjuntoDifference(Conjunto c1, Conjunto c2, Conjunto &diff);

bool ConjuntoMember(Conjunto c, int valor);

bool ConjuntoEquals(Conjunto c1, Conjunto c2);

void ConjuntoIntersection(Conjunto c1, Conjunto c2, Conjunto &inter);

bool ConjuntoIncluded(Conjunto c1, Conjunto c2);

void ConjuntoCopy(Conjunto &c1, Conjunto c2);

void ConjuntoSave(string name, Conjunto c);

void ConjuntoLoad(string name, Conjunto &c);

#endif
