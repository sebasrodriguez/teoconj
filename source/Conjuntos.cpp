#include "Conjuntos.h"

void ConjuntosCreate(Conjuntos &c){
    ListaABBCreate(c.conjuntos);
    c.tope = 0;
}

void ConjuntosAdd(Conjuntos &c, Conjunto conjunto){
    ListaABBInsBack(c.conjuntos, conjunto);
    c.tope ++;
}

bool ConjuntosHasId(Conjuntos c, int id){
    return id <= c.tope;
}

void ConjuntosAddValueToConj(Conjuntos &c, int id, int valor, Conjunto &conjunto){
    ListaABB aux;
    aux = c.conjuntos;
    bool found = false;
    int i = 1;
    while(!found){
        if(i == id){
            ConjuntoAddValue(aux->info, valor);
            conjunto = aux->info;
            found = true;
        }
        aux = aux->sig;
        i ++;
    }
}

void ConjuntosGetById(Conjuntos &c, int id, Conjunto &conjunto){
    ListaABB aux;
    aux = c.conjuntos;
    bool found = false;
    int i = 1;
    while(!found){
        if(i == id){
            conjunto = aux->info;
            found = true;
        }
        aux = aux->sig;
        i ++;
    }
}

int ConjuntosGetNextId(Conjuntos c){
    return c.tope + 1;
}

void ConjuntosShow(Conjuntos c){
    int i = 1;
    while (c.conjuntos != NULL) {
        printf("c%d = ", i); ConjuntoShow(c.conjuntos->info); printf("\n");
        c.conjuntos = c.conjuntos->sig;
        i++;
    }
}

void ConjuntosAddAndShow(Conjuntos &conjuntos, Conjunto conjunto)
{
    int newid = ConjuntosGetNextId(conjuntos);
    ConjuntosAdd(conjuntos, conjunto);
    printf(MESSAGE_PRE_C, newid);
    ConjuntoShow(conjunto);
}

int ConjuntosCount(Conjuntos c){
    return c.tope;
}
