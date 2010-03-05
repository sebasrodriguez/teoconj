#include "file.h"

void fbajarInt (int entero, ffile f){
    fwrite(&entero, sizeof(int), 1, f);
}

void fbajarLong(long int entero, ffile f){
    fwrite(&entero, sizeof(long int), 1, f);
}

void flevantarInt (int &entero, ffile &f)
{
    fread(&entero, sizeof(int), 1, f);
}

bool fexists(string name){
    ffile f = fopen(name, "rb");
    ffile g = f;
    if (g != NULL)
    {
        fclose(f);
    }
    return g != NULL;
}
