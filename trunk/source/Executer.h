#ifndef EXECUTER_H_INCLUDED
#define EXECUTER_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "Params.h"
#include "Conjuntos.h"

void AddAndShowConjunto(Conjuntos &conjuntos, Conjunto conjunto);

void executeComandoHelp();

void executeComandoListAll();

void executeComandoExit();

void executeComandoUnion();

void executeComandoIntersection(Params params, Conjuntos &conjuntos);

void executeComandoDifference();

void executeComandoIncluded(Params params, Conjuntos conjuntos);

void executeComandoEquals();

void executeComandoAdd();

void executeComandoRemove();

void executeComandoMember();

void executeComandoCreate(Params params, Conjuntos &conjuntos);

void executeComandoShow(Params params, Conjuntos conjuntos);

void executeComandoLoad();

void executeComando(Comando cmd, ListaString params, Conjuntos &conjuntos);

#endif
