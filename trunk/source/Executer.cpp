#include "Executer.h"
#include "Conjunto.h"
#include "lib\utils.h"

void executeComandoHelp()
{
    nl();
    printf("AYUDA DE SINTAXIS:");
    nl();
    printf("* help: help");
    nl();
    printf("* create: create valor1 valor2 ... valorN");
    nl();
    printf("* add: add cN valor");
    nl();
    printf("* remove: remove cN valor");
    nl();
    printf("* member: member cN valor");
    nl();
    printf("* union: union cN cM");
    nl();
    printf("* intersection: intersection cN cM");
    nl();
    printf("* difference: difference cN cM");
    nl();
    printf("* included: included cN cM");
    nl();
    printf("* equals: equals cN cM");
    nl();
    printf("* show: show cN");
    nl();
    printf("* listall: listall");
    nl();
    printf("* save: save cN nombreArchivo.txt");
    nl();
    printf("* load: load nombreArchivo.txt");
    nl();
    printf("* exit: exit");
    nl();
}
void executeComandoListAll(Conjuntos conjuntos)
{
    ConjuntosShow(conjuntos);
}
void executeComandoExit()
{
    printf("Hasta la proxima");
}

void executeComandoIntersection(Params params, Conjuntos &conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);
    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2, inter;
        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);
        ConjuntoCreate(inter);

        ConjuntoIntersection(c1, c2, inter);

        AddAndShowConjunto(conjuntos, inter);
    }
    else
    {
        //error
    }

}

void AddAndShowConjunto(Conjuntos &conjuntos, Conjunto conjunto)
{
    int newid = ConjuntosGetNextId(conjuntos);
    ConjuntosAdd(conjuntos, conjunto);
    printf("c%d = ", newid);
    ConjuntoShow(conjunto);
}

void executeComandoDifference(Params params, Conjuntos &conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);

    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2, diff;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);
        ConjuntoCreate(diff);

        ConjuntoDifference(c1, c2, diff);

        AddAndShowConjunto(conjuntos, diff);
    }
    else
    {
        //error
    }
}
void executeComandoIncluded(Params params, Conjuntos conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);

    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);

        if (ConjuntoCount(c2) <= ConjuntoCount(c1))
        {
            printf("El primer conjunto NO esta incluido estrictamente en el segundo");
        }
        else
        {
            Conjunto inter;
            ConjuntoIntersection(c1, c2, inter);
            if (ConjuntoEquals(c1, inter))
            {
                printf("El primer conjunto esta incluido estrictamente en el segundo");
            }
            else
            {
                printf("El primer conjunto NO esta incluido estrictamente en el segundo");
            }
        }
    }
    else
    {
        //error
    }
}
void executeComandoEquals(Params params, Conjuntos conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);

    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);

        bool equals = ConjuntoEquals(c1, c2);
        if (!equals)
        {
            printf("No son iguales");
        }
        else
        {
            printf("Son iguales");
        }
    }
    else
    {
        //error
    }
}

void executeComandoUnion(Params params, Conjuntos &conjuntos)
{
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);

    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2, cUnion;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);
        ConjuntoCreate(cUnion);

        ConjuntoUnion(c1, c2, cUnion);

        AddAndShowConjunto(conjuntos, cUnion);
    }
    else
    {
        //error
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

void UpdateConjuntoRef(Conjuntos &conjuntos, Conjunto conjunto, int id)
{
    ListaABB aux;
    aux = conjuntos.conjuntos;
    int count = 1;
    while(count < id)
    {
        aux = aux->sig;
        count++;
    }
    aux->info = conjunto;
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
            if (ConjuntoPertenece(conjunto, valor))
            {
                ConjuntoRemoveValue(conjunto, valor);
            }
            params = params->sig;
        }
        UpdateConjuntoRef(conjuntos, conjunto, id);
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
void executeComandoShow(Params params, Conjuntos conjuntos)
{
    int id = parseParamConjunto(params->info);
    if (ConjuntosHasId(conjuntos, id))
    {
        Conjunto c;
        ConjuntosGetById(conjuntos, id, c);
        ConjuntoShow(c);
    }
    else
    {
        //error
    }
}

void executeComandoSave(Params params, Conjuntos conjuntos)
{
    int id = parseParamConjunto(params->info);
    if (ConjuntosHasId(conjuntos, id))
    {
        Conjunto c;
        ConjuntosGetById(conjuntos, id, c);
        ConjuntoSave(params->sig->info, c);
        printf("c%d almacenado correctamente en ", id);
        print(params->sig->info);
    }
    else
    {
    }
}

void executeComandoLoad(Params params, Conjuntos &conjuntos)
{
    Conjunto c;
    ConjuntoCreate(c);
    ConjuntoLoad(params->info, c);
    AddAndShowConjunto(conjuntos, c);
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
        executeComandoExit();
        break;
    case UNION:
        executeComandoUnion(params, conjuntos);
        break;
    case INTERSECTION:
        executeComandoIntersection(params, conjuntos);
        break;
    case DIFFERENCE:
        executeComandoDifference(params, conjuntos);
        break;
    case INCLUDED:
        executeComandoIncluded(params, conjuntos);
        break;
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
        executeComandoShow(params, conjuntos);
        break;
    case SAVE:
        executeComandoSave(params, conjuntos);
        break;
    case LOAD:
        executeComandoLoad(params, conjuntos);
        break;
    }
}
