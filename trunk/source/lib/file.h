#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include<stdio.h>

typedef FILE * ffile;

void fbajarInt (int entero, ffile f );

void fbajarLong(long int entero, ffile f);

void flevantarInt (int &entero, ffile &f);

#endif // FILE_H_INCLUDED
