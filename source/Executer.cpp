#include "Executer.h"
#include "Conjunto.h"
#include "lib\utils.h"

void executeComandoHelp()
{
    nl();
    printf("AYUDA DE SINTAXIS:");
    nl();
    printf("* Sintaxis help: help");
    nl();
    printf("* Sintaxis create: create valor1 valor2 ... valorN");
    nl();
    printf("* Sintaxis add: add cN valor");
    nl();
    printf("* Sintaxis remove: remove cN valor");
    nl();
    printf("* Sintaxis member: member cN valor");
    nl();
    printf("* Sintaxis union: union cN cM");
    nl();
    printf("* Sintaxis intersection: intersection cN cM");
    nl();
    printf("* Sintaxis difference: difference cN cM");
    nl();
    printf("* Sintaxis included: included cN cM");
    nl();
    printf("* Sintaxis equals: equals cN cM");
    nl();
    printf("* Sintaxis show: show cN");
    nl();
    printf("* Sintaxis listall: listall");
    nl();
    printf("* Sintaxis save: save cN nombreArchivo.txt");
    nl();
    printf("* Sintaxis load: load nombreArchivo.txt");
    nl();
    printf("* Sintaxis exit: exit");
    nl();
}
void executeComandoListAll(Conjuntos conjuntos)
{
    ConjuntosShow(conjuntos);
}
void executeComandoExit()
{
    printf("Hasta la próxima");
}

void Intersection(Conjunto c1, Conjunto c2, Conjunto &inter)
{
    if (c1 != NULL)
    {
        Intersection(c1->hizq, c2, inter);
        Intersection(c1->hder, c2, inter);
        if (ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(inter, c1->info);
        }
    }
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

        Intersection(c1, c2, inter);

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
bool executeComandoIncluded(Params params, Conjuntos conjuntos)
{
    bool incluido;
    int id1 = parseParamConjunto(params->info);
    int id2 = parseParamConjunto(params->sig->info);

    if (ConjuntosHasId(conjuntos, id1) && ConjuntosHasId(conjuntos, id2))
    {
        Conjunto c1, c2;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntosGetById(conjuntos, id2, c2);

        if (ConjuntoCount(c2) <= ConjuntoCount(c1))
        {
            incluido = false;
        }
        else
        {
            Conjunto inter;
            Intersection(c1, c2, inter);
            if (ConjuntoEquals(c1, inter))
            {
                incluido = true;
            }
            else
            {
                incluido = false;
            }
        }
    }
    else
    {
        incluido = false;
    }
    return incluido;
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
        if(!equals)
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
void executeComandoMember(Params params, Conjuntos conjuntos)//DEBE SER BOOL
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
    int id1 = parseParamConjunto(params->info);

    if (ConjuntosHasId(conjuntos, id1))
    {
        Conjunto c1;

        ConjuntosGetById(conjuntos, id1, c1);
        ConjuntoShow(c1);
    }
    else
    {
        //error
    }
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
        break;
    case INTERSECTION:
        executeComandoIntersection(params, conjuntos);
        break;
    case DIFFERENCE:
        executeComandoDifference(params, conjuntos);
        break;
    case INCLUDED:
        if (!executeComandoIncluded(params, conjuntos))
        {
            printf("El primer conjunto NO esta incluido estrictamente en el segundo");
        }
        else
        {
            printf("El primer conjunto esta incluido estrictamente en el segundo");
        }
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
        break;
    case LOAD:
        break;
    }
}
