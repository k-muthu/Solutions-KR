#include<stdio.h>
/* 
print a table consisting of fahrenheit values
and their respective Centigrade values in the adjacent column */

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  // Lower limit of temp table
    upper = 300;    //upper limit of temp table
    step = 20;  // value increaw for each row

    fahr = lower;
    printf("%3c\t%3c\n",'F','C');
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step; 
    }
    return 0;
}