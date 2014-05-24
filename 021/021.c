#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void find_amicables(int *a, int size)
{
	int i, j;
	memset(a, 0, (sizeof(*a) * size));
	for (i = 2; i < size; i++) {
		a[i] += 1;
		for (j = (i + i); j < size; j += i)
			a[j] += i;
	}
}

int sum_amicables(int num)
{
	int i, sum;
	int *a;

	a = calloc(num, sizeof(*a));
	assert(a != NULL);

	find_amicables(a, num);

	sum = 0;
	for (i = 2; i < num; i++) {
		if (a[i] >= num)
			continue;
		if (i != a[a[i]])
			continue;
		if (i >= a[i])
			continue;
		sum += (a[i] + a[a[i]]);
	}

	free(a);

	return sum;
}

static inline int sum_divisors(int num)
{
	int i, p, sum, _num;
	_num = num;
	sum = 1;
	p = 2;
	while (((p * p) <= _num) && (_num > 1)) {
		if ((_num % p) == 0) {
			i = (p * p);
			_num /= p;
			while ((_num % p) == 0) {
				i *= p;
				_num /= p;
			}
			sum *= (i - 1);
			sum /= (p - 1);
		}
		p = ((p == 2) ? 3 : (p + 2));
	}
	if (_num > 1)
		sum *= (_num + 1);
	return (sum - num);
}

int sum_amicables_2(int num)
{
	int i, j, sum = 0;
	for (i = 2; i < num; i++) {
		j = sum_divisors(i);
		if (i <= j)
			continue;
		if (sum_divisors(j) == i)
			sum += (i + j);
	}
	return sum;
}

int main(int argc, char *argv[])
{
	printf("%d\n", sum_amicables(1000000));
	return 0;
}


