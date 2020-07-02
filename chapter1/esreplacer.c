#include<stdio.h>

/*
This program replaces tabs, backspace, 
backslash by their escape sequence notations
*/

int main(){
    int c;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }
        if(c == '\b'){
            putchar('\\');
            putchar('b');
        }
        if(c == '\\'){
            putchar('\\');
            putchar('\\');
        }
        if(c != '\t')
            if(c != '\b')
                if(c != '\\')
                    putchar(c);
    }
    return 0; 
}