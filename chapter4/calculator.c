#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100   /* max size of operand or operator*/
#define NUMBER '0'
#define STACKSIZE 100
#define BUFFERSIZE 100

int getop(char s[]);
void push(double number);
double pop(void);
double top();

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
            
            case '\n' :
                    printf("Answer : %g\n", pop());
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

double top(){
    if(sp){
        return stack[sp - 1];
    }
    else{
        printf("stack empty, nothing to print");
        return 0.0;
    }
}

int getch(void);
void ungetch(int c);

int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;

    i = 0;
    if(isdigit(c))
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