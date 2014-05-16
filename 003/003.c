#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER 600851475143UL

int main(int argc, char *argv[])
{
	unsigned char *primes;
	unsigned int i, j;
	unsigned int n = (unsigned int)sqrtl((long double)NUMBER);

	if (n & 1)
		n++;

	primes = calloc(n, sizeof(*primes));
	if (primes == NULL)
		exit(-1);

	for (i = 3; i < n; i += 2) {
		if (primes[i] != 0)
			continue;
		for (j = (i + i); j < n; j += i)
			primes[j] = 1;
	}

	i = (n - 1);
	if ((i & 1) == 0)
		i--;

	for (i = (n - 1); i > 2; i -= 2) {
		if (primes[i] != 0)
			continue;
		if ((NUMBER % i) == 0)
			break;
	}

	free(primes);

	if ((i == 2) && ((NUMBER % i) != 0)) {
		printf("No prime factor is found\n");
		return 0;
	}

	printf("%d\n", i);

	return 0;
}
