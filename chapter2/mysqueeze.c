#include <stdio.h>

void shrink(char s[], char d[]);

int main()
{
	char s[] = "I am trying to delete all spaces and this word \" xxzz \".\n";
	char d[] = " xzxz";
	shrink(s, d);
	printf("%s", s);
	return 0;
}

/* shrink : deletes all occurances of any character in the string d from the string s */
void shrink(char s[], char d[])
{
	int i, j, k;
	for (i= j = 0; s[i] != '\0'; ++i) {
		for (k = 0; d[k] != '\0' && s[i] != d[k]; ++k);
		if (d[k] == '\0')
			s[j++] = s[i];
	}
	s[j] = '\0';
}

