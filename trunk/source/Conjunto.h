#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED

typedef struct nodoC{
        int info;
        nodoC * hizq;
        nodoC * hder;
} NodoConjunto;

typedef NodoConjunto * Conjunto;

#endif
