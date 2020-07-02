#include<stdio.h>

/*
This program converts a given string of numbers
into its decimal equivalent
*/

int myatoi(char number[]);

int main(){
    char number[] = "12345";
    printf("%d\n", myatoi(number));
}

int myatoi(char number[]){
    int result = 0;
    int i;
    for(i = 0; number[i] >= '0' && number[i] <= '9'; ++i){
        result = (result * 10) + (number[i] - '0');
    }
    return result;
}