#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
//config de la aplicacion
//aca van los parametros globales a toda a aplicacion
#include <stdio.h>
#include "lib/string.h"
#include "lib/utils.h"


const string CONSOLE_PROMPT = "TC>: ";
const string CONSOLE_RESULT_PROMPT = "";
const string CONSOLE_ERROR_PROMPT = "!ERROR: ";

const string DATA_FILE_PATH = "data/";
const string DATA_FILE_EXTENSION = "teoconj";

const string ERROR_WRONG_PARAMS = "Parametros Incorrectos";
const string ERROR_WRONG_COMMAND = "El comando no existe";
const string ERROR_WRONG_ID  = "El conjunto no existe en la lista";
const string ERROR_WRONG_FILENAME = "El archivo no existe";

const string MESSAGE_EMPTY_LIST = "La lista de conjuntos esta vacia";
const string MESSAGE_EXIT = "Hasta la proxima!";
const string MESSAGE_TRUE = "true";
const string MESSAGE_FALSE = "false";
const string MESSAGE_PRE_C = "c%d = ";
const string MESSAGE_SAVED = "c%d almacenado correctamente en %s";

const string Q_REPLASE = "Ya existe un archivo con ese nombre, ¿desea reemplazarlo?";

void printError(string s);

void getFilePath(string name, string &s);

bool confirm(string question);

#endif
