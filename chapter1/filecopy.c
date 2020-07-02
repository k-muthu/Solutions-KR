#include<stdio.h>

/*
This program reads all input and prints it 
onto the display as long as there exists a character
*/

int main(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
    printf("%d\n",EOF);
}