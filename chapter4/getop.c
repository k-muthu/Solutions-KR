#include <stdio.h>
#include "calc.h"

#define NOV 27	/* no of variables */
double var[NOV];

int mygetop(char s[])
{
	int c, i;
	char variable = '\0';

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	/* checking for a variable or a math function */
	if (c >= 'a' && c <= 'z') {
		while ((s[++i] = c = getch()) >= 'a' && c <= 'z')
			;
		/* variable assignment found */
		if (c == '=') {
			variable = s[i - 1];
			s[0] = c = getch();
		}
		/* performing operations on variables */
		else if (i == 1) {
			ungetch(c);
			variable = s[0];
			s[i] = '\0';
			return VARIABLE;
		}
		/* math function found */
		else {
			ungetch(c);
			s[i] = '\0';
			return FUNCTION;
		}
	}
	/* checking for basic math operations or a newline */
	if (!(c >= '0' && c <= '9') && c != '.' && c != '-' && variable == '\0')
		return c;	/* not a number */
	/* checking if '-' is subtraction or part of a negative number */
	if (c == '-') {
		c = getch();
		ungetch(c);
		if (!(c >= '0' && c <= '9'))
			return '-';
	}
	i = 0;
	/* collecting numbers into array */
	if (c >= '0' && c <= '9')
		while ((s[++i] = c = getch()) >= '0' && c <= '9')
			;
	if (c == '.')
		while ((s[++i] = c = getch()) >= '0' && c <= '9')
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	/* variable assignment */
	if (variable != '\0') {
		var[variable - 'a'] = myatof(s);
		s[0] = variable;
		s[1] = '\0';
		return VARIABLE;
	}
	return NUMBER;
}

