#include <stdio.h>
#include <ctype.h>
#include "getch.h"

#define MAX 100

int getint(int *num); 

int main(){
    int number, status;
    while((status = getint(&number)) != 0){
        printf("The next number in input : %d\n", number);
        if(status == -1)
            break;
    }
    return 0;
}

int getint(int *num){
    int status = 0, c, sign;

    while((c = getch()) == ' ' || c == '\t');   /* skip whitespaces */

    if(!isdigit(c) && c != '-' && c != '+' && c != EOF){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if(c == '-' || c == '+')
        c = getch();

    if(!isdigit(c)){    /* To push back an invalid character after '+' or '-' character */
        ungetch(c);
        return 0;
    }
    *num = 0;
    while(isdigit(c)){
        *num = 10 * (*num) + (c - '0');
        c = getch();
    }
    *num *= sign;

    if(c != EOF)
        ungetch(c);

    return c;
}