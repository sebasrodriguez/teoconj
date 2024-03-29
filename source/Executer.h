#ifndef EXECUTER_H_INCLUDED
#define EXECUTER_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "Conjuntos.h"

void executeComandoHelp();

void executeComandoListAll(Conjuntos conjuntos);

void executeComandoExit();

void executeComandoUnion(Params params, Conjuntos &conjuntos);

void executeComandoIntersection(Params params, Conjuntos &conjuntos);

void executeComandoDifference(Params params, Conjuntos &conjuntos);

void executeComandoIncluded(Params params, Conjuntos conjuntos);

void executeComandoEquals(Params params, Conjuntos conjuntos);

void executeComandoAdd(Params params, Conjuntos &conjuntos);

void executeComandoRemove(Params params, Conjuntos &conjuntos);

void executeComandoMember(Params params, Conjuntos conjuntos);

void executeComandoCreate(Params params, Conjuntos &conjuntos);

void executeComandoShow(Params params, Conjuntos conjuntos);

void executeComandoSave(Params params, Conjuntos conjuntos);

void executeComandoLoad(Params params, Conjuntos &conjuntos);

void executeComandoClear();

void executeComando(Comando cmd, Params params, Conjuntos &conjuntos);

#endif
