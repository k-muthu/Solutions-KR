#include<stdio.h>

#define IN 1
#define OUT 0

/*
This program prints all the contents of the input
into separate lines each consisting one word
*/

int main(){
    int c, state, word_found;
    state = OUT;
    word_found = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c== '\n'){
            state = OUT;
            if(word_found != 0){
                putchar('\n');
            }
        }
        else{
            putchar(c);
            if(state == OUT){
                state = IN;
                word_found = 1;
            }
        }
    }
    return 0;
}