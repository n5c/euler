#include <stdio.h>
#define LIMIT 1000

int main (int argc, char *argv[])
{
	int i, sum = 0;

	for (i = 3; i < LIMIT; i += 3)
		sum += i;

	for (i = 5; i < LIMIT; i += 5) {
		if ((i % 3) == 0)
			continue;
		sum += i;
	}

	printf ("%d\n", sum);
	return 0;
}
