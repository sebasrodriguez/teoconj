#include "Conjunto.h"

void ConjuntoCreate(Conjunto &c){
    ArbolIntCreate(c);
}

void ConjuntoAddValue(Conjunto &c, int valor){
    ArbolIntAdd(c, valor);
}
