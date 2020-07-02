#include<limits.h>
#include<stdio.h>
#include<float.h>

/*
This program calculates the range of 
basic data types and the range when
qualifiers are applied to it
*/

int main(){
    printf("Calculating ranges using symbolic constans from headers\n");
    printf("Char Max : %d\n", CHAR_MAX);
    printf("Char Min : %d\n", CHAR_MIN);
    printf("Unsigned Char Max : %d\n", UCHAR_MAX);
    printf("Signed Char Max : %d\n", SCHAR_MAX);
    printf("Signed Char Min : %d\n", SCHAR_MIN);
    printf("Integer Max : %d\n", INT_MAX);
    printf("Integer Min : %d\n", INT_MIN);
    printf("Unsigned Integer Max : %u\n", UINT_MAX);
    printf("Short Integer Max : %d\n", SHRT_MAX);
    printf("Short Integer Min : %d\n", SHRT_MIN);
    printf("Unsigned Short Integer Max : %d\n", USHRT_MAX);
    printf("Long Integer Max : %ld\n", LONG_MAX);
    printf("Ling Integer Min : %ld\n", LONG_MIN);
    printf("Unsigned Long Integer Max : %lu\n", ULONG_MAX);

    unsigned int var = 1;
    unsigned int result = 1;
    while(var > 0){
        result = var;
        ++var;
    }
    printf("Calculation by direct Computation\n");
    printf("Unsigned Long Int Max : %u\n", result);
    return 0;
}