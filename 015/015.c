#include <stdio.h>
#include <string.h>

long long find_total_routes(int column, int line)
{
	int i, j;
	long long a[(column + 1)];
	for (i = 0; i <= column; i++)
		a[i] = 1;
	for (i = 1; i <= line; i ++) {
		for (j = 1; j <= column; j++)
			a[j] += a[(j - 1)];
	}
	return a[column];
}

int main(int argc, char *argv[])
{
	printf("%lld\n", find_total_routes(20, 20));
	return 0;
}

