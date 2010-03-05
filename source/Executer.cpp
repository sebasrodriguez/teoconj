#include "Executer.h"
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
    if(ConjuntosCount(conjuntos) > 0)
        ConjuntosShow(conjuntos);
    else
        printf(MESSAGE_EMPTY_LIST);
}
void executeComandoExit()
{
    printf(MESSAGE_EXIT);
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

        ConjuntosAddAndShow(conjuntos, inter);
    }
    else
    {
        printError(ERROR_WRONG_ID);
    }

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

        ConjuntosAddAndShow(conjuntos, diff);
    }
    else
    {
        printError(ERROR_WRONG_ID);
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
           printf(MESSAGE_FALSE);
        }
        else
        {
            Conjunto inter;
            ConjuntoIntersection(c1, c2, inter);
            if (ConjuntoEquals(c1, inter))
            {
                printf(MESSAGE_TRUE);
            }
            else
            {
                 printf(MESSAGE_FALSE);
            }
        }
    }
    else
    {
        printError(ERROR_WRONG_ID);
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
            printf(MESSAGE_FALSE);
        }
        else
        {
            printf(MESSAGE_TRUE);
        }
    }
    else
    {
        printError(ERROR_WRONG_ID);
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

        ConjuntosAddAndShow(conjuntos, cUnion);
    }
    else
    {
        printError(ERROR_WRONG_ID);
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
        printf(MESSAGE_PRE_C, id);
        ConjuntoShow(conjunto);
    }
    else
    {
        printError(ERROR_WRONG_ID);
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
        printf(MESSAGE_PRE_C, id);
        ConjuntoShow(conjunto);
    }
    else
    {
        printError(ERROR_WRONG_ID);
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
                printf(MESSAGE_TRUE);
            else
                printf(MESSAGE_FALSE);
            params = params->sig;
        }
    }
    else
    {
        printError(ERROR_WRONG_ID);
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
    printf(MESSAGE_PRE_C, id);
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
        printError(ERROR_WRONG_ID);
    }
}

void executeComandoSave(Params params, Conjuntos conjuntos)
{
    int id = parseParamConjunto(params->info);
    if (ConjuntosHasId(conjuntos, id))
    {
        Conjunto c;
        ConjuntosGetById(conjuntos, id, c);
        string path;
        strcop(path, DATA_FILE_PATH);
        strcon(path, params->sig->info);
        ConjuntoSave(path, c);
        printf("c%d almacenado correctamente en ", id);
        print(params->sig->info);
    }
    else
    {
        printError(ERROR_WRONG_ID);
    }
}

void executeComandoLoad(Params params, Conjuntos &conjuntos)
{
    Conjunto c;
    ConjuntoCreate(c);
    ConjuntoLoad(params->info, c);
    ConjuntosAddAndShow(conjuntos, c);
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
