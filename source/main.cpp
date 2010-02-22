#include <stdlib.h>
#include <stdio.h>

#include "lib/string_extended.h"
#include "config.h"
#include "Comando.h"

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
    Conjuntos conjuntos;
    ConjuntosCreate(conjuntos);
    bool salir = false;
    ListaString comando;
    string strcomando;
    do{
        printf("%s: ", CONSOLE_PROMPT);
        ListaStringCreate(comando);
        strcrear(strcomando);
        scan(strcomando);
        if(strcomando[0] != EOS){
            strsplit(strcomando, BSP, comando);
            if(validateComando(comando->info)){
                Comando cmd = getComandoFromString(comando->info);
                ListaString params; ListaStringCreate(params);
                params = comando->sig;
                if(validateParams(cmd, params)){
                    printf("%s: ", CONSOLE_RESULT_PROMPT);
                    executeComando(cmd, params, conjuntos);printf("\n");
                    salir = (cmd == EXIT);
               }else
                    printf("valid command, params not valid");
            }else
                printf("command not valid");
        }
        strdestruir(strcomando);
    }while(!salir);
    return 0;
}
