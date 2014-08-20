#include <stdio.h>
#include <math.h>
#include <string.h>

int sum_matched_powers(int *powers, int total, int picks)
{
	int i, j, k, l, sum;
	int digits[picks];

	sum = 0;
	memset(digits, 0, sizeof(digits));

	while (1) {
		j = k = 0;
		for (i = 0; i < picks; i++)
			j += powers[digits[i]];

		for (i = j, l = 0; i > 0; i /= total, l++)
			k += powers[i % total];


		if ((j == k) && (l == picks))
			sum += j;

		if (digits[0] == (total - 1))
			break;

		for (i = (picks - 1); i >= 0; i--) {
			if (digits[i] >= (total - 1))
				continue;
			digits[i]++;
			for (l = (i + 1); l < picks; l++)
				digits[l] = digits[i];
			break;
		}
	}

	return sum;
}

int sum_digit_powers(int exp)
{
	int i, sum, max_digit, powers[10];

	powers[0] = 0;
	powers[1] = 1;
	for (i = 2; i < 10; i++)
		powers[i] = (int)pow(i, exp);

	max_digit = 1;
	for (i = powers[9]; i > 0; i /= 10)
		max_digit++;
	max_digit++;

	sum = 0;
	for (i = 2; i < max_digit; i++)
		sum += sum_matched_powers(powers, 10, i);

	return sum;
}

int main(int argc, char *argv[])
{
	printf("%d\n", sum_digit_powers(5));
	return 0;
}

