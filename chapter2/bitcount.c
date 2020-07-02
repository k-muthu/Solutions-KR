#include<stdio.h>

/*
This program implements bitcount(n)
It orints the number of ones in binary
representation of n
*/

int bitcount(unsigned n);

int main(){ 
    int n = 127;
    printf("%d\n", bitcount(n));
}

int bitcount(unsigned n){
    int result = 0;
    while(n != 0){
        ++result;
        n &= (n - 1);
    }
    return result;
}

/*
considering a 2's complement notation,
n and n-1 differ by a value of 1
so say n = 0111 (7) -> n-1 = 0110
n & (n - 1) = 0110
n = 0110 and n-1 = 0101
n & (n - 1) = 0100
etc.
*/
