#include <stdio.h>
#include <string.h>
#include <math.h>

int find_distinct_powers(int min, int max)
{
	int i, j, k, l, cnt, bases[max + 1], exps[max + 1];

	memset(&bases, 0, sizeof(bases));
	memset(&exps, 0, sizeof(exps));

	cnt = 0;
	for (i = 2; i <= max; i++) {
		for (j = (i * i), k = 2; j <= max; j *= i, k++) {
			if (bases[j] != 0)
				continue;
			bases[j] = i;
			exps[j] = k;
		}

		if (i < min)
			continue;

		cnt += (max - min + 1);

		if (exps[i] == 0)
			continue;

		for (j = min; j <= max; j++) {
			k = (exps[i] * j);
			for (l = (exps[i] - 1); (int)pow(bases[i], l) >= min; l--) {
				if (k % l != 0)
					continue;
				if ((k / l) < min)
					continue;
				if ((k / l) > max)
					break;
				cnt--;
				break;
			}
		}
	}

	return cnt;
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_distinct_powers(2, 100));
	return 0;
}

