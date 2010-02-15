#include "string_extended.h"

void strsplit(string str, char c, ListaString &l){
    bool scanning = false;
    string buffer;
    int i = 0;
    while(str[i] != EOS){
        if(str[i] == c && str[i]){
            if(scanning){
                ListaStringInsBack(l, buffer);
                scanning = false;
                strdestruir(buffer);
            }
        }else{
            if(!scanning){
                strcrear(buffer);
                scanning = true;
            }
            straddchar(buffer, str[i]);
        }
        i ++;
    }
    if(scanning)
        ListaStringInsBack(l, buffer);
}
