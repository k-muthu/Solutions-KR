#include<stdio.h>

/*
This program implements lowercase(c)
using conditional expression
*/

int lowercase(int c);

int main(){
    int c;
    while((c = getchar()) != EOF){
        putchar(lowercase(c));
    }
    return 0;
}

int lowercase(int c){
    return (c >= 'A' && c <= 'Z') ? ('a' + c - 'A') : c;
}