#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include<stdio.h>
#include "lib/string.h"
#include "lib/listastring.h"

typedef enum {
    ADD=0,
    CREATE=1,
    DIFFERENCE=2,
    EQUALS=3,
    EXIT=4,
    HELP=5,
    INCLUDED=6,
    INTERSECTION=7,
    LISTALL=8,
    LOAD=9,
    MEMBER=10,
    REMOVE=11,
    SAVE=12,
    SHOW=13,
    UNION=14
}Comando;

void getComandoList(ListaString &l);

Comando getComandoFromString(string s);

bool equalComandoString(Comando cmd, string s);

bool validateComando(string cmd);

void getComandoString(Comando cmd, string &s);

#endif
