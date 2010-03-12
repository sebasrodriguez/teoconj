#include "utils.h"
void nl()
{
    printf("%c", EOL);
}

void repeatChar(char c, int cant)
{
    for (int i = 0; i < cant; i ++)
    {
        printf("%c", c);
    }
}
void tab()
{
    printf("%c", TAB);
}
void tabs(int cant)
{
    repeatChar(TAB, cant);
}
void line(int size)
{
    nl();
    repeatChar('=', size);
    nl();
}

void printInt(int i)
{
    printf("%d", i);
}

void printFloat(float f)
{
    printf("%f", f);
}
