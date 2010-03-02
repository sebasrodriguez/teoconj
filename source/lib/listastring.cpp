#include "listastring.h"

void ListaStringCreate(ListaString &lista){
    lista = NULL;
}

bool ListaStringEmpty(ListaString lista){
    return (lista == NULL);
}

void ListaStringInsFront(ListaString &lista, string valor){
    ListaString aux = new NodoListaString;
    strcop(aux->info, valor);
    aux->sig = lista;
    lista = aux;
}

void ListaStringFirst(ListaString lista, string first){
    strcop(first, lista->info);
}

void ListaStringResto(ListaString &lista){
    ListaString aux = lista;
    lista = lista->sig;
    delete(aux);
}

int ListaStringCount(ListaString lista){
    int largo = 0;
    while (lista != NULL)    {
        lista = lista->sig;
        largo++;
    }
    return largo;
}

void ListaStringShow(ListaString lista){
    int i = 0;
    while (lista != NULL)    {
        print(lista->info);
        lista = lista->sig;
        i++;
    }
}

void ListaStringInsBack(ListaString &lista, string valor){
    if (lista == NULL){
        ListaStringInsFront(lista, valor);
    }else if (lista->sig == NULL){
        ListaStringInsFront(lista->sig, valor);
    }else{
        ListaStringInsBack(lista->sig, valor);
    }
}

void ListaStringSplit(string str, char c, ListaString &l){
    bool scanning = false;
    string buffer;
    int i = 0;
    while(str[i] != EOS){
        if(str[i] == c){
            if(scanning){
                ListaStringInsBack(l, buffer);
                scanning = false;
                strdestruir(buffer);
            }
        }else{
            if(!scanning){
                strcrearmax(buffer);
                scanning = true;
            }
            straddchar(buffer, str[i]);
        }
        i ++;
    }
    //TODO: eliminar buffer
    if(scanning)
        ListaStringInsBack(l, buffer);
}
