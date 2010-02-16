#include "Comando.h"

void getComandoList(ListaString &l){
    ListaStringInsBack(l, "add");
    ListaStringInsBack(l, "create");
    ListaStringInsBack(l, "difference");
    ListaStringInsBack(l, "equals");
    ListaStringInsBack(l, "exit");
    ListaStringInsBack(l, "help");
    ListaStringInsBack(l, "included");
    ListaStringInsBack(l, "intersection");
    ListaStringInsBack(l, "listall");
    ListaStringInsBack(l, "load");
    ListaStringInsBack(l, "member");
    ListaStringInsBack(l, "remove");
    ListaStringInsBack(l, "save");
    ListaStringInsBack(l, "show");
    ListaStringInsBack(l, "union");
}

bool validateComando(string cmd){
    ListaString comandos;
    ListaStringCreate(comandos);
    getComandoList(comandos);
    bool valid = false;
    while(!valid && comandos != NULL){
            valid = streq(cmd, comandos->info);
            comandos = comandos->sig;
    }
    return valid;
}

Comando getComandoFromString(string s){
    Comando cmd;
    if(equalComandoString(ADD, s)) cmd = ADD;
    else if(equalComandoString(CREATE, s)) cmd = CREATE;
    else if(equalComandoString(DIFFERENCE, s)) cmd = DIFFERENCE;
    else if(equalComandoString(EQUALS, s)) cmd = EQUALS;
    else if(equalComandoString(EXIT, s)) cmd = EXIT;
    else if(equalComandoString(HELP, s)) cmd = HELP;
    else if(equalComandoString(INCLUDED, s)) cmd = INCLUDED;
    else if(equalComandoString(INTERSECTION, s)) cmd = INTERSECTION;
    else if(equalComandoString(LISTALL, s)) cmd = LISTALL;
    else if(equalComandoString(LOAD, s)) cmd = LOAD;
    else if(equalComandoString(MEMBER, s)) cmd = MEMBER;
    else if(equalComandoString(REMOVE, s)) cmd = REMOVE;
    else if(equalComandoString(SAVE, s)) cmd = SAVE;
    else if(equalComandoString(SHOW, s)) cmd = SHOW;
    else if(equalComandoString(UNION, s)) cmd = UNION;
    return cmd;
}

bool equalComandoString(Comando cmd, string s){
    string c; strcrear(c);
    getComandoString(cmd, c);
    return streq(c, s);
}

void getComandoString(Comando cmd, string &s){
    switch(cmd){
        case ADD: strcop(s, "add"); break;
        case CREATE: strcop(s, "create"); break;
        case DIFFERENCE: strcop(s, "difference"); break;
        case EQUALS: strcop(s, "equals"); break;
        case EXIT: strcop(s, "exit"); break;
        case HELP: strcop(s, "help"); break;
        case INCLUDED: strcop(s, "included"); break;
        case INTERSECTION: strcop(s, "intersection"); break;
        case LISTALL: strcop(s, "listall"); break;
        case LOAD: strcop(s, "load"); break;
        case MEMBER: strcop(s, "member"); break;
        case REMOVE: strcop(s, "remove"); break;
        case SAVE: strcop(s, "save"); break;
        case SHOW: strcop(s, "show"); break;
        case UNION: strcop(s, "union"); break;
        default: strcop(s, "");
    }
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
    return streq(s, "0") || atoi(s) != 0;
}
bool validateParamName(string s){
    return true;
}

bool validateParams(Comando cmd, ListaString params){
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
            valid = ListaStringCount(params) >=2;
            while(valid && params != NULL){
                valid = validateParamConjunto(params->info);
                params = params->sig;
            }
            break;
        case ADD:
        case REMOVE:
        case MEMBER:
            if(ListaStringCount(params) < 2) valid = false;
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
            valid = ListaStringCount(params) == 1;
            while(valid && params != NULL){
                valid = validateParamConjunto(params->info);
                params = params->sig;
            }
            break;
        case SAVE:
            if(ListaStringCount(params) != 2) valid = false;
            else valid = validateParamConjunto(params->info) && validateParamName(params->sig->info);
            break;
        case LOAD:
            if(ListaStringCount(params) != 1) valid = false;
            else valid = validateParamName(params->info);
            break;
    }
    return valid;
}

int parseParamConjunto(string s){
    s++;
    return atoi(s);
}
int parseParamValor(string s){
    return atoi(s);
}

void executeComandoHelp(){
    printf("No Implementado");
}
void executeComandoListAll(){
    printf("No Implementado");
}
void executeComandoExit(){
    printf("Hasta la próxima");
}
void executeComandoUnion(){
    printf("No Implementado");
}
void executeComandoIntersection(){
    printf("No Implementado");
}
void executeComandoDifference(){
    printf("No Implementado");
}
void executeComandoIncluded(){
    printf("No Implementado");
}
void executeComandoEquals(){
    printf("No Implementado");
}
void executeComandoAdd(ListaString params, Conjuntos &conjuntos){
    int id = parseParamConjunto(params->info);
    params = params->sig;
    if(ConjuntosHasId(conjuntos, id)){
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        while(params != NULL){
            ConjuntoAddValue(conjunto, parseParamValor(params->info));
            params = params->sig;
        }
        printf("c%d = ", id);
        ConjuntoShow(conjunto);
    }else{
        //error
    }
}
void executeComandoRemove(){
    printf("No Implementado");
}
void executeComandoMember(){
    printf("No Implementado");
}
void executeComandoCreate(ListaString params, Conjuntos &conjuntos){
    Conjunto conjunto;
    ConjuntoCreate(conjunto);
    int id = conjuntos.tope;
    while(params != NULL){
        ConjuntoAddValue(conjunto, parseParamValor(params->info));
        params = params->sig;
    }
    ConjuntosAdd(conjuntos, conjunto);
    printf("c%d = ", id); ConjuntoShow(conjunto);
}
void executeComandoShow(){
    printf("No Implementado");
}
void executeComandoLoad(){
    printf("No Implementado");
}

void executeComando(Comando cmd, ListaString params, Conjuntos &conjuntos){
    switch(cmd){
        case HELP: executeComandoHelp();break;
        case LISTALL:
        case EXIT:
            break;
        case UNION:
        case INTERSECTION:
        case DIFFERENCE:
        case INCLUDED:
        case EQUALS:
            break;
        case ADD: executeComandoAdd(params, conjuntos); break;
        case REMOVE:
        case MEMBER:
            break;
        case CREATE: executeComandoCreate(params, conjuntos); break;
        case SHOW:
            break;
        case SAVE:
            break;
        case LOAD:
            break;
    }
}
