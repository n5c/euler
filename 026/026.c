#include <stdio.h>
#include <string.h>

#define BITS_PER_BYTE           8
#define BITS_PER_INT            (BITS_PER_BYTE * sizeof(int))
#define BIT_MASK(nr)            (1 << ((nr) % BITS_PER_INT))
#define BIT_WORD(nr)            ((nr) / BITS_PER_INT)
#define BITS_TO_INTS(nr)        ((nr + BITS_PER_INT - 1) / BITS_PER_INT)
#define CHK_BITS(nr, addr)      (addr[BIT_WORD(nr)] & BIT_MASK(nr))
#define SET_BITS(nr, addr)      do {addr[BIT_WORD(nr)] |= BIT_MASK(nr);} while(0);

int cal_cycle_length(int d)
{
	int q, r, len;
	int rbits[BITS_TO_INTS(d)];

	memset(rbits, 0, sizeof(rbits));

	r = 1;
	len = 0;
	while (1) {
		q = r * 10;
		r = (q % d);
		if (r == 0)
			break;
		if (CHK_BITS(r, rbits))
			break;
		SET_BITS(r, rbits);
		len++;
	}

	return len;
}

int find_longest_reciprocal_cycles_denominator(int range)
{
	int i, len, max, d;

	max = 0;
	for (i = 2; i < range; i++) {
		len = cal_cycle_length(i);
		if (len > max) {
			max = len;
			d = i;
		}
	}

	return d;
}

int main(int argc, char *argv[])
{
	printf("%d\n", find_longest_reciprocal_cycles_denominator(1000));
	return 0;
}

