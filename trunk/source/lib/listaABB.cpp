#include "listaABB.h"

void ListaABBCreate(ListaABB &lista)
{
    lista = NULL;
}

bool ListaABBEmpty(ListaABB lista)
{
    return (lista == NULL);
}

void ListaABBInsFront(ListaABB &lista, ArbolInt valor)
{
    ListaABB aux = new NodoListaABB;
    aux->info = valor;
    aux->sig = lista;
    lista = aux;
}

void ListaABBFirst(ListaABB lista, ArbolInt &valor)
{
    valor = lista->info;
}

void ListaABBResto(ListaABB &lista)
{
    ListaABB aux = lista;
    lista = lista->sig;
    delete(aux);
}

int ListaABBCount(ListaABB lista)
{
    int largo = 0;
    while (lista != NULL)
    {
        lista = lista->sig;
        largo++;
    }
    return largo;
}

void ListaABBShow(ListaABB lista)
{
    int i = 0;
    while (lista != NULL)
    {
        ArbolIntOrden (lista->info);
        lista = lista->sig;
        i++;
    }
}

void ListaABBInsBack(ListaABB &lista, ArbolInt valor)
{
    if (lista == NULL)
    {
        ListaABBInsFront(lista, valor);
    }
    else if (lista->sig == NULL)
    {
        ListaABBInsBack(lista->sig, valor);
    }
    else
    {
        ListaABBInsBack(lista->sig, valor);
    }
}
