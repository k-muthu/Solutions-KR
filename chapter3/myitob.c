#include<stdio.h>
#include<limits.h>

#define MAXLINE 1000

/*
This program implements myitob(int n, char s[], int b).
Converts a given integer in base 10 to a string 
representaion of the integer in base b.
*/

void myitob(int n, char s[], int base);
void reverse(char s[]);
int mystrlen(char s[]);
int positive(int n);

int main(){
    int base, n;
    char s[MAXLINE];
    n = INT_MIN;
    base = 16;
    myitob(n, s, base);
    printf("%s\n", s);
    return 0;
}

int mystrlen(char s[]){
    int len;
    for(len = 0; s[len] != '\0'; ++len);
    return len;
}

void reverse(char s[]){
    int c;
    int i, j;
    for(i = 0, j = mystrlen(s) - 1; i < j; ++i, --j){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int positive(int n){
    return (n > 0) ? n : -n;
}

void myitob(int n, char s[], int base){
    int j, c, sign;
    sign = n;

    j = 0;
    do {
        c = positive(n % base) + '0';
        s[j++] = (c > '9') ? (c + 'A' - '9' - 1) : c; 

    }while(n /= base);
    
    if(sign < 0)
        s[j++] = '-';

    s[j] = '\0';
    reverse(s);    
}
