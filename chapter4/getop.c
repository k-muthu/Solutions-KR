#include <ctype.h>
#include<stdio.h>
#include "calc.h"

int functions(char s[]);
int compare(char s1[], char s2[]);

double variables[27];
int var_set[26];
int initialize = -1;

int getop(char s[]){
    int i, c;
    static int buffer = -1;
    initialize = -1;
    if(buffer != -1){
        s[0] = c = buffer;
        buffer = -1;
    }
    else{
        s[0] = c = getch();
    }

    while(c == ' ' || c == '\t'){
        s[0] = c = getch();
    }
    s[1] = '\0';
    if(isalpha(c)){
        i = 0;
        while(isalpha(s[++i] = c = getch()));
        if(c == '=' && i == 1){
            initialize = s[0] - 'a';
            s[0] = c = getch();    
        }
        else if(c == ' ' && i == 1){
            initialize = s[0] - 'a';
            s[1] = '\0';
            return VARIABLE;
        }
        else{
            buffer = c;
            s[i] = '\0';
            return functions(s);
        }
    }
    if(c == '-'){
        c = getch();
        buffer = c;
        if(!isdigit(c)){    /* To check if there is a negative number */
            return '-';
        }
    }

    if(!isdigit(c) && c != '.' && c!= '-')
        return c;

    i = (c == '-') ? 1 : 0;
    if(isdigit(c) || c == '-'){
        if(buffer != -1){
            s[++i] = buffer;
            buffer = -1;
        }
        while(isdigit(s[++i] = c = getch()));
    }

    if(c == '.')
        while(isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if(c != EOF)
        buffer = c;
    
    if(initialize >= 0 && initialize <= 26){
        return VARIABLE;
    }

    return NUMBER;
}

/* compare : a simple version of the library function strcmp */
int compare(char s1[], char s2[]){
    int i, j;
    i = j = 0;
    while((tolower(s1[i]) == tolower(s2[j])) && s1[i] != '\0' && s2[j] != '\0'){
        ++i;
        ++j;
    }
    if(!i && !j)
        return -1;  /* Both strings are emoty */
    else if(s1[i] == '\0' && s2[j] == '\0')
        return 1;
    else
        return 0;

}

int functions(char s[]){
    int type;
    if(compare(s, "sin") > 0)
        return '1';
    if(compare(s, "exp") > 0)
        return '2';
    if(compare(s, "pow") > 0)
        return '3';
    if(compare(s, "clearvariables") > 0)
        return '4';
    if(compare(s, "printtop") > 0)
        return '5';
    if(compare(s, "clearstack") > 0)
        return '6';
    if(compare(s, "swaptop2") > 0)
        return '7';
    if(compare(s, "duplicatestack") > 0)
        return '8';
    
    return -1;
}
