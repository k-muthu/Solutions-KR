#include <stdio.h>

unsigned int myhtoi(char line[]);
unsigned int mylen(char line[]);

int main()
{
	char line[] = "0xFF2";
	printf("%u\n", myhtoi(line));
}

/* myhtoi : converts hex input into unsigned ints */
unsigned int myhtoi(char line[])
{
	int c;
	unsigned int i;
	unsigned int length;
	unsigned int num; /* num : variable that holds the result */

	num = 0;
	length = mylen(line);

	/* checks if 0x or 0X is part of the input */
	if (length >= 2) {
		if (line[0] == '0' && (line[1] == 'x' || line[1] == 'X'))
			i = 2;
		else if (line[0] == 'x' || line[0] == 'X')
			i = 1;
		else
			i = 0;
	}
	else
		i = 0;
	while ((c = line[i]) != '\0') {
		if ( c >= '0' && c <= '9')
			c = c - '0';
		else if (c >= 'a' && c <= 'f')
			c = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			c = c - 'A' + 10;
		num = 16 * num + c;
		++i;
	}
	return num;
}

unsigned int mylen(char line[])
{
	unsigned int i;

	for (i = 0; line[i] != '\0'; ++i);
	return i;
}
