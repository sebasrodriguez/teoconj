#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include<stdio.h>
#include "lib/string.h"
#include "lib/listastring.h"

typedef enum {
    ADD,
    CREATE,
    DIFFERENCE,
    EQUALS,
    EXIT,
    HELP,
    INCLUDED,
    INTERSECTION,
    LISTALL,
    LOAD,
    MEMBER,
    REMOVE,
    SAVE,
    SHOW,
    UNION
}Comando;

void getComandoList(ListaString &l);

Comando getComandoFromString(string s);

bool equalComandoString(Comando cmd, string s);

bool validateComando(string cmd);

void getComandoString(Comando cmd, string &s);

#endif
