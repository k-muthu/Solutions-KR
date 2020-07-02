#include<stdio.h>

/*
Counts the number of characters 
in a given input
*/

int main(){
    long count;
    count = 0;
    while(getchar() != EOF){
        count += 1;
    }
    printf("The total number of characters were %ld\n",count);
    return 0;
}