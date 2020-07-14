#include<stdio.h>
#include<limits.h>

#define MAXLINE 1000

/*
This program implements myitoa(int n, char s[], int width).
Converts a given integer to a string with the given width size.
*/

void myitoa(int n, char s1[], int width);
int mystrlen(char s[]);
void reverse(char s[]);
int positive(int n);

int main(){
    int n = 456;
    int width = 10;
    char s1[MAXLINE];
    myitoa(n, s1, width);
    printf("%s\n", s1);
    return 0;
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

int positive(int n){
    return (n > 0) ? n : -n;
}

void myitoa(int n, char s1[], int width){
    int j, sign;
    sign = n;

    j = 0;
    do {
        s1[j++] = positive(n % 10) + '0';
        --width;
    }while((n /= 10) > 0);

    if(sign < 0){
        s1[j++] = '-';
        --width;
    }
        
    while(width--){
        s1[j++] = ' ';
    }

    s1[j] = '\0';
    reverse(s1);    
}
