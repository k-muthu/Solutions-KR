#include<stdio.h>

#define MAXLINE 1000

/*
myatof : converts string s to double
Excercise : 4-2
*/

double myatof(char input[]);
int whitespace(char c);
int digit(char c);
double mypow(double base, double power);

/*Note : for printing floating point numbers there are 3 specifiers
assume the number to be printed is 123.45e-2
%f : print the number in fractional format i.e. for the above number itll print 1.2345
%e or %E : print the number in scientific notation i.e for above number itll print 1.2345e-04(%e), 1.2345E-04(%E)
%g or %G : if a number is in a certain range itll print in fractional format otherwise itll use scientific notation
when using scientific notation %g is equivalent to %e and %G is equivalent to %F.
*/
int main(){
    char input[] = "123.45";
    double num = myatof(input);
    printf("%g\n", num);
    return 0;
}

double myatof(char input[]){
    double result, power, exponent;
    int i, sign, powersign;
    powersign = 1;
    for(i = 0; whitespace(input[i]); ++i);
    sign = (input[i] == '-') ? -1 : 1;
    if(input[i] == '+' || input[i] == '-')
        ++i;
    for(result = 0.0; digit(input[i]) != '\0'; ++i){
        result = (result * 10) + (input[i] - '0');
    }
    if(input[i] == '.')
        ++i;
    for(power = 1.0; digit(input[i]); ++i){
        result = (result * 10) + (input[i] - '0');
        power *= 10.0; 
    }
    power = 1.0 / power ;
    if(input[i] == 'e' || input[i] == 'E')
        ++i;
    powersign = (input[i] == '-') ? -1 : 1;

    if(input[i] == '-' || input[i] == '+')
        ++i;

    for(exponent = 0.0; digit(input[i]); ++i)
        exponent = (exponent * 10) + (input[i] - '0');

    exponent *= powersign;
    power *= mypow(10.0, exponent);
    return sign * result * power;
}

double mypow(double base, double pow){
    double result = 1.0;
    int sign = 1;
    double i;
    if(pow < 0){
        sign = -1;
        pow = -pow;
    }
    while(pow--){
        result *= base; 
    }
    return (sign) ? (1/result) : result;
}

/* ctype.h has a function isspace(c) */
int whitespace(char c){
    return (c == ' ' || c == '\n' || c == '\t');
}

/* ctype.h has a function isdigit(c) */
int digit(char c){
    return (c >= '0' && c <= '9');
}