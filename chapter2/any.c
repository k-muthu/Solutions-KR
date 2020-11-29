#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s1[] = "the index of character x is 8\n";
	char s2[] = "x";
	printf("s1 : %s", s1);
	printf("s2 : %s\n", s2);
	printf("%d : the first position in s1 of any character in s2\n", any(s1, s2));
}

/* any : returns the first position, in s1, of any character in s2 */
int any(char s1[], char s2[])
{
	int pos;
	int i, j;

	pos = -1;
	for (i = 0; s1[i] != '\0' && pos == -1; ++i) {
		for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j);
		if (s2[j] != '\0')
			pos = i;
	}
	return pos;
}
