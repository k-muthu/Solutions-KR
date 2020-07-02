#include<stdio.h>

/*
This program implements invert(x, p, n).
x - the number whose bits is to be inverted
p - the start position 
n - th number of bits to be inverted
*/

int invert(int x, int p, int n);

int main(){
    int x = 103;
    int p = 4;
    int n = 2;
    printf("%d\n", invert(x, p, n));
    return 0;
}

int invert(int x, int p, int n){
    return (x & ~(~(~0<<n) << (p + 1 - n))) | (~x & (~(~0<<n) << (p + 1 - n)));
}