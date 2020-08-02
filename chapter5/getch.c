#include <stdio.h>

#define BUFFERSIZE 100

static int buffer[BUFFERSIZE];
static int bufp;    /* Next free buffer position */

void ungetch(int c){
    if(bufp < BUFFERSIZE)
        buffer[bufp++] = c;
    else
        printf("Too many characters pushed back\n");
}

int getch(void){
    return (bufp > 0) ? buffer[--bufp] : getchar();
}