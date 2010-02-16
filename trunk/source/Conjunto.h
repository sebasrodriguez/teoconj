#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

#include <iostream.h>
#include <stdio.h>
#include "lib/string.h"
#include "lib/arbolint.h"

typedef ArbolInt Conjunto;

void ConjuntoCreate(Conjunto &c);

void ConjuntoAddValue(Conjunto &c, int valor);

void ConjuntoShow(Conjunto c);

void ConjuntoOrdenBuffer(Conjunto c, string &buffer, string &result);

#endif
