#include <stdio.h>
#include <ctype.h>

#define MAXLINE 30

char expanded[MAXLINE];

int mygetline(char line[], int max);
void expand(char s[], char t[]);

int main()
{
	char line[MAXLINE];
	while ((mygetline(line, MAXLINE))) {
		printf("line : %s", line);
		expand(expanded, line);
		printf("%s", expanded);
	}
}
/* expand : expands all shorthand notations in t while copying it to string s */
void expand(char s[], char t[])
{
	int i, j, k;

	for (i = 0, j = 0; t[i] != '\0'; ++i) {
		/* check for a shorthand notation */
		if (t[i] == '-') {
			/* check if the '-' is a leading or trailing character of the line */
			if ((i != 0) && (t[i + 1] != '\n') && (t[i + 1] != '\0')) {
				++i;
				/* shorthand notation is expanded only for a-z, A-Z, 0-9 */
				if ((isdigit(t[i-2]) && isdigit(t[i])) || (isalpha(t[i-2]) && isalpha(t[i])))
					/* shorthand notation is expanded in this loop */
					for (k = t[i - 2] + 1; k <= t[i]; ++k)
						s[j++] = k;
				else{
					s[j++] = '-';
					s[j++] = t[i];
				}
			}
			else
				s[j++] = t[i];
		}
		else
			s[j++] = t[i];
	}
	s[j] = '\0';
}

int mygetline(char line[], int max)
{
	int i, c;

	i = 0;
	while ((i < max - 1) && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;

	if (c == '\n')
		line[i++] = c;

	line[i] = '\0';
	return i;
}
