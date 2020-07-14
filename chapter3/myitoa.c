#include<stdio.h>
#include<limits.h>

#define MAXLINE 1000

/*
This program implements myitoa(int n, char s[]).
Converts a given integer to a string
*/

void myitoa(int n, char s1[]);
int mystrlen(char s[]);
void reverse(char s[]);
int positive(int n);

int main(){
    int n = ~(1 << 31) + 1;
    char s1[MAXLINE];
    myitoa(n, s1);
    printf("%s\n", s1);
    return 0;
}

int positive(int n){
    return (n > 0) ? n : -n;
}

int mystrlen(char s[]){
    int len = 0;
    for(len = 0; s[len] != '\0'; ++len);
    return len;
}

void reverse(char s[]){
    int len = mystrlen(s);
    int forward, backward, c;
    for(forward = 0, backward = len - 1; forward < backward; ++forward, --backward){
        c = s[forward];
        s[forward] = s[backward];
        s[backward] = c;
    }
}

/* 
In C, % is defined as the remainder operator
and according to C99 standard it is defined to be
a == ((a/b) * b) + (a % b)
*/
void myitoa(int n, char s1[]){
    int j, sign;
    sign = n;

    j = 0;
    do {
        s1[j++] = positive(n % 10) + '0';
    }while(n /= 10);

    if(sign < 0)
        s1[j++] = '-';

    s1[j] = '\0';
    reverse(s1);
}
