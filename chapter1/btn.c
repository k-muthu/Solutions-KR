#include<stdio.h>
 
/*
This program counts the number of
blanks, tabs, newlines in a given
input stream
*/

int main(){
    int blanks = 0, lines = 0, tabs = 0;
    int c;
    while((c = getchar()) != EOF){
        if(c == ' ')
            ++blanks;
        else if(c == '\n')
            ++lines;
        else if(c == '\t')
            ++tabs;
    }
    printf("The total number of lines are %d\n", lines);
    printf("The total number of blanks are %d\n", blanks);
    printf("The total number of tabs are %d\n", tabs);
}