#include <iostream>
#include <stdio.h>

#include "lib/string_extended.h"
#include "config.h"
#include "Comando.h"

int main(){
    string strcomando; strcrear(strcomando);
    printf("%s:", CONSOLE_PROMPT);
    ListaString comando;
    ListaStringCreate(comando);
    scan(strcomando);
    strsplit(strcomando, BSP, comando);
    if(validateComando(comando->info)){
        Comando cmd = getComandoFromString(comando->info);
        printf("valid");
    }else
        printf("not valid");
    return 0;
}
