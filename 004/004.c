#include <stdio.h>

int _pow(int base, int exp)
{
	int i, j = 1;
	for (i = 0; i < exp; i++)
		j *= base;
	return j;
}

int is_palindrome(int p)
{
	int i, j = p;
	char chk[10];

	for (i = 0; j > 0; i++) {
		chk[i] = (j % 10);
		j /= 10;
	}

	i--;
	for (j = 0; j < i; i--, j++) {
		if (chk[j] != chk[i])
			return 0;
	}

	return 1;
}

int is_palindrome_2(int p)
{
	int n = p, reverse = 0;
	while (n > 0) {
		reverse = ((10 * reverse) + n % 10);
		n /= 10;
	}
	return (p == reverse);
}

int find_largest_palindrome_product(int digit)
{
	int i, j, p, max = 0, lo, hi;
	
	lo = _pow(10, (digit - 1));
	hi = _pow(10, digit);
	for (i = (hi - 1); i >= lo; i--) {
		for (j = i; j >= lo; j--) {
			p = (i * j);
			if (p < max)
				break;
			if (is_palindrome_2(p) == 0)
				continue;
			max = p;
		}
	}

	return max;
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_largest_palindrome_product(3));
	return 0;
}

