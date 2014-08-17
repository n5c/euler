#include <stdio.h>
#include <math.h>

#define LIMIT 500

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

int find_triangle_number(int limit)
{
	int i = 1; /* start from 1 */
	int j;
	int tnum = 1; /* triangle number */
	int cnt;
	int chk; /* check limit */
	while (tnum > 0) {
		i++;
		tnum += i;
		cnt = 2; /* 1 + i */
		chk = (int)(sqrt((double)tnum) + 1);
		for (j = 2; j < chk; j++) {
			if ((tnum % j) != 0)
				continue;
			cnt += 2;
			if ((tnum / j) == j)
				cnt--;
			chk = (tnum / j);
		}
		if (cnt > limit)
			break;
	}
	return tnum;
}

static inline int is_prime(int *primes, int size, int num)
{
	int i, j;
	j = (int)(sqrt((double)num) + 1);
	for (i = 0; primes[i] < j; i++) {
		if ((num % primes[i]) == 0)
			return FALSE;
	}
	return TRUE;
}

void create_prime_tables(int *primes, int size)
{
	int i, j, k, cnt;
	primes[0] = 2;
	primes[1] = 3;
	cnt = 2;
	for (i = 5; cnt < size; i += 6) {
		if (is_prime(primes, cnt, i)) {
			primes[cnt] = i;
			cnt++;
			if (cnt >= size)
				break;
		}

		if (is_prime(primes, cnt, (i + 2))) {
			primes[cnt] = (i + 2);
			cnt++;
		}
	}
}

int find_triangle_number_2(int limit)
{
	int i, j, tnum, _tnum, exp, cnt;
	int primes[65536];
	create_prime_tables(primes, 65536);

	cnt = 0;
	for (i = 2, tnum = 1; cnt <= limit; i++) {
		tnum += i;
		cnt = 1;
		_tnum = tnum;
		for (j = 0; j < 65536; j++) {
			if ((primes[j] * primes[j]) > _tnum) {
				cnt *= 2;
				break;
			}
			exp = 1;
			while (_tnum % primes[j] == 0) {
				_tnum /= primes[j];
				exp++;
			}
			if (exp > 1)
				cnt *= exp;
			if (_tnum <= 1)
				break;
		}
	}
	return tnum;
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_triangle_number(LIMIT));
	return 0;
}

