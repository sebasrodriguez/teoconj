#include "Params.h"

void ParamsCreate(Params &p){
    ListaStringCreate(p);
}

int ParamsCount(Params p){
    return ListaStringCount(p);
}

bool ParamsValidate(Comando cmd, Params params){
    bool valid = true;
    switch(cmd){
        case HELP:
        case LISTALL:
        case EXIT:
            valid = ListaStringEmpty(params);
            break;
        case UNION:
        case INTERSECTION:
        case DIFFERENCE:
        case INCLUDED:
        case EQUALS:
            valid = ParamsCount(params) >=2;
            while(valid && params != NULL){
                valid = validateParamConjunto(params->info);
                params = params->sig;
            }
            break;
        case ADD:
        case REMOVE:
        case MEMBER:
            if(ParamsCount(params) < 2) valid = false;
            else{
                valid = validateParamConjunto(params->info);
                params = params->sig;
                while(valid && params != NULL){
                    valid = validateParamValor(params->info);
                    params = params->sig;
                }
            }
            break;
        case CREATE:
            while(valid && params != NULL){
                valid = validateParamValor(params->info);
                params = params->sig;
            }
            break;
        case SHOW:
            valid = ParamsCount(params) == 1;
            while(valid && params != NULL){
                valid = validateParamConjunto(params->info);
                params = params->sig;
            }
            break;
        case SAVE:
            if(ParamsCount(params) != 2) valid = false;
            else valid = validateParamConjunto(params->info) && validateParamName(params->sig->info);
            break;
        case LOAD:
            if(ParamsCount(params) != 1) valid = false;
            else valid = validateParamName(params->info);
            break;
    }
    return valid;
}

bool validateParamConjunto(string s){
    bool valid = false;
    if(s[0] == 'c'){
        s ++;
        if(atoi(s) != 0) valid = true;
    }
    return valid;
}
bool validateParamValor(string s){
    return streq(s, "0") || atoi(s) > 0;
}
bool validateParamName(string s){
    return true;
}

int parseParamConjunto(string s){
    s++;
    return atoi(s);
}
int parseParamValor(string s){
    return atoi(s);
}
