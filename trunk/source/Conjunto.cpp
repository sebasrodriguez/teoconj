#include "Conjunto.h"

void ConjuntoCreate(Conjunto &c){
    ArbolIntCreate(c);
}

void ConjuntoAddValue(Conjunto &c, int valor){
    ArbolIntAdd(c, valor);
}

void ConjuntoShow(Conjunto c){
    string buffer; strcrear(buffer);
    string result; strcrear(result);
    ConjuntoOrdenBuffer(c, buffer, result);
    result += 2;
    printf("{");print(result);printf("}");
}

void ConjuntoOrdenBuffer(Conjunto c, string &buffer, string &result){
    if (c != NULL){
        ConjuntoOrdenBuffer(c->hizq, buffer, result);
        strcon(result, ", ");
        strcon(result, itoa(c->info, buffer, 10));
        ConjuntoOrdenBuffer(c->hder, buffer, result);
    }
}

bool ConjuntoPertenece(Conjunto c, int valor){
    return ArbolIntPertenece(c, valor);
}
