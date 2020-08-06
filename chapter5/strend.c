#include <stdio.h>

int mystrcmp(char *s1, char *s2);
int mystrlen(char *s1);
int mystrend(char *s1, char *s2);

int main(){
    char s1[] = "This program checks if string t comes at the end of string t";
    char s2[] = "string t";
    printf("Result : %d\n", mystrend(s1, s2));
    return 0;
}

int mystrcmp(char *s1, char *s2){
    while(*s1 == *s2){
        if(*s1 == '\0')
            return 0;
        ++s1;
        ++s2;
    }
    return *s1 - *s2;
}

int mystrlen(char *s1){
    char *p;
    p = s1;

    while(*s1)
        ++s1;
        
    return s1 - p;
}

int mystrend(char *s1, char *s2){
    int s1_length, s2_length;

    s1_length = mystrlen(s1);
    s2_length = mystrlen(s2);

    if(s1_length >= s2_length)
        s1 += (s1_length - s2_length);

    return (mystrcmp(s1, s2)) ? 0 : 1;
}
