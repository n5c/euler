#include <stdio.h>

long long find_nth_permutation(int *digits, int size, int nth)
{
	int i, j, perms[size], number[size], __nth;
	long long perm;

	for (i = 0; i < size; i++)
		digits[i] = i;

	perms[0] = 1;
	for (i = 1; i < size; i++)
		perms[i] = ((i + 1) * perms[(i - 1)]);

	if (nth > perms[size - 1])
		return 0;

	__nth = 0;
	for (i = (size - 2); i >= 0; i--) {
		for (j = 0; j < size; j++) {
			if (digits[j] == -1)
				continue;
			number[i + 1] = digits[j];
			break;
		}

		if ((__nth + perms[i]) >= nth) {
			digits[j] = -1;
			continue;
		}

		for (; j < size; j++) {
			if (digits[j] == -1)
				continue;
			number[i + 1] = digits[j];
			if ((__nth + perms[i]) >= nth)
				break;
			__nth += perms[i];
		}

		digits[j] = -1;
	}

	for (j = 0; j < size; j++) {
		if (digits[j] == -1)
			continue;
		number[0] = digits[j];
		break;
	}

	perm = 0;
	j = 1;
	for (i = 0; i < size; i++) {
		perm += (long long)(number[i] * j);
		j *= 10;
	}

	return perm;
}

int main(int argc, char *argv[])
{
	int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%llu\n", find_nth_permutation(digits,
					      (sizeof(digits)/sizeof(int)),
					      1000000));
	return 0;
}


