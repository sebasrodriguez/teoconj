#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "lib/string.h"
#include "lib/listastring.h"
#include "Conjunto.h"
#include "Conjuntos.h"

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

bool validateParamConjunto(string s);

bool validateParamValor(string s);

bool validateParamName(string s);

bool validateParams(Comando cmd, ListaString params);

int parseParamConjunto(string s);

int parseParamValor(string s);

void executeComandoHelp();

void executeComandoListAll();

void executeComandoExit();

void executeComandoUnion();

void executeComandoIntersection();

void executeComandoDifference();

void executeComandoIncluded();

void executeComandoEquals();

void executeComandoAdd();

void executeComandoRemove();

void executeComandoMember();

void executeComandoCreate(ListaString params, Conjuntos &conjuntos);

void executeComandoShow();

void executeComandoLoad();

void executeComando(Comando cmd, ListaString params, Conjuntos &conjuntos);
#endif
