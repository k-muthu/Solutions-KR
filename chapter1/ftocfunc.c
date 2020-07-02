#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
/*
This program calculates the temperature in 
Celsius given the temperature in Fahrenheit 
as input using a function
*/

float converter(float f);

int main(){
    int i;
    for(i = LOWER; i < UPPER; i += STEP){
        printf("Fahrenheit : %3d degrees Celsius : %7.2f degrees\n", i, converter(i));
    }
    return 0;
}

float converter(float f){
    float c;
    return (5.0/9.0)*(f-32);
}