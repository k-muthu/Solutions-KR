#include <stdio.h>
#include <limits.h>

#define MAXLINE 20

void myitoa(int n, char s[]);
void strreverse(char s[]);
int len(char s[]);

int main()
{
	int num = INT_MIN + 1;
	char s[MAXLINE];

	myitoa(num, s);
	printf("%s\n", s);
	return 0;
}

/* myitoa : converts a number to a string */
void myitoa(int n, char s[])
{
	int i, sign, min;

	i = 0;
	min = 0;
	sign = 1;
	if (n < 0) {
		sign = -1;
		if (n == INT_MIN) {
			min = 1;
			n = INT_MAX;
		}
		else
			n = -n;
	}
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	/* INT_MAX and INT_MIN differ by one in the units place when absolute value is taken */
	if (min == 1)
		s[0] = s[0] + 1;
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	strreverse(s);
}

/* strreverse : reverse the input string */
void strreverse(char s[])
{
	int i, j, temp;
	
	for (i = 0, j = len(s) - 1; i < j; ++i, --j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

/* len : returns string length */
int len(char s[])
{
	int i;

	for ( i = 0; s[i] != '\0'; ++i);
	return i;
}
