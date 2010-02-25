#include "Executer.h"

void executeComandoHelp()
{
    printf("No Implementado");
}
void executeComandoListAll(Conjuntos conjuntos)
{
    ConjuntosShow(conjuntos);
}
void executeComandoExit()
{
    printf("Hasta la pr�xima");
}

void Intersection(Conjunto c1, Conjunto c2, Conjunto &inter)
{
    if (c1 != NULL)
    {
        Intersection(c1->hizq, c2, inter);
        if (ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(inter, c1->info);
        }
        Intersection(c1->hder, c2, inter);
    }
}

void executeComandoIntersection(Params params, Conjuntos conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);
    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2)){
        Conjunto c1, c2, inter;
        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);
        ConjuntoCreate(inter);
        Intersection(c1, c2, inter);
        ConjuntoShow(inter);
        //GUARDAR A LISTA DE CONJUNTOS?
    }

}
void executeComandoDifference()
{
    printf("No Implementado");
}
void executeComandoIncluded()
{
    printf("No Implementado");
}
void executeComandoEquals(Params params, Conjuntos conjuntos)
{
    int oldid = parseParamConjunto(params->info);
    // while(

}

void Union(Conjunto c1, Conjunto &c2)//EN EL SEUDOCODIGO ESTA EN "ORDEN"
{
    if (c1 != NULL)
    {
        if (!ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(c2, c1->info);
        }
        Union(c1->hizq, c2);
        Union(c1->hder, c2);
    }
}

void executeComandoUnion(Params params, Conjuntos conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);

    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2, c3;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);
        ConjuntoCopy(c3, c1);

        Union(c2, c3);
        ConjuntoShow(c3);
    }
}

void executeComandoAdd(Params params, Conjuntos &conjuntos)
{
    int valor, id = parseParamConjunto(params->info);
    params = params->sig;
    if (ConjuntosHasId(conjuntos, id))
    {
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        if (ConjuntoCount(conjunto) == 0)
        {
            valor = parseParamValor(params->info);
            ConjuntosAddValueToConj(conjuntos, id, valor, conjunto);
            params = params->sig;
        }
        while (params != NULL)
        {
            valor = parseParamValor(params->info);
            if (!ConjuntoPertenece(conjunto, valor))
                ConjuntoAddValue(conjunto, valor);
            params = params->sig;
        }
        printf("c%d = ", id);
        ConjuntoShow(conjunto);
    }
    else
    {
        //error
    }
}
void executeComandoRemove(Params params, Conjuntos &conjuntos)
{
    int valor, id = parseParamConjunto(params->info);
    params = params->sig;
    if (ConjuntosHasId(conjuntos, id))
    {
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        while (params != NULL)
        {
            valor = parseParamValor(params->info);
            if (!ConjuntoPertenece(conjunto, valor))
                ConjuntoRemoveValue(conjunto, valor);
            params = params->sig;
        }
        printf("c%d = ", id);
        ConjuntoShow(conjunto);
    }
    else
    {
        //error
    }
}
void executeComandoMember(Params params, Conjuntos conjuntos)
{
    int valor, id = parseParamConjunto(params->info);
    params = params->sig;
    if (ConjuntosHasId(conjuntos, id))
    {
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        while (params != NULL)
        {
            valor = parseParamValor(params->info);
            if (ConjuntoPertenece(conjunto, valor))
                printf(" true");
            else
                printf(" false");
            params = params->sig;
        }
    }
    else
    {
        //error
    }
}
void executeComandoCreate(Params params, Conjuntos &conjuntos)
{
    Conjunto conjunto;
    ConjuntoCreate(conjunto);
    int id = ConjuntosGetNextId(conjuntos) ;
    int valor;
    while (params != NULL)
    {
        valor = parseParamValor(params->info);
        if (!ConjuntoPertenece(conjunto, valor))
            ConjuntoAddValue(conjunto, valor);
        params = params->sig;
    }
    ConjuntosAdd(conjuntos, conjunto);
    printf("c%d = ", id);
    ConjuntoShow(conjunto);
}
void executeComandoShow()
{
    printf("No Implementado");
}
void executeComandoLoad()
{
    printf("No Implementado");
}

void executeComando(Comando cmd, Params params, Conjuntos &conjuntos)
{
    switch (cmd)
    {
    case HELP:
        executeComandoHelp();
        break;
    case LISTALL:
        executeComandoListAll(conjuntos);
        break;
    case EXIT:
        break;
    case UNION:
        executeComandoUnion(params, conjuntos);
    case INTERSECTION:
        executeComandoIntersection(params, conjuntos);
    case DIFFERENCE:
    case INCLUDED:
    case EQUALS:
        executeComandoEquals(params, conjuntos);
        break;
    case ADD:
        executeComandoAdd(params, conjuntos);
        break;
    case REMOVE:
        executeComandoRemove(params, conjuntos);
        break;
    case MEMBER:
        executeComandoMember(params, conjuntos);
        break;
    case CREATE:
        executeComandoCreate(params, conjuntos);
        break;
    case SHOW:
        break;
    case SAVE:
        break;
    case LOAD:
        break;
    }
}
