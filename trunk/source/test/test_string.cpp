#include <iostream>
#include <stdio.h>
#include "../lib/string.h"


void split(string str, char c){
    bool scanning = false;
    string buffer;
    int i = 0;
    while(str[i] != EOS){
        if(str[i] == c){
            if(scanning){
                print(buffer);printf("\n");
                scanning = false;
                strdestruir(buffer);
            }
        }else{
            if(!scanning){
                strcrear(buffer);
                scanning = true;
            }
            printf("%c", str[i]);
            straddchar(buffer, str[i]);
        }
        i ++;
    }
    //printf("%d", aux);
}


int main(){
    string str ;
    strcrear(str);
    strcop(str, "HOLA PETECO COMO ESTAS YO BIEN");
    split(str, ' ');
    return 0;
}
