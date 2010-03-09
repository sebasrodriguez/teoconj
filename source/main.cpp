#include <stdlib.h>
#include <stdio.h>

#include "Executer.h"

void showBanner()
{
    printf("                      #####                            #        ###   \n");
    printf(" ##### ######  ####  #     #  ####  #    #      #     ##       #   #  \n");
    printf("   #   #      #    # #       #    # ##   #      #    # #      #     # \n");
    printf("   #   #####  #    # #       #    # # #  #      #      #      #     # \n");
    printf("   #   #      #    # #       #    # #  # #      #      #      #     # \n");
    printf("   #   #      #    # #     # #    # #   ## #    #      #   ##  #   #  \n");
    printf("   #   ######  ####   #####   ####  #    #  ####     ##### ##   ###   \n");
    nl();
    printf("======================================================================");
    nl();
}

int main()
{
    showBanner();
    Conjuntos conjuntos;
    ConjuntosCreate(conjuntos);
    bool salir = false;
    ListaString comando;
    string strcomando;
    do
    {
        printf(CONSOLE_PROMPT);
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
                    printf(CONSOLE_RESULT_PROMPT);
                    executeComando(cmd, params, conjuntos);
                    nl();nl();
                    salir = (cmd == EXIT);
                }
                else
                {
                    printError(ERROR_WRONG_PARAMS);
                }
            }
            else
            {
                printError(ERROR_WRONG_COMMAND);
            }
        }
        strdestruir(strcomando);
    }
    while (!salir);
    return 0;
}
