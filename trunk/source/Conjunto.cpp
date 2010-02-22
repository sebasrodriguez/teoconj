#include "Conjunto.h"

void ConjuntoCreate(Conjunto &c){
    ArbolIntCreate(c);
    ArbolIntAdd(c, ELEMENTO_VACIO);
}

void ConjuntoAddValue(Conjunto &c, int valor){
    ArbolIntAdd(c, valor);
}

void ConjuntoShow(Conjunto c){
    string buffer; strcrear(buffer);
    string result; strcrear(result);
    if(ConjuntoCount(c) > 0){
        ConjuntoOrdenBuffer(c, buffer, result);
        result += 2;
    }
    printf("{");print(result);printf("}");
}

void ConjuntoOrdenBuffer(Conjunto c, string &buffer, string &result){
    if (c != NULL){
        ConjuntoOrdenBuffer(c->hizq, buffer, result);
        if(c->info != ELEMENTO_VACIO){
            straddchar(result, ','); straddchar(result, BSP);
            strcon(result, itoa(c->info, buffer, 10));
        }
        ConjuntoOrdenBuffer(c->hder, buffer, result);
    }
}

bool ConjuntoPertenece(Conjunto c, int valor){
    return ArbolIntPertenece(c, valor);
}

int ConjuntoCount(Conjunto c){
    return ArbolIntCount(c) - 1;
}

void ConjuntoRemoveValue(Conjunto &c, int valor){
    ArbolIntRemove(c, valor);
}
