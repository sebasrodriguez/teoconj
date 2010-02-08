#include "utils.h"
void nl(){
    printf("%c", EOL);
}

void repeatChar(char c, int cant){
    for(int i = 0; i < cant; i ++){
        printf("%c", c);
    }
}
void tab(){
    printf("%c", TAB);
}
void tabs(int cant){
    repeatChar(TAB, cant);
}
void line(int size){
    nl();
    repeatChar('=', size);
    nl();
}

void printInt(int i){
    printf("%d", i);
}

void printFloat(float f){
    printf("%f", f);
}

bool optionOk(int option, int minRange, int maxRange){
    bool optOk = false;
    if(option >= minRange && option <= maxRange){
        optOk = true;
    }
    return optOk;
}

//Pregunta por una opcion hasta que la ingresada
//este dentro del rango dado
int getNumericOption(int minRange, int maxRange){
    int option;
    bool ok;
    do{
        fflush(stdin);
        scanf("%d", &option);
        ok = optionOk(option, minRange , maxRange);
        if(!ok){
            printf("Opcion no valida, ingrese nuevamente: ");
        }
    }
    while(!ok);
    return option;
}
