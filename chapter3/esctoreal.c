#include <stdio.h>

#define MAXLINE 48

int mygetline(char line[], int max);
void esctoreal(char s[], char t[]);

int main()
{
	char line[MAXLINE];
	char t[MAXLINE];
	int len;

	while ((len = mygetline(line, MAXLINE))) {
		esctoreal(t, line);
		printf("%s", t);
	}
}

/* esctoreal : replaces escape sequences with their whitespace characters*/
void esctoreal(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[i] != '\0') {
		if (t[i] == '\\') {
			++i;
			switch (t[i]) {
				case 'n' :
					s[j++] = '\n';
					break;
				case 't' :
					s[j++] = '\t';
					break;
				case '\\' :
					s[j++] = '\\';
					break;
				default :
					s[j++] = '\\';
					s[j++] = t[i];
					break;
			}
		}
		else
			s[j++] = t[i];
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

