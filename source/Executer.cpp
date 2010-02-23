#include "Executer.h"

void executeComandoHelp(){
    printf("No Implementado");
}
void executeComandoListAll(Conjuntos conjuntos){
    ConjuntosShow(conjuntos);
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
void executeComandoEquals(Params params, Conjuntos conjuntos){
    int oldid = parseParamConjunto(params->info);
   // while(

}
void executeComandoAdd(Params params, Conjuntos &conjuntos){
    int valor, id = parseParamConjunto(params->info);
    params = params->sig;
    if(ConjuntosHasId(conjuntos, id)){
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        if(ConjuntoCount(conjunto) == 0){
            valor = parseParamValor(params->info);
            ConjuntosAddValueToConj(conjuntos, id, valor, conjunto);
            params = params->sig;
        }
        while(params != NULL){
            valor = parseParamValor(params->info);
            if(!ConjuntoPertenece(conjunto, valor))
                ConjuntoAddValue(conjunto, valor);
            params = params->sig;
        }
        printf("c%d = ", id);
        ConjuntoShow(conjunto);
    }else{
        //error
    }
}
void executeComandoRemove(Params params, Conjuntos &conjuntos){
    int valor, id = parseParamConjunto(params->info);
    params = params->sig;
    if(ConjuntosHasId(conjuntos, id)){
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        while(params != NULL){
            valor = parseParamValor(params->info);
            if(!ConjuntoPertenece(conjunto, valor))
                ConjuntoRemoveValue(conjunto, valor);
            params = params->sig;
        }
        printf("c%d = ", id);
        ConjuntoShow(conjunto);
    }else{
        //error
    }
}
void executeComandoMember(Params params, Conjuntos conjuntos){
    int valor, id = parseParamConjunto(params->info);
    params = params->sig;
    if(ConjuntosHasId(conjuntos, id)){
        Conjunto conjunto;
        ConjuntosGetById(conjuntos, id, conjunto);
        while(params != NULL){
            valor = parseParamValor(params->info);
            if(ConjuntoPertenece(conjunto, valor))
                printf(" true");
            else
                printf(" false");
            params = params->sig;
        }
    }else{
        //error
    }
}
void executeComandoCreate(Params params, Conjuntos &conjuntos){
    Conjunto conjunto;
    ConjuntoCreate(conjunto);
    int id = ConjuntosGetNextId(conjuntos) ;
    int valor;
    while(params != NULL){
        valor = parseParamValor(params->info);
        if(!ConjuntoPertenece(conjunto, valor))
            ConjuntoAddValue(conjunto, valor);
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

void executeComando(Comando cmd, Params params, Conjuntos &conjuntos){
    switch(cmd){
        case HELP: executeComandoHelp(); break;
        case LISTALL: executeComandoListAll(conjuntos); break;
        case EXIT: break;
        case UNION:
        case INTERSECTION:
        case DIFFERENCE:
        case INCLUDED:
        case EQUALS: executeComandoEquals(params, conjuntos); break;
        case ADD: executeComandoAdd(params, conjuntos); break;
        case REMOVE: executeComandoRemove(params, conjuntos); break;
        case MEMBER: executeComandoMember(params, conjuntos); break;
        case CREATE: executeComandoCreate(params, conjuntos); break;
        case SHOW: break;
        case SAVE: break;
        case LOAD: break;
    }
}
