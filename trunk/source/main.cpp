#include <iostream>
#include <stdio.h>

#include "lib/string_extended.h"
#include "config.h"
#include "Comando.h"


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
    string aux; strcrear(aux);
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
/*
Comando help (patron: "cmd")
Comando create (patron: "cmd val val val ... val")
Comando add (patron: "cmd conj val")
Comando remove (patron: "cmd conj val")
Comando member (patron: "cmd conj val")
Comando union (patron: "cmd conj conj")
Comando intersection (patron: "cmd conj conj")
Comando difference (patron: "cmd conj conj")
Comando included (patron: "cmd conj conj")
Comando equals (patron: "cmd conj conj")
Comando show (patron: "cmd conj")
Comando listall (patron: "cmd")
Comando save (patron: "cmd conj name")
Comando load (patron: "cmd name")
Comando exit (patron: "cmd")*/

int main(){
    string strcomando; strcrear(strcomando);
    printf("%s:", CONSOLE_PROMPT);
    ListaString comando;
    ListaStringCreate(comando);
    scan(strcomando);
    strsplit(strcomando, BSP, comando);
    if(validateComando(comando->info)){
        Comando cmd = getComandoFromString(comando->info);
        ListaString params; ListaStringCreate(params);
        params = comando->sig;
        if(validateParams(cmd, params))
            printf("valid");
        else
            printf("valid command, params not valid");
    }else
        printf("command not valid");
    return 0;
}
