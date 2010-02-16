#include "arbolint.h"

void ArbolIntCreate(ArbolInt &a){
    a = NULL;
}

ArbolInt ArbolIntCons(int info, ArbolInt hizq, ArbolInt hder){
    ArbolInt a = new NodoArbolInt;
    a->info = info;
    a->hizq = hizq;
    a->hder = hder;
    return a;
}

void ArbolIntPreorden (ArbolInt a){
    if (a != NULL){
        printf("  %d", a->info);
        ArbolIntPreorden(a->hizq);
        ArbolIntPreorden(a->hder);
    }
}

void ArbolIntOrden (ArbolInt a){
    if (a != NULL){
        ArbolIntOrden(a->hizq);
        printf(" %d", a->info);
        ArbolIntOrden(a->hder);
    }
}

void ArbolIntPosorden (ArbolInt a){
    if (a != NULL){
        ArbolIntPosorden(a->hizq);
        ArbolIntPosorden(a->hder);
        printf(" %d", a->info);
    }
}

int ArbolIntCount (ArbolInt a){
    int cont = 0;
    if (a != NULL){
        cont = 1;
        cont += ArbolIntCount(a->hizq);
        cont += ArbolIntCount(a->hder);
    }
    return cont;
}

bool ArbolIntPertenece (ArbolInt a, int valor){
    bool found = false;
    while (a != NULL && found != true){
        if (a->info == valor){
            found = true;
        }else
            if (a->info > valor){
                a = a->hizq;
            }else
                if (a->info < valor){
                    a = a->hder;
                }
    }
    return found;
}

void ArbolIntDelete (ArbolInt a){
    if (a != NULL){
        ArbolIntDelete(a->hizq);
        ArbolIntDelete(a->hder);
        delete(a);
    }
    a = NULL;
}

void ArbolIntCopy(ArbolInt &a, ArbolInt b){
    if(b != NULL){
        ArbolIntCopy(a->hizq, b->hizq);
        a->info = b->info;
        ArbolIntCopy(a->hizq, b->hder);
    }
}

void ArbolIntAdd(ArbolInt &a, int valor){
    if (a == NULL)
        a = ArbolIntCons(valor, NULL, NULL);
    else if (a->info > valor)
        ArbolIntAdd(a->hizq, valor);
    else if (a->info < valor)
        ArbolIntAdd(a->hder, valor);
}

