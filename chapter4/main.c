#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100   /* max size of operand or operator*/

int operation = 0;


void initializer(int a[], int value, int length);

int main(){
    int type;
    double op2;
    char s[MAXOP];
    extern int var_set[26];
    extern double variables[27];
    extern int initialize;
    initializer(var_set, 0, 26);
    printf("Reverse Polish notation calculator\n");
    printf("Variable allowed(a-z), initializing rule for variable : \"variable_name\"=\"value\" \n");
    printf("clearvariables command required before a used variable can be reassigned\n");
    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER :
                push(atof(s));
                operation = 0;
                break;
            
            case '+' : 
                push(pop() + pop());
                operation = 1;
                break;

            case '*' :
                push(pop() * pop());
                operation = 1;
                break;

            case '-' :
                op2 = pop();
                push(pop() - op2);
                operation = 1;
                break;

            case '/' : 
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() / op2);
                    operation = 1;
                }   
                else
                    printf("error : Trying to divide by zero");
                break;

            case '%' : 
                op2 = pop();
                push(fmod(pop(), op2));
                operation = 1;
                break;
            
            case '\n' :
                if(operation){
                    variables[26] = pop();
                    printf("Answer : %g\n", variables[26]);
                }
                operation = 0;
                break;
            
            case '1' :
                push(sin(pop()));
                operation = 1;
                break;

            case '2' :
                push(exp(pop()));
                operation = 1;
                break;
            
            case '3' :
                op2 = pop();
                push(pow(pop(), op2));
                operation = 1;
                break;
            
            case '4' :
                initializer(var_set, 0, 26);
                operation = 0;
                break;
            
            case '5' :
                printtop();
                operation = 0;
                break;

            case '6' :
                clearstack();
                operation = 0;
                break;

            case '7' :
                swaptop2();
                operation = 0;
                break;

            case '8' :
                duplicatestack();
                operation = 0;
                break;

            case VARIABLE :
                if(var_set[initialize]){
                    push(variables[initialize]);
                }
                else{
                    var_set[initialize] = 1;
                    variables[initialize] = atof(s);
                }
                operation = 0;
                break;
            
            defult : 
                printf("Unknown operation");
                operation = 0;
                break;
        }
    }

    return 0;
}

void initializer(int a[], int value, int length){
    int i;
    for(i = 0; i < length; ++i)
        a[i] = value;
}
