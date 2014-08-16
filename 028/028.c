#include <stdio.h>

int sum_spiral_diagonals(int side)
{
	int i, j, k, sum;

	sum = 1;
	k = 1;
	for (i = 3; i <= side; i += 2) {
		for (j = 0; j < 4; j++) {
			k += (i - 1);
			sum += k;
		}
	}

	return sum;
}

int main(int argc, char *argv[])
{
	printf("%d\n", sum_spiral_diagonals(1001));
	return 0;
}

