#ifndef EXECUTER_H_INCLUDED
#define EXECUTER_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "Params.h"
#include "Conjuntos.h"

void executeComandoHelp();

void executeComandoListAll();

void executeComandoExit();

void executeComandoUnion();

void Intersection(Conjunto c1, Conjunto c2, Conjunto &inter);

void executeComandoIntersection(Params params, Conjuntos conjuntos);

void executeComandoDifference();

void executeComandoIncluded();

void executeComandoEquals();

void executeComandoAdd();

void executeComandoRemove();

void executeComandoMember();

void executeComandoCreate(Params params, Conjuntos &conjuntos);

void executeComandoShow();

void executeComandoLoad();

void executeComando(Comando cmd, ListaString params, Conjuntos &conjuntos);

#endif
