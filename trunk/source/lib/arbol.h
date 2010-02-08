#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct NodoA{
        int info;
        NodoA * hizq;
        NodoA * hder;
    }Nodo;

typedef Nodo * Arbol;

void Crear(Arbol &a);

Arbol Cons(int info, Arbol hizq, Arbol hder);

void Preorden (Arbol a);

void Orden (Arbol a);

void Posorden (Arbol a);

int ContarNodos (Arbol a);

#endif // ARBOL_H_INCLUDED
