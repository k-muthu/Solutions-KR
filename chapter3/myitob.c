#include <stdio.h>
#include <limits.h>

#define MAXLINE 20

void myitob(int n, char s[], int b);
void strreverse(char s[]);
int len(char s[]);

int main()
{
	int num = INT_MIN;
	char s[MAXLINE];

	myitob(num, s, 8);
	printf("%s\n", s);
	return 0;
}

/* myitoa : converts a number to a string */
void myitob(int n, char s[], int b)
{
	int i, j, sign, min;

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
		s[i++] = (n % b > 9) ? (n % b + 'A' - 10) : (n % b + '0');
	} while ((n /= b) > 0);

	/* INT_MAX and INT_MIN differ by one in the units place when absolute value is taken */
	if (min == 1) {
		/* to find if the base is a power of 2 */
		j = 1 << 1;
		while(j) {
			if ((b & j) == b)
				break;
			else
				j <<= 1;
		}
		/* if b is a power of 2 */
		if (j) {
			for (j = 0; j < i - 1; ++j)
				s[j] = '0';
			++s[j];
		}
		else
			++s[0];
	}
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
