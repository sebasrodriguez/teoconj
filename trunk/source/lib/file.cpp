#include "file.h"

void fbajarInt (int entero, ffile f){
    fwrite(&entero, sizeof(int), 1, f);
}

void fbajarLong(long int entero, ffile f){
    fwrite(&entero, sizeof(long int), 1, f);
}

void flevantarInt (int &entero, FILE * f)
{
    fread(&entero, sizeof(int), 1, f);
}
