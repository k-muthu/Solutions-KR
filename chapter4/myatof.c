#include <stdio.h>

double myatof(char s[]);

int main()
{
	char s[] = "1456.23e-03";

	printf("number : %g\n", myatof(s));
	return 0;
}

/* myatof : returns the double equivalent of the string */
double myatof(char s[])
{
	int i, sign, exp_sign;
	double val, power, exponent;

	/* remove leading whitespace characters */
	for (i = 0; s[i] == ' '; ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (val = 0.0; s[i] >= '0' && s[i] <= '9'; ++i)
		val = 10 * val + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		val = 10 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		++i;
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (exponent = 0; s[i] != '\0'; ++i)
		exponent = exponent * 10 + (s[i] - '0');
	exponent *= exp_sign;
	/* combining power and exponent together to form a single power */
	while (exponent) {
		if (exp_sign == -1) {
			power *= 10;
			++exponent;
		}
		else{
			power /= 10;
			--exponent;
		}
	}
	return val/power * sign;
}

/* a comment on format specifiers for double datatype
 * assume number = 1456.23e-03
 * %f will print it in fractional format i.e. 1.45623
 * %e or %E will print it in scientific notation i.e. 1.456230e+00 or 1.456230E+00 accordingly
 * %g or %G will print the number in fractional format if the number is in certain range or in scientific notation
 * if the number is out of that range. In this example itll print 1.45623
 */
