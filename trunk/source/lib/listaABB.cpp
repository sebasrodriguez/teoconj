#include "listaABB.h"

void ListaABBCreate(ListaABB &lista){
    lista = NULL;
}

bool ListaABBEmpty(ListaABB lista){
    return (lista == NULL);
}

void ListaABBInsFront(ListaABB &lista, ArbolInt valor){
    ListaABB aux = new NodoListaABB;
    aux->info = valor;
    aux->sig = lista;
    lista = aux;
}

void ListaABBFirst(ListaABB lista, ArbolInt &valor){
    valor = lista->info;
}

void ListaABBResto(ListaABB &lista){
    ListaABB aux = lista;
    lista = lista->sig;
    delete(aux);
}

int ListaABBCount(ListaABB lista){
    int largo = 0;
    while (lista != NULL)    {
        lista = lista->sig;
        largo++;
    }
    return largo;
}

void ListaABBShow(ListaABB lista){
    int i = 0;
    while (lista != NULL)    {
        ArbolIntOrden (lista->info);
        lista = lista->sig;
        i++;
    }
}

void ListaABBInsBack(ListaABB &lista, ArbolInt valor){
    if (lista == NULL){
        ListaABBInsFront(lista, valor);
    }else if (lista->sig == NULL){
        ListaABBInsBack(lista->sig, valor);
    }else{
        ListaABBInsBack(lista->sig, valor);
    }
}

/*
int SumaPares(Lista lista){
    int i = 0;
    int total = 0;
    while (lista != NULL)    {
        if (i % 2 == 0)        {
            total += lista->info;
        }
        lista = lista->sig;
        i++;
    }
    return total;
}

bool Pertenece(Lista lista, int valor){
    bool pertenece = false;
    while (!pertenece && lista != NULL)    {
        if (lista->info == valor)        {
            pertenece = true;
        }
        lista = lista->sig;
    }
    return pertenece;
}

Lista Interseccion(Lista lista1, Lista lista2){
    Lista interseccion;
    Lista aux;
    bool existe;
    Crear(interseccion);
    Crear(aux);

    aux = lista2;

    while (lista1 != NULL)    {
        existe = false;
        lista2 = aux;
        while (lista2 != NULL && !existe)        {
            if (lista1->info == lista2->info)            {
                existe = true;
                InsFront(interseccion, lista1->info);
            }
            lista2 = lista2->sig;
        }
        lista1 = lista1->sig;
    }

    return interseccion;
}

void Sustituir(Lista &lista, int a, int b){
    Lista aux = lista;
    while (aux != NULL)    {
        if (aux->info == a)        {
            aux->info = b;
        }
        aux = aux->sig;
    }
}

//Elimina todas las ocurrencias de valor
void Borrar(Lista &lista, int valor)
{
    Lista aux, aux2;
    aux = lista;
    bool iterar = true;
    if (lista->info == valor)
    {
        aux2 = lista;
        aux = lista->sig;
        lista = lista->sig;

        delete(aux2);
        aux2 = NULL;
    }
    while (lista != NULL)
    {
        iterar = true;
        if (lista->sig != NULL && lista->sig->info == valor)
        {
            aux2 = lista->sig;
            lista->sig = lista->sig->sig;
            if (lista->sig != NULL && lista->sig->info == valor)
            {
                iterar = false;
            }
            delete(aux2);
            aux2 = NULL;
        }
        if (iterar)
        {
            lista = lista->sig;
        }
    }
    lista = aux;
}

Lista Tomar(Lista lista, int n)
{
    int i = 1;
    Lista tomar;
    Crear(tomar);
    while (lista != NULL)
    {
        if (i <= n)
        {
            InsBack(tomar, lista->info);
        }
        i++;
        lista = lista->sig;
    }
    return tomar;
}

bool Iguales(Lista lista1, Lista lista2)
{
    bool iguales = true;
    while (lista1 != NULL && lista2 != NULL && iguales)
    {
        if (lista1->info != lista2->info)
        {
            iguales = false;
        }
        lista1 = lista1->sig;
        lista2 = lista2->sig;
    }
    if ((lista1 != NULL && lista2 == NULL) || (lista1 == NULL && lista2 != NULL))
    {
        iguales = false;
    }

    return iguales;
}

int Minimo(Lista lista)
{
    if (lista->sig == NULL)
    {
        return lista->info;
    }
    else
    {
        int valor = Minimo(lista->sig);
        if (valor <= lista->info)
        {
            return valor;
        }
        else
        {
            return lista->info;
        }
    }
}

Nodo N_Esimo(Lista lista, int i)
{
    if (i == 1)
    {
        return *lista;
    }
    else
    {
        return N_Esimo(lista->sig, i - 1);
    }
}

bool Pertenece2(Lista lista, int valor)
{
    if (lista->sig == NULL && lista->info != valor)
    {
        return false;
    }
    else if (lista->info == valor)
    {
        return true;
    }
    else
    {
        return Pertenece2(lista->sig, valor);
    }
}

void InsBack(Lista &lista, int valor)
{
    if (lista == NULL)
    {
        InsFront(lista, valor);
    }
    else if (lista->sig == NULL)
    {
        InsFront(lista->sig, valor);
    }
    else
    {
        InsBack(lista->sig, valor);
    }
}

void Borrar2(Lista &lista, int valor)
{
    Lista aux;
    if (lista != NULL)
    {
        if (lista->info == valor)
        {
            aux = lista;
            lista = lista->sig;
            delete(aux);
            aux = NULL;
            Borrar2(lista, valor);
        }
        else
        {
            Borrar2(lista->sig, valor);
        }
    }
}

Lista Tomar2(Lista lista, int n)
{
    if (n == 0)
    {
        return NULL;
    }
    else
    {
        Lista aux = Tomar2(lista->sig, n-1);
        InsFront(aux, lista->info);
        return aux;
    }
}

bool Iguales2(Lista lista1, Lista lista2)
{
    if (lista1->sig != NULL && lista2->sig == NULL)
    {
        return false;
    }
    else if (lista1->sig == NULL && lista2->sig != NULL)
    {
        return false;
    }
    else if (lista1->sig == NULL && lista2->sig == NULL)
    {
        if (lista1->info == lista2->info)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (lista1->info == lista2->info)
        {
            return Iguales2(lista1->sig, lista2->sig);
        }
        else
        {
            return false;
        }
    }
}

void Eliminar(Lista &lista)
{
    Lista aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->sig;
        delete(aux);
    }
    lista = NULL;
}
*/


