#include "common.h"

void printError(string s){
    printf(CONSOLE_ERROR_PROMPT);
    printf(s);
    nl();nl();
}

void printBool(bool b){
    if(b)
        printf(MESSAGE_TRUE);
    else
        printf(MESSAGE_FALSE);
}

void getFilePath(string name, string &s){
    string path;
    strcop(path, DATA_FILE_PATH);
    strcon(path, name);
    strcon(path, ".");
    strcon(path, DATA_FILE_EXTENSION);
    strcop(s, path);
}

bool confirm(string question){
    bool r = false;
    printf(question);
    printf(" y/n, (Enter=y): ");
    char c;
    scanf("%c", &c);
    if(c == 'y' || c == EOL)
        r = true;
    return r;
}
