#include<stdio.h>

/*
This program replaces multiple continous spaces 
in input with a single space
*/

int main(){
    int c;
    int tru = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            if(tru == 0){
                putchar(c);
                tru = 1;
            }
        }
        if(c != ' '){
            putchar(c);
            tru = 0;
        }
    }
    return 0;
}