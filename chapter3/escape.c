#include <stdio.h>

#define MAXLINE 28

int mygetline(char line[], int max);
void escape(char s[], char t[]);

int main()
{
	char line[MAXLINE];
	char t[MAXLINE];
	int len;

	while ((len = mygetline(line, MAXLINE))) {
		escape(t, line);
		printf("%s", t);
	}
}

/* escape : replaces whitespace characters with their visible escape sequences */
void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[i] != '\0') {
		switch (t[i]) {
			case '\n' :
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t' :
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default :
				s[j++] = t[i];
				break;
		}
		++i;
	}
	s[j] = '\0';
}

/* mygetline : returns the length of line, 0 if no line is present */
int mygetline(char line[], int max)
{
	int i, c;
	
	i = 0;
	while (i < max - 1 && ((c = getchar()) != EOF) && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return i;
}

