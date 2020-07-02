#include<stdio.h>

/*
This program prints the number of occurences 
of each digit, whitespace(blanks, tabs, newlines) 
and other characters in the given input
*/

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for(i = 0; i < 10; i++){
        ndigit[i] = 0;
    }
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            ++nwhite;
        }
        else if(c >= '0' && c <= '9'){
            ++ndigit[c - '0'];
        }
        else
            ++nother;
    }
    printf("The occurence of each digit is : ");
    for(i = 0; i < 10; i++){
        printf("%d ", ndigit[i]);
    }
    printf("\nThe number of whitespace characters: %d\n", nwhite);
    printf("The number of other characters: %d\n", nother);
    return 0;
}