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
        ConjuntoUnion(c1->hizq, c2);
        if (!ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(c2, c1->info);
        }
        ConjuntoUnion(c1->hder, c2);
    }
}

void ConjuntoUnion(Conjunto c1, Conjunto c2, Conjunto &cUnion)
{
    ConjuntoCopy(cUnion, c1);
    ConjuntoUnion(c2, cUnion);
}

void ConjuntoDifference(Conjunto c1, Conjunto c2, Conjunto &diff)
{
    if (c1 != NULL)
    {
        ConjuntoDifference(c1->hizq, c2, diff);
        if (!ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(diff, c1->info);
        }
        ConjuntoDifference(c1->hder, c2, diff);
    }
}

void RecursiveEquals(Conjunto c1, Conjunto c2, bool &equals)
{
    if (c1 != NULL && equals)
    {
        equals = ConjuntoPertenece(c2, c1->info);
        if (equals)
        {
            RecursiveEquals(c1->hizq, c2, equals);
            if (equals)
            {
                RecursiveEquals(c1->hder, c2, equals);
            }
        }
    }
}

bool ConjuntoEquals(Conjunto c1, Conjunto c2)
{
    bool equals;
    if (ConjuntoCount(c1) != ConjuntoCount(c2))
    {
        equals = false;
    }
    else
    {
        RecursiveEquals(c1, c2, equals);
    }
    return equals;
}

void ConjuntoIntersection(Conjunto c1, Conjunto c2, Conjunto &inter)
{
    if (c1 != NULL)
    {
        ConjuntoIntersection(c1->hizq, c2, inter);
        ConjuntoIntersection(c1->hder, c2, inter);
        if (ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(inter, c1->info);
        }
    }
}

void ConjuntoSave(string name, Conjunto c){
    ffile file = fopen(name, "wb");
    ConjuntoOrdenSave(file, c);
    fclose(file);
}
void ConjuntoOrdenSave(ffile &file, Conjunto c){
    if (c != NULL)
    {
        ConjuntoOrdenSave(file, c->hizq);
        fbajarInt(c->info, file);
        ConjuntoOrdenSave(file, c->hder);
    }
}

void ConjuntoLoad(string name, Conjunto &c){
    ffile file = fopen(name, "rb");
    int i;
    flevantarInt(i, file);
    while(!feof(file)){
        ConjuntoAddValue(c, i);
        flevantarInt(i, file);
    }
    fclose(file);
}
