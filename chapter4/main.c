#include <stdio.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100	/* max size of operator or operand */

int compare(char [], char []);

/*reverse polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	extern double var[];

	while ((type = mygetop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(myatof(s));
				break;
			case FUNCTION:
				if (compare(s, "sin"))
					push(sin(pop()));
				else if (compare(s, "exp"))
					push(exp(pop()));
				else if (compare(s, "pow")) {
					op2 = pop();
					push(pow(pop(), op2));
				}
				break;
			case VARIABLE:
				push(var[s[0] - 'a']);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 == 0.0)
					printf("zero division error\n");
				else
					push(pop() / op2);
				break;
			case '%':
				op2 = pop();
				if (op2 == 0.0)
					printf("zero modulo error\n");
				else
					push(((int)pop()) % ((int)op2));
				break;
			case '\n':
				var[PRINT] = pop();
				printf("%g\n", var[PRINT]);
				break;
			default:
				printf("ERROR\n");
				break;
		}
	}
	return 0;
}

int compare(char s[], char t[])
{
	int i;

	for (i = 0; (s[i] == t[i]) && s[i] != '\0' && t[i] != '\0'; ++i)
		;
	if (s[i] == '\0' && t[i] == '\0')
		return 1;
	else
		return 0;
}
