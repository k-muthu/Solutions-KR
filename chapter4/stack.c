#include <stdio.h>

#define STACKSIZE 100

static int sp = 0; /* The next free stack position */
static double stack[STACKSIZE];

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
