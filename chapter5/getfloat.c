#include <stdio.h>
#include <ctype.h>
#include "getch.h"

int getfloat(double *num);
double mypow(double base, double power);

int main(){
    double number;
    int status;
    while((status = getfloat(&number)) != 0){
        printf("The next number in input : %g\n", number);
        if(status == -1)
            break;
    }
    return 0;
}

int getfloat(double *num){
    double sign, powersign, c;
    double power, exponent;
    power = exponent = 0.0;
    while((c = getch()) == ' ' || c == '\t');

    if(c != '-' && c != '+' && c != '.' && c != EOF && !isdigit(c) && c != 'e' && c != 'E'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if(c == '-' || c == '+')
        c = getch();

    if(!isdigit(c) && c != 'e' && c != 'E'){
        ungetch(c);
        return 0;
    }

    for(*num = 0.0; isdigit(c); c = getch()){
        *num = 10.0 * (*num) + (c - '0');
    }

    if(c == '.'){
        for(exponent = 0.0, c = getch(); isdigit(c); c = getch(), --exponent){
            *num = 10.0 * (*num) + (c - '0');
        }
    }
    if(c == 'E' || c == 'e'){
        c = getch();
        powersign = (c == '-') ? -1 : 1;
        if(c == '-' || c == '+')
            c = getch();
        
        for(power = 0.0; isdigit(c); c = getch()){
            power = 10.0 * power + (c - '0');
        }
        power *= powersign; 
    }
    power += exponent;
    exponent = mypow(10.0, power);
    *num *= exponent;
    *num *= sign;
    if(c != EOF)
        ungetch(c);

    return c; 
}  

double mypow(double base, double power){
    double result;
    int sign = 1;
    if(power < 0){
        sign = -1;
        power = -power;
    }
    for(result = 1.0; power > 0; --power, result *= base);
    if(sign == -1)
        result = 1.0/result;

    return result;
}