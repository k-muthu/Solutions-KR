#include<stdio.h>

/*
This program implements rightrot(x, n).
x - the number to be right rotated
n - the number of bits to be right rotated
*/

int rightrot(int x, int n);

int main(){
    int x = 103;
    int n = 3;
    printf("%d\n", rightrot(x, n));
    return 0;
}

int rightrot(int x, int n){
    int all_ones = ~0;
    int left_shifted_by_n = all_ones << n;
    int to_be_rotated = x & ~left_shifted_by_n;
    int no_of_shifts = 0;
    int temp = x >> n;
    while(temp != 0){
        temp = temp >> 1;
        ++no_of_shifts;
    }
    return (to_be_rotated << no_of_shifts) | (x >> n);
}
