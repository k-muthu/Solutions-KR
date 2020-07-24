#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100   /* max size of operand or operator*/
#define NUMBER '0'
#define VARIABLE 'v'
#define STACKSIZE 100
#define BUFFERSIZE 100

int operation = 0;

int getop(char s[]);
void push(double number);
double pop(void);
void printtop(void);
void clearstack(void);
void swaptop2(void);
void duplicatestack(void);
int functions(char s[]);
int compare(char s1[], char s2[]);
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


int sp = 0; /* The next free stack position */
double stack[STACKSIZE];
double variables[27];
int var_set[26];
int initialize = -1;

void push(double number){
    if(sp < STACKSIZE)
        stack[sp++] = number;
    else
        printf("error : stack full, cant add %g to stack\n", number);
}

double pop(void){
    if(sp){
        return stack[--sp];
    }
    else{
        printf("error : stack empty, nothing to pop\n");
        return 0.0;
    }
}

/* printtop : prints the top element in the stack(Excercise 4-4) */
void printtop(void){
    if(sp){
        printf("Top of Stack : %g\n", stack[sp - 1]);
    }
    else{
        printf("stack empty");
    }
}

/* clearstack : empties the stack(Excercise 4-4)*/
void clearstack(void){
    printf("Stack cleared\n");
    sp = 0;
}

/* swaptop2 : swaps the top 2 elements of the stack(Excercise 4-4) */
void swaptop2(void){
    if(sp > 0){
        int op1, op2;
        op2 = pop();    /* The top element of the stack */
        op1 = pop();
        push(op2);
        push(op1);
    }
    else
        printf("stack empty");
}

/* duplicatestack : duplicates the top element in the stack provided if theres any (Excercise 4-4)*/
void duplicatestack(void){
    int top;
    if(sp){
        push(top = pop());
        push(top);
    }
    else{
        printf("stack empty\n");
    }
}

int getch(void);
void ungetch(int c);

int getop(char s[]){
    int i, c;
    initialize = -1;
    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(isalpha(c)){
        i = 0;
        while(isalpha(s[++i] = c = getch()));
        if(c == '=' && i == 1){
            initialize = s[0] - 'a';
            s[0] = c = getch();    
        }
        else if(c == ' ' && i == 1){
            initialize = s[0] - 'a';
            s[1] = '\0';
            return VARIABLE;
        }
        else{
            ungetch(c);
            s[i] = '\0';
            return functions(s);
        }
    }
    if(c == '-'){
        c = getch();
        ungetch(c);
        if(!isdigit(c)){    /* To check if there is a negative number */
            return '-';
        }
    }

    if(!isdigit(c) && c != '.' && c!= '-')
        return c;

    i = (c == '-') ? 1 : 0;
    if(isdigit(c) || c == '-')
        while(isdigit(s[++i] = c = getch()));

    if(c == '.')
        while(isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    
    if(initialize >= 0 && initialize <= 26){
        return VARIABLE;
    }

    return NUMBER;
}

char buffer[BUFFERSIZE];
int bufp = 0;   /* The next free buffer index */

int getch(void){
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp < BUFFERSIZE)
        buffer[bufp++] = c;
    else
        printf("Too many characters pushed back.\n");
}

/* compare : a simple version of the library function strcmp */
int compare(char s1[], char s2[]){
    int i, j;
    i = j = 0;
    while((tolower(s1[i]) == tolower(s2[j])) && s1[i] != '\0' && s2[j] != '\0'){
        ++i;
        ++j;
    }
    if(!i && !j)
        return -1;  /* Both strings are emoty */
    else if(s1[i] == '\0' && s2[j] == '\0')
        return 1;
    else
        return 0;

}

int functions(char s[]){
    int type;
    if(compare(s, "sin") > 0)
        return '1';
    if(compare(s, "exp") > 0)
        return '2';
    if(compare(s, "pow") > 0)
        return '3';
    if(compare(s, "clearvariables") > 0)
        return '4';
    if(compare(s, "printtop") > 0)
        return '5';
    if(compare(s, "clearstack") > 0)
        return '6';
    if(compare(s, "swaptop2") > 0)
        return '7';
    if(compare(s, "duplicatestack") > 0)
        return '8';
    
    return -1;
}

void initializer(int a[], int value, int length){
    int i;
    for(i = 0; i < length; ++i)
        a[i] = value;
}
