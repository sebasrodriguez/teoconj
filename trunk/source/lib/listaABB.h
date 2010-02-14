#ifndef LISTAABB_H_INCLUDED
#define LISTAABB_H_INCLUDED

#include <stdio.h>

typedef struct NListaABB{
        int info;
        NListaABB * sig;
}NodoListaABB;

typedef NodoListaABB * ListaABB;

void ListaABBCreate(ListaABB &lista);

bool ListaABBEmpty(ListaABB lista);

void ListaABBInsFront(ListaABB &lista, int valor);

int ListaABBCount(ListaABB lista);

int ListaABBFirst(ListaABB lista);

void ListaABBResto(ListaABB &lista);

void ListaABBShow(ListaABB lista);

void ListaABBDelete(ListaABB &lista);

//Iterativas
/*
int SumaPares(ListaABB lista);

bool Pertenece(ListaABB lista, int valor);

ListaABB Interseccion(ListaABB lista1, ListaABB lista2);

void Sustituir(ListaABB &lista, int a, int b);

void Borrar(ListaABB &lista, int valor);

ListaABB Tomar(ListaABB lista, int n);

bool Iguales(ListaABB lista1, ListaABB lista2);

//Recursivas

int Minimo(Lista lista);

Nodo N_Esimo(Lista lista, int i);

bool Pertenece2(Lista lista, int valor);

void InsBack(Lista &lista, int valor);

void Borrar2(Lista &lista, int valor);

Lista Tomar2(Lista lista, int n);

bool Iguales2(Lista lista1, Lista lista2);

*/
#endif // LISTAABB_H_INCLUDED
