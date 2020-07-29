#include <stdio.h>

#define BUFFERSIZE 100

static char buffer[BUFFERSIZE];
static int bufp = 0;   /* The next free buffer index */

int getch(void){
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp < BUFFERSIZE)
        buffer[bufp++] = c;
    else
        printf("Too many characters pushed back.\n");
}