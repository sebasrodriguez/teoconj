#include <stdlib.h>
#include <stdio.h>

#include "../lib/string_extended.h"
#include "../Conjunto.h"
#include "../lib/utils.h"
#include "../common.h"

int main(){
    printf("=> TESTEANDO Conjunto.h (ABB de int)\n");
    Conjunto c1; ConjuntoCreate(c1);
    ConjuntoAddValue(c1, 3);
    ConjuntoAddValue(c1, 17);
    ConjuntoAddValue(c1, 2);
    ConjuntoAddValue(c1, 9);
    ConjuntoAddValue(c1, 4);
    ConjuntoShow(c1);nl();
    Conjunto c2; ConjuntoCreate(c2);
    ConjuntoAddValue(c2, 4);
    ConjuntoAddValue(c2, 5);
    ConjuntoAddValue(c2, 4);
    ConjuntoAddValue(c2, 2);
    ConjuntoAddValue(c2, 11);
    ConjuntoAddValue(c2, 4);
    ConjuntoShow(c2);nl();
    Conjunto c3; ConjuntoCreate(c3);
    ConjuntoUnion(c1, c2, c3);
    printf("union = ");
    ConjuntoShow(c3); nl();
    Conjunto c4; ConjuntoCreate(c4);
    ConjuntoIntersection(c2, c1, c4);
    printf("intersection = ");
    ConjuntoShow(c4); nl();
    Conjunto c5; ConjuntoCreate(c5);
    ConjuntoDifference(c3, c4, c5);
    printf("difference = ");
    ConjuntoShow(c5); nl();
    printf("included = ");
    printBool(ConjuntoIncluded(c4, c2));nl();
    printf("equals = ");
    printBool(ConjuntoEquals(c4, c2));nl();
    printf("member = ");
    printBool(ConjuntoMember(c3, 11));nl();
    ConjuntoSave("pepe.txt", c3);



    getchar();
    return 0;
}
