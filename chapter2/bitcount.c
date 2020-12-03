#include <stdio.h>

unsigned int bitcount(unsigned int num);

int main()
{
	unsigned int num = 255;

	printf("%u\n", bitcount(num));
	return 0;
}

/* bitcount : returns the position of the leftmost bit that is set to 1 */
unsigned int bitcount(unsigned int num)
{
	unsigned int count;

	count = 0;
	while (num != 0) {
		++count;
		num &= num - 1;
	}
	return count;
}
