#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int *primes;
int primes_length;
int primes_max;

int is_prime(int p);
void expand_primes(int limit);

int find_coeffs_production(int limit)
{
	int a, b, n, p, max, max_a, max_b;
	for (a = (1 - limit); a < limit; a++) {
		for (b = (1 - limit); b < limit; b++) {
			n = 0;
			while (1) {
				p = ((n * n) + (a * n) + b);
				if (p < -1)
					p *= -1;
				if (!is_prime(p))
					break;
				n++;
			}

			if (n > max) {
				max = n;
				max_a = a;
				max_b = b;
			}
		}
	}

	return (max_a * max_b);
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_coeffs_production(1000));
	return 0;
}

int is_prime(int p)
{
	int i, chk;
	chk = ((int)sqrt((double)p) + 1);
	if (chk > primes_max)
		expand_primes(chk);
	for (i = 0; (i < primes_length) && (primes[i] < chk); i++) {
		if (p % primes[i] == 0) {
			return 0;
		}
	}

	return 1;
}

void expand_primes(int limit)
{
	int i, j, chk;
	if (primes_length == 0) {
		primes_length = 4;
		primes = malloc(primes_length * sizeof(*primes));
		assert(primes != NULL);

		primes[0] = 2;
		primes[1] = 3;
		primes[2] = 5;
		primes[3] = 7;
		primes_max = 7;
	}

	while (primes_max < limit) {
		i = primes_length;
		primes_length <<= 1;
		primes = realloc(primes, (sizeof(*primes) * primes_length));
		assert(primes != NULL);

		for (j = (primes_max + 6); i < primes_length; j += 6) {
			if (is_prime(j)) {
				primes[i] = j;
				i++;
			}

			if (is_prime(j - 2)) {
				primes[i] = (j - 2);
				i++;
			}
		}

		primes_max = primes[primes_length - 1];
	}
}

