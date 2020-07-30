#include <stdio.h>

#define MAXLINE 100

void myitoa(int number, char s[]);

int main(){
    int number;
    number = -12345;
    char s[MAXLINE];
    myitoa(number, s);
    printf("%s\n", s);
    return 0;
}

void myitoa(int number, char s[]){
    static int i = 0;
    if(number < 0){
        s[i++] = '-';
        number = -number;
    }
    if(number / 10){
        myitoa(number / 10, s);
    }
    s[i++] = '0' + (number % 10);
    s[i] = '\0';
}