#include <stdio.h>
#include "arbol.h"

void Crear(Arbol &a)
{
    a = NULL;
}

Arbol Cons(int info, Arbol hizq, Arbol hder)
{
    Arbol a = new Nodo;

    a->info = info;
    a->hizq = hizq;
    a->hder = hder;

    return a;
}

void Preorden (Arbol a)
{
    if (a != NULL)
    {
        printf("  %d", a->info);

        Preorden(a->hizq);

        Preorden(a->hder);
    }
}

void Orden (Arbol a)
{
    if (a != NULL)
    {
        Orden(a->hizq);
        printf(" %d", a->info);
        Orden(a->hder);
    }
}

void Posorden (Arbol a)
{
    if (a != NULL)
    {
        Posorden(a->hizq);
        Posorden(a->hder);
        printf(" %d", a->info);
    }
}

int ContarNodos (Arbol a)
{
    int cont = 0;
    if (a != NULL)
    {
        cont = 1;
        cont += ContarNodos(a->hizq);
        cont += ContarNodos(a->hder);
    }
    return cont;
}


int SumarElem (Arbol a)
{
    if (a != NULL)
    {
        return a->info + SumarElem(a->hizq) + SumarElem(a->hder);
    }
    else
        return 0;
}

void ListarImpar (Arbol a)
{
    if (a != NULL)
    {
        ListarImpar(a->hizq);
        if (a->info % 2 == 0)
        {
            printf(" %d", a->info);
        }
        ListarImpar(a->hder);
    }
}

int MaxValue (Arbol a)
{
    while (a->hder != NULL)
    {
        a = a->hder;
    }
    return a->info;
}

int MaxValueRec (Arbol a)
{
    if (a->hder != NULL)
    {
        return MaxValueRec (a->hder);
    }
    else
        return a->info;
}

int ContImpar (Arbol a)
{
    if (a != NULL)
    {
        if (a->info %2 == 1)
        {
            return 1 + ContImpar (a->hizq) + ContImpar (a->hder);
        }
        else
            return ContImpar (a->hizq) + ContImpar (a->hder);
    }
    else
        return 0;
}

bool Pertenece (Arbol a, int valor)
{
    bool found = false;
    while (a != NULL && found != true)
    {
        if (a->info == valor)
        {
            found = true;
        }
        else
            if (a->info > valor)
            {
                a = a->hizq;
            }
            else
                if (a->info < valor)
                {
                    a = a->hder;
                }
    }
    return found;
}

bool PerteneceRec (Arbol a, int valor)
{
    if (a == NULL)
    {
        return false;
    }
    else
        if (a->info == valor)
        {
            return true;
        }
        else
            if (a->info > valor)
            {
                return PerteneceRec (a->hizq, valor);
            }
            else
                if (a->info > valor)
                {
                    return PerteneceRec (a->hder, valor);
                }
}

int Deepness (Arbol a, int valor)
{
    bool found = false;
    int deep = 1;
    while (a != NULL && found != true)
    {
        if (a->info == valor)
        {
            found = true;
        }
        else
            if (a->info > valor)
            {
                a = a->hizq;
                deep++;
            }
            else
                if (a->info < valor)
                {
                    a = a->hder;
                    deep++;
                }
    }
    return deep;
}

int DeepnessRec (Arbol a, int valor)
{
    if (a->info == valor)
    {
        return 1;
    }
    else
        if (a->info > valor)
        {
            return 1 + DeepnessRec(a->hizq, valor);
        }
        else
            if (a->info < valor)
            {
                return 1 + DeepnessRec (a->hder, valor);

            }
}

void DeleteTree (Arbol a)
{
    if (a != NULL)
    {
        DeleteTree(a->hizq);
        DeleteTree(a->hder);
        delete(a);
    }
    a = NULL;
}

