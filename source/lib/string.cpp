#include "string.h"

void strcrear(string &s){
    s = new char[1];
    s[0] = EOS;
}

void strdestruir(string &s){
    delete [] s;
    s = NULL;
}

int strlar(string s){
    int i = 0;
    while (s[i] != EOS)
        i++;
    return i;
}

void strcop(string &s, string t){
    s = new char[strlar(t) + 1];
    int i = 0;
    while (t[i] != EOS){
        s[i] = t[i];
        i++;
    }
    s[i] = EOS;
}

void scan(string &s){
    char l, * a = new char[CHAR_MAX];
    int i = 0;
    fflush(stdin);
    scanf("%c", &l);
    while (l != EOL && i < CHAR_MAX - 1){
        a[i] = l;
        i++;
        scanf("%c", &l);
    }
    a[i] = EOS;
    strcop(s, a);
    strdestruir(a);
}

void strcon(string &s, string t){
    int i = strlar(s), j = 0;
    while (i < CHAR_MAX - 1 && t[j] != EOS){
        s[i] = t[j];
        i++;
        j++;
    }
    s[i] = EOS;
}

void strswp(string &s, string &t){
    string aux;
    strcrear(aux);
    strcop(aux, s);
    strcop(s, t);
    strcop(t, aux);
}

void print(string s){
    int i = 0;
    while (s[i] != EOS){
        printf("%c", s[i]);
        i++;
    }
}

void strtolower(string &s){
    int i = 0;
    while (s[i] != EOS){
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] += 32;
        i ++;
    }
}

bool strmen(string s, string t){
    string aux1;
    string aux2;
    strcrear(aux1);
    strcrear(aux2);
    strcop(aux1, s);
    strcop(aux2, t);
    strtolower(aux1);
    strtolower(aux2);
    int i = 0;
    while (aux1[i] == aux2[i] && aux1[i] != EOS && aux2[i] != EOS)
        i++;
    return (aux1[i] <= aux2[i]);
}

bool streq(string s, string t){
    string aux1;
    string aux2;
    strcrear(aux1);
    strcrear(aux2);
    strcop(aux1, s);
    strcop(aux2, t);
    strtolower(aux1);
    strtolower(aux2);
    int i = 0;
    while (aux1[i] == aux2[i] && aux1[i] != EOS && aux2[i] != EOS)
        i++;
    return (aux1[i] == aux2[i]);
}

void straddchar(string &s, char c){
    string t = new char[strlar(s) + 2];
    int i = 0;
    while (s[i] != EOS){
        t[i] = s[i];
        i++;
    }
    t[i] = c;
    i ++;
    t[i] = EOS;
    strcop(s, t);
}

void strclear(string &s){
    strcop(s, "");
}

void strcrearmax(string &s){
    s = new char[CHAR_MAX];
    s[0] = EOS;
}
