#include<stdio.h>

/*
This program counts the number of lines
in a given input stream
*/

int main(){
    int c;
    double count = 0;
    while((c = getchar()) != EOF){
        if(c == '\n')
            ++count;
    }
    printf("The total number of lines were %.0f \n", count);
    return 0;
}