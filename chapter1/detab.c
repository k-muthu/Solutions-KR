#include<stdio.h>

#define TABSTOP 8

/*
This program deals with replacing 
tabs with appropriate number of spaces
*/

int main(){
    int c, count, i;
    count = 0;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            i = TABSTOP - count;
            while(i > 0){
                putchar(' ');
                --i;
            }
            count = 0;
        }
        else{
            ++count;
            putchar(c);
            if(count == TABSTOP || c = '\n')
                count = 0;
        }

    }
    return 0;
}
