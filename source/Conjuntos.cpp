#include "Conjuntos.h"

void ConjuntosCreate(Conjuntos &c){
    ListaABBCreate(c.conjuntos);
    c.tope = 0;
}

void ConjuntosAdd(Conjuntos &c, ArbolInt conjunto){
    ListaABBInsBack(c.conjuntos, conjunto);
    c.tope ++;
}

bool ConjuntosHasId(Conjuntos c, int id){
    return id < c.tope + 1;
}

void ConjuntosGetById(Conjuntos &c, int id, ArbolInt &conjunto){
    ListaABB aux;
    aux = c.conjuntos;
    bool found = false;
    int i = 1;
    while(!found && aux != NULL){
        if(i == id){
            conjunto = aux->info;
            found = true;
        }
        aux = aux->sig;
        i ++;
    }
}
