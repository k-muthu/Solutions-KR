#include <stdio.h>

#define MAXVAL 100	/* max depth of stack */

static int sp = 0;	/* next free position in stack */
static double stack[MAXVAL];	/* the stack that holds the values */

/* push : push the number onto the stack */
void push(double num)
{
	if (sp < MAXVAL)
		stack[sp++] = num;
	else
		printf("error : stack full, cant push %g\n", num);
}

/* pop : returns the top of the stack */
double pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else {
		printf("error : stack empty\n");
		return 0.0;
	}
}

/* printtop : print top element of stack without using pop() */
void printtop(void)
{
	if (sp == 0)
		printf("Stack Empty\n");
	else
		printf("%g\n", stack[sp - 1]);
}

/* duplicatetop : duplicates the top element in stack */
void duplicatetop(void)
{
	double top;
	top = pop();
	push(top);
	push(top);
}

/* swap : swaps the top 2 elements in stack */
void swap(void)
{
	double op1, op2;
	op1 = pop();
	op2 = pop();
	push(op1);
	push(op2);
}

/* clearstack : clears the stack */
void clearstack(void)
{
	sp = 0;
}

