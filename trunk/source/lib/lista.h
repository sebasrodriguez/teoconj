#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>

typedef struct nodoL{
        int info;
        nodoL * sig;
}Nodo;

typedef Nodo * Lista;

void Crear(Lista &lista);

bool EsVacia(Lista lista);

void InsFront(Lista &lista, int valor);

int Largo(Lista lista);

int Primero(Lista lista);

void Resto(Lista &lista);

void Desplegar(Lista lista);

void Eliminar(Lista &lista);

//Iterativas

int SumaPares(Lista lista);

bool Pertenece(Lista lista, int valor);

Lista Interseccion(Lista lista1, Lista lista2);

void Sustituir(Lista &lista, int a, int b);

void Borrar(Lista &lista, int valor);

Lista Tomar(Lista lista, int n);

bool Iguales(Lista lista1, Lista lista2);

//Recursivas

int Minimo(Lista lista);

Nodo N_Esimo(Lista lista, int i);

bool Pertenece2(Lista lista, int valor);

void InsBack(Lista &lista, int valor);

void Borrar2(Lista &lista, int valor);

Lista Tomar2(Lista lista, int n);

bool Iguales2(Lista lista1, Lista lista2);


#endif // LISTA_H_INCLUDED
