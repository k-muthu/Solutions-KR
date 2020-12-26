double myatof(char s[])
{
	int i, sign, exp_sign;
	double mantissa, exponent, power;

	for (i = 0; s[i] == ' ' || s[i] == '\t'; ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (mantissa = 0.0; s[i] >= '0' && s[i] <= '9'; ++i)
		mantissa = 10 * mantissa + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		mantissa = 10 * mantissa + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		++i;
	exp_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (exponent = 0.0; s[i] >= '0' && s[i] <= '9'; ++i)
		exponent = 10 * exponent + (s[i] - '0');
	exponent *= exp_sign;
	while (exponent) {
		if (exp_sign == -1) {
			power *= 10.0;
			++exponent;
		}
		else {
			power /= 10.0;
			--exponent;
		}
	}
	return sign * (mantissa / power);
}
