#include "file.h"

void AgregarFolios(string nomArch, Folios folios)
{
    FILE * file = fopen(nomArch, "wb");
    AgregarFolio(folios, file);
    fclose(file);
}

void AgregarFolio(Folios folios, FILE * file)
{
    if (folios != NULL)
    {
        BajarFolio(folios->info, file);
        AgregarFolio(folios->hizq, file);
        AgregarFolio(folios->hder, file);
    }
}

void BajarFolio(Folio folio, FILE * file)
{
    Bajar_Int(folio.codigo, file);
    Bajar_String(folio.caratula, file);
    Bajar_String(folio.nombre, file);
    Bajar_String(folio.apellido, file);
    Bajar_Int(folio.expedientes, file);
}

void LevantarFolios(Folios &a, string nomArch)
{
    FILE * file = fopen (nomArch,"rb");
    Folio * buffer = new Folio;

    LevantarFolio(*buffer, file);

    while (!feof(file))
    {
        AgregarNodoFolio(a, *buffer);
        buffer = new Folio;
        LevantarFolio(*buffer, file);
    }
    fclose(file);
}

void LevantarFolio(Folio &folio, FILE * file)
{
    Levantar_Int(folio.codigo, file);
    Levantar_String(folio.caratula, file);
    Levantar_String(folio.nombre, file);
    Levantar_String(folio.apellido, file);
    Levantar_Int(folio.expedientes, file);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void AgregarRevs(string nomArch, Revisiones revs)
{
    FILE * file = fopen(nomArch, "wb");
    AgregarRev(revs, file);
    fclose(file);
}

void AgregarRev(Revisiones revs, FILE * file)
{
    if (revs != NULL)
    {
        BajarRev(revs->info, file);
        AgregarRev(revs->sig, file);
    }
}

void BajarRev(Revision rev, FILE * file)
{
    Bajar_Date(rev.fecha, file);
    Bajar_String(rev.descripcion, file);
    Bajar_Int(rev.folio, file);
    Bajar_Enum(rev.evaluacion, file);
}

void LevantarRevs(Revisiones &r, string nomArch)
{
    FILE * file = fopen (nomArch,"rb");
    Revision * buffer = new Revision;

    LevantarRev(*buffer, file);

    while (!feof(file))
    {
        AgregarRevision(r, *buffer);
        buffer = new Revision;
        LevantarRev(*buffer, file);
    }
    fclose(file);
}

void LevantarRev(Revision &r, FILE * file)
{
    Levantar_Date(r.fecha, file);
    Levantar_String(r.descripcion, file);
    Levantar_Int(r.folio, file);
    Levantar_Enum(r.evaluacion, file);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool Existe(string nomArch)
{
    FILE * f = fopen(nomArch, "rb");
    FILE * g = f;
    if (g != NULL)
    {
        fclose(f);
    }
    return g != NULL;
}

bool Vacio(string nomArch)
{
    FILE * f = fopen(nomArch, "rb");
    int buffer;
    bool vacio;
    fread(&buffer, sizeof(int), 1, f);
    vacio = feof(f);
    fclose(f);
    return vacio;
}

bool Pertenece (string nomArch, int entero)
{
    FILE * f = fopen(nomArch, "rb");
    int buffer;
    bool found = false;
    fread(&buffer, sizeof(int), 1, f);
    while (!found && !feof(f))
    {
        if (buffer == entero)
            found = true;
        else
            fread(&buffer, sizeof(int), 1, f);
    }
    return found;
}

long Largo(string nomArch)
{
    FILE * f = fopen(nomArch, "rb");
    fseek(f, 0, SEEK_END);
    long totalBytes = ftell(f);
    fclose(f);
    return totalBytes/sizeof(int);
}

int K_esimo(string nomArch, int k)
{
    int buffer;

    FILE * f = fopen(nomArch, "rb");
    fseek(f, (sizeof(int)*(k - 1)) , SEEK_SET);
    fread(&buffer, sizeof(int), 1, f);
    fclose(f);

    return buffer;
}

void Bajar_String (string s, FILE * f)
{
    int i = 0;
    while (s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}

void Levantar_String (string &s, FILE * f)
{
    string aux;
    strcrear(aux);

    int i = 0;
    char buffer;
    fread(&buffer, sizeof(char), 1, f);
    while (buffer != EOS && !feof(f))
    {
        aux[i] = buffer;
        fread(&buffer, sizeof(char), 1, f);
        i++;
    }
    aux[i] = EOS;

    strcop(s, aux);
    strdestruir(aux);
}


void Bajar_Long(long int entero, FILE * f)
{
    fwrite(&entero, sizeof(long int), 1, f);
}

void Bajar_Int(int entero, FILE * f)
{
    fwrite(&entero, sizeof(int), 1, f);
}

void Bajar_Enum(Evaluacion e, FILE * f)
{
    fwrite(&e, sizeof(Evaluacion), 1, f);
}

void Bajar_Date(date fecha, FILE * f)
{
    fwrite(&fecha.day, sizeof(int), 1, f);
    fwrite(&fecha.month, sizeof(int), 1, f);
    fwrite(&fecha.year, sizeof(int), 1, f);
}

void Levantar_Date(date &fecha, FILE * f)
{
    fread(&fecha.day, sizeof(int), 1, f);
    fread(&fecha.month, sizeof(int), 1, f);
    fread(&fecha.year, sizeof(int), 1, f);
}

void Levantar_Enum(Evaluacion &e, FILE * f)
{
    fread(&e, sizeof(Evaluacion), 1, f);
}

void Levantar_Int (int &entero, FILE * f)
{
    fread(&entero, sizeof(int), 1, f);
}
