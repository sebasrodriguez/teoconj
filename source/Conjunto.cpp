#include "Conjunto.h"

void ConjuntoCreate(Conjunto &c)
{
    ArbolIntCreate(c);
}

void ConjuntoAddValue(Conjunto &c, int valor)
{
    ArbolIntAdd(c, valor);
}

void ConjuntoShow(Conjunto c)
{
    string buffer;
    strcrearmax(buffer);
    string result;
    strcrear(result);
    if (ConjuntoCount(c) > 0)
    {
        ConjuntoOrdenBuffer(c, buffer, result);
        result += 2;
    }
    printf("{");
    print(result);
    printf("}");
}

void ConjuntoOrdenBuffer(Conjunto c, string &buffer, string &result)
{
    if (c != NULL)
    {
        ConjuntoOrdenBuffer(c->hizq, buffer, result);
        straddchar(result, ',');
        straddchar(result, BSP);
        strcon(result, itoa(c->info, buffer, 10));
        ConjuntoOrdenBuffer(c->hder, buffer, result);
    }
}

bool ConjuntoPertenece(Conjunto c, int valor)
{
    return ArbolIntPertenece(c, valor);
}

int ConjuntoCount(Conjunto c)
{
    return ArbolIntCount(c);
}

void ConjuntoRemoveValue(Conjunto &c, int valor)
{
    ArbolIntRemove(c, valor);
}

void ConjuntoCopy(Conjunto &c1, Conjunto c2)
{
    ConjuntoCreate(c1);
    ArbolIntCopy(c1, c2);
}

void ConjuntoUnion(Conjunto c1, Conjunto &c2)
{
    if (c1 != NULL)
    {
        if (!ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(c2, c1->info);
        }
        ConjuntoUnion(c1->hizq, c2);
        ConjuntoUnion(c1->hder, c2);
    }
}
