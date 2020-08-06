#include <stdio.h>

#define MAX 1000

/* function strcat assumes that s has enough space to store t */
void mystrcat(char *s, char *t);

int main(){
    char s1[MAX] = "This program appends string";
    char s2[MAX] = " t to string s";
    mystrcat(s1, s2);
    printf("Result after appending : %s\n", s1);
    return 0;
}

void mystrcat(char *s, char *t){
    while(*s++);
    --s;
    while((*s++ = *t++));
}