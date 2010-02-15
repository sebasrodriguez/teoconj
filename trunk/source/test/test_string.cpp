#include <iostream>
#include <stdio.h>
#include "../lib/string_extended.h"


int main(){
    string str ;
    ListaString ls;
    strcrear(str);
    ListaStringCreate(ls);
    strcop(str, "  HOLA   PETECO   COMO ESTAS YO BIEN   ");
    strsplit(str, BSP, ls);
    return 0;
}
