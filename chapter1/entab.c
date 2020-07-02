#include<stdio.h>

#define TABSTOP 8
#define INS 1   /*Flag for inside series of blanks*/
#define ONS 0
/*
This program replaces spaces using 
a combination of spaces and tabs
*/

int main(){
    int c;
    int state = ONS;
    int column = 0;
    int count = 0;
    while((c = getchar()) != EOF){
        ++column;
        if(c == ' ' && state == ONS){
            if(column == TABSTOP)
                putchar(c);
            else{
                state = INS;
                ++count;
            }
        }
        else if(c == ' ' && state == INS){
            ++count;
            if(column == TABSTOP){
                putchar('\t');
                column = 0;
                count = 0;
                state = ONS;  
            }
        }
        else{
            while(count > 0){
                putchar(' ');
                --count;
            }
            putchar(c);
            state = ONS;
            count = 0;
            if(c == '\n' || c== '\t' || column == TABSTOP)
                column = 0;
        }
    }
    return 0;
}