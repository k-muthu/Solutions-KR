#include<stdio.h>
#define IN 1
#define OUT 0
/*
This program counts the number of lines,
words and characters in the given input 
*/

int main(){
    int c,state;
    int word_count = 0, line_count = 0, character_count = 0;
    state = OUT;
    while((c = getchar()) != EOF){
        ++character_count;
        if(c == '\n')
            ++line_count;
        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            ++word_count;
        }
    }
    printf("The number of words %d\n",word_count);
    printf("The number of lines %d\n",line_count);
    printf("The number of characters %d\n",character_count);
    return 0;   
}