#include<stdio.h>
#include<limits.h>

#define MAXLINE 1000
#define MIN 1
#define NOTMIN 0

/*
This program implements myitoa(int n, char s[]).
Converts a given integer to a string
*/

void myitoa(int n, char s1[]);
int mystrlen(char s[]);
void reverse(char s[]);

int main(){
    int n = ~(1 << 31) + 1;
    char s1[MAXLINE];
    myitoa(n, s1);
    printf("%s\n", s1);
    return 0;
}

void myitoa(int n, char s1[]){
    int j, sign, state = NOTMIN;
    if(n == INT_MIN){
        n = INT_MAX;
        sign = -1;
        state = MIN;
    }
    else if(n < 0){
        sign = -1;
        n = -n;
    }
    else
        sign = 1;

    j = 0;
    do {
        s1[j++] = (n % 10) + '0';
    }while((n /= 10) > 0);

    if(state){
        ++s1[0];
    }

    if(sign == -1)
        s1[j++] = '-';

    s1[j] = '\0';
    reverse(s1);
    
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
