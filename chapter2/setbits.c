#include<stdio.h>

/*
This program implements the setbits(x, p, n, y) function.
x - the number whose bits are to be set
p - the position at which the bits are set
n - the number of bits to be set
y - the target number from which the bits are taken
*/

int setbits(int x, int p, int n, int y);

int main(){
    int x = 103;
    int p = 4;
    int n = 3;
    int y = 86;
    printf("%d\n", setbits(x, p, n, y));
    return 0;
}

int setbits(int x, int p, int n, int y){
    return (x & ~( ~(~0 << n) << (p + 1 - n) ) ) | ( (y & ~(~0 << n)) << (p + 1 - n) );
}