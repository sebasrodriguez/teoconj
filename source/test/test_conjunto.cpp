#include <stdlib.h>
#include <stdio.h>

#include "../lib/string_extended.h"
#include "../Conjunto.h"

int main(){
    printf("=> TESTEANDO Conjunto.h (ABB de int)\n");
    Conjunto c; ConjuntoCreate(c);
    ConjuntoAddValue(c, 2);
    ConjuntoAddValue(c, 4);
    ConjuntoAddValue(c, 8);
    ConjuntoAddValue(c, 7);
    ConjuntoShow(c);
    ConjuntoAddValue(c, 1);
    ConjuntoAddValue(c, 9);
    ConjuntoShow(c);
    getchar();
    return 0;
}
