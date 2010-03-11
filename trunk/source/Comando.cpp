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
    ListaStringInsBack(l, "clear");
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
    else if(equalComandoString(CLEAR, s)) cmd = CLEAR;
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
        case CLEAR: strcop(s, "clear"); break;
        default: strcop(s, "");
    }
}


