#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <stdio.h>
#include "lib/arbolint.h"

typedef ArbolInt Conjunto;

void ConjuntoCreate(Conjunto &c);

void ConjuntoAddValue(Conjunto &c, int valor);

#endif
