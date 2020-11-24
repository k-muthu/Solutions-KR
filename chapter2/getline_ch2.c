#include <stdio.h>

#define MAXLINE 40

int modgetline(char line[], int max);

int main()
{
	char line[MAXLINE + 1];
	while (modgetline(line, MAXLINE + 1) > 0)
		printf("%s", line);

	return 0;
}

/* modgetline : doesnt use && or || in the normal getline function */
int modgetline(char line[], int max)
{
	int c;
	int i, cont;
	
	i = 0;
	cont = 1; /* cont : loop variable that is set when all 3 conditions of getline are met */
	while (cont != 0) {
		if (i < max - 1) {
			if ((c = getchar()) != EOF) {
				if (c != '\n')
					line[i] = c;
				else{
					line[i] = '\n';
					++i;
					line[i] = '\0';
					cont = 0;
				}
			}
			else{
				cont = 0;
				line[i] = '\0';
			}
		}
		else{
			line[i] = '\0';
			cont = 0;
		}
		++i;
	}
	return i - 1;
}
