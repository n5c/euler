#include <stdio.h>

int find_product(int limit)
{
	int i, j, k, p = 0;

	for (i = 1; i <= (limit - 2); i++) {
		for (j = 1; j < (limit - i - 1); j++) {
			k = (limit - i - j);
			if ((i * i) != ((j * j) + (k * k)))
				continue;
			p = (i * j * k);
			break;
		}

		if (p)
			break;
	}

	return p;
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_product(1000));
	return 0;
}
