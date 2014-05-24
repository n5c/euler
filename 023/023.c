#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum_nonabundants(int limit)
{
	int i, j, k, l, sum, *n, *a;

	n = calloc((limit + 1), sizeof(*n));
	assert(n != NULL);

	a = calloc((limit + 1), sizeof(*a));
	assert(a != NULL);

	k = 0;
	for (i = 2; i <= limit; i++) {
		n[i] += 1;
		for (j = (i + i); j <= limit; j += i)
			n[j] += i;
		if (n[i] > i) {
			a[k] = i;
			k++;
		}
	}

	sum = (((limit) * (limit + 1)) >> 1);

	for (i = 0; i < k; i++) {
		if ((a[i] << 1) > limit)
			break;
		for (j = i; j < k; j++) {
			l = (a[i] + a[j]);
			if (l > limit)
				break;
			if (n[l] == 0)
				continue;
			n[l] = 0;
			sum -= l;
		}
	}

	free(a);
	free(n);

	return sum;
}

int main(int argc, char *argv[])
{
	printf("%d\n", sum_nonabundants(28123));
	return 0;
}

