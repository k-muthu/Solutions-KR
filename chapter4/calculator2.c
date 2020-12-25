#include <stdio.h>
#include <math.h>

#define MAXOP 100	/* max size of operator or operand */
#define NUMBER '0'	/* signal that a number was found */
#define FUNCTION '1'	/* signal that a math library function was found */
#define VARIABLE '2'	/* signal that a variable is found */
#define PRINT 26	/* variable that holds the value of whatever is printed */

double myatof(char []);
int mygetop(char []);
void push(double);
double pop(void);
int compare(char [], char []);

/* reverse polish calculator */
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

#define MAXVAL 100	/* max depth of stack */

int sp = 0;	/* next free position in stack */
double stack[MAXVAL];	/* the stack that holds the values */

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

#define NOV 27	/* no of variables */
double var[NOV];

#define MAXLINE 40

int lineempty;
int ind;
int length;
char line[MAXLINE];

int mygetline(char [], int);

int mygetop(char s[])
{
	int c, i, j;
	char variable = '\0';

	if (!lineempty) {
		length = mygetline(line, MAXLINE);
		ind = 0;
		lineempty = 1;
	}
	if (length > 0) {
		while ((s[0] = c = line[ind++]) == ' ' || c == '\t')
			;
		s[1] = '\0';
		i = 0;
		/* checking for a variable or a math function */
		if (c >= 'a' && c <= 'z') {
			while ((s[++i] = c = line[ind++]) >= 'a' && c <= 'z')
				;
			/* variable assignment found */
			if (c == '=') {
				variable = s[i - 1];
				s[0] = c = line[ind++];
			}
			/* performing operations on variables */
			else if (i == 1) {
				--ind;
				variable = s[0];
				s[i] = '\0';
				return VARIABLE;
			}
			/* math function found */
			else {
				--ind;
				s[i] = '\0';
				return FUNCTION;
			}
		}
		/* checking for basic math operations or a newline */
		if (!(c >= '0' && c <= '9') && c != '.' && c != '-' && variable == '\0') {
			//printf("wanted : %d\n", (c == ' ') ? 'y' : c);
			if (c == '\n') {
				lineempty = 0;
			}
			return c;	/* not a number */
		}
		/* checking if '-' is subtraction or part of a negative number */
		if (c == '-') {
			c = line[ind++];
			--ind;
			if (!(c >= '0' && c <= '9'))
				return '-';
		}
		i = 0;
		/* collecting numbers into array */
		if (c >= '0' && c <= '9')
			while ((s[++i] = c = line[ind++]) >= '0' && c <= '9')
				;
		if (c == '.')
			while ((s[++i] = c = line[ind++]) >= '0' && c <= '9')
				;
		s[i] = '\0';
		if (c != EOF)
			--ind;
		/* variable assignment */
		if (variable != '\0') {
			var[variable - 'a'] = myatof(s);
			s[0] = variable;
			s[1] = '\0';
			return VARIABLE;
		}
		return NUMBER;
	}
	return EOF;
}

int mygetline(char line[], int max)
{
	int i, c;

	i = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}

double myatof(char s[])
{
	int i, sign, exp_sign;
	double mantissa, exponent, power;

	for (i = 0; s[i] == ' ' || s[i] == '\t'; ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (mantissa = 0.0; s[i] >= '0' && s[i] <= '9'; ++i)
		mantissa = 10 * mantissa + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		mantissa = 10 * mantissa + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		++i;
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (exponent = 0.0; s[i] >= '0' && s[i] <= '9'; ++i)
		exponent = 10 * exponent + (s[i] - '0');
	exponent *= exp_sign;
	while (exponent) {
		if (exp_sign == -1) {
			power *= 10.0;
			++exponent;
		}
		else {
			power /= 10.0;
			--exponent;
		}
	}
	return sign * (mantissa / power);
}
