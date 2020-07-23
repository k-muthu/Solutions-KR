#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100   /* max size of operand or operator*/
#define NUMBER '0'
#define STACKSIZE 100
#define BUFFERSIZE 100

int getop(char s[]);
void push(double number);
double pop(void);
void printtop(void);
void clearstack(void);
void swaptop2(void);
void duplicatestack(void);
int functions(char s[]);
int compare(char s1[], char s2[]);

int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch(type){
            case NUMBER :
                push(atof(s));
                break;
            
            case '+' :
                push(pop() + pop());
                break;

            case '*' :
                push(pop() * pop());
                break;

            case '-' :
                op2 = pop();
                push(pop() - op2);
                break;

            case '/' : 
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error : Trying to divide by zero");
                break;

            case '%' : 
                op2 = pop();
                push(fmod(pop(), op2));
                break;
            
            case '\n' :
                printf("Answer : %g\n", pop());
                clearstack();
                break;
            
            case '1' :
                push(sin(pop()));
                break;

            case '2' :
                //printf("enetered\n");
                push(exp(pop()));
                break;
            
            case '3' :
                op2 = pop();
                push(pow(pop(), op2));
                break;
            
            defult : 
                printf("Unknown operation");
                break;
        }
    }

    return 0;
}


int sp = 0; /* The next free stack position */
double stack[STACKSIZE];

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
    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(isalpha(c)){
        i = 0;
        while(isalpha(s[++i] = c = getch()));
        ungetch(c);
        s[i] = '\0';
        return functions(s);
    }
    if(c == '-'){
        if(isdigit(c = getch()))    /* To check if there is a negative number */
            ungetch(c);
        else
            return '-';
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
    
    return -1;
}
