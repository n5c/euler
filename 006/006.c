#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, limit, sum_of_sqrt, sqrt_of_sum;

	limit = 100;

	sum_of_sqrt = 0;
	sqrt_of_sum = 0;
	for (i = 1; i <= limit; i++) {
		sum_of_sqrt += (i * i);
		sqrt_of_sum += i;
	}

	sqrt_of_sum = sqrt_of_sum * sqrt_of_sum;

	printf ("%d\n", abs(sqrt_of_sum - sum_of_sqrt));

	return 0;
}


