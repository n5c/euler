#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define BUFSIZE 10001
#define LIMIT 2000000


long long sum_of_primes_2(unsigned num)
{
	unsigned i, j, *primes;
	unsigned crosslimit = sqrt((double)num);
	long long sum;

	primes = calloc(num, sizeof(*primes));
	assert(primes != NULL);

	sum = 2;
	for (i = 3; i < crosslimit; i += 2) {
		if (primes[i] != 0)
			continue;
		for (j = (i * i); j < num; j += (2 * i))
			primes[j] = 1;
		sum += i;
	}

	for (; i < num; i += 2) {
		if (primes[i] != 0)
			continue;
		sum += i;
	}

	free(primes);
	return sum;
}

long long sum_of_primes(int num)
{
	int i, j, *primes;
	long long sum;

	primes = calloc(num, sizeof(*primes));
	assert(primes != NULL);

	sum = 2;
	for (i = 3; i < num; i += 2) {
		if (primes[i] != 0)
			continue;
		for (j = (i + i); j < num; j += i)
			primes[j] = 1;
		sum += i;
	}

	free(primes);
	return sum;
}

int main(int argc, char *argv[])
{
	printf("%lld\n", sum_of_primes_2(LIMIT));
	return 0;
}


