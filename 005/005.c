#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, input, num, *primes;

	input = 20; // 1 ~ input

	primes = calloc((input + 1), sizeof(*primes));
	if (primes == NULL)
		exit(-1);

	if (input == 0)
		return 0;

	primes[0] = 1;
	primes[1] = 1;
	for (i = 2; i <= input; i++) {
		if (primes[i] != 0)
			continue;

		num = (i << 1);
		while(num <= input) {
			primes[num] = 1;
			num += i;
		}

		num = i;
		while(num <= input) {
			primes[i] = num;
			num *= i;
		}
	}

	num = 1;
	for (i = 0; i <= input; i++) {
		if (primes[i] == 1)
			continue;
		num = num * primes[i];
	}

	free(primes);

	printf ("%d\n", num);

	return 0;
}

