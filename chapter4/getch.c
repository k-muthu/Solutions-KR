#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];	/* buffer for ungetch */
static int bufp = 0;	/* next free position in buf */

int getch(void)
{
	return (bufp == 0) ? getchar() : buf[--bufp];
}

void ungetch(int c)
{
	if (bufp == BUFSIZE)
		printf("error : buffer full, cant push back '%c'\n", c);
	else
		buf[bufp++] = c;
}

/* unget : push back an entire string onto the input */
void unget(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	for (; i > 0; --i)
		ungetch(s[i]);
}

