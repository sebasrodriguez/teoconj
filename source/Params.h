#ifndef PARAMS_H_INCLUDED
#define PARAMS_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "Comando.h"

typedef ListaString Params;

void ParamsCreate(Params &p);

int ParamsCount(Params p);

bool ParamsValidate(Comando cmd, Params params);

bool validateParamConjunto(string s);

bool validateParamValor(string s);

bool validateParamName(string s);


int parseParamConjunto(string s);

int parseParamValor(string s);





#endif
