#include<stdio.h>

/* 
prints the fahrenheit celsius conversion 
from 0 F to 300 F but using a for loop
*/
#define LOWER 0 //Lower limit
#define UPPER 300   //Upper limit
#define STEP 20 //Step value
int main(){
    int fahr;
    for(fahr = LOWER; fahr <= UPPER; fahr += STEP){
        printf("%3d\t%6.1f\n",fahr,(5.0/9.0)*(fahr-32));
    }
    return 0;
}