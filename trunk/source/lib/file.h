#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

/*

void AgregarFolios(string nomArch, Folios folios);

void AgregarFolio(Folios folios, FILE * file);

void LevantarFolios(Folios &a, string nomArch);

void BajarFolio(Folio folio, FILE * file);

void LevantarFolio(Folio &folio, FILE * file);

void AgregarRevs(string nomArch, Revisiones revs);

void AgregarRev(Revisiones revs, FILE * file);

void BajarRev(Revision rev, FILE * file);

//Determina si existe un archivo con el nombre recibido por par�metro
bool Existe(string nomArch);

//Determina si el archivo esta vac�o o no. Precondici�n: El archivo existe
bool Vacio(string nomArch);

//Determina si el entero recibido est� en el archivo. Precondici�n: El archivo existe
bool Pertenece (string nomArch, int entero);

//Devuelve la cantidad de enteros almacenados en el archivo. Precondici�n: El archivo existe
long Largo(string nomArch);

//Devuelve el k-�simo entero almacendado en el archivo.Precondici�n: El archivo existe y su largo es >= k.
int K_esimo(string nomArch, int k);


void Bajar_String (string s, FILE * f);


void Levantar_String (string &s, FILE * f);

void Bajar_Long(long int entero, FILE * f);

void Bajar_Int(int entero, FILE * f);

void Bajar_Enum(Evaluacion e, FILE * f);

void Bajar_Date(date fecha, FILE * f);

void LevantarRevs(Revisiones &r, string nomArch);

void LevantarRev(Revision &r, FILE * file);

void Levantar_Date(date &fecha, FILE * file);

void Levantar_Enum(Evaluacion &e, FILE * f);

void Levantar_Int (int &entero, FILE * f);

*/

#endif // FILE_H_INCLUDED
