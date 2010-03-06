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

void ConjuntoOrdenUnion(Conjunto c1, Conjunto &c2)
{
    if (c1 != NULL)
    {
        ConjuntoOrdenUnion(c1->hizq, c2);
        if (!ConjuntoPertenece(c2, c1->info))
        {
            ConjuntoAddValue(c2, c1->info);
        }
        ConjuntoOrdenUnion(c1->hder, c2);
    }
}

void ConjuntoUnion(Conjunto c1, Conjunto c2, Conjunto &uni)
{
    ConjuntoCopy(uni, c1);
    ConjuntoOrdenUnion(c2, uni);
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

void ConjuntoPostOrdenEquals(Conjunto c1, Conjunto c2, bool &equals)
{
    if (c1 != NULL && equals)
    {
        equals = ConjuntoPertenece(c2, c1->info);
        if (equals)
        {
            ConjuntoPostOrdenEquals(c1->hizq, c2, equals);
            if (equals)
            {
                ConjuntoPostOrdenEquals(c1->hder, c2, equals);
            }
        }
    }
}

bool ConjuntoMember(Conjunto c, int valor){
    return ConjuntoPertenece(c, valor);
}

bool ConjuntoEquals(Conjunto c1, Conjunto c2)
{
    bool equals = ConjuntoCount(c1) == ConjuntoCount(c2);
    if(equals){
        ConjuntoPostOrdenEquals(c1, c2, equals);
    }
    return equals;
}

bool ConjuntoIncluded(Conjunto c1, Conjunto c2){
    bool r = false;
    if (ConjuntoCount(c1) < ConjuntoCount(c2)){
        Conjunto inter; ConjuntoCreate(inter);
        ConjuntoIntersection(c1, c2, inter);
        if (ConjuntoEquals(c1, inter))
        {
            r = true;
        }
    }
    return r;
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

void ConjuntoOrdenSave(ffile &file, Conjunto c){
    if (c != NULL)
    {
        ConjuntoOrdenSave(file, c->hizq);
        fbajarInt(c->info, file);
        ConjuntoOrdenSave(file, c->hder);
    }
}

void ConjuntoSave(string name, Conjunto c){
    ffile file = fopen(name, "wb");
    ConjuntoOrdenSave(file, c);
    fclose(file);
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
