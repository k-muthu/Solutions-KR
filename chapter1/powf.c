#include<stdio.h>

/*
This program calculates m to the nth power
where both m and n are integers
*/

int power(int base, int n);

int main(){
    int i;
    for(i = 0; i < 10; i++){
        printf("i : %d, power(2,i) : %d\n", i, power(2,i));
    }
    return 0;
}

int power(int base, int n){
    int result = 1,i;
    for(i = 1; i < n+1; i++){
        result = result * base;
    }
    return result;
}