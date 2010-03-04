#include <stdlib.h>
#include <stdio.h>

#include "lib/string.h"
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
    printf("\n");
    printf("======================================================================");
    printf("\n");
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
                    if (cmd != HELP && cmd != EXIT)
                    {
                        printf("%s: ", CONSOLE_RESULT_PROMPT);
                    }
                    printf("\n");
                    executeComando(cmd, params, conjuntos);
                    printf("\n");
                    salir = (cmd == EXIT);
                }
                else
                {
                    printf("Parametros incorrectos");
                    printf("\n");
                }
            }
            else
            {
                printf("Comando incorrecto");
                printf("\n");
            }
        }
        strdestruir(strcomando);
    }
    while (!salir);
    return 0;
}
