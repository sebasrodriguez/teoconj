#include <stdlib.h>
#include <stdio.h>

#include "lib/string_extended.h"
#include "config.h"
#include "Executer.h"

int main()
{
    Conjuntos conjuntos;
    ConjuntosCreate(conjuntos);
    bool salir = false;
    ListaString comando;
    string strcomando;
    do
    {
        printf("%s: ", CONSOLE_PROMPT);
        ListaStringCreate(comando);
        strcrear(strcomando);
        scan(strcomando);
        if (strcomando[0] != EOS)
        {
            ListaStringSplit(strcomando, BSP, comando);
            if (validateComando(comando->info))
            {
                Comando cmd = getComandoFromString(comando->info);
                Params params;
                ParamsCreate(params);
                params = comando->sig;
                if (ParamsValidate(cmd, params))
                {
                    printf("%s: ", CONSOLE_RESULT_PROMPT);
                    executeComando(cmd, params, conjuntos);
                    printf("\n");
                    salir = (cmd == EXIT);
                }
                else
                {
                    printf("valid command, params not valid");
                }
            }
            else
            {
                printf("command not valid");
            }
        }
        strdestruir(strcomando);
    }
    while (!salir);
    return 0;
}
