#include "listastring.h"

void ListaStringCreate(ListaABB &lista){
    lista = NULL;
}

bool ListaStringEmpty(ListaString lista){
    return (lista == NULL);
}

void ListaStringInsFront(ListaString &lista, string valor){
    ListaString aux = new NodoListaString;
    strcop(aux->info, valor);
    aux->sig = lista;
    lista = aux;
}

void ListaStringFirst(ListaString lista, string first){
    strcop(first, lista->info);
}

void ListaStringResto(ListaString &lista){
    ListaString aux = lista;
    lista = lista->sig;
    delete(aux);
}

int ListaStringCount(ListaString lista){
    int largo = 0;
    while (lista->sig != NULL)    {
        lista = lista->sig;
        largo++;
    }
    if (largo > 0)    {
        largo++;
    }
    return largo;
}

void ListaStringShow(ListaString lista){
    int i = 0;
    while (lista != NULL)    {
        print(lista->info);
        lista = lista->sig;
        i++;
    }
}
